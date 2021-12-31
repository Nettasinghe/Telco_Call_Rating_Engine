

//////////////////////////////////////////////////////////////////////
//
// roaming_networks.cpp: 
//			implementation of the roaming_networks class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
// the networks and rate plans for roaming
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"

bool roam_network_key::operator < (const roam_network_key &s) const
{
	if(net_prefix < s.net_prefix)
		return true;
	return false;
}


void roaming_networks::print()
{
	for(ROAM_NET_DEF::iterator i= r_networks.begin(); i != r_networks.end(); i++)
		cout<<"{"<<(*i).first<<"}, {"<<(*i).second<<"}"<<endl;
}


ostream& operator<<(ostream& out, roam_network_key x)
{
	out<<x.net_prefix;
	return out;
}


void roaming_networks::insert(string mcc, string mnc, string rate_group_id)
{
	roam_network_key k;
	k.net_prefix = mcc+mnc;

	pair<ROAM_NET_DEF::iterator, bool> p= r_networks.insert(make_pair(k, rate_group_id));
	if (p.second == false)
	{
		cout<<"ERR: Duplicate roaming network number "<<mcc+mnc<<endl;
	}
}


string roaming_networks:: get_rate_group(string roam_number_prefix)
{
	ROAM_NET_DEF::iterator i;

	roam_network_key k;

	k.net_prefix = roam_number_prefix;
	i = r_networks.find(k);
		
	if(i != r_networks.end()) // network has been found
	{
		return((*i).second);
	}
	return "";				//  is not a fixed rate number
}
