

//////////////////////////////////////////////////////////////////////
//
// db_data_containers.h : 
//			header file for main class definitions.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////



#pragma warning(disable:4786)
// u07/tss/root/Dev/Src/shared/rand/GSM/Admin
// root/ob1knob
//twsbuild
// godir
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdio.h>

using namespace std;

#define RATE_S cout
static const int MIN_YEAR=1949;
static const int MAX_YEAR=2051;
static const char* WILD_CARD="UNDEF";
static const int BILLING_THRESHOLD_DURATION=4;
static const int ROAMING_ACCOUNT=999999;

typedef enum {T_UNDEF, T_ON, T_OFF} e_token_state;


typedef enum
{
	O_PLUS	= 1,
	O_MINUS	= 2,
	O_MUL	= 3,
	O_DIV	= 4,
	O_ASSIGN= 5,
	O_AT	= 6,
	O_UNDEF	= 0
} e_operator;

typedef enum
{
	C_NO_INDICATION	= 0x0,
	C_CHARGE		= 0x1,
	C_NO_CHARGE		= 0x2,
	C_NOT_APPLICABLE= 0xf
} e_charging_indicator;

typedef enum
{
	NATIONAL_CALL				= 0x0,
	INTERNATIONAL_CALL			= 0x1,
	MANUAL_NATIONAL_CALL		= 0x2,
	MANUAL_INTERNATIONAL_CALL	= 0x3,
	INDICATOR_NOT_APPLICABLE	= 0xf
} e_origin_of_call_indicator;

typedef enum
{
	ORIGINATING_CALL_RADIO					= 0x0,
	TERMINATING_CALL_RADIO					= 0x1,
	MSC_FORWARDED_TERMINATING_CALL			= 0x2,
	REROUTED_TERMINATING_CALL				= 0x4,
	GMSC_FORWARDED_TERMINATING_CALL			= 0x6,
	ORIGINATING_CALL_RADIO_WITH_HOT_BILLING = 0xd,
	TERMINATING_CALL_WITH_HOT_BILLING		= 0xe,
	MSC_FORWARDED_TERMINATING_CALL_RADIO_WITH_HOT_BILLING=0xf
} e_type_of_call;

typedef enum
{
	MSC				= 0x0,
	GMSC			= 0x1,
	IWGMSC			= 0x3
} e_type_of_msc;

typedef enum
{
	TELEPHONY		= 0x11,
	EMERGENCY_CALLS	= 0x12,
	SMS_MT_PP		= 0x21,
	SMS_MO_PP		= 0x22,
	FAX_G3_SPEECH	= 0x61,
	AUTO_FAX_G3		= 0x62,
	VOICE_MAIL		= 0x77,
	NOT_USED		= 0xff
} e_required_tele_service;

typedef enum
{
	CPE_NATIONAL		= 0xa0, // 160
	CPE_INTERNATIONAL	= 0x90  // 144
} e_call_partner_ext; 

typedef enum
{	R_RATED				= 0,
	R_CLIENT_NOT_FOUND	= 1,
	R_NO_RATE_PLAN		= 2,
	R_NO_MATCHING_RULE	= 3,
	R_DUPLICATE_RULES	= 4,
	R_UNDEF				= 9
} e_rate_result;

typedef enum
{	E_PHONE_CHANGE		= 0,
	E_EXPIRED_SERVICE	= 1,	// using a service that is no longer applicable
	E_IMEI_MISMATCH		= 2,	// imei no in cust profile not correct
	E_HISTORIC_IMSI		= 3,	// rating done on old imsi number
	E_DISCONNECTED		= 4		// disconnected customer taking calls (switch out of sync)
} e_note; 
//VOICE mail nvde

char* decode_type_msc(int tmsc);
char* decode_type_of_call( int toc);
char* decode_call_termination_type(int ctt);
char* decode_origin_of_call_indicator(int ooci);
char* decode_charging_indicator(int ci);
char* decode_required_tele_service(int rts);
char* decode_required_bearer_service(int rbs);
char* decode_required_bearer_service(int rbs);
char* decode_required_bearer_capability(int rbc);

