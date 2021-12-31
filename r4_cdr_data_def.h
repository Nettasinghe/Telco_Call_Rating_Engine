

//////////////////////////////////////////////////////////////////////
//
// r4_cdr_data_def.h : 
//			All the constants that are required for the CDR Broker
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


// All the constants that are required for the CDR Broker

static const int  SIGNATURE_LENGTH=5;

static const int   BLOCK_SIZE =100;
static const int   CDR_FILL_PATTERN= 0x00;
static const int   SIGNATURE_OFFSET= 1;  
//static const int   SIGNATURE_LENGTH 5
//static const int   CDR_BUF_LENGTH 300
#define	  RECORD_FILLER 'F'

// static const int VERBOSE

// CDR field positions
static const int	CDR_FIXED_LENGTH = 23;
static const int	CIRCUIT_OFFSET = 9;  //  bytes from start of cdr to circuit allocation time stamp
static const int	CALL_OFFSET = 18;    // bytes from start of cdr to  call time stamp


static const int circuit_allocation_time_stamp_LENGTH = 6;
static const int call_time_stamp_LENGTH = 5;

// -1 notation is a carry over from R3
static const int cdr_start_of_call_time_stamp=(18);
static const int cdr_start_of_circuit_allocation_time_stamp=(9);
static const int cdr_start_of_type_of_msc=(4-1);
static const int cdr_start_of_call_termination_type=(5-1);
static const int cdr_start_of_origin_of_call_indicator=(7-1);
static const int cdr_start_of_required_tele_service=(8-1);
static const int cdr_start_of_required_bearer_service=(9-1);
static const int cdr_start_of_call_duration=(16-1);
static const int cdr_start_of_unefficiency_cause=(6-1);


// variable

static const int conversation_duration_POSITION=(15-1);
static const int conversation_duration_LENGTH=(3);

static const int mobile_station_identity_POSITION =	(24-1);
static const int mobile_station_identity_LENGTH =(7.5+0.5+8.5+0.5);
static const int invoked_supplementary_services_LENGTH=(1+32+1+1+8+1+1);	// Should be changed?
static const int link_information_LENGTH=(1+8);
static const int mobile_subscriber_identity_LENGTH=(8);

static const int msc_identity_LENGTH=(1+8);
static const int call_partner_identity_LENGTH=(1+19);

static const int ms_location_identity_LENGTH=(1+8);
static const int MCC_LENGTH=(1+2);
static const int MNC_LENGTH=(1+2);

static const int ms_location_identity_extension_LENGTH=(1+8);
static const int required_bearer_capability_LENGTH=(1+6);

static const int fixed_network_information_LENGTH=(1+49);					// added CJN