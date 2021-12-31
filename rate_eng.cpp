

///////////////////////////////////////////////////////////////////////////////////
//
// Telco Call Rating Engine – 
// The function of a Call Rating Engine is to rate or charge (give a monitory value)
// to a particular Call Detail Record (CDR) depending on various parameters such as 
// the rating plan of the customer and the time zone (peak / off peak) etc. 
// Telco Call Rating Engine is a rate rule based (by picking up the best matched 
// rate rule from a rule base using a weightage based algorithm).
//
////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////
//
//  Project		: Telco Call Rating Engine
//  File		: rate_eng.cpp 
//  Description : main() method contains here 
//  Code start	: Jan 1999 
//  Developer	: Chandika Nettasinghe 
//
///////////////////////////////////////////////////


#include "defines.h"
#include "r4_cdr.h"
#include "db.h"
#include "db_data_containers.h"

#ifdef SUN
	#include "PAdm.H"

	// Process admin
	PAdm ProcessAdm;
	// Global variables for RV connectivity
	rv_Error		err;
	rv_Session		rvsess;
	RvSession		*sess;
#endif

//unsigned char cdr_start_buf[7];
r4_cdr_buffer *cdr_store;
bool core_dump;
string original_call_partner_identity; // hack or gen calls
int original_call_partner_extension;


// -- db data containers begin
	connections				*gsm_connections;
	rates					*gsm_rates;
	package_services		*gsm_package_services;
	value_added_services	*gsm_value_added_services;
	rated_cdr				*gsm_rated_cdr;
	rated_cdr				*gsm_cdr_block;
	network_groups			*gsm_network_groups;
	holiday_priorities		*gsm_holiday_priorities;
	time_discount_bands		*gsm_time_discount_bands;
	discount_numbers		*gsm_discount_numbers;
	celebration_discounts	*gsm_celebration_discounts;
	group_discounts			*gsm_group_discounts;
	rate_groups				*gsm_rate_groups;
	cell_groups				*gsm_cell_groups;
	fixed_rate_numbers		*gsm_fixed_rate_numbers;
	roaming_networks		*gsm_roaming_networks;
	call_partner_networks	*gsm_call_partner_networks;
	historic_imsi			*gsm_historic_imsi;
	historic_package		*gsm_historic_package;
	cdr_rejects				*gsm_cdr_rejects;

// --db data containers end

	r4_cdr_decode raw_cdr;			// all the methods to extract data from a cdr

