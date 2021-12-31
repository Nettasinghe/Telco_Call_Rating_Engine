


//////////////////////////////////////////////////////////////////////
//
// call_partner_networks.cpp: 
//			implementation of the call_partner_networks class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////

#include "db_data_containers.h"
#include "defines.h"

bool call_partner_networks::insert(string network_id, int locale)
{
	/*
	bool found =true;

	pair<N_CALL_PART_DEF::iterator, bool> p = c_partner_networks.insert(network_id);
	if (p.second == false)
	{
		RATE_S<<"ERR: duplicate network number "<<network_id<<endl;
		found = false;
	}
	return found;
	*/

	//	pair<N_CALL_PART_DEF::iterator, bool> p=c_partner_networks.insert(c_partner_networks(c_k,a));
	pair<N_CALL_PART_DEF::iterator, bool> p=c_partner_networks.insert(make_pair(network_id, locale));
	if (p.second == false)
	{
		cout<<"ERR: duplicate network number "<<network_id<<endl;
		return false;
	}
	return true;
}


void call_partner_networks::print()
{
	for(N_CALL_PART_DEF::iterator i=c_partner_networks.begin(); i!=c_partner_networks.end(); i++)
	{
		cout<<"{"<<(*i).first<<"} {"<<(*i).second<<"}"<<endl;
	}
}

// the call partner string consists of network_no+tel_no
// both are variable length fields try reapeadted matching to locate a valid nework
// starting from the longest template till a string is found (see egrep code)
// 1) 4 char match
// 2) 3 char match
// 3) 2 char match
// 4) 1 char match
bool call_partner_networks::get_partner_network(string call_partner, string &network_no, string &tel_no)
{
	N_CALL_PART_DEF::iterator i;

	bool found=false;
	int network_no_length;
	
	string possible_network;

	for(int j=4; j>0; j--)
	{
		possible_network = call_partner.substr(0,j);
		i = c_partner_networks.find(possible_network);
		found = (i != c_partner_networks.end());
		if(found)
		{
			network_no = call_partner.substr(0,j);
			network_no_length = network_no.size();
			tel_no =call_partner.substr(network_no_length, call_partner.size()-network_no_length);
			return found;
		}
	} 
	return found;
}


bool call_partner_networks::is_national(string network_id)
{
	N_CALL_PART_DEF::iterator i;

	i = c_partner_networks.find(network_id);
	if(i != c_partner_networks.end())
	{
		if( (*i).second == 0)  // national call
			return true;
		else 
			return false;		// international call
	}
	cout<<"ERR network not found "<<network_id<<endl;
	return true;
}



