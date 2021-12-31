

//////////////////////////////////////////////////////////////////////
//
// rate_groups.cpp: 
//			implementation of the rate_groups class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "r4_cdr.h"
#include "db_data_containers.h"
#include "defines.h"

ostream& operator<<(ostream& out, rate_group_data x)
{
	out<<x.re_rate_group_id<<", "<<x.time_threshold;
	return out;
}


void rate_groups::print()
{
	for(RATE_GRP_DEF::iterator i=r_group.begin(); i != r_group.end(); i++)
	{
		cout<<(*i).first<<" -> "<<(*i).second<<endl;
	}
}


void rate_groups::insert(string rate_grp, rate_group_data rgd)
{
	pair<RATE_GRP_DEF::iterator, bool> p=r_group.insert(make_pair(rate_grp, rgd));
	if (p.second==false)
	{
		cout<<"<ERROR>: Duplicate rate group "<<rate_grp<<endl;
	}
}


string  rate_groups::get_re_rate_group(string rate_grp)
{
	RATE_GRP_DEF::iterator i;
	i=r_group.find(rate_grp);
	
	if(i != r_group.end())
		return (*i).second.re_rate_group_id;

	return "*";
}


int  rate_groups::get_time_threshold(string rate_grp)
{
	RATE_GRP_DEF::iterator i;
	i=r_group.find(rate_grp);
	
	if (i != r_group.end())
		return (*i).second.time_threshold;

	return 0;
}