class rating_observer;
class rated_cdr;
class reng_time;

class reng_time
{
public:
	int hour;
	int min;
	int second;
	bool set_time(int h, int m, int s=0);
	bool set_time(char *t);
	bool set_h_m(const char *t);
	bool set_from_db(char *t, int secs);

	bool operator < (const reng_time  &s) const;
	reng_time operator+ (int s) const;
	void Print();
	void init();
};


ostream& operator<<(ostream& out, reng_time x);

class reng_date
{
public:
	int year;
	int month;
	int day;
	bool operator < (const reng_date  &s) const;
	bool set_date(int y, int m, int d);
	bool set_date(char *d);
	void init();
};

ostream& operator<<(ostream& out, reng_date x);


class reng_date_time
{
public:
	reng_date date;
	reng_time time;
	bool set_date_time(char *d);
	bool operator < (const reng_date_time  &s) const;
};

ostream& operator<<(ostream& out, reng_date_time x);


class time_band_data
{
public:
	reng_time start;
	reng_time end;
	string description;
	bool is_in_band(reng_time t); // pass by value
};

ostream& operator<<(ostream& out, time_band_data x);

// networks -- begin ---------------------------------------------------------
// all the networks contacted by the operator
typedef map<string, int, less<string> > N_CALL_PART_DEF;

class call_partner_networks
{
public:
	N_CALL_PART_DEF c_partner_networks;
	bool insert(string network_id, int locale);
	bool get_partner_network(string call_partner, string &network_no, string &tel_no);
	bool is_national(string network_id);
	void db_read();
	void print();
};
// networks -- end ------------------------------------------------------------


// network groups -- begin ----------------------------------------------------
class network_group_key
{
public:
	string	network_id;
	string	network_group;
	bool operator < (const network_group_key &s) const;
};

ostream& operator<<(ostream& out, network_group_key x);

typedef set<network_group_key, less<network_group_key> > N_MEMEBER_DEF;

class network_groups
{
public:
	N_MEMEBER_DEF n_members;
	bool insert(string network_id, string network_group);
	bool is_network_in_group(string &network_id, string &network_group);
	void db_read();
	void print();
};
// network groups -- end ------------------------------------------------------


// Connections -- begin -------------------------------------------------------
class connection_detail
{
public:
	int		account_no;				// the customer unique id
	string	client_code;			// a secondry unique id which we dont need
	int		phone_no;				// cell phone number
	string	imei_no;				// international mobile equipment identifier
	string	sim_no;					// sim card number
	string	group_code;				// the discount group code
	string  group_rate_plan_id;		// rate plan applicable to group (discount)

	string	package_code;			// the rateing package (bill plan) code
	// risk management 
	float	gross_charge_for_run;	// the charge for connection for this rating run
	void init();
};

class connection_key
{
public:
	string	imsi_no;
	bool operator < (const connection_key &s) const;
	connection_key& operator=(const string &s);
};

ostream& operator<<(ostream& out, connection_key x);


typedef map<connection_key, connection_detail, less<connection_key> > CONNECTION_DEF;
typedef map<int, string, less<int> > PHONE_NO_TO_GRP_DEF;
typedef map<int, string, less<int> > PHONE_NO_TO_IMSI_DEF;	// 
// map for acc_no - to imsi
typedef map<int, string, less<int> > ACC_NO_TO_IMSI_DEF;	// historic imsi lookup

class connections
{
public:
	CONNECTION_DEF conn;					// asscociate imsi with connection details
	PHONE_NO_TO_GRP_DEF ph_to_grp;			// associate phone number with group
	PHONE_NO_TO_IMSI_DEF ph_to_imsi;		// asscocate phone number with imsi
	ACC_NO_TO_IMSI_DEF ac_to_imsi;			// asscocate account no with imsi

