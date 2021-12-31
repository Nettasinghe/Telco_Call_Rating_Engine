
//////////////////////////////////////////////////////////////////////
//
// cdr_file_locations.cpp:
//				implementation of the file_locations class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "r4_cdr.h"
#include "defines.h"



void file_locations::init(string i)
{
	path=i;
	path_and_name ="";
	return;
}


char* file_locations::get_full_file_name(string file_name)
{
	path_and_name = path+file_name;
	return ((char*)path_and_name.c_str());
}






