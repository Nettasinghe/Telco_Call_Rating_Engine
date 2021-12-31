

//////////////////////////////////////////////////////////////////////
//
// historic_package.cpp: 
//			implementation of the historic package class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
// 
// gets the applicable package for the account at call time
//
//////////////////////////////////////////////////////////////////////

#include "db_data_containers.h"
#include "defines.h"


// get package of account_no in the past !!
bool  historic_package::get_package(int account_no, string call_time, string &package_code)
{
	HIST_PACKAGE_DEF::iterator i;
	historic_package_data h_p_d;
	historic_package_key h_p_k;
	h_p_k.account_no=account_no;
	
	for (i = h_package.equal_range(h_p_k).first; i != h_package.equal_range(h_p_k).second; i++)
	{
		h_p_d = (*i).second;	// debugger friendly
		if (h_p_d.start <= call_time && h_p_d.end >= call_time)
		{ //  found
			package_code = h_p_d.package_code;
			return true;
		}
	}
	package_code = "UNDEF";	// to avoid confusion
	return false;
}

void historic_package::insert(historic_package_key k, historic_package_data d)
{
	h_package.insert(make_pair(k,d));
}

ostream& operator<<(ostream& out, historic_package_data x)
{
    out<<x.package_code<<", "<<x.start<<", "<<x.end;
    return(out);
}

ostream& operator<<(ostream& out, historic_package_key x)
{
    out<<x.account_no;
    return(out);
}



void historic_package::print()
{
	for(HIST_PACKAGE_DEF::iterator i=h_package.begin(); i != h_package.end(); i++)
	{
		cout<<"{"<<(*i).first<<"}, {"<<(*i).second<<"}"<<endl;
	}
}


bool historic_package_key::operator < (const historic_package_key &s) const
{
	if(account_no < s.account_no)
		return true;
	return false;
}




