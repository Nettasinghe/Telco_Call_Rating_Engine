

//////////////////////////////////////////////////////////////////////
//
// r4_cdr_decode.cpp: 
//			implementation of the r4_cdr_decode class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "r4_cdr.h"


using namespace std;

//extern unsigned char cdr_start_buf[7];
//extern unsigned char cdr_buf[300];

void r4_cdr_decode::init()
{
	// init all buffers
	circuit_allocation_time_stamp[0] ='\0';
	call_time_stamp[0] ='\0';
	valid = true;
	
	// Variable length Arrays
	mobile_station_identity[0] = '\0';
	invoked_supplementary_services[0] = '\0';
	link_information[0] = '\0';
	mobile_subscriber_identity[0] = '\0';
	msc.init();
	call_partner.init();
	ms_location.init();
	MCC[0]='\0';
	MNC[0]='\0';
	LAC=0;
	CI=0;


	required_bearer_capability[0] = '\0';
	fixed_network_information[0] = '\0';
}


bool r4_cdr_decode::init_var_length_field(unsigned char *s)
{
	position_to_decode_from = s;
	record_length = *position_to_decode_from;
	checked_record_length = record_length;
	return true;
}

// Added by Chandika - a hack
bool r4_cdr_decode::init_var_length_field_for_invoked_sup_services(unsigned char *s)
{
	position_to_decode_from = s+1;
	//record_length = *position_to_decode_from;		// CJN
	record_length = int(*s)*256+int(*(s+1));
//	cout << "Inv sup ser record length : " << record_length << endl;
	checked_record_length = record_length;
	return true;
}
// End Chandika

int  r4_cdr_decode::get_read_field_length()
{
	return checked_record_length;
}

int  r4_cdr_decode::get_move_field_length()
{
	return record_length;
}


int  r4_cdr_decode::adjust_read_field_length(int a)
{
	checked_record_length=a;
	valid=false;
	return checked_record_length;
}


bool r4_cdr_decode::is_over_run(int a)
{
	bool over_run = false;

	if (record_length > a)
	{
		over_run = true;
		//statistics->error_count++;
	}
	return (over_run);
}



// all the stuff is in the fixed length portion of the cdr
bool r4_cdr_decode::get_ints() 
{
	hot_billing_indication		= ( *(cdr_start+cdr_start_of_type_of_msc))>>7;
	type_of_msc					= ( U.get_most_significant_nibble( *(cdr_start+cdr_start_of_type_of_msc)) ) & 0x07;              
	type_of_call				= U.get_least_significant_nibble( *(cdr_start+cdr_start_of_type_of_msc));
	call_termination_type		= U.get_least_significant_nibble(*(cdr_start+cdr_start_of_call_termination_type));
	origin_of_call_indicator	= U.get_most_significant_nibble(*(cdr_start+cdr_start_of_origin_of_call_indicator));  
	charging_indicator			= U.get_least_significant_nibble(*(cdr_start+cdr_start_of_origin_of_call_indicator));
	required_tele_service		= U.get_BIN( *(cdr_start+cdr_start_of_required_tele_service));
	required_bearer_service		= U.get_BIN( *(cdr_start+cdr_start_of_required_bearer_service));
	call_duration				= get_three_byte_binary(cdr_start+cdr_start_of_call_duration);
	unefficiency_cause			= U.get_BIN( *(cdr_start+cdr_start_of_unefficiency_cause));
	efficiency_indicator		= U.get_most_significant_nibble(*(cdr_start+cdr_start_of_call_termination_type));

	return true;
}


void r4_cdr_decode::set_statistics_collector(cdr_file_statistics *s)
{
	statistics = s;
}



bool r4_cdr_decode::show_ints() 
{
	cout << "hot_billing_indication : "<< hot_billing_indication << endl;
	cout << "type_of_msc : "<< type_of_msc << endl;              
	cout << "type_of_call: "<< type_of_call<< endl;
	cout << "efficiency_indicator: "<< efficiency_indicator<< endl;
	cout << "call_termination_type : "<< call_termination_type << endl;
	cout << "unefficiency_cause : "<< unefficiency_cause << endl;
	cout << "origin_of_call_indicator : "<< origin_of_call_indicator << endl;  
	cout << "charging_indicator : " << charging_indicator << endl;
	cout << "required_tele_service : "<< required_tele_service << endl;
	cout << "required_bearer_service : "<< required_bearer_service << endl;
	cout << "call_duration : "<<	call_duration<< endl;

	return true;
}


