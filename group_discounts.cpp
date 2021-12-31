

//////////////////////////////////////////////////////////////////////
//
// group_discounts.cpp: 
//			implementation of the group_discounts class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"


bool group_discount_key::operator < (const group_discount_key &s) const 
{
	if(orig_group < s.orig_group)
		return true;
	else if	((orig_group == s.orig_group) && (term_group < s.term_group))
		return true;
	return false;
}


ostream& operator<<(ostream& out, group_discount_key x)
{
    out<<x.orig_group<<", "<<x.term_group;
    return(out);
}


ostream& operator<<(ostream& out, group_discount_data x)
{
    out<<x.rate_group_id<<", "<<x.dis_operator<<", "<<x.dis_operand;
    return(out);
}


void group_discounts::print()
{
	for(GROUP_DIS_DEF::iterator i=g_discounts.begin(); i != g_discounts.end(); i++)
		RATE_S<<"{"<<(*i).first<<"}, {"<<(*i).second<<"}"<<endl;
}


bool group_discounts::insert(group_discount_key &k, group_discount_data &d)
{
	bool no_errors=true;
	
	// put in duplicate data value check and send back no errors on that
	
	pair<GROUP_DIS_DEF::iterator, bool> p=g_discounts.insert(make_pair(k,d));
	if (p.second==false)
	{
		no_errors=true;
		RATE_S<<"ERR: Duplicate group discounts  {"<<k<<"}"<<endl;
	}
	return no_errors;
}

// handles two cases in the in a priority basis
bool group_discounts::compute(rated_cdr &cdr, string locale_id, rating_observer &r_o, rates &r)
{
	bool valid	=	false;
	// caller and call partner are in the same group and the
	// call partners rate group is used for rating.
	// rate plan id has allrady been found
	if(cdr.group_discount_rate_plan_id != WILD_CARD)
	{
		valid = r.match(cdr.group_discount_rate_plan_id, locale_id, cdr, r_o);
		return valid;
	}

	// caller and call partner are in two different group
	// a inter group rateplan  discount is then used.

	GROUP_DIS_DEF::iterator i;
	group_discount_key k;

	k.orig_group = cdr.connection_d.group_code;
	k.term_group = cdr.call_partner_group;
	i = g_discounts.find(k);

	valid = (i != g_discounts.end());
	
	// swap originator & terminator and check
	if(!valid)
	{
		k.orig_group = cdr.call_partner_group;
		k.term_group = cdr.connection_d.group_code;
		i = g_discounts.find(k);
		valid = (i != g_discounts.end());
	}

	if(valid)
	{
		if((*i).second.rate_group_id != "")
		{
			r.match((*i).second.rate_group_id,locale_id, cdr, r_o);
		}
		else if ( (*i).second.dis_operator != O_UNDEF)
		{
			(*i).second.compute(r_o.charge, r_o.charge);
		}
	}
	return valid;
}


