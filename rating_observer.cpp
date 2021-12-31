

//////////////////////////////////////////////////////////////////////
//
// rating_observer.cpp: 
//			implementation of the rating_observer class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"

#include <math.h>
#include <stdlib.h>


void rating_observer::init(float chg, string d_type)
{
	charge = chg;
	charge_discount_expression = 0;

	discounted_charge = 0;

	score = 0;				// score 
	block_approximated_call_duration = 0;

	units = 0;
	charged_units = 0;
	unit_cost = 0;			// the cost of a unit
	unit_duration = 0;		// the length of a unit in secs
	
	rate_rule_id = "";

	rated = false;			//sucessfuly rated
	comments = "";			// whole rule
	score_comment = "";		// secondry scores
	result_id = "U";
	rate_result =R_UNDEF;	// 999 intial value 0 is true

	time_band_type = WILD_CARD;
	discount_type = d_type;
}

ostream& operator<<(ostream& out, rating_observer x)
{
	out<<" charge "<<x.charge<<endl;
	out<<" units  "<<x.units<<endl;
	out<<" comments "<<x.comments<<endl;
	out<<" result id "<<x.result_id<<endl;
	out<<" discount type "<<x.discount_type<<endl;
	return out;
}


