

//////////////////////////////////////////////////////////////////////
//
// fixed_rate_numbers.cpp: 
//			implementation of the fixed_rate_numbers class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
// numbers which when they appear as call partner allways result in a 
// fixed number dependent unit rate, even zero for as in the 
// case of hot lines
// 
// some call partner number's do not have a network id, hence 
// comparison with call partner id in a un packed state.
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"


bool fixed_rate_number_key::operator < (const fixed_rate_number_key &s) const 
{
	if(call_partner < s.call_partner)
		return true;
	else if	((call_partner == s.call_partner) && (type_of_call < s.type_of_call))
		return true;
	return false;
}


ostream& operator<<(ostream& out, fixed_rate_number_key x)
{
    out<<x.call_partner<<", "<<x.type_of_call;
    return(out);
}



void fixed_rate_numbers::print()
{
	for(FIXED_RATE_DEF::iterator i=fixed_numbers.begin(); i != fixed_numbers.end(); i++)
		cout<<"{"<<(*i).first<<"}, {"<<(*i).second<<"}"<<endl;
}


void fixed_rate_numbers::insert(fixed_rate_number_key key, float rate)
{
	pair<FIXED_RATE_DEF::iterator, bool> p=fixed_numbers.insert(make_pair(key, rate));
	if (p.second == false)
	{
		cout<<"ERR: Duplicate fixed rate number key "<<key<<endl;
	}
}



// resets rate, discounts & charge for number
bool fixed_rate_numbers::fixed_rate_number_charge(rated_cdr *cdr)
{
	fixed_rate_number_key k;

	k.call_partner=cdr->call_partner_identity;
	k.type_of_call=cdr->type_of_call;

	FIXED_RATE_DEF::iterator i;
	i = fixed_numbers.find(k);

	if (i == fixed_numbers.end()) 
		return false;				// no fixed rate charges, nothing more to do

	cdr->billing.discount_type	= "F";	// fixed rate number
	cdr->billing.unit_cost		= (*i).second;
	cdr->billing.charge			= (*i).second*cdr->billing.units;
	cdr->billing.rate_result    = R_RATED;
	return true;
}