	CONNECTION_DEF::iterator iter;
	void insert(string imsi, connection_detail &a );
	bool get_client(connection_key imsi, connection_detail &a, string call_time);
	bool get_client_from_historic_imsi(int account_no, connection_detail &a, string &call_time);
	bool get_group(int ph_no, string &grp);
	bool set_detail(rated_cdr *cdr);
	bool set_call_partner_group(rated_cdr &rated_cdr);
	bool add_gross_call_charge(connection_key k, float call_charge);
	void db_read();
	void db_insert_revenue(int run_id);
	void print();
	bool is_new_client(string imsi);
};

ostream& operator<<(ostream& out, connection_detail x);

// Connections -- end ---------------------------------------------------------



// Rates -- begin -------------------------------------------------------------
class rate_key
{
public:
	string	rate_group_id;
	string	call_type_id; 
	string	locale_id; 
	string	service_type_id; 

	bool operator < (const rate_key &s) const;
};

ostream& operator<<(ostream& out, rate_key x);


class rate_detail
{
public:
	string			time_band_group; 
	string			unit_rate_id; 
	string			default_rate; 
	string			rate_id; 
	string			day_id;
	int				priority; 
	string			route_group_id;
	string			net_group_id;
	string			time_band_type;
	string			time_block_id;
	string			discount_group_id;
	int				unit_duration;
	float			unit_cost;
	int				billable_duration;
	time_band_data	active_period;

	string			start_date; 
	string			end_date;
	int				call_duration;
};

ostream& operator<<(ostream& out, rate_detail x);


typedef multimap<rate_key, rate_detail, less<rate_key> > RATE_DEF;
typedef map<string, rate_detail, less<string> > RATE_ID_SC_DEF;

class rates
{
public:
	RATE_DEF rate_data;
	RATE_ID_SC_DEF rate_ids;

	class rule_score
	{
	public:
		int day_type;
		int network_group;
		int cell_group;
		int duration;

		void init();
		rule_score();
		bool operator < (const rule_score &s) const;
		bool operator == (const rule_score &s) const;
	};

	bool insert(rate_key &rk, rate_detail &rd);
	bool match(string rate_group, string a_locale_id, rated_cdr &cdr, rating_observer &observer);
	bool score_rule(rated_cdr &cdr, RATE_DEF::iterator rule_iter, rule_score &score);
	void print();
	void db_read();
};
// Rates -- end ---------------------------------------------------------------


// Holiday priorities -- start ------------------------------------------------
class holiday_priority_key
{
public:
	reng_date date;
	string day_id;
	bool operator < (const holiday_priority_key  &s) const;
};

ostream& operator<<(ostream& out, holiday_priority_key x);

typedef map<holiday_priority_key, int, less<holiday_priority_key> > H_PRIORITY_DEF;

class holiday_priorities
{
public:
	H_PRIORITY_DEF h_priority;
	bool insert(holiday_priority_key &k, int priority);
	bool get_priority(reng_date dte, string day_id, int &p);
	void db_read();
	void print();
};
// Holiday priorties -- end ---------------------------------------------------

// package services -- start --------------------------------------------------
class package_services_key
{
public:
	string		package_code;		// pk from rates
	string		service_code;
	bool operator < (const package_services_key  &s) const;
};

ostream& operator<<(ostream& out, package_services_key x);


class package_services_data
{
public:
	float	rental;
	string	rate_group_id;			// pk from rates
};

ostream& operator<<(ostream& out, package_services_data x);

typedef multimap<package_services_key, package_services_data, less<package_services_key> > PACKAGE_SERVICES_DEF;

class package_services
{
public:
	PACKAGE_SERVICES_DEF p_services;
	bool insert(package_services_key &k, package_services_data &d);
	bool set_package_rate_group(rated_cdr &cdr);
	bool get_telephony_rate_group(string package_code, string &rate_group_id);
	void print();
	void db_read();
};
// package services -- end ----------------------------------------------------


// value added services -- start ----------------------------------------------
class value_added_services_key
{
public:
	int			account_no;
	string		service_code;
	bool operator < (const value_added_services_key  &s) const;
};

ostream& operator<<(ostream& out, value_added_services_key x);