int r4_cdr_decode::get_three_byte_binary(unsigned char * a) 
{
	return a[0]*256*256+a[1]*256+a[2];
}


bool r4_cdr_decode::get_circuit_allocation_time_stamp()
{
	U.get_BCD((cdr_start+cdr_start_of_circuit_allocation_time_stamp),
		circuit_allocation_time_stamp_LENGTH, circuit_allocation_time_stamp);

	// sieve for max and min cdr times in file (adds 5% extra to decode time)
	string min_max_time=circuit_allocation_time_stamp;

	// y2k
	if(min_max_time.substr(0,2) < "50")
		min_max_time = "20"+min_max_time;
	else
		min_max_time = "19"+min_max_time;

	if (min_max_time < statistics->first_cdr_date)
		statistics->first_cdr_date = min_max_time;
	
	if (min_max_time > statistics->last_cdr_date)
		statistics->last_cdr_date = min_max_time;


	return true;
}


bool r4_cdr_decode::get_call_time_stamp()
{
	U.get_BCD( (cdr_start+cdr_start_of_call_time_stamp), call_time_stamp_LENGTH, 
		call_time_stamp);

	return true;
}


int r4_cdr_decode::decode(unsigned char *buf) //imsi_filter *F
{
	int i=0; // poor choice of name ajit
	init();  // all the variables
	cdr_start	= buf;
	cdr_length	= *(buf+2)*256+(*buf)+2;
	
	// Fixed length
	get_circuit_allocation_time_stamp();
	get_call_time_stamp();
	get_ints();
	
	// variable length, must be called in order
	get_mobile_station_identity();
	get_invoked_supplementary_services();
	get_link_information();
	//get_link_information();                  // CJN
	get_mobile_subscriber_identity();
	get_msc_identity();
	get_call_partner_identity();
	get_ms_location_identity();
	get_ms_location_identity_extension();  // though the length of this is always 0 in R4
										   //  this should be called to complete the sequence
	get_required_bearer_capability();
	get_fixed_network_information();
	
	return 1;
}


ostream& operator<<(ostream& out, r4_cdr_decode x)
{
	// fixed length data
	out<<"hot billing ind   = {"<<x.hot_billing_indication<<"}"<<endl;
	out<<"type of msc       = {"<<x.type_of_msc<<"}"<<endl;
	out<<"type of call      = {"<<hex<<x.type_of_call<<"}"<<dec<<endl;
	out<<"termination type  = {"<<hex<<x.call_termination_type<<"}"<<dec<<endl;
	out<<"origin of call ind= {"<<x.origin_of_call_indicator<<"}"<<endl;
	out<<"charging indicator= {"<<x.charging_indicator<<"}"<<endl;
	out<<"tele service      = {"<<hex<<x.required_tele_service<<"}"<<dec<<endl;
	out<<"bearer service    = {"<<x.required_bearer_service<<"}"<<endl;
	out<<"cir time          = {"<<x.circuit_allocation_time_stamp<<"}"<<endl;
	out<<"call duration     = {"<<x.call_duration<<"}"<<endl;
	out<<"call time         = {"<<x.call_time_stamp<<"}"<<endl;
	
	// Variable length Arrays
	out<<"imei              = {"<<x.mobile_station_identity<<"}"<<endl;		
	out<<"supp surv         = {"<<x.invoked_supplementary_services<<"}"<<endl;
	out<<"link info         = {"<<x.link_information<<"}"<<endl;
	out<<"imsi              = {"<<x.mobile_subscriber_identity<<"}"<<endl;
	out<<"msc               = {"<<x.msc<<"}"<<endl;
	out<<"call partner      = {"<<x.call_partner<<"}"<<endl;
	out<<"ms location       = {"<<x.ms_location<<"}"<<endl;
	
	out<<"MCC               = {"<<x.MCC<<"}"<<endl;
	out<<"MNC               = {"<<x.MNC<<"}"<<endl;
	out<<"LAC               = {"<<x.LAC<<"}"<<endl;
	out<<"CI                = {"<<x.CI<<"}"<<endl;

	out<<"req bearer        = {"<<x.required_bearer_capability<<"}"<<endl;
	out<<"fixed network     = {"<<x.fixed_network_information<<"}"<<endl;

	out<<"efficiency_ind    = {"<<x.efficiency_indicator<<"}"<<endl;
	out<<"unefficiency cause= {"<<x.unefficiency_cause <<"}"<<endl;

	return out;
}


