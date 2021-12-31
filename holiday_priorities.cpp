

//////////////////////////////////////////////////////////////////////
//
// holiday_priorities.cpp: 
//			implementation of the holiday_priorities class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"


bool holiday_priority_key::operator < (const holiday_priority_key &s) const 
{
	if((day_id < s.day_id))
		return true;
	else if	((day_id == s.day_id) && (date < s.date) )
		return true;
	return false;
}


ostream& operator<<(ostream& out, holiday_priority_key x)
{
    out<<x.date<<", "<<x.day_id;
    return(out);
}


bool holiday_priorities::insert(holiday_priority_key &k, int priority)
{
	pair<H_PRIORITY_DEF::iterator, bool> p=h_priority.insert(make_pair(k, priority));
	bool valid=true;
	if (p.second==false)
	{
		RATE_S<<"ERR: Duplicate holiday priority "<<k<<endl;
		valid=false;
	}
	return valid;
}



bool holiday_priorities::get_priority(reng_date dte, string day_id, int &p)
{
	H_PRIORITY_DEF::iterator i;

	holiday_priority_key k;
	
	k.date=dte;
	k.day_id=day_id;

	i=h_priority.find(k);
	
	bool found;
	found = (i != h_priority.end());

	if(found)
	{
		p=(*i).second;
	}
	else
	{
		p = 0;		// week day priority
	}

	return found;
}


void holiday_priorities::print()
{
	cout<<" holiday priorities size "<<h_priority.size()<<endl;
	for(H_PRIORITY_DEF::iterator i=h_priority.begin(); i != h_priority.end(); i++)
	{
		RATE_S<<"{"<<(*i).first<<"}, {"<<(*i).second<<"}"<<endl;
	}
}

