

//////////////////////////////////////////////////////////////////////
//
// package_services.cpp: 
//			implementation of the package_services class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"


bool package_services_key::operator < (const package_services_key &s) const 
{
	if(package_code < s.package_code)
		return true;
	else if	((package_code == s.package_code) && (service_code < s.service_code))
		return true;
	return false;
}


ostream& operator<<(ostream& out, package_services_key x)
{
    out<<x.package_code<<", "<<x.service_code;
    return(out);
}


ostream& operator<<(ostream& out, package_services_data x)
{
    out<<x.rate_group_id<<", "<<x.rental;
    return(out);
}


bool package_services::insert(package_services_key &k, package_services_data &d)
{
	bool no_errors=true;
	p_services.insert( make_pair(k, d) );

	return no_errors;
}


// not found cases for roaming have previously attached rate_group ids so
// dont initalise rate group id's
bool package_services::set_package_rate_group(rated_cdr &cdr)
{
	PACKAGE_SERVICES_DEF::iterator i;
	
	package_services_key k;
	k.package_code = cdr.connection_d.package_code;
	k.service_code = cdr.decoded_service;

	bool found=false;
	i=p_services.find(k);

	found = (i != p_services.end());

	if (found)
	{
		cdr.rate_group_id =(*i).second.rate_group_id;
	}
	return found;
}


bool package_services::get_telephony_rate_group(string package_code, string &rate_group_id)
{
	PACKAGE_SERVICES_DEF::iterator i;
	
	package_services_key k;
	k.package_code = package_code;
	k.service_code = "TEL";

	bool found=false;
	i=p_services.find(k);

	found = (i != p_services.end());

	if (found)
	{
		rate_group_id =(*i).second.rate_group_id;
	}
	else
		rate_group_id="*"; // force a failure in rating

	return found;
}


void package_services::print()
{
	for(PACKAGE_SERVICES_DEF::iterator i=p_services.begin(); i != p_services.end(); i++)
	{
		RATE_S<<"{"<<(*i).first<<"}, {"<<(*i).second<<"}"<<endl;
	}
}