// ------------------------ variable length fields ----------------------------

bool r4_cdr_decode::get_mobile_station_identity()
{
	init_var_length_field(cdr_start+mobile_station_identity_POSITION);

	if(is_over_run(mobile_station_identity_LENGTH))
	{
		cout<<"WARN  mobile station identity  overflow (truncated)"<<endl;
		adjust_read_field_length(mobile_station_identity_LENGTH);
	}

	if(get_read_field_length())
	U.get_TBCD(position_to_decode_from+1, get_read_field_length(), mobile_station_identity);
	*(mobile_station_identity+15) = '\0';	// only 15 digits used 16 decoded

	move_to_next_record(get_move_field_length());

	return true;
}


bool r4_cdr_decode::get_invoked_supplementary_services()
{
	//init_var_length_field(position_to_decode_from);
	init_var_length_field_for_invoked_sup_services(position_to_decode_from); // Chandika

	if(is_over_run(invoked_supplementary_services_LENGTH))
	{
		cout<<"WARN  InvokedSupplementaryServices  overflow (truncated)"<<endl;
		adjust_read_field_length(invoked_supplementary_services_LENGTH);
		valid=false;
	}

	int major_field_length = int(*(position_to_decode_from-1))*256+int(*(position_to_decode_from));
	
	if (major_field_length > 0)
	{
		int no_of_sub_fields = 0;
		int processed_length = 0;
		//int major_field_length = int(*(position_to_decode_from-1))*256+int(*(position_to_decode_from));
//		cout << "major_field_length : " << major_field_length << endl;
		unsigned char* temp_position_to_decode_from;
		temp_position_to_decode_from = position_to_decode_from;
		int subfield_length = int(*(temp_position_to_decode_from+2));
		
/*
		while (processed_length < major_field_length)
		{

			cout << "subfield_length : " << subfield_length << endl;
			cout<<"Invoked Supplementary Service Type :   ";
		
			switch(*(temp_position_to_decode_from+1))
			{
				case 1:		cout<<"Invoked IN service"<<endl;			break;
				case 13:	cout<<"Operator intervention"<<endl;		break;
				case 14:	cout<<"forwarding information"<<endl;		break;
				case 2:		cout<<"Invoked CAMEL service"<<endl;		break;
				case 3:		cout<<"Invoked Call Hold service"<<endl;	break;
				case 4:		cout<<"Invoked Closed User Group"<<endl;	break;
				case 5:		cout<<"Invoked Advice of Charge"<<endl;		break;
				case 6:		cout<<"Explicit Call Transfer"<<endl;		break;
				case 7:		cout<<"Invoked MPTYM (Master)"<<endl;		break;
				case 8:		cout<<"Invoked MPTYS (Slave)"<<endl;		break;
				case 9:		cout<<"TDMF"<<endl;							break;
				case 10:	cout<<"PREFIX"<<endl;						break;
				case 12:	cout<<"dual services"<<endl;				break;
				case 16:	cout<<"PUUS service"<<endl;					break;
				case 17:	cout<<"CLIP service"<<endl;					break;
				case 21:	cout<<"CRN and MSC-Id"<<endl;				break;
				default:	cout<<"Invalid Service Type found"<<endl;
			}

			no_of_sub_fields++;
			processed_length = processed_length + subfield_length + 2;
			//cout << "processed_length : " << processed_length << endl;
			(temp_position_to_decode_from) = (temp_position_to_decode_from + 2 + subfield_length);
			subfield_length = int(*(temp_position_to_decode_from+2));
		}
*/
	}


	// forwarding reason req

	if(get_read_field_length())
	{
		// changed below  - Chandika
	   U.get_BCD(position_to_decode_from+1,get_read_field_length(), invoked_supplementary_services);
	   // forward_reason valid only for type_of_call==2 || type_of_call==6 see note R
	}

	move_to_next_record(get_move_field_length());

	return true;
}


