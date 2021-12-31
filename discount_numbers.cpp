

//////////////////////////////////////////////////////////////////////
//
// discount_numbers.cpp: 
//			implementation of the discount_numbers class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"



// with histric look up
//
bool discount_number_key::operator < (const discount_number_key &s) const 
{
	if(account_no < s.account_no)
		return true;
	else if	((account_no == s.account_no) && (phone_number < s.phone_number))
		return true;
	else if ((account_no == s.account_no) && (phone_number == s.phone_number) && (network_id < s.network_id))
		return true;
	return false;
}



ostream& operator<<(ostream& out, discount_number_key x)
{
    out<<x.account_no<<", "<<x.phone_number<<", "<<x.network_id;
    return(out);
}


void discount_numbers::print()
{
	for(DIS_NUM_DEF::iterator i=d_numbers.begin(); i != d_numbers.end(); i++)
	{
		RATE_S<<"{"<<(*i).first<<"}, {"<<(*i).second<<"}"<<endl;
	}
}


bool discount_numbers::insert(discount_number_key &k, discount_number_data &d)
{
	d_numbers.insert(make_pair(k,d));
	return true;
}




ostream& operator<<(ostream& out, discount_number_data x)
{
    out<<x.discount_type_id<<", "<<x.rate_group_id<<", "<<x.dis_operator<<", "<<x.dis_operand<<", "<<x.start_date<<", "<<x.end_date;
    return(out);
}


// find s=discount numvber rate group
// a) valid for the cdr time.
bool discount_numbers::compute(rated_cdr &cdr, string locale_id, rating_observer &r_o, rates &r)
{
	// find if discount exsists
	discount_number_key k;
	discount_number_data d;

	k.account_no	= cdr.connection_d.account_no;
	k.phone_number	= atoi(cdr.call_partner_telephone_no.c_str());
	k.network_id	= cdr.call_partner_network_id;

	DIS_NUM_DEF::iterator i;
	i=d_numbers.find(k);

	for (i = d_numbers.equal_range(k).first; i != d_numbers.equal_range(k).second; i++)
	{
		d = (*i).second;	// debugger friendly
		if (d.start_date <= cdr.circuit_allocation_time_stamp && d.end_date >= cdr.circuit_allocation_time_stamp)
		{ //  found
//			cout<<" Discount for A/C "<<	k.account_no <<	"CALL P# "<<  k.phone_number <<" NETWORK # "<<k.network_id<<endl;
			if((*i).second.rate_group_id != "")
			{
				r.match((*i).second.rate_group_id,locale_id, cdr, r_o);
//				cout<<" Computed match" <<endl;
			}
			else if ( (*i).second.dis_operator != O_UNDEF)
			{
				(*i).second.compute(r_o.charge, r_o.charge);
//				cout<<" Computed UNDEF match "<<endl;
			}
			return true;
		}
	}
	return false;
}


