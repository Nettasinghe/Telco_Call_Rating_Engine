

//////////////////////////////////////////////////////////////////////
//
// imsi_filter.cpp :
//				implementation of the imsi_filter class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "r4_cdr.h"
#include "defines.h"

bool imsi_filter::is_valid_imsi(string a)
{
	bool valid = false;
	//cout<<" imsi {"<<a<<"}"<<endl;

	if(valid_imsi_list.find(a) != valid_imsi_list.end())
	{
		valid= true;
//		cout<<"found imsi {"<<a<<"}"<<endl;
	}

	return valid;
}

	
bool imsi_filter::read_imsi_file(string name)
{
	ifstream IMSI(name.c_str());
	int imsi_count=0;
	
	if (!IMSI)
	{
		cerr<<"Unable to open IMSI File list {"<<name<<"}"<<endl;
		exit(1);
	}
	

	string required_imsi;
	while (IMSI >> required_imsi)
	{
		imsi_count++;
		valid_imsi_list.insert(required_imsi);
	}
	
	IMSI.close();

	cout<< "Read in "<<imsi_count<<" IMSI's for filtering"<<endl;

	return true;
}


void imsi_filter::print()
{
	for(set<string>::iterator i=valid_imsi_list.begin(); i!=valid_imsi_list.end(); i++)
	{
		cout<< *i<<" "<<endl;
	}
	cout<<endl;
}
