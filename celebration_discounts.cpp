

//////////////////////////////////////////////////////////////////////
//
// celebration_discounts.cpp: 
//			implementation of the celebration_discounts class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"

bool celebration_discount_key::operator < (const celebration_discount_key &s) const 
{
	if(account_no < s.account_no)
		return true;
	else if	((account_no == s.account_no) && (cele_date.month < s.cele_date.month))
		return true;
	else if	((account_no == s.account_no) && (cele_date.month == s.cele_date.month) && (cele_date.day < s.cele_date.day) )
		return true;
	return false;
}


ostream& operator<<(ostream& out, celebration_discount_key x)
{
	out<<x.account_no<<", "<<x.cele_date;
	return(out);
}


ostream& operator<<(ostream& out, celebration_discount_data x)
{
	out<<x.discount_id<<", "<<x.start_date<<", "<<x.end_date<<", "<<x.dis_operator<<", "<<x.dis_operand<<", "<<x.rate_group_id;
	return(out);
}


void celebration_discounts::print()
{
	for(CELE_DIS_DEF::iterator i=c_discounts.begin(); i != c_discounts.end(); i++)
	{
		RATE_S<<"{"<<(*i).first<<"}, {"<<(*i).second<<"}"<<endl;
	}
}


bool celebration_discounts::insert(celebration_discount_key &k, celebration_discount_data &d)
{
	bool no_errors=true;
	
	// put in duplicate data value check and send back no errors on that
	
	pair<CELE_DIS_DEF::iterator, bool> p=c_discounts.insert(make_pair(k,d));
	if (p.second==false)
	{
		no_errors=false;
		RATE_S<<"ERR: Duplicate clebration discounts  {"<<k<<"}"<<endl;
	}
	return no_errors;
}


bool celebration_discounts::compute(rated_cdr &cdr,string locale_id, rating_observer &r_o, rates &r)
{
	// find if discount exsists

	CELE_DIS_DEF::iterator i;
	celebration_discount_key k;

	k.account_no=cdr.connection_d.account_no;
	k.cele_date=cdr.d_circuit_allocation_date;

	i=c_discounts.find(k);
	
	bool valid;
	if(i != c_discounts.end() )
	{
		// has vaildity period of discount expired
		// when defining bracket giving one days room (ajit)
		if (   (*i).second.start_date < cdr.d_circuit_allocation_date
			&& cdr.d_circuit_allocation_date < (*i).second.end_date )
		{
			valid = true;
		}
	}
	else
		valid = false;

	if(valid)
	{
		if((*i).second.rate_group_id != "")
		{
			r.match((*i).second.rate_group_id,locale_id, cdr, r_o);
		}
		else if ( (*i).second.dis_operator != O_UNDEF)
		{
			(*i).second.compute(r_o.charge, r_o.charge);
		}
	}

	return valid;
}


