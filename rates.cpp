

//////////////////////////////////////////////////////////////////////
//
// rates.cpp: 
//			implementation of the rates class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"

#include <math.h>
#include <stdlib.h>


extern holiday_priorities		*gsm_holiday_priorities;
extern time_discount_bands		*gsm_time_discount_bands;
extern rate_groups				*gsm_rate_groups;
extern cell_groups				*gsm_cell_groups;
extern network_groups			*gsm_network_groups;


bool rate_key::operator < (const rate_key &s) const
{
	if(rate_group_id < s.rate_group_id)
		return true;
	else if	(
		(rate_group_id == s.rate_group_id) && 
		(service_type_id < s.service_type_id)
		)
		return true;
	else if (
		(rate_group_id == s.rate_group_id) && 
		(service_type_id == s.service_type_id) && 
		(call_type_id < s.call_type_id)
		)
		return true;
	else if (
		(rate_group_id == s.rate_group_id) && 
		(service_type_id == s.service_type_id) && 
		(call_type_id == s.call_type_id) && 
		(locale_id < s.locale_id) 
		)
		return true;
	
	return false;
}

void rates::rule_score::init()
{
	day_type		= 0;
	network_group	= 0;
	cell_group		= 0;
	duration		= 999999;
}

rates::rule_score::rule_score()
{
	day_type		= 0;
	network_group	= 0;
	cell_group		= 0;
	duration		= 999999;
}

// highest attribute score with the 
// lowest duration score is the best rule
bool rates::rule_score::operator < (const rule_score &s) const
{
	if     (day_type < s.day_type)
		return true;
	else if(day_type == s.day_type &&
			network_group < s.network_group)
		return true;
	else if(day_type == s.day_type &&
			network_group == s.network_group &&
			cell_group < s.cell_group)
		return true;
	else if(day_type == s.day_type &&
			network_group == s.network_group &&
			cell_group == s.cell_group &&
			duration > s.duration)
		return true;

	return false;
}


bool rates::rule_score::operator == (const rule_score &s) const
{
	if (day_type		== s.day_type &&
		network_group	== s.network_group &&
		cell_group		== s.cell_group &&
		duration		== s.duration )
		return true;

	return false;
}


bool rates::insert(rate_key  &rk, rate_detail &rd )
{
	bool no_errors = true;

	rate_data.insert( make_pair(rk, rd) );	// multiple vals possible
	rate_ids[rd.rate_id]=rd;				// get one value out of many

	return no_errors;
}


void rates::print()
{
	for(RATE_DEF::iterator i=rate_data.begin(); i!=rate_data.end(); i++)
		RATE_S<<"{"<<(*i).first<<"},"<<endl<<" {"<<(*i).second<<"}"<<endl;
}


bool rates::match(string rate_group, string a_locale_id, rated_cdr &cdr, rating_observer &observer)
{
	int  same_score_rule_count=0, rules_evaluated=0; 
	RATE_DEF::iterator best_rule = rate_data.end();

	rule_score best_score, current_score, null_score;	// constructors zeros
	null_score.init();

	rate_key rk;
	string secondry_match_trail;			// not used  remove from score when possible
	
	rk.rate_group_id	= rate_group;		// can be sent with other rate groups
	rk.call_type_id		= decode_type_of_call(cdr.type_of_call); 
	rk.locale_id		= a_locale_id; 
	rk.service_type_id	= cdr.service_type_id; 

	//  not in customer data base and local imsi, make into class method ajit TODO
	if(cdr.imsi_found == false && "41302" == cdr.mobile_subscriber_identity.substr(0,5))
	{
		observer.rate_result = R_CLIENT_NOT_FOUND;
		return false;
	}
	else if(rate_group == "")
	{
		observer.rate_result = R_NO_RATE_PLAN;
		return false;
	}
	
	for (RATE_DEF::iterator i=rate_data.equal_range(rk).first; i!=rate_data.equal_range(rk).second; i++)
	{
		if (score_rule(cdr, i, current_score)==false)
		{
			rules_evaluated++;
			continue;
		}
		
		if (best_score < current_score) // only < operator is defined
		{
			best_score				= current_score;
			same_score_rule_count	= 1;
			best_rule				= i; // keep best match rule
		}
		// cant have more than 1 matching rule with the same score
		// This is a fatal error only if the heihgest score has two more rules
		else if (current_score == best_score)
		{
			same_score_rule_count	+= 1;
		}
	}
	
	// no rules found NRF
	if (best_score == null_score)
	{
		observer.rate_result = R_NO_MATCHING_RULE;
		return false;
	}
	// multiple final rules MFR of highest score
	else if (same_score_rule_count > 1)
	{
		observer.rate_result = R_DUPLICATE_RULES;
		return false;
	}
	// single rule is found
	else
	{
		rate_detail *rule; 
		rule = &(*best_rule).second; //  debugger friendly

		observer.rate_result = R_RATED;
		
		// rate rule detail
		observer.rate_rule_id		= rule->rate_id;
		observer.time_band_type		= rule->time_band_type;
		
		// time approximation
		div_t time_approximation;
		
		time_approximation = div(cdr.call_duration, rule->billable_duration);
		
		if(time_approximation.rem > 0  && rule->billable_duration > 1) // not per second billing
		{
			// very short calls can be ignored (must be less than unit size other wise fraction bombs)
			int threshold;
			threshold = gsm_rate_groups->get_time_threshold(rk.rate_group_id);
			if(cdr.call_duration < threshold)
			{
				time_approximation.rem = 0;
				observer.block_approximated_call_duration = 0;
			}
			else
			{
				// approximate
				observer.block_approximated_call_duration = time_approximation.quot * rule->billable_duration
					+ rule->billable_duration;
			}
		}
		else // per second billing
		{
			observer.block_approximated_call_duration = cdr.call_duration;
		}
		
		observer.unit_cost		= rule->unit_cost;
		observer.unit_duration	= rule->unit_duration;
		observer.units			= ((float)observer.block_approximated_call_duration)/observer.unit_duration;
		observer.charged_units	= observer.units;
		observer.charge			= observer.units * observer.unit_cost;
		
		// set time discounts
		if(rule->discount_group_id != "UNDEF") // discount has been defined saves function call
			gsm_time_discount_bands->set_discount(rule->discount_group_id, cdr, observer);
	}	
	return true;
}



