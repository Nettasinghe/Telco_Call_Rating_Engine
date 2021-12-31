

//////////////////////////////////////////////////////////////////////
//
// historic_imsi.cpp: 
//			implementation of the historic imsi class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
// gets the applicable account for the imsi at call time
//
//////////////////////////////////////////////////////////////////////

#include "db_data_containers.h"
#include "defines.h"


// if imsi was allocated to a account no at a past date date get it !!
bool historic_imsi::get_account_no(string imsi, string call_time, int &account_no)
{
	HIST_IMSI_DEF::iterator i;
	historic_imsi_data h_i_d;
	historic_imsi_key h_i_k;
	h_i_k.imsi_no=imsi;
	
	for (i = h_imsi.equal_range(h_i_k).first; i != h_imsi.equal_range(h_i_k).second; i++)
	{
		h_i_d = (*i).second;	// debugger friendly
		if (h_i_d.start <= call_time && h_i_d.end >= call_time)
		{ //  found
			account_no = h_i_d.account_no;
			return true;
		}
	}
	account_no = 0;	// to avoid confusion
	return false;
}

void historic_imsi::insert(string imsi, int ac, string start, string end)
{
	historic_imsi_data d;
	d.account_no=ac;
	d.start=start;
	d.end=end;

	historic_imsi_key k;
	k.imsi_no=imsi;

	h_imsi.insert(make_pair(k,d));
}


ostream& operator<<(ostream& out, historic_imsi_data x)
{
    out<<x.account_no<<", "<<x.start<<", "<<x.end;
    return(out);
}

ostream& operator<<(ostream& out, historic_imsi_key x)
{
    out<<x.imsi_no;
    return(out);
}



void historic_imsi::print()
{
	for(HIST_IMSI_DEF::iterator i=h_imsi.begin(); i != h_imsi.end(); i++)
	{
		cout<<"{"<<(*i).first<<"}, {"<<(*i).second<<"}"<<endl;
	}
}


bool historic_imsi_key::operator < (const historic_imsi_key &s) const
{
	if(imsi_no < s.imsi_no)
		return true;
	return false;
}




