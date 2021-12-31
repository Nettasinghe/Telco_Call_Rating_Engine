

//////////////////////////////////////////////////////////////////////
//
// identity.cpp :
//				implementation of the no_identity class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "r4_cdr.h"
#include "defines.h"


void no_identity::init()
{
	ext=0;
	id[0]='\0';
}


ostream& operator<<(ostream& out, no_identity x)
{
    out<<x.ext<<", "<<x.id;
    return(out);
}