class value_added_services_data
{
public:
	string		rate_group_id;
	reng_date	start_date;
	reng_date	end_date;
};
ostream& operator<<(ostream& out, value_added_services_data x);


typedef multimap<value_added_services_key, value_added_services_data, less<value_added_services_key> > VAL_ADD_SERVICES_DEF;


class value_added_services
{
public:
	VAL_ADD_SERVICES_DEF v_services;

	bool insert(value_added_services_key &k, value_added_services_data &d);
	bool set_value_added_rate_group(rated_cdr &cdr);
	bool get_air_group(int ac_no, string &air);
	bool get_sms_group_mo(int ac_no, string &sms);
	bool get_sms_group_mt(int ac_no, string &sms);
	void print();
	void db_read();

};
// package services -- end ----------------------------------------------------


// class aritmetic discount -- begin ------------------------------------------
class discount_expression
{
public:
	e_operator		dis_operator;
	float			dis_operand;
bool  compute(float x, float & result);
};
ostream& operator<<(ostream& out, e_operator x);
// class aritmetic discount -- end --------------------------------------------


// Time band discount bands -- begin ------------------------------------------

class time_discount_band_key
{
public:
	string		group_id;
	bool operator < (const time_discount_band_key  &s) const;
};
ostream& operator<<(ostream& out, time_discount_band_key x);


class time_discount_band_data: public discount_expression
{
public:
	int		start_second;
	int		end_second;
};

ostream& operator<<(ostream& out, time_discount_band_data x);

typedef multimap<time_discount_band_key, time_discount_band_data, less<time_discount_band_key> > TIME_DISCOUNT_DEF;

class time_discount_bands
{
public:
	TIME_DISCOUNT_DEF t_d_band;
	bool insert(string k, time_discount_band_data &d);
	//bool get_client(string imsi, connection_detail &a);
	bool set_discount(string discount_group_id, rated_cdr &c, rating_observer &r_o);
	void db_read();
	void print();
};
// Time band discount bands -- end --------------------------------------------


// Discount numbers -- begin --------------------------------------------------
class discount_number_key
{
public:
	int		account_no;
	int		phone_number;
	string	network_id;
	bool operator < (const discount_number_key  &s) const;
};
ostream& operator<<(ostream& out, discount_number_key x);

class discount_number_data: public discount_expression
{
public:
	string	discount_type_id;
	string	client_code;
//		string	valid; 
	string	rate_group_id;
	string	start_date;
	string	end_date;
};
ostream& operator<<(ostream& out, discount_number_data x);

//typedef map<discount_number_key, discount_number_data, less<discount_number_key> > DIS_NUM_DEF;
typedef multimap<discount_number_key, discount_number_data, less<discount_number_key> > DIS_NUM_DEF;


class discount_numbers
{
public:
	DIS_NUM_DEF d_numbers;
	bool insert(discount_number_key &k, discount_number_data &d);
	bool compute(rated_cdr &cdr, string locale_id, rating_observer &r_o, rates &r);
	void db_read();
	void print();
};
// Discount numbers -- end ----------------------------------------------------


// celebration_discounts -- begin ---------------------------------------------
class celebration_discount_key
{
public:
	int			account_no;
	reng_date	cele_date;
	bool operator < (const celebration_discount_key  &s) const;
};
ostream& operator<<(ostream& out, discount_number_key x);


class celebration_discount_data: public discount_expression
{
public:
	string		discount_id;
	reng_date	start_date;
	reng_date	end_date;
	string		rate_group_id; 
};

ostream& operator<<(ostream& out, celebration_discount_data x);

typedef map<celebration_discount_key, celebration_discount_data, less<celebration_discount_key> > CELE_DIS_DEF;


class celebration_discounts
{
public:
	CELE_DIS_DEF c_discounts;
	bool insert(celebration_discount_key &k, celebration_discount_data &d);
	bool compute(rated_cdr &cdr, string locale_id, rating_observer &r_o, rates &r);
	void db_read();
	void print();
};
// celebration discounts -- end -----------------------------------------------



