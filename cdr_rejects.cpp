

//////////////////////////////////////////////////////////////////////
//
// cdr_rejects.cpp :
//				implementation of the cdr_rejects class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "r4_cdr.h"
#include "defines.h"


bool cdr_rejects::is_reject(int file_id, int file_pos)
{
	cdr_id a;
	a.file_id=file_id;
	a.file_position=file_pos;

	return (reject_cdr_list.find(a) != reject_cdr_list.end());
}

	
bool cdr_rejects::read_reject_date_range_file(string name)
{
	ifstream reject_date_range(name.c_str());
	
	if (!reject_date_range)
	{
		cerr<<"Unable to open reject_date_range File list {"<<name<<"}"<<endl;
		exit(1);
	}

	reject_date_range >> start_date;
	reject_date_range >> end_date;

	reject_date_range.close();

	sanitize_date(start_date);
	sanitize_date(end_date);

	cout<< "reject cdr range "<<start_date<<" to "<<end_date<<endl;

	return true;
}


void cdr_rejects::print()
{
	for(set<cdr_id>::iterator i=reject_cdr_list.begin(); i!=reject_cdr_list.end(); i++)
		cout<< (*i).file_id<<" "<<(*i).file_position<<endl;

	cout<<endl;
}


bool cdr_rejects::cdr_id::operator < (const cdr_id &s) const
{
	if     (file_id < s.file_id)
		return true;
	else if(file_id == s.file_id &&
			file_position < s.file_position)
		return true;

	return false;
}


void cdr_rejects::insert(int file_id, int file_pos)
{
	cdr_id a;
	a.file_id=file_id;
	a.file_position=file_pos;

	reject_cdr_list.insert(a);
}


bool cdr_rejects::sanitize_date(string dte)
{
	// YYYYMMDDHHMISS
	if (dte.size() < 14)
	{
		cout << "ERROR date too short must be 'YYYYMMDDHHMISS' "<<endl;
		return false;
	}
	return true;
}


