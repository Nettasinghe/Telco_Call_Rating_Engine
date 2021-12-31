

//////////////////////////////////////////////////////////////////////
//
// cell_groups.cpp: 
//			implementation of the cell_groups class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"


cell_group_key::cell_group_key()
{
	cell_group	=	"*";
	cell_id		=	-1;
}


bool cell_group_key::operator < (const cell_group_key &s) const 
{
	if(cell_group < s.cell_group)
		return true;
	else if	((cell_group == s.cell_group) && (cell_id < s.cell_id))
		return true;
	return false;
}


ostream& operator<<(ostream& out, cell_group_key x)
{
    out<<x.cell_group<<", "<<x.cell_id;
    return(out);
}


void cell_groups::print()
{
	for(CELL_GRP_DEF::iterator i=c_groups.begin(); i != c_groups.end(); i++)
	{
		cout<<"{"<<(*i)<<"}"<<endl;
	}
}

bool cell_groups::insert(string cell_group, int cell_id)
{
	bool no_errors=true;
	
	cell_group_key k;
	k.cell_group=cell_group;
	k.cell_id=cell_id;
	
	
	pair<CELL_GRP_DEF::iterator, bool> p=c_groups.insert(k);
	if (p.second == false)
	{
		no_errors=true;
		cout<<"<ERROR>: Duplicate cells in group {"<<k<<"}"<<endl;
	}
	
	return no_errors;
}

bool cell_groups::is_in_cell(string cell_group, int cell_id)
{
	cell_group_key k;
	k.cell_group=cell_group;
	k.cell_id=cell_id;

	return(c_groups.end() != c_groups.find(k));
}