bool r4_cdr_decode::get_link_information()
{
	init_var_length_field(position_to_decode_from);

	if(is_over_run(link_information_LENGTH))
	{
		cout<<"WARN  link_information  overflow (truncated)"<<endl;
		adjust_read_field_length(link_information_LENGTH);
		valid=false;
	}

	// Hack -----------------------------| here
	if(get_read_field_length())
	{
		U.get_TBCD(position_to_decode_from+1+1, get_read_field_length()-1, link_information);
	//	cout<<" ********** link {"<<link_information<<"}"<<endl;
	}

	move_to_next_record(get_move_field_length());

	return true;
}


bool r4_cdr_decode::get_mobile_subscriber_identity()
{
	init_var_length_field(position_to_decode_from);

	if(is_over_run(mobile_subscriber_identity_LENGTH))
	{
		cout<<"WARN  mobile_subscriber_identity  overflow (truncated)"<<endl;
		adjust_read_field_length(mobile_subscriber_identity_LENGTH);
		valid=false;
	}

	if(get_read_field_length())
		U.get_TBCD(position_to_decode_from+1, get_read_field_length(), mobile_subscriber_identity);

	move_to_next_record(get_move_field_length());

	return true;
}


bool r4_cdr_decode::get_msc_identity() // Mobile switching center
{
	init_var_length_field(position_to_decode_from);

	if(is_over_run(msc_identity_LENGTH))
	{
		cout<<"WARN  msc_identity  overflow (truncated)"<<endl;
		adjust_read_field_length(msc_identity_LENGTH);
		valid=false;
	}

	msc.ext=*(position_to_decode_from+1);
	// get the most significant nibble, mask out the extension indicator
	msc.ext = msc.ext & 0xf0;


	if(get_read_field_length())
		U.get_TBCD(position_to_decode_from+1+1, get_read_field_length()-1, msc.id);
		//U.get_TBCD(position_to_decode_from+1+1, get_read_field_length()-1, msc_identity);

	move_to_next_record(get_move_field_length());


	return true;
}



bool r4_cdr_decode::get_call_partner_identity()  
{
	init_var_length_field(position_to_decode_from);

	if(is_over_run(call_partner_identity_LENGTH))
	{
		cout<<"WARN  call_partner_identity  overflow (truncated)"<<endl;
		adjust_read_field_length(call_partner_identity_LENGTH);
		valid=false;
	}

		call_partner.ext = *(position_to_decode_from+1);
		// get the most significant nibble, mask out the extension indicator
		call_partner.ext = call_partner.ext & 0xf0;

	if(get_read_field_length())
	{
		//U.get_TBCD(position_to_decode_from+1+1, get_read_field_length()-1, call_partner.id);
		// For Optimal Routing Calls
		U.get_TBCD_call_partner(position_to_decode_from+1+1, get_read_field_length()-1, call_partner.id);
	}
	move_to_next_record(get_move_field_length());


	return true;
}



bool r4_cdr_decode::get_ms_location_identity()  
{
	init_var_length_field(position_to_decode_from);
	
	if(is_over_run(ms_location_identity_LENGTH))
	{
		cout<<"WARN  ms_location_identity  overflow (truncated)"<<endl;
		adjust_read_field_length(ms_location_identity_LENGTH);
		valid=false;
	}
	
	// originating = 0, terminating = 1
	if(type_of_call==0 || type_of_call==1)
	{
		U.get_TBCD(position_to_decode_from+1, 2, MCC);
		U.get_TBCD((position_to_decode_from+1)+2, 1, MNC);
		LAC=U.get_HEXA((position_to_decode_from+1)+3, 2);
		CI=U.get_HEXA((position_to_decode_from+1)+3+2, 2);
	}
	else // all other types of call
	{
		ms_location.ext = *(position_to_decode_from+1);
		// get the most significant nibble, mask out the extension indicator
		ms_location.ext = ms_location.ext & 0xf0;

		U.get_TBCD(position_to_decode_from+1+1, get_read_field_length()-1, ms_location.id);
	}
	
	move_to_next_record(get_move_field_length());
	
	return true;
}



