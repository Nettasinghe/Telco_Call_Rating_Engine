

//////////////////////////////////////////////////////////////////////
//
// network_groups.cpp: 
//			implementation of the network_groups class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"

bool network_group_key::operator < (const network_group_key &s) const
{
	if(network_id < s.network_id)
		return true;
	else if	((network_id == s.network_id) && (network_group < s.network_group))
		return true;

	return false;
}



bool network_groups::insert(string network_id, string network_group)
{
	bool found=true;
	network_group_key net;

	net.network_id=network_id;
	net.network_group=network_group;

		pair<N_MEMEBER_DEF::iterator, bool> p = n_members.insert(net);
		if (p.second == false)
		{
			RATE_S<<"ERR: Duplicate network, group pair "<<network_id<<","<<network_group<<endl;
			found = false;
		}
	return found;
}


ostream& operator<<(ostream& out, network_group_key x)
{
	out<<x.network_group<<" "<<x.network_id;
	return out;
}


void network_groups::print()
{
	for(N_MEMEBER_DEF::iterator i=n_members.begin(); i!=n_members.end(); i++)
	{
		RATE_S<<"{"<<(*i)<<"} "<<endl;
	}
}


bool network_groups::is_network_in_group(string &network_id, string &network_group)
{
	network_group_key possible_group;

	possible_group.network_group=network_group;
	possible_group.network_id=network_id;

	return (n_members.end() !=n_members.find(possible_group));
}