bool rates::score_rule(rated_cdr &cdr, RATE_DEF::iterator rule_iter, rule_score &score)
{
	int i=0;
	score.init();
	rate_detail *rule;

	rule = &(*rule_iter).second;
	
	// is the call timestamp within rule start and end dates
	if(!rule->active_period.is_in_band(cdr.d_circuit_allocation_time))
		return false;
	
	// score network group
	if(gsm_network_groups->is_network_in_group(cdr.call_partner_network_id,  rule->net_group_id))
		score.network_group = 11;		// exact match
	else if(rule->net_group_id == WILD_CARD) 
		score.network_group = 5;		// match any network group
	else
		return false;					// no match on network group

	// score cell 
	if( (cdr.type_of_call == ORIGINATING_CALL_RADIO || cdr.type_of_call == TERMINATING_CALL_RADIO) &&
		cdr.origin_of_call_indicator == NATIONAL_CALL)
	{
		if(gsm_cell_groups->is_in_cell(rule->route_group_id, cdr.ci) )
			score.cell_group = 11;		// exact match
		else if(rule->route_group_id == WILD_CARD) 
			score.cell_group = 5;		// rule for any cell group
		else
			return false;				// no matching cell
	}
	
	// score day type
	if(gsm_holiday_priorities->get_priority(cdr.d_circuit_allocation_date, rule->day_id, i))
		score.day_type = i+1;			// to catch 0 prirority days
	else if(rule->day_id == WILD_CARD)
		score.day_type = 0;
	else
		return false;					// no match

	// score call duration
	if(rule->call_duration >= cdr.call_duration)
		score.duration = rule->call_duration - cdr.call_duration;
	else
		return false;
	
	return true;
}


ostream& operator<<(ostream& out, rate_detail x)
{
	out<<" time_band_group	= "<<x.time_band_group<<endl<<
		" day_id			= "<<x.day_id<<endl<<
		" route_grp_id		= "<<x.route_group_id<<endl<<
		" net_group_id		= "<<x.net_group_id<<endl<<
		" time_band_type	= "<<x.time_band_type<<endl<<
		" time_block_id		= "<<x.time_block_id<<endl<<
		" discount_group_id = "<<x.discount_group_id<<endl<<
		" unit_duration		= "<<x.unit_duration<<endl<<
		" unit_cost			= "<<x.unit_cost<<endl<<
		" billable_duration = "<<x.billable_duration<<endl<<
		" start_date		= "<<x.start_date<<endl<<
		" end_date			= "<<x.end_date<<endl<<
		" active			= "<<x.active_period<<endl<<
		" call duration		= "<<x.call_duration;
	return out;
}


ostream& operator<<(ostream& out, rate_key x)
{
	out<<" rate_group_id="<<x.rate_group_id<<" call_type_id="<<x.call_type_id<<" locale_id="<<x.locale_id
		<<" service_type_id="<<x.service_type_id;
	return out;
}




