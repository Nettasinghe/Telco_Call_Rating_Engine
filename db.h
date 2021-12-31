

//////////////////////////////////////////////////////////////////////
//
// db.h : 
//			header file for database interaction functions.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////



void	db_connect(char *in_login); 
void	db_disconnect(); 
void	db_insert_rated_cdr(int cdr_count);


void db_connect_cust_care(char *in_login);
void db_connect_rating(char *in_login);
void db_disconnect_rating();
void db_disconnect_cust_care();




