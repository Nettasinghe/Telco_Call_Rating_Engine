

//////////////////////////////////////////////////////////////////////
// time_discount_bands.cpp: 
//			implementation of the time_discount_bands class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"


bool time_discount_band_key::operator < (const time_discount_band_key &s) const
{
	if(group_id < s.group_id)
		return true;
	return false;
}

ostream& operator<<(ostream& out, time_discount_band_key x)
{
	out<<x.group_id;
	return out;
}


ostream& operator<<(ostream& out, time_discount_band_data x)
{
    out<<x.start_second<<", "<<x.end_second<<", "<<x.dis_operator<<", "<<x.dis_operand;
    return(out);
}


void time_discount_bands::print()
{
	for(TIME_DISCOUNT_DEF::iterator i=t_d_band.begin(); i != t_d_band.end(); i++)
	{
		RATE_S<<"{"<<(*i).first<<"}, {"<<(*i).second<<"}"<<endl;
	}
}


bool time_discount_bands::insert(string k, time_discount_band_data &d)
{
	bool no_errors=true;
	time_discount_band_key dis;
	dis.group_id=k;
	t_d_band.insert(make_pair(dis,d));
	return no_errors;
}


bool time_discount_bands::set_discount(string discount_group_id, rated_cdr &cdr, rating_observer &r_o)
{
	TIME_DISCOUNT_DEF::iterator i;
	int discount_time, block_start, block_end;
	bool valid = true;

	float call_cost = 0, deducted_cost = 0, discounted_cost  =0;
	call_cost = r_o.charge;

	time_discount_band_key dis;
	dis.group_id=discount_group_id;
	for (i=t_d_band.equal_range(dis).first; i!=t_d_band.equal_range(dis).second; i++)
	{
		block_start = (*i).second.start_second;	// debugger friendly
		block_end   = (*i).second.end_second;

		if(r_o.block_approximated_call_duration > block_start) // must be in block so no >=
		{
			if(r_o.block_approximated_call_duration >= block_end)
			{
				discount_time = block_end - block_start;
			}
			else
			{
				discount_time = r_o.block_approximated_call_duration - block_start;
			}
			deducted_cost = ((float)discount_time * r_o.unit_cost)/ r_o.unit_duration;

			float new_unit_cost;
			e_operator oper;
			oper=(*i).second.dis_operator;  // type checking and debugger friendly;

			if((*i).second.compute(r_o.unit_cost, new_unit_cost))
			{
				if(oper == O_ASSIGN)
				{
					discounted_cost = (*i).second.dis_operand;
				}
				else
				{
					discounted_cost = ((float)new_unit_cost*discount_time) / r_o.unit_duration;
				}
				call_cost = call_cost - deducted_cost + discounted_cost;
			}
		}
	}
	if (call_cost < 0)
	{
		cout<<"ERR: negative time discount "<<call_cost<<endl;
		call_cost=0;
	//	valid=false;
	}
//  +2 may be used access fee hence this is obsolete
//	else if (call_cost > r_o.charge)
//		cout<<" ERR: time discount increases cost"<<endl;
	r_o.charged_units = (r_o.units * call_cost)/r_o.charge;
	r_o.charge = call_cost;
	return valid;
}