// group discounts -- begin ---------------------------------------------------
class group_discount_key
{
public:
	string	orig_group;
	string	term_group;
	bool operator < (const group_discount_key  &s) const;
};
ostream& operator<<(ostream& out, discount_number_key x);

class group_discount_data: public discount_expression
{
public:
	string rate_group_id;
};

ostream& operator<<(ostream& out, group_discount_data x);

typedef map<group_discount_key, group_discount_data, less<group_discount_key> > GROUP_DIS_DEF;
	
class group_discounts
{
public:
	GROUP_DIS_DEF g_discounts;
	bool insert(group_discount_key &k, group_discount_data &d);
	bool compute(rated_cdr &cdr, string locale_id, rating_observer &r_o, rates &r);
	void db_read();
	void print();
};
// group discounts -- end -----------------------------------------------------



class CDRDecode; // from cdrsvr.h forward dec


class rating_observer
{
public:
	float charge;				// after applying time discounts, inital
	float charge_discount_expression;
	float discounted_charge;	// after applying other discounts to be billed

	int score;					// score 
	int block_approximated_call_duration;

	float units;
	float charged_units;
	float unit_cost;			// the cost of a unit
	int unit_duration;			// the length of a unit in secs
	
	string	rate_rule_id;		// rule used for call rating

	bool rated;					//sucessfuly rated
	string comments;			// remove
	string score_comment;		// remove
	string result_id;			// R rated, U unrated; // remove
	e_rate_result rate_result;

	string time_band_type;
	string discount_type;

	void init(float chg, string d_type);
};

ostream& operator<<(ostream& out, rating_observer x);


// CDR -- begin ---------------------------------------------------------------
class r4_cdr_decode;

class rated_cdr
{
public:
	bool vaild;

	int file_id;			// the number of the file
	int file_pos;			// the bytes from start of cdr where file started

	// call detail
	int type_of_msc;
	int type_of_call;
	int call_termination_type;
	int origin_of_call_indicator;
	int charging_indicator;
	int required_tele_service;
	int required_bearer_service;

	int call_duration;
	int invoked_supplementary_services;
	string required_bearer_capability;

	string mobile_station_identity;
	string link_information;
	string mobile_subscriber_identity;
	int msc_identity_extension;
	string msc_identity;

	int call_partner_extension;
	string call_partner_identity;		// needs unpacking to get all the info
	string ms_location_identity;
	int ms_location_identity_extention;

	// call timing stuff
	string circuit_allocation_time_stamp;
	string call_time_stamp;
	string fixed_network_info;

	// gathered stuff for dumping
	// connections table
	connection_detail connection_d;
	
	bool imsi_found;

	// a quick hack-to be rationalised
	string group_discount_rate_plan_id;	 // call partner rate plan for group discounts

	// for rate rule selection
	string service_type_id;
	string locale_id;

	// decoded stuff
	reng_time d_circuit_allocation_time;
	reng_date d_circuit_allocation_date;
	string rate_group_id;
	string decoded_service;				// with all operator specified value added services included
										// used only to get a fix on rate group.
	// call partner info
	string call_partner_network_id;		// telephone company 077=dialog, 074=suntel.
	string call_partner_telephone_no;	// 6 digits
	string call_partner_group;			// users can be grouped for inter group discounts

	string discount_type;				// varchar2(1)
	string mcc;							// mobile country code
	string mnc;							// mobile network code
	int lac;							// location area code
	int ci;								// cell id
 
	int tap_flag;

	rating_observer billing;			// rating results

	// Optimal Routed indicator
	int or_indicator;					// non or	= 0 -- default value
										// or MT	= 1
										// or MO with Forign IMSI = 2
										// or MO with Local IMSI  = 3

	bool unpack(r4_cdr_decode *a);
	void init(int f_id, int f_pos);
	bool decode_service();
	bool decode_network();

	bool print();
	bool process_optimal_routed_calls();			// To convert Optimal Routed MT to MO
};

ostream& operator<<(ostream& out, rated_cdr x);

int  match(rated_cdr &c, rate_detail &r);