void main(int argc,char *argv[])
{
	char *ver = "4.0.5";

	cout<<"\nCall Rating Engine R4 "<<ver<<endl
	<<"Build Time "<<__DATE__<<" at "<<__TIME__<<endl
	<<"Dialog GSM"<<endl
	<<"Colombo, Sri Lanka"<<endl<<endl;

#ifdef RE_RATE
	cout<<"Config =  Re Rate  "<<endl;
#endif

#ifdef HISTORIC
	cout<<"Config =  Historic lookup for IMSI, PACKAGE"<<endl;
#endif

#ifdef TICKET_ACTIVE
	cout<<"Config =  TICKET ENABLED "<<endl;
#else
	cout<<"Config =  TICKET DISABLED "<<endl;
#endif

#ifdef TICKET_ACTIVE
	token run_ticket("./rate_eng.ticket");

	// tokens to prevent multiple instances running
	if(run_ticket.is_runable())
	{
		run_ticket.set_token(T_ON);
	}
	else
	{
		cout<<" No ticket to run"<<endl;
		exit(0);
	}
#endif


#ifdef SUN
	// Process manager definitions
	err = rv_Init(&rvsess, NULL, NULL, NULL);   
	
	if(err != RV_OK)
	{
		fprintf(stderr, "Failed to initialize session--%s\n",
			rv_ErrorText(NULL, err));
		exit(1);
	}
	
	sess = new RvSession(rvsess);
	if (sess->status() != RV_OK)
	{
		fprintf(stderr, "Failed to initialize RvSession--%s\n",
			sess->status().description());
		exit(1);
	}
	ProcessAdm.CreatePAdm(sess, argv[1], atoi(argv[2]), ver, argv[3]);
	ProcessAdm.Ready();
	cout << "process administration ready " << endl;
	ProcessAdm.SendText("Startup","rate engine starting");
#endif

	
	// db data containers memory allocation start
	cdr_store					= new r4_cdr_buffer(1024*1024*70); // allocate space in memory for binary read of whole cdr file
	gsm_connections				= new connections;
	gsm_rates					= new rates;
	gsm_package_services		= new package_services;
	gsm_value_added_services	= new value_added_services;
	gsm_rated_cdr				= new rated_cdr;
	gsm_cdr_block				= new rated_cdr[CDR_INSERT_BLOCK_SIZE];
	gsm_network_groups			= new network_groups;
	gsm_holiday_priorities		= new holiday_priorities;
	gsm_time_discount_bands		= new time_discount_bands;
	gsm_discount_numbers		= new discount_numbers;
	gsm_celebration_discounts	= new celebration_discounts;
	gsm_group_discounts			= new group_discounts;
	gsm_rate_groups				= new rate_groups;
	gsm_cell_groups				= new cell_groups;
	gsm_fixed_rate_numbers		= new fixed_rate_numbers;
	gsm_roaming_networks		= new roaming_networks;
	gsm_call_partner_networks	= new call_partner_networks;
	gsm_historic_imsi			= new historic_imsi;
	gsm_historic_package		= new historic_package;
	gsm_cdr_rejects				= new cdr_rejects;
	// db data containers memory allocation end
	
	// allocate space in memory for binary read of whole cdr file
	cdr_files cdr_f;

//-------------- database logins and print file location -----------------------
FILE *login;
char cust_care_login[128];
char rate_login[128];
char cdr_dump_location[128];

	// get config data
	if( (login  = fopen( "./rate_eng.config", "r" )) == NULL )
	{
		printf( "The file 'rate_eng.config' was not opened\n" );
		exit(0);
	}

	fscanf( login, "%s", cust_care_login );
	fscanf( login, "%s", rate_login );
	fscanf( login, "%s", cdr_dump_location );

#ifndef DIALOG
	cout<<cust_care_login<<" "<<rate_login<<" "<<cdr_dump_location<<endl;
#endif

	if( fclose( login ) )
		printf( "The file 'rate_eng.config' was not closed\n" );

//-------------- database logins and print file location -----------------------

//	db_connect(cust_care_login); 
	db_connect_cust_care(cust_care_login); 

	gsm_value_added_services->db_read();
	//	gsm_value_added_services->print();
	gsm_connections->db_read();
	//	gsm_connections->print();
	gsm_historic_imsi->db_read();
	//gsm_historic_imsi->print();
	gsm_historic_package->db_read();
//	gsm_historic_package->print();


	gsm_rates->db_read();
	//	gsm_rates->print();
	gsm_package_services->db_read();
	//	gsm_package_services->print();
	gsm_network_groups->db_read();
	//	gsm_network_groups->print();
	gsm_holiday_priorities->db_read();
	//	gsm_holiday_priorities->print();
	gsm_time_discount_bands->db_read();
	//	gsm_time_discount_bands->print();
	gsm_discount_numbers->db_read();
	//	gsm_discount_numbers->print();
	gsm_celebration_discounts->db_read();
	//	gsm_celebration_discounts->print();
	gsm_group_discounts->db_read();
	//	gsm_group_discounts->print();
	gsm_rate_groups->db_read();
	//	gsm_rate_groups->print();
	gsm_cell_groups->db_read();
	// gsm_cell_groups->print();
	gsm_fixed_rate_numbers->db_read();
	// gsm_fixed_rate_numbers->print();
	gsm_roaming_networks->db_read();
	// gsm_roaming_networks->print();
	gsm_call_partner_networks->db_read();
	// gsm_call_partner_networks->print();

	// disconnect from customer care as load up of refeance data is done
	db_disconnect_cust_care();

	// login to rating database

	printf("\nReady to connect to Rating data base\n");

	db_connect_rating(rate_login);

	// must be after connection to rate data base
#ifdef RE_RATE
	gsm_cdr_rejects->read_reject_date_range_file("./cdr_reject_date_range.config");
	gsm_cdr_rejects->db_read(); // with dates read in from config file
	gsm_cdr_rejects->print();
#endif

	cdr_f.db_read();		// read in list of cdrs files to be rated from database
	//cdr_f.print();

	cdr_f.init(cdr_dump_location);
	// :REMOVE only for testing core dump
	//db_disconnect_rating();
 	//	exit(0);

	// Rate eng performance measurement defs
	time_t	run_start_time,		// when rating process was awakend
		run_end_time,			// when rating process stopped
		file_start_time,		// start of rating a cdr file
		file_end_time,			// when cdr file stopped rating
		time_now,
		block_start_time;
	
	int	total_cdrs_rated = 0;	// cumilative for this run over all cdr files
	int cdrs_pending_insert = 0;// must allways be less than block size
	int cdrs_inserted = 0;		// must allways be less than block size

	float block_cdr_rate,		// instanteanous block rate	
		avg_cdr_rate;			// Average rate from rate engine woke up
	// observers keep the rateing results for all the types of rating runs for a cdr
	rating_observer initial, local_charge, discount_number, discount_cele, discount_group ;
	
	FILE *fp;
	cdr_file_statistics *s;		// the stuff is stored in a map so dont allocate storage,
								// this gives access to storage area in map, but must assign!!
	
#ifdef VALID_IMSI_ONLY
	imsi_filter imsi;
	imsi.read_imsi_file("imsi.lst");
#endif
	bool loop_limit;

	time(&run_start_time);						// time rate engine woke up
	time(&block_start_time);

	while(cdr_f.get_next_file(&fp,&s))			// get handle of cdr file
	{
		time(&file_start_time);					// time this cdr file rateing began
		cdr_store->read_cdr_file(fp,s);			// read in whole file to buffer
		cout<<" cdr data "<<s->file_id<<endl;
		raw_cdr.set_statistics_collector(s);	// direct statistics to file statistics area
		
		while(cdr_store->get_cdr_start())		// look for start of a cdr in the file
		{
#ifdef CDR_PRINT
			core_dump = true; // force a print out
#else
			core_dump = false;
#endif

			raw_cdr.decode(cdr_store->current);
			
			// the call is not to be charged if charge indicator && duration less 90 secs
			if(C_NO_CHARGE == raw_cdr.charging_indicator  && raw_cdr.call_duration < 90)
				continue;
			// skip emergency calls
			if(EMERGENCY_CALLS == raw_cdr.required_tele_service)
				continue;
			
#ifdef VALID_IMSI_ONLY
			if(!imsi.is_valid_imsi(raw_cdr.mobile_subscriber_identity))
				continue;
#endif

			if (core_dump)								// if  error dump to screen
			{
				cdr_store->print_cdr_in_hex();
				cout<<raw_cdr<<endl;
			}
			gsm_rated_cdr->init(s->file_id, cdr_store->get_cdr_position());
			gsm_rated_cdr->unpack(&raw_cdr);			// extract all the info from the file format rec

			// If Optimal Routed MT cdr --> convert to MO
			gsm_rated_cdr->process_optimal_routed_calls();


			loop_limit=true;
generated_cdr:
// --------------------------------------------------------------------------------------------			

			gsm_connections->set_detail(gsm_rated_cdr);	// get CDR details

			gsm_rated_cdr->decode_service();			// get operator service type
			// get rate group
			// value added services get priority if not use the default
			// specified in package services else reject;
			if(!gsm_value_added_services->set_value_added_rate_group(*gsm_rated_cdr))
			{
				gsm_package_services->set_package_rate_group(*gsm_rated_cdr);
			}
			
			// cdr will rejected call if not found as rate_group_id will be = ""
			gsm_rated_cdr->decode_network();
			gsm_connections->set_call_partner_group(*gsm_rated_cdr);
			
			initial.init(0,"O");  // O = original
			rating_observer *r_o;
			r_o = &initial;
			
			string locale_id;
			locale_id = decode_origin_of_call_indicator(gsm_rated_cdr->origin_of_call_indicator); 
			
			if(gsm_rates->match(gsm_rated_cdr->rate_group_id, locale_id, *gsm_rated_cdr, initial))
			{
				// discounting is for local calls only
				if(	gsm_rated_cdr->origin_of_call_indicator == (int)NATIONAL_CALL)
				{
					discount_number.init(initial.charge,"N");	// N = number
					gsm_discount_numbers->compute((*gsm_rated_cdr), locale_id, discount_number, (*gsm_rates));
					
					discount_cele.init(initial.charge,"C");		// C = Celebration
					gsm_celebration_discounts->compute((*gsm_rated_cdr),locale_id, discount_cele, (*gsm_rates));
					
					discount_group.init(initial.charge,"G");	// G = Group
					gsm_group_discounts->compute((*gsm_rated_cdr),locale_id, discount_group, (*gsm_rates));
					
					// get the most favorable for the client
					if (discount_number.charge < r_o->charge)
						r_o = &discount_number;
					
					if (discount_cele.charge < r_o->charge)
						r_o = &discount_cele;
					
					if (discount_group.charge < r_o->charge)
						r_o = &discount_group;
				}
				// add local call charge to this
				//else if ((int)INTERNATIONAL_CALL == gsm_rated_cdr->origin_of_call_indicator)
				// removal of Local Air Charge for IDD - chandika
				else if ( ((int)INTERNATIONAL_CALL == gsm_rated_cdr->origin_of_call_indicator) && (gsm_rated_cdr->ms_location_identity == "RRI") )
				{
					local_charge.init(0,"L"); // L = Local
					string local_charge_rate_group;

					//local_charge_rate_group = gsm_rate_groups->get_re_rate_group(gsm_rated_cdr->rate_group_id);
					gsm_package_services->get_telephony_rate_group(gsm_rated_cdr->connection_d.package_code, local_charge_rate_group);
					if(gsm_rates->match(local_charge_rate_group,"NATIONAL", *gsm_rated_cdr, local_charge))
					{
						r_o->charge += local_charge.charge;
						r_o->unit_cost += local_charge.unit_cost;
					}
				}
				// removal of Local Air Charge for IDD - chandika (Debug code commented due to no meaning any more)
				/*
				else
				{
					cout<<"<ERROR> bad orgin of call indicator "<<gsm_rated_cdr->origin_of_call_indicator<<endl;
				}
				*/
			}

			// fixed rate numbers like vioce mail, music, help etc
			gsm_rated_cdr->billing = *r_o;
			gsm_fixed_rate_numbers->fixed_rate_number_charge(gsm_rated_cdr);
			// rateing end


			// skip zero rated calls
#ifdef ZERO_RATE_SKIP
			if(gsm_rated_cdr->billing.charge == 0 && 
			   gsm_rated_cdr->billing.rate_result == R_RATED && 
			   gsm_rated_cdr->connection_d.account_no != ROAMING_ACCOUNT)
				goto skip_db_log;
#endif

#ifdef RE_ROUTED_SKIP
			if(gsm_rated_cdr->type_of_call == REROUTED_TERMINATING_CALL)
				goto skip_db_log;
#endif
			//database log and performance statistics
			gsm_cdr_block[cdrs_pending_insert] = (*gsm_rated_cdr);
			cdrs_pending_insert++;
			total_cdrs_rated++;  
			if (CDR_INSERT_BLOCK_SIZE == cdrs_pending_insert)
			{
				cdrs_inserted += cdrs_pending_insert;
#ifdef DBLOG
				db_insert_rated_cdr(cdrs_pending_insert);
#endif
				cdrs_pending_insert = 0;	// must allways be after the insert!!
				time(&time_now);
				avg_cdr_rate = total_cdrs_rated/(difftime(time_now, run_start_time)+1); // zero divide get out kludge
				block_cdr_rate = (float)CDR_INSERT_BLOCK_SIZE/(float)(difftime(time_now, block_start_time)+1); // zero divide get out kludge
				time(&block_start_time);
#ifdef SUN
				ProcessAdm.SendHeartbeat();
				ProcessAdm.SendStat("CDR COUNT", "Total cdrs rated = %d ", total_cdrs_rated);
				ProcessAdm.SendStat("AVG RATE",  "Avg rating speed = %7.2f cdrs/sec ", avg_cdr_rate);
				ProcessAdm.SendStat("BLOCK RATE","Block rating speed = %7.2f cdrs/sec ", block_cdr_rate);
#else // debug on NT
				if( !(total_cdrs_rated%500))
				{
					printf("Rate= %7.2f cdrs/sec ", avg_cdr_rate);
					cout<<" CDRS inserted "<<total_cdrs_rated<<endl;
				}
#endif
			}
			else if (cdrs_pending_insert > CDR_INSERT_BLOCK_SIZE )
			{
				cout<<"ERROR insert array size over flow "<<cdrs_pending_insert<<endl;
			}
			//database log and perfromance statistics end
skip_db_log:

			// cdr re-issue (business case is detailed elseware
			if( // call-forwarding to a number other than voice mail
				(gsm_rated_cdr->type_of_call == GMSC_FORWARDED_TERMINATING_CALL ||
				gsm_rated_cdr->type_of_call == MSC_FORWARDED_TERMINATING_CALL) 
				&& loop_limit == true
			  )
			{
				gsm_rated_cdr->call_partner_identity			= gsm_rated_cdr->ms_location_identity;
				gsm_rated_cdr->call_partner_extension			= gsm_rated_cdr->ms_location_identity_extention;
				// for roaming idd forwards
				if((int)CPE_INTERNATIONAL == gsm_rated_cdr->call_partner_extension )  
					gsm_rated_cdr->origin_of_call_indicator = INTERNATIONAL_CALL;
/*
				if("41302" != gsm_rated_cdr->mobile_subscriber_identity.substr(0,5))
				{
					cout<<"call partner ext roam "<<gsm_rated_cdr->call_partner_extension<<	endl;
					cout<<"call partner id roam "<<gsm_rated_cdr->call_partner_identity<<	endl;
				}
*/
				gsm_rated_cdr->ms_location_identity				= "FWD"; // possible bomb ??? char in numeric context field :TODO (ajit)
				gsm_rated_cdr->ms_location_identity_extention	= 0;
				gsm_rated_cdr->type_of_call						= ORIGINATING_CALL_RADIO;
				gsm_rated_cdr->file_pos							*= -1;				// indicate  generated outgoing cdr
				gsm_rated_cdr->group_discount_rate_plan_id		= WILD_CARD;		// dont carry over
				loop_limit = false;
				goto generated_cdr;
			} else if ( // re-routed terminated international calls for outbound roaming
				gsm_rated_cdr->type_of_call == REROUTED_TERMINATING_CALL &&
				gsm_rated_cdr->ms_location_identity.substr(0,2) != "77"  &&
				loop_limit == true// non dialog msrn number
				)
			{
				original_call_partner_identity					= gsm_rated_cdr->call_partner_identity; // save for later use
				original_call_partner_extension					= gsm_rated_cdr->call_partner_extension;
				gsm_rated_cdr->call_partner_identity			= gsm_rated_cdr->ms_location_identity;
				gsm_rated_cdr->call_partner_extension			= gsm_rated_cdr->ms_location_identity_extention;
				gsm_rated_cdr->type_of_call						= ORIGINATING_CALL_RADIO;
				gsm_rated_cdr->ms_location_identity				= "RRI";			// possible bomb ??? char in numeric context field :TODO (ajit)
				gsm_rated_cdr->origin_of_call_indicator			= INTERNATIONAL_CALL;
				gsm_rated_cdr->file_pos							*= -1;				// indicate  generated outgoing cdr
				gsm_rated_cdr->group_discount_rate_plan_id		= WILD_CARD;		// dont carry over

				//loop_limit = false;
				goto generated_cdr;
			}
			else if ( gsm_rated_cdr->ms_location_identity == "RRI")
			{
				gsm_rated_cdr->call_partner_identity			= original_call_partner_identity;
				gsm_rated_cdr->call_partner_extension			= original_call_partner_extension;
				gsm_rated_cdr->type_of_call						= TERMINATING_CALL_RADIO;
				gsm_rated_cdr->ms_location_identity				= "TNN"; // Terminated national call
				gsm_rated_cdr->origin_of_call_indicator			= NATIONAL_CALL;
				gsm_rated_cdr->file_pos							+= -1;				// as bytes pos no duplicates will occur
				gsm_rated_cdr->group_discount_rate_plan_id		= WILD_CARD;  // dont carry over

				loop_limit = false;
				goto generated_cdr;
			}
			// cdr re-issue 
		};
//------------------------------------------------------------------------------------------------
		
		if(fclose(fp))
			cout<<"<ERROR> cant close cdr file"<<endl; // only valid files get here
		
		time( &file_end_time );
		
		// time file was rated
		char time_buf[50];
		strftime(time_buf, 15, "%Y%m%d%H%M%S",localtime(&file_start_time));
		s->rating_start_date	= time_buf;
		s->rating_duration		= (int)difftime(file_end_time, file_start_time); 
		// remember ariane 5 so why cast?. Ans not critical, 1*e9 secs = 1900 years no overflow possible
		
#ifdef SUN
		ProcessAdm.SendStat("FILE INFO","File id %d  rated %d cdrs in %6.0f secs",
			s->file_id, s->valid_cdr_count, difftime(file_end_time, file_start_time));
#endif
		//cout<<*s<<endl;
		cdr_f.db_update(*s);
		if(s->error_count > 0)
			cout<<"         Error count "<<s->error_count<<endl;
		cdr_store->init(); // rest all pointers
	};
	
#ifdef DBLOG
	// get any partial block size inserts
	if(cdrs_pending_insert > 0)
		db_insert_rated_cdr(cdrs_pending_insert);
#endif

	db_disconnect_rating();

	time( &run_end_time );
	cout<<"INFO: rateing done in = "<<difftime(run_end_time, run_start_time)<<" secs"<<endl<<endl;
#ifdef TICKET_ACTIVE
	run_ticket.set_token(T_OFF);	// release lock
#endif

#ifdef SUN
	// if not done only multiples of array size will be shown
	ProcessAdm.SendStat("CDR COUNT", "cdrs rated = %d ", total_cdrs_rated);
	ProcessAdm.Terminate();
#endif
	
	// cdr_f.print();
	return;
}


