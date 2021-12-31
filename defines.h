

//////////////////////////////////////////////////////////////////////
//
// defines.h : 
//			configuration information contains here.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


// configuration information


/*
	files to watch when changing from rate to re-rate
	db_cdr_files
		a) dump files tables (two locations in file)
	db_insert_cdr
		a) cdr table
	db_connections
		a) connections view
	db_read_value_added_services
		change view to R_V

	cdr_buffer
		a) reject processing set by define RE_RATE
	rate_eng
		a) reject processing set by define RE_RATE
		b) Dialog non dialog issues

	// re rate useage
		a) r_re_rate_dump_files			<- cdr files
		b) R_RE_RATED_CDRS				<- re- rated cdrs (gets inserted here, so clear before use)
		c) R_RE_RATE_CONNECTIONS_V		<- connections
		d) R_VALUE_ADDED_SERVICES_R_V	<- value added service _R_ for rerate
*/


//#define DIALOG				// run at dialog site comment to test at dev shop
//#define RE_RATE_VERSION	// re_rate for reject processing
//#define CDR_PRINT
//#define TICKET_ACTIVE		// ticket to run enables


#define CDR_INSERT_BLOCK_SIZE 500

#define RE_ROUTED_SKIP  // re- routed terminated calls skip

#ifdef DIALOG
	#define SUN
	#define DBLOG
	#define TICKET_ACTIVE	// ticket to run enables
#else
	#define DBLOG
//	#define VALID_IMSI_ONLY
#endif

#define HISTORIC

#ifdef RE_RATE_VERSION
	// #define CDR_PRINT
	// #define ZERO_RATE_SKIP
	// #define VALID_IMSI_ONLY
	#define RE_RATE
	#undef TICKET_ACTIVE 
#endif 