class rate_group_data
{
public:
	string re_rate_group_id;			// varchar2(5)
	int time_threshold;					// not null number(3)
	// key string rate_group_id;		// not null varchar2(5)
};

ostream& operator<<(ostream& out, rate_group_data x);

typedef map<string, rate_group_data, less<string> > RATE_GRP_DEF;

class rate_groups
{
public:
	RATE_GRP_DEF r_group;
	void insert(string rate_grp, rate_group_data rgd);
	void print();
	void db_read();
	int get_time_threshold(string rate_grp);
	string get_re_rate_group(string rate_grp);
};

class cell_group_key
{
public:
	string cell_group;
	int cell_id;
	cell_group_key();
	bool operator < (const cell_group_key &s) const;
};

typedef set<cell_group_key, less<cell_group_key> > CELL_GRP_DEF;

class cell_groups
{
public:
	CELL_GRP_DEF c_groups;
	bool insert(string cell_group, int cell_id);
	void print();
	void db_read();
	bool is_in_cell(string cell_group, int cell_id);
};

// concat of call and network
class fixed_rate_number_key
{
public:
	string call_partner;
	int type_of_call;
	bool operator < (const fixed_rate_number_key &s) const;
};

ostream& operator<<(ostream& out, fixed_rate_number_key x);


typedef map<fixed_rate_number_key, float, less<fixed_rate_number_key> > FIXED_RATE_DEF;

class fixed_rate_numbers
{
public:
	FIXED_RATE_DEF fixed_numbers;
	void print();
	void db_read();
	void insert(fixed_rate_number_key key, float unit_rate);
	bool fixed_rate_number_charge(rated_cdr *cdr);
};

class roam_network_key
{
public:
	string net_prefix;
	bool operator < (const roam_network_key &s) const;
};

ostream& operator<<(ostream& out, roam_network_key x);

typedef map<roam_network_key, string, less<roam_network_key> > ROAM_NET_DEF;

class roaming_networks
{
public:
	ROAM_NET_DEF r_networks;
	void print();
	void db_read();
	string get_rate_group(string roam_number_prefix);
	void insert(string mcc, string mnc, string rate_group_id );
};


// ----------------------------------------------------------------------------

class historic_imsi_key
{
public:
	string	imsi_no;
	bool operator < (const historic_imsi_key &s) const;
};


class historic_imsi_data
{
public:
	string	start;
	string	end;
	int		account_no;
};

ostream& operator<<(ostream& out, time_discount_band_data x);
ostream& operator<<(ostream& out, historic_imsi_key x);


// imsi -> A/C, start-end
typedef multimap<historic_imsi_key, historic_imsi_data, less<historic_imsi_key> > HIST_IMSI_DEF;

class historic_imsi
{
public:
	HIST_IMSI_DEF h_imsi;
	void db_read();
	void insert(string imsi, int ac, string start, string end);
	bool get_account_no(string imsi, string call_time, int &account_no);
	void print();
};
ostream& operator<<(ostream& out, historic_imsi_data x);


// ----------------------------------------------------------------------------

class historic_package_key
{
public:
	int	account_no;
	bool operator < (const historic_package_key &s) const;
};


class historic_package_data
{
public:
	string	start;
	string	end;
	string	package_code;
};

ostream& operator<<(ostream& out, historic_package_key x);


typedef multimap<historic_package_key, historic_package_data, less<historic_package_key> > HIST_PACKAGE_DEF;

class historic_package
{
public:
	HIST_PACKAGE_DEF h_package;
	void db_read();
	void insert(historic_package_key k, historic_package_data d);
	bool get_package(int account_no, string call_time, string &package_code);
	void print();
};
ostream& operator<<(ostream& out, historic_package_data x);

//--------------------------------------------------------------------------------

class token
{
public:
	e_token_state token_state;
	string file_name;
	string token_text;

	FILE *token_file;

	bool set_token(e_token_state a);
	token(string f_name);
	bool is_runable(void);
	e_token_state code_token(string a);
	string decode_token(e_token_state a);
};