bool r4_cdr_decode::get_ms_location_identity_extension() // Mobile switching center
{
	init_var_length_field(position_to_decode_from);

	if(is_over_run(ms_location_identity_extension_LENGTH))
	{
		cout<<"WARN  ms_location_identity_extension  overflow (truncated)"<<endl;
		adjust_read_field_length(ms_location_identity_extension_LENGTH);
		valid=false;
	}

	move_to_next_record(get_move_field_length());

	return true;
}



bool r4_cdr_decode::get_required_bearer_capability() 
{
	init_var_length_field(position_to_decode_from);

	if(is_over_run(required_bearer_capability_LENGTH))
	{
		cout<<"WARN  required_bearer_capability  overflow (truncated)"<<endl;
		adjust_read_field_length(required_bearer_capability_LENGTH);
		valid=false;
	}

	// +1 & -1 are to skip speech version
	if(get_read_field_length()>1)
		U.get_ASCII((position_to_decode_from+1)+1, get_read_field_length()-1, required_bearer_capability);

	move_to_next_record(get_move_field_length());

	return true;
}

// CJN
// the following method is to extract only the incoming trunk group for Optimal Routed (OR)
// Call Rating, though there all many other info, they are ignored
bool r4_cdr_decode::get_fixed_network_information()
{
	init_var_length_field(position_to_decode_from);

	if(is_over_run(fixed_network_information_LENGTH))
	{
		cout<<"WARN  fixed network information  overflow (truncated)"<<endl;
		adjust_read_field_length(fixed_network_information_LENGTH);
	}

	int major_field_length = int(*(position_to_decode_from));
	
	if (major_field_length > 0)
	{
		int no_of_sub_fields = 0;
		int processed_length = 0;
		
		//cout << "major_field_length : " << major_field_length << endl;
		unsigned char* temp_position_to_decode_from;
		temp_position_to_decode_from = position_to_decode_from;
		int subfield_length = int(*(temp_position_to_decode_from+2));
		

		while (processed_length < major_field_length)
		{
			//cout << "subfield_length : " << subfield_length << endl;
			//cout<<"Fixed Network Information Type :   ";
		
			switch(*(temp_position_to_decode_from+1))
			{
				case 96:	U.get_ASCII((temp_position_to_decode_from+1+1)+1, 5, fixed_network_information);
							break;
				case 97:	
					//cout<<"ITX / CPH type"<<endl;				
					break;
				case 250:	
					//cout<<"ITX / CPH type"<<endl;				
					break;
				case 98:	
					//cout<<"TAX / CHB type"<<endl;				
					break;
				case 251:	
					//cout<<"TAX / CHB type"<<endl;				
					break;
				case 99:	
					//cout<<"CHT Type"<<endl;						
					break;
				
				default:	cout<<"<ERROR> Invalid fixed network information Type found"<<endl;
		
			}
			no_of_sub_fields++;
			processed_length = processed_length + subfield_length + 2;
			//cout << "processed_length : " << processed_length << endl;
			(temp_position_to_decode_from) = (temp_position_to_decode_from + 2 + subfield_length);
			subfield_length = int(*(temp_position_to_decode_from+2));
		}
	}

	//if(get_read_field_length())
	//U.get_BCD(position_to_decode_from+1, get_read_field_length(), fixed_network_information);
	
	move_to_next_record(get_move_field_length());

	return true;
}
// CJN


bool r4_cdr_decode::move_to_next_record(int length)
{
	position_to_decode_from += (length+1);

	// check if length of CDR is exceded
	// asssumes linear address space 
	if(position_to_decode_from > (cdr_start+cdr_length))
	{
		cout<<"CDR Overun ERROR {"<<hex<<(int)position_to_decode_from<<"} {"<<(int)(cdr_start+cdr_length)<<"}"<<dec<<endl;
		//core_dump=true;
	}
	return true;
}
