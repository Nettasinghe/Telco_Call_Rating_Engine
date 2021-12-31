

//////////////////////////////////////////////////////////////////////
//
// value_added_services.cpp: 
//			implementation of the value_added_services class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////

#include "db_data_containers.h"
#include "defines.h"


bool value_added_services_key::operator < (const value_added_services_key &s) const 
{
	if(account_no < s.account_no)
		return true;
	else if	((account_no == s.account_no) && (service_code < s.service_code))
		return true;
	return false;
}


ostream& operator<<(ostream& out, value_added_services_key x)
{
    out<<x.account_no<<", "<<x.service_code;
    return(out);
}


ostream& operator<<(ostream& out, value_added_services_data x)
{
    out<<x.rate_group_id<<", "<<x.start_date<<", "<<x.end_date;
    return(out);
}


bool value_added_services::insert(value_added_services_key &k, value_added_services_data &d)
{
	bool no_errors=true;
	v_services.insert( make_pair(k, d) );

	return no_errors;
}

// a bad recursive relationship , re-structure
// a iterative solution
// Put in date range check :TODO
bool value_added_services::get_air_group(int ac_no, string &air)
{
	value_added_services_key k;

	k.account_no = ac_no;

	k.service_code = "AIRR";
	if(v_services.find(k) != v_services.end())
	{
		air=k.service_code;
		return true;
	}
	
	k.service_code = "AIRA";
	if(v_services.find(k) != v_services.end())
	{
		air=k.service_code;
		return true;
	}

	air =""; // force failure on rateing
	return false;
}

// SMS or SMSMO allows useage
bool value_added_services::get_sms_group_mo(int ac_no, string &sms)
{
	value_added_services_key k;

	k.account_no = ac_no;

	k.service_code = "SMS";
	if(v_services.find(k) != v_services.end())
	{
		sms=k.service_code;
		return true;
	}
	
	k.service_code ="SMSMO";
	if(v_services.find(k) != v_services.end())
	{
		sms=k.service_code;
		return true;
	}
	
	sms ="";		// force failure on rateing
	return false;
}

// SMS or SMSMT allows useage
bool value_added_services::get_sms_group_mt(int ac_no, string &sms)
{
	value_added_services_key k;

	k.account_no = ac_no;

	k.service_code = "SMS";
	if(v_services.find(k) != v_services.end())
	{
		sms=k.service_code;
		return true;
	}
	
	k.service_code ="SMSMT";
	if(v_services.find(k) != v_services.end())
	{
		sms=k.service_code;
		return true;
	}
	
	sms ="";		// force failure on rateing
	return false;
}

	
// not found cases for roaming have previously attached rate_group ids so
// dont initalise rate group id's
bool value_added_services::set_value_added_rate_group(rated_cdr &cdr)
{
	VAL_ADD_SERVICES_DEF::iterator i;
	
	value_added_services_key k;
	k.account_no = cdr.connection_d.account_no;
	k.service_code = cdr.decoded_service;

	bool found=false;
	for (i=v_services.equal_range(k).first; i!=v_services.equal_range(k).second; i++)
	{
		// check service has valid dates
		// must be  >=start and < end (see STL on how < becomes  >=)
		// possible case fro removeing date check ??? :ASK MILI
		if ((!(cdr.d_circuit_allocation_date < (*i).second.start_date))  && 
			  cdr.d_circuit_allocation_date < (*i).second.end_date )
		{
			found=true;
			cdr.rate_group_id =(*i).second.rate_group_id;
			break;
		}
		else
		{
			found=false;
#ifdef DEBUG
			cout<<" DEBUG: value_added service invalid time"<<endl;
#endif
		}
	}
	
	return found;
}


void value_added_services::print()
{
	for(VAL_ADD_SERVICES_DEF::iterator i=v_services.begin(); i != v_services.end(); i++)
	{
		RATE_S<<"{"<<(*i).first<<"}, {"<<(*i).second<<"}"<<endl;
	}
}

