
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned long magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[31];
};
static const struct sqlcxp sqlfpn =
{
    30,
    "d:\\src\\r4_rate_engine_or\\db.pc"
};


static unsigned long sqlctx = 2033932181;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   unused;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
            void  *sqhstv[30];
   unsigned int   sqhstl[30];
            int   sqhsts[30];
            void  *sqindv[30];
            int   sqinds[30];
   unsigned int   sqharm[30];
   unsigned int   *sqharc[30];
   unsigned short  sqadto[30];
   unsigned short  sqtdso[30];
} sqlstm = {10,30};

// Prototypes
extern "C" {
  void sqlcxt (void **, unsigned long *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlcx2t(void **, unsigned long *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlbuft(void **, char *);
  void sqlgs2t(void **, char *);
  void sqlorat(void **, unsigned long *, void *);
}

// Forms Interface
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern "C" { void sqliem(char *, int *); }

 static const char *sq0006 = 
"select NETWORK_ID ,LOCALE_ID  from R_NETWORKS            ";

 static const char *sq0007 = 
"select FILE_NAME ,CDR_FILE_ID_NO  from cdr_dump_files where RATING_START_DAT\
E is null            ";

 static const char *sq0010 = 
"select FILE_ID ,FILE_POS  from R_RJECTED_CDRS_V where (CALL_TIME>=:b0 and CA\
LL_TIME<=:b1)           ";

 static const char *sq0011 = 
"select ACCOUNT_NO ,CLIENT_CODE ,PHONE_NO ,IMSI_NO ,IMEI_NO ,SIM_NO ,GROUP_CO\
DE ,PACKAGE_CODE ,GROUP_RATE_PLAN_ID  from R_CONNECTIONS_V            ";

 static const char *sq0012 = 
"select CALL_PARTNER ,UNIT_RATE ,CALL_TYPE  from R_FIXED_RATE_NUMBERS        \
    ";

 static const char *sq0013 = 
"select IMSI_NO ,ACCOUNT_NO ,TO_CHAR(START_DATE,'YYYYMMDDHH24MISS') ,TO_CHAR(\
END_DATE,'YYYYMMDDHH24MISS')  from SIM_NO_HISTORY where END_DATE is  not null \
           ";

 static const char *sq0016 = 
"select NETWORK_ID ,GROUP_ID  from R_network_members_V            ";

 static const char *sq0017 = 
"select DISCOUNT_ID ,ACCOUNT_NO ,OPERAND ,OPERATOR ,CELE_DATE ,START_DATE ,EN\
D_DATE ,RATE_GROUP_ID  from R_CELEBRATION_DISCOUNTS_V            ";

 static const char *sq0018 = 
"select NVL(CELL_ID,0) ,NVL(ROUTE_GROUP_ID,'UNDEF')  from R_ROUTES           \
 ";

 static const char *sq0019 = 
"select DISCOUNT_TYPE_ID ,ACCOUNT_NO ,CLIENT_CODE ,NETWORK_ID ,PHONE_NUMBER ,\
RATE_GROUP_ID ,OPERATOR ,OPERAND ,TO_CHAR(START_DATE,'YYYYMMDDHH24MISS') ,TO_C\
HAR(END_DATE,'YYYYMMDDHH24MISS')  from R_DISCOUNT_NUMBERS_V            ";

 static const char *sq0020 = 
"select ORIG_GROUP_CODE ,TERM_GROUP_CODE ,RATE_GROUP_ID ,OPERATOR ,OPERAND  f\
rom R_group_discountS_V            ";

 static const char *sq0021 = 
"select HOLIDAY_DATE ,DAY_ID ,PRIORITY  from r_holiday_priorities_v          \
  ";

 static const char *sq0022 = 
"select RENTAL ,SERVICE_CODE ,PACKAGE_CODE ,RATE_GROUP_ID  from R_PACKAGE_SER\
VICES_V            ";

 static const char *sq0023 = 
"select RATE_GROUP_ID ,RE_RATE_GROUP_ID ,TIME_THRESHOLD  from R_RATE_GROUPS_V\
            ";

 static const char *sq0024 = 
"select RATE_GROUP_ID ,RATE_ID ,PRIORITY ,DEFAULT_RATE ,CALL_TYPE_ID ,LOCALE_\
ID ,DAY_ID ,ROUTE_GROUP_ID ,NET_GROUP_ID ,SERVICE_TYPE_ID ,TIME_BAND_GROUP ,TI\
ME_BAND_TYPE ,TIME_BLOCK_ID ,DISCOUNT_GROUP_ID ,UNIT_RATE_ID ,UNIT_DURATION ,C\
OST_UNIT ,BILLABLE_DURATION ,START_DATE ,END_DATE ,START_TIME ,END_TIME ,CALL_\
DURATION  from R_RATE_RULE_V            ";

 static const char *sq0025 = 
"select BAND_ID ,START_SECOND ,END_SECOND ,OPERATOR ,OPERAND ,DISCOUNT_GROUP_\
ID  from R_TIME_DISCOUNT_BANDS_V            ";

 static const char *sq0026 = 
"select ACCOUNT_NO ,SERVICE_CODE ,RATE_GROUP_ID ,START_DATE ,END_DATE  from R\
_VALUE_ADDED_SERVICES_V            ";

 static const char *sq0027 = 
"select NVL(MCC,'') ,NVL(MNC,'') ,NVL(RATE_GROUP_ID,'')  from GSM_NETWORKS   \
         ";

 static const char *sq0028 = 
"select PACKAGE_CODE ,ACCOUNT_NO ,TO_CHAR(START_DATE,'YYYYMMDDHH24MISS') ,TO_\
CHAR(END_DATE,'YYYYMMDDHH24MISS')  from PACKAGE_HISTORY where END_DATE is  not\
 null            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{10,4130,0,0,0,
5,0,0,1,0,0,32,66,0,0,0,0,0,1,0,
20,0,0,2,0,0,27,83,0,0,4,4,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,1,5,0,
0,1,10,0,0,1,10,0,0,1,10,0,0,
64,0,0,3,0,0,27,100,0,0,4,4,0,3,6,82,65,84,73,78,71,1,5,0,0,1,10,0,0,1,10,0,0,
1,10,0,0,
101,0,0,4,0,0,30,108,0,0,0,0,0,3,6,82,65,84,73,78,71,
122,0,0,5,0,0,30,115,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
150,0,0,6,57,0,9,137,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
178,0,0,6,0,0,13,143,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,5,
0,0,2,3,0,0,
214,0,0,6,0,0,15,147,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
242,0,0,7,97,0,9,186,0,0,0,0,0,3,6,82,65,84,73,78,71,
263,0,0,7,0,0,13,193,0,0,2,0,0,3,6,82,65,84,73,78,71,2,5,0,0,2,3,0,0,
292,0,0,7,0,0,15,205,0,0,0,0,0,3,6,82,65,84,73,78,71,
313,0,0,8,265,0,5,243,0,0,8,8,0,3,6,82,65,84,73,78,71,1,3,0,0,1,3,0,0,1,3,0,0,
1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,3,0,0,
366,0,0,9,0,0,29,257,0,0,0,0,0,3,6,82,65,84,73,78,71,
387,0,0,10,100,0,9,300,0,0,2,2,0,3,6,82,65,84,73,78,71,1,5,0,0,1,5,0,0,
416,0,0,10,0,0,13,306,0,0,2,0,0,3,6,82,65,84,73,78,71,2,3,0,0,2,3,0,0,
445,0,0,10,0,0,15,316,0,0,0,0,0,3,6,82,65,84,73,78,71,
466,0,0,11,146,0,9,370,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
494,0,0,11,0,0,13,378,0,0,9,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
558,0,0,11,0,0,15,400,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
586,0,0,12,80,0,9,425,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
614,0,0,12,0,0,13,432,0,0,3,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
5,0,0,2,4,0,0,2,3,0,0,
654,0,0,12,0,0,15,438,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
682,0,0,13,165,0,9,479,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
710,0,0,13,0,0,13,485,0,0,4,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,
754,0,0,13,0,0,15,495,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
782,0,0,14,206,0,3,622,0,0,30,30,0,3,6,82,65,84,73,78,71,1,3,0,0,1,3,0,0,1,3,0,
0,1,3,0,0,1,4,0,0,1,4,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,
0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,
5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,4,0,0,
923,0,0,15,0,0,29,625,0,0,0,0,0,3,6,82,65,84,73,78,71,
944,0,0,16,65,0,9,649,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
972,0,0,16,0,0,13,655,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
5,0,0,2,5,0,0,
1008,0,0,16,0,0,15,659,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1036,0,0,17,141,0,9,690,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1064,0,0,17,0,0,13,699,0,0,8,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
5,0,0,2,3,0,0,2,4,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
1124,0,0,17,0,0,15,714,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1152,0,0,18,77,0,9,748,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1180,0,0,18,0,0,13,756,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,5,0,0,
1216,0,0,18,0,0,15,765,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1244,0,0,19,225,0,9,801,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1272,0,0,19,0,0,13,810,0,0,10,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,3,0,0,2,4,0,0,2,5,0,0,2,5,0,
0,
1340,0,0,19,0,0,15,826,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1368,0,0,20,111,0,9,855,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1396,0,0,20,0,0,13,864,0,0,5,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,4,0,0,
1444,0,0,20,0,0,15,876,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1472,0,0,21,78,0,9,901,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1500,0,0,21,0,0,13,910,0,0,3,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
5,0,0,2,5,0,0,2,3,0,0,
1540,0,0,21,0,0,15,917,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1568,0,0,22,95,0,9,944,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1596,0,0,22,0,0,13,953,0,0,4,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
4,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
1640,0,0,22,0,0,15,963,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1668,0,0,23,88,0,9,987,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1696,0,0,23,0,0,13,995,0,0,3,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
5,0,0,2,5,0,0,2,3,0,0,
1736,0,0,23,0,0,15,1003,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1764,0,0,24,350,0,9,1059,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1792,0,0,24,0,0,13,1065,0,0,23,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,
0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,4,0,0,2,3,0,0,2,5,0,0,2,5,
0,0,2,5,0,0,2,5,0,0,2,3,0,0,
1912,0,0,24,0,0,15,1099,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1940,0,0,25,120,0,9,1127,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1968,0,0,25,0,0,13,1135,0,0,6,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,5,0,0,
2020,0,0,25,0,0,15,1145,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2048,0,0,26,111,0,9,1187,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2076,0,0,26,0,0,13,1196,0,0,5,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
2124,0,0,26,0,0,15,1214,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2152,0,0,27,85,0,9,1238,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2180,0,0,27,0,0,13,1244,0,0,3,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,5,0,0,2,5,0,0,2,5,0,0,
2220,0,0,27,0,0,15,1248,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2248,0,0,28,171,0,9,1289,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2276,0,0,28,0,0,13,1298,0,0,4,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,
2320,0,0,28,0,0,15,1312,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
};




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <oraca.h>
#include <sqlcpr.h>
#include <sqlda.h>
#include <sqlca.h>

#include "defines.h"

#ifndef ORA_PROC
#include "db.h"
#include "db_data_containers.h"
#include "r4_cdr.h"
#include <fstream>
#endif


extern rated_cdr *gsm_cdr_block;

/*
	Platform issues
	GNU 2.85 Solaris 2.6 oracle 8.1.5 
	a)	gives core with pointer based array host variables
		EXEC SQL AT rating FOR :rows_to_fetch FETCH c_cdr INTO :a INDICATOR :ind
		when rows_to_fetch > 10 on a moderatly large (2K) data structure
		but the same works on the stack variables

	MSVC 6.0 NT 4.0 oracle 8.0.5
	a)	Give stack overflow for above case when :fetch_size *(datastrcre_size) exceeds a
		finite bound. 
		
		So exprementation has been used to set FETCH_SIZE value to work on both platforms
	Ajit 01-DEC-2000
*/


#define BUF_LEN 	100
#define FETCH_SIZE	1000		


/* EXEC SQL DECLARE CUSTOMER_CARE DATABASE; */ 
 
/* EXEC SQL DECLARE RATING DATABASE; */ 



/* EXEC SQL BEGIN DECLARE SECTION; */ 

	char *login_cust_care;
	char *login_rating;
/* EXEC SQL END DECLARE SECTION; */ 



void sql_error(char *msg)
{
	cout << endl << msg << endl;
	sqlca.sqlerrm.sqlerrmc[sqlca.sqlerrm.sqlerrml] = '\0';
	oraca.orastxt.orastxtc[oraca.orastxt.orastxtl] = '\0';
	oraca.orasfnm.orasfnmc[oraca.orasfnm.orasfnml] = '\0';
	cout << sqlca.sqlerrm.sqlerrmc << endl;
	cout << "in " << oraca.orastxt.orastxtc << endl;
	cout << "on line " << oraca.oraslnr << " of " << oraca.orasfnm.orasfnmc
		<< endl << endl;
	
	//-- Roll back any pending changes and disconnect from Oracle.
	/* EXEC SQL ROLLBACK RELEASE; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 0;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	exit(1);
}


//-- Connect to ORACLE. 
void db_connect_cust_care(char *in_login)
{
	login_cust_care = in_login;  // a pointer assignment, in_login has the space acclocation

    /* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error--"); */ 

#ifdef DIALOG
    cout<<"\nConnecting to ORACLE Customer care"<<endl; 
#else
	cout<<"\nConnecting to ORACLE Customer care as: "<<login_cust_care<<endl;
#endif
 
    /* EXEC SQL CONNECT :login_cust_care AT CUSTOMER_CARE; */ 

{
    struct sqlexd sqlstm;

    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )20;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)0;
    sqlstm.sqhstv[0] = (         void  *)login_cust_care;
    sqlstm.sqhstl[0] = (unsigned int  )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


    cout<<"Connected  to Customer Care "<<endl<<endl; 

}


void db_connect_rating(char *in_login)
{
	login_rating = in_login;  // a pointer assignment, in_login has the space acclocation

    /* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error--"); */ 

#ifdef DIALOG
    cout<<"\nConnecting to ORACLE Rating "<<endl; 
#else
    cout<<"\nConnecting to ORACLE Rating as: "<<login_rating<<endl; 
#endif

    /* EXEC SQL CONNECT :login_rating AT rating; */ 

{
    struct sqlexd sqlstm;

    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )64;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)0;
    sqlstm.sqhstv[0] = (         void  *)login_rating;
    sqlstm.sqhstl[0] = (unsigned int  )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


    cout<<"Connected  to Rating "<<endl<<endl; 
}


void db_disconnect_rating()
{
	cout<<"\nORACLE Rating database: DISCONNECT"<<endl;
    /* EXEC SQL AT rating COMMIT WORK RELEASE; */ 

{
    struct sqlexd sqlstm;

    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )101;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
}


void db_disconnect_cust_care()
{
	cout<<"\nORACLE Customer Care database: DISCONNECT"<<endl;
	/* EXEC SQL AT CUSTOMER_CARE COMMIT WORK RELEASE; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )122;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
}	


void call_partner_networks::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct network_number 
	{ 
		char	network_id[BUF_LEN]; 
		int 	locale_id; 
		
	} a, *n_n_ptr; 
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	n_n_ptr = &a;
	
	/* EXEC SQL  AT CUSTOMER_CARE DECLARE c_call_partner_network CURSOR FOR 
		SELECT NETWORK_ID, LOCALE_ID
		FROM R_NETWORKS; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN   c_call_partner_network; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0006;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )150;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 
	
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_call_partner_network INTO :n_n_ptr; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )178;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)n_n_ptr->network_id;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&n_n_ptr->locale_id;
  sqlstm.sqhstl[1] = (unsigned int  )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		insert(n_n_ptr->network_id, n_n_ptr->locale_id);
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_call_partner_network; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )214;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<i<<" call partner network's loaded."<<endl;
}


void cdr_files::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct cdr_file_t
	{ 
		char file_name[128];	// varchar2(123)
		int file_id;			// called id_no in table number(9)
	} a[FETCH_SIZE]; 

	struct cdr_file_t_ind
	{ 
		short file_name;		// varchar2(123)
		short file_id;			// called id_no in table number(9)
	} ind[FETCH_SIZE]; 

	int rows_to_fetch, rows_before, rows_this_time; 
	/* EXEC SQL END DECLARE SECTION; */ 

	
	
	rows_to_fetch = FETCH_SIZE; 	// number of rows in each "batch"  
	rows_before = 0;				// previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 
	
	
	//--RERATE
	/* EXEC SQL 
	AT RATING 
	DECLARE c_cdr_file CURSOR FOR 
		SELECT	FILE_NAME,	CDR_FILE_ID_NO
		//--FROM	r_re_rate_dump_files_r4
		FROM	cdr_dump_files
		WHERE RATING_START_DATE IS NULL; */ 

	
	/* EXEC SQL AT RATING OPEN  c_cdr_file; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0007;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )242;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 
	
	cdr_file_statistics cd;

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL  AT RATING  FETCH c_cdr_file INTO :a INDICATOR :ind; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1000;
  sqlstm.offset = (unsigned int  )263;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)a->file_name;
  sqlstm.sqhstl[0] = (unsigned int  )128;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct cdr_file_t);
  sqlstm.sqindv[0] = (         void  *)&ind->file_name;
  sqlstm.sqinds[0] = (         int  )sizeof(struct cdr_file_t_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqharc[0] = (unsigned int   *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->file_id;
  sqlstm.sqhstl[1] = (unsigned int  )4;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct cdr_file_t);
  sqlstm.sqindv[1] = (         void  *)&ind->file_id;
  sqlstm.sqinds[1] = (         int  )sizeof(struct cdr_file_t_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqharc[1] = (unsigned int   *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

		 
		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		
		cd.init();
		for(int i=0; i<rows_this_time; i++)
		{
			cd.file_id = a[i].file_id;			
			insert(a[i].file_name, cd);
		}
	} 
	
	/* EXEC SQL AT RATING CLOSE c_cdr_file; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )292;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<rows_before<<" cdr files loaded."<<endl;
}



void cdr_files::db_update(cdr_file_statistics s)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct cdr_file_t
	{ 
		int valid_cdr_count;					//	number(7)
		int error_count;						//	number(7)
		int bytes_read; 					//	number(9)
		char first_cdr_date[BUF_LEN];				//	varchar2(14)
		char last_cdr_date[BUF_LEN];				//	varchar2(14)
		int rating_duration;
		char rating_start_date[BUF_LEN];	//	varchar2(14)
		
		int id_no;						//	number(9)
	} a; 
	
	/* EXEC SQL END DECLARE SECTION; */ 

	
	/* EXEC SQL WHENEVER NOT FOUND GOTO nofile; */ 

	
	a.valid_cdr_count = s.valid_cdr_count;
	a.error_count = s.error_count;
	a.bytes_read = s.bytes_read;
	strcpy(a.first_cdr_date, s.first_cdr_date.c_str());
	strcpy(a.last_cdr_date, s.last_cdr_date.c_str());
	a.rating_duration = s.rating_duration;
	strcpy(a.rating_start_date, s.rating_start_date.c_str());
	
	a.id_no = s.file_id;	

	//--RERATE
	/* EXEC SQL 
	AT RATING 	
	UPDATE cdr_dump_files 
	//--UPDATE	r_re_rate_dump_files_r4
		SET 
		valid_cdr_count 		= :a.valid_cdr_count, 
		error_count 			= :a.error_count,
		bytes_read				= :a.bytes_read,
		first_cdr_date			= to_date(:a.first_cdr_date,'YYYYMMDDHH24MISS'),
		last_cdr_date			= to_date(:a.last_cdr_date,'YYYYMMDDHH24MISS'),
		rating_duration 		= :a.rating_duration,
		rating_start_date		= to_date(:a.rating_start_date,'YYYYMMDDHH24MISS')
		WHERE cdr_file_id_no  = :a.id_no; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "update cdr_dump_files  set valid_cdr_count=:b0,error_count=:\
b1,bytes_read=:b2,first_cdr_date=to_date(:b3,'YYYYMMDDHH24MISS'),last_cdr_date\
=to_date(:b4,'YYYYMMDDHH24MISS'),rating_duration=:b5,rating_start_date=to_date\
(:b6,'YYYYMMDDHH24MISS') where cdr_file_id_no=:b7";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )313;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)&(a.valid_cdr_count);
 sqlstm.sqhstl[0] = (unsigned int  )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&(a.error_count);
 sqlstm.sqhstl[1] = (unsigned int  )4;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&(a.bytes_read);
 sqlstm.sqhstl[2] = (unsigned int  )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)(a.first_cdr_date);
 sqlstm.sqhstl[3] = (unsigned int  )100;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)(a.last_cdr_date);
 sqlstm.sqhstl[4] = (unsigned int  )100;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)&(a.rating_duration);
 sqlstm.sqhstl[5] = (unsigned int  )4;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)(a.rating_start_date);
 sqlstm.sqhstl[6] = (unsigned int  )100;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)&(a.id_no);
 sqlstm.sqhstl[7] = (unsigned int  )4;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         void  *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) goto nofile;
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	
	/* EXEC SQL AT RATING COMMIT; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )366;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	
	cout<<"\n cdr file id = "<<s.file_id<<" log updated.\n\n"<<endl;
	return;
nofile:
	cout<<"\n <ERROR> file id = "<<s.file_id<<" not found to update.\n\n"<<endl;
}



void cdr_rejects::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct cdr_reject_
	{ 
		int 	file_id;
		int 	file_position;
	} a[FETCH_SIZE]; 

	struct cdr_reject_ind
	{ 
		short 	file_id;
		short 	file_position;
	} ind[FETCH_SIZE]; 

	char t_start[BUF_LEN], t_end[BUF_LEN];
	int i;
	int rows_to_fetch, rows_before, rows_this_time; 
	/* EXEC SQL END DECLARE SECTION; */ 

	
	strcpy(t_start, start_date.c_str());
	strcpy(t_end, end_date.c_str());
	
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				// previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 
	
	
	/* EXEC SQL  AT RATING DECLARE c_rejects CURSOR FOR 
		SELECT FILE_ID, FILE_POS	
		FROM R_RJECTED_CDRS_V WHERE CALL_TIME >= :t_start
		AND CALL_TIME <= :t_end; */ 
 
	
	/* EXEC SQL AT RATING OPEN  c_rejects; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0010;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )387;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlstm.sqhstv[0] = (         void  *)t_start;
 sqlstm.sqhstl[0] = (unsigned int  )100;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)t_end;
 sqlstm.sqhstl[1] = (unsigned int  )100;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 
	
	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL  AT RATING  FETCH c_rejects INTO :a INDICATOR :ind; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1000;
  sqlstm.offset = (unsigned int  )416;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&a->file_id;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct cdr_reject_);
  sqlstm.sqindv[0] = (         void  *)&ind->file_id;
  sqlstm.sqinds[0] = (         int  )sizeof(struct cdr_reject_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqharc[0] = (unsigned int   *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->file_position;
  sqlstm.sqhstl[1] = (unsigned int  )4;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct cdr_reject_);
  sqlstm.sqindv[1] = (         void  *)&ind->file_position;
  sqlstm.sqinds[1] = (         int  )sizeof(struct cdr_reject_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqharc[1] = (unsigned int   *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		
		for (i=0; i<rows_this_time; i++) 
		{ 
			insert(a[i].file_id, a[i].file_position);
		}
	} 
	
	/* EXEC SQL AT RATING CLOSE c_rejects; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )445;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<rows_before<<" rejected cdrs loaded."<<endl;
}



void connections::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct connection
	{ 
		int 	account_no;
		char	client_code[BUF_LEN];
		int 	phone_no;
		char	imsi_no[BUF_LEN]; 
		char	imei_no[BUF_LEN]; 
		char	sim_no[BUF_LEN]; 
		char	group_code[BUF_LEN]; 
		char	package_code[BUF_LEN];
		char	group_rate_plan_id[BUF_LEN];
	} a[FETCH_SIZE]; 

	struct connection_ind
	{ 
		short 	account_no;
		short	client_code;
		short 	phone_no;
		short	imsi_no; 
		short	imei_no; 
		short	sim_no; 
		short	group_code; 
		short	package_code;
		short	group_rate_plan_id;
	} ind[FETCH_SIZE]; 

	int rows_to_fetch, rows_before, rows_this_time; 
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	rows_to_fetch = FETCH_SIZE; 	// number of rows in each "batch"  
	rows_before = 0;				// previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	//--RERATE
	/* EXEC SQL  
	AT CUSTOMER_CARE 
		DECLARE c_connection CURSOR FOR 
		SELECT ACCOUNT_NO, CLIENT_CODE, PHONE_NO, 
		IMSI_NO, IMEI_NO, SIM_NO, GROUP_CODE, 
		PACKAGE_CODE, GROUP_RATE_PLAN_ID	
		//--FROM R_RE_RATE_CONNECTIONS_V; 
		FROM R_CONNECTIONS_V; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_connection; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0011;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )466;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	connection_detail cd;
	
	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FETCH c_connection INTO :a INDICATOR :ind; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1000;
  sqlstm.offset = (unsigned int  )494;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[0] = (         void  *)&ind->account_no;
  sqlstm.sqinds[0] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqharc[0] = (unsigned int   *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->client_code;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[1] = (         void  *)&ind->client_code;
  sqlstm.sqinds[1] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqharc[1] = (unsigned int   *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->phone_no;
  sqlstm.sqhstl[2] = (unsigned int  )4;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[2] = (         void  *)&ind->phone_no;
  sqlstm.sqinds[2] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqharc[2] = (unsigned int   *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->imsi_no;
  sqlstm.sqhstl[3] = (unsigned int  )100;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[3] = (         void  *)&ind->imsi_no;
  sqlstm.sqinds[3] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqharc[3] = (unsigned int   *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->imei_no;
  sqlstm.sqhstl[4] = (unsigned int  )100;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[4] = (         void  *)&ind->imei_no;
  sqlstm.sqinds[4] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqharc[4] = (unsigned int   *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->sim_no;
  sqlstm.sqhstl[5] = (unsigned int  )100;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[5] = (         void  *)&ind->sim_no;
  sqlstm.sqinds[5] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqharc[5] = (unsigned int   *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)a->group_code;
  sqlstm.sqhstl[6] = (unsigned int  )100;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[6] = (         void  *)&ind->group_code;
  sqlstm.sqinds[6] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqharc[6] = (unsigned int   *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)a->package_code;
  sqlstm.sqhstl[7] = (unsigned int  )100;
  sqlstm.sqhsts[7] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[7] = (         void  *)&ind->package_code;
  sqlstm.sqinds[7] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqharc[7] = (unsigned int   *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)a->group_rate_plan_id;
  sqlstm.sqhstl[8] = (unsigned int  )100;
  sqlstm.sqhsts[8] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[8] = (         void  *)&ind->group_rate_plan_id;
  sqlstm.sqinds[8] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqharc[8] = (unsigned int   *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 

		//-- all dialog no's are prefixed with 77 in custcare db hence subtract 77M

		for (i=0; i<rows_this_time; i++) 
		{ 
			cd.account_no			= a[i].account_no;
			cd.client_code			= a[i].client_code;
			cd.phone_no 			= a[i].phone_no-770000000;  
			cd.imei_no				= a[i].imei_no; 
			cd.sim_no				= a[i].sim_no; 
			cd.group_code			= a[i].group_code; 
			cd.package_code 		= a[i].package_code;
			cd.group_rate_plan_id	= a[i].group_rate_plan_id;
			cd.gross_charge_for_run = 0;
			
			insert(a[i].imsi_no, cd );
		}
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_connection; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )558;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<rows_before<<" connections loaded."<<endl;
}



void fixed_rate_numbers::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct f_r_number 
	{ 
		char  call_partner[BUF_LEN];	// VARCHAR2(12) NOT NULL,
		float unit_rate;				// NUMBER(9,2)	NOT NULL
		int call_type;
	} a, *f_r_n_ptr; 
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	f_r_n_ptr = &a;
	
	/* EXEC SQL AT CUSTOMER_CARE DECLARE c_fixed_rate_number CURSOR FOR 
		SELECT CALL_PARTNER, UNIT_RATE, CALL_TYPE
		FROM R_FIXED_RATE_NUMBERS; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_fixed_rate_number; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0012;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )586;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 
	
	fixed_rate_number_key k;
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_fixed_rate_number INTO :f_r_n_ptr; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )614;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)f_r_n_ptr->call_partner;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&f_r_n_ptr->unit_rate;
  sqlstm.sqhstl[1] = (unsigned int  )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&f_r_n_ptr->call_type;
  sqlstm.sqhstl[2] = (unsigned int  )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		k.call_partner = f_r_n_ptr->call_partner;
		k.type_of_call = f_r_n_ptr->call_type;
		insert(k, f_r_n_ptr->unit_rate);
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_fixed_rate_number; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )654;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<i<<" fixed rate numbers loaded."<<endl;
}


void historic_imsi::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct h_imsi
	{ 
		char	imsi[BUF_LEN];
		int 	account_no;
		char	start[BUF_LEN];
		char	end[BUF_LEN];
	} a[FETCH_SIZE]; 

	struct h_imsi_ind
	{ 
		short	imsi;
		short 	account_no;
		short	start;
		short	end;
	} ind[FETCH_SIZE]; 

	int rows_to_fetch, rows_before, rows_this_time;
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	rows_to_fetch = FETCH_SIZE; 	// number of rows in each "batch"  
	rows_before = 0;				// previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 
	

	// get all closed out records
	/* EXEC SQL  AT CUSTOMER_CARE DECLARE c_his_imsi CURSOR FOR 
		SELECT IMSI_NO, ACCOUNT_NO, 
		TO_CHAR(START_DATE,'YYYYMMDDHH24MISS'), 
		TO_CHAR(END_DATE,'YYYYMMDDHH24MISS')
		FROM SIM_NO_HISTORY WHERE END_DATE IS NOT NULL; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_his_imsi; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0013;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )682;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 
	
	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL  AT CUSTOMER_CARE  FETCH c_his_imsi INTO :a INDICATOR :ind; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1000;
  sqlstm.offset = (unsigned int  )710;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)a->imsi;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct h_imsi);
  sqlstm.sqindv[0] = (         void  *)&ind->imsi;
  sqlstm.sqinds[0] = (         int  )sizeof(struct h_imsi_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqharc[0] = (unsigned int   *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->account_no;
  sqlstm.sqhstl[1] = (unsigned int  )4;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct h_imsi);
  sqlstm.sqindv[1] = (         void  *)&ind->account_no;
  sqlstm.sqinds[1] = (         int  )sizeof(struct h_imsi_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqharc[1] = (unsigned int   *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->start;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct h_imsi);
  sqlstm.sqindv[2] = (         void  *)&ind->start;
  sqlstm.sqinds[2] = (         int  )sizeof(struct h_imsi_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqharc[2] = (unsigned int   *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->end;
  sqlstm.sqhstl[3] = (unsigned int  )100;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct h_imsi);
  sqlstm.sqindv[3] = (         void  *)&ind->end;
  sqlstm.sqinds[3] = (         int  )sizeof(struct h_imsi_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqharc[3] = (unsigned int   *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		
		for (i=0; i<rows_this_time; i++) 
		{
			insert(a[i].imsi, a[i].account_no, a[i].start, a[i].end);
		}
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_his_imsi; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )754;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<rows_before<<" historic imsis loaded."<<endl;
}



void db_insert_rated_cdr(int cdr_count)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	
	static struct db_cdr
	{
		int file_id;								//	number(9)
		int file_pos;								//	number(9)
		int account_no; 							//	number(10)
		int termination_type;						//	number(3)
		float units;								//	number(11,2)
		float charge;								//	number(11,2)
		char call_partner_id[BUF_LEN];				//	varchar2(20)
		int duration;								//	number(9)
		char call_time[BUF_LEN];					//	varchar2(14)
		char ms_location[BUF_LEN];					//	varchar2(20)
		char msc_identity[BUF_LEN]; 				//	varchar2(20)
		int call_type_id;							//	number(3)
		char network_id[BUF_LEN];					//	varchar2(5)
		char bearer_capability[BUF_LEN];			//	varchar2(10)
		int bearer_service; 						//	number(3)
		char rate_rule_id[BUF_LEN]; 				//	varchar2(15)
		int service_type_id;						//	number(3)
		int locale_id;								//	number(3)
		char imsi[BUF_LEN]; 						//	varchar2(20)
		char imei[BUF_LEN]; 						// varchar2(20)
		int result_code;
		char discount_type[BUF_LEN];				// varchar2(1)
		char mcc[BUF_LEN];							// varchar2(5)
		char mnc[BUF_LEN];							// varchar2(3)
		int lac;									// number(5)
		int ci; 									// number(5)
		int part;
		int charging_indicator; 					// number(2)
		char link_information[BUF_LEN];				// varchar2(20)
		float charged_units;						// number(11,2)
	} *a; 
	
	int rows_to_insert;
	
	/* EXEC SQL END DECLARE SECTION; */ 

	rows_to_insert = cdr_count;
	
	if((a = new db_cdr[CDR_INSERT_BLOCK_SIZE])==NULL)
	{
		cout<<" cant allocate memory for bill insert"<<endl;
		exit(0);
	}
	
	
	char buf[100]; 
	for(int j=0; j<CDR_INSERT_BLOCK_SIZE; j++)
	{
		a[j].file_pos = 0;
	}
	
	for(int i=0; i<rows_to_insert; i++)
	{
		
		a[i].file_id =	gsm_cdr_block[i].file_id; 
		a[i].file_pos = gsm_cdr_block[i].file_pos;
		a[i].account_no = gsm_cdr_block[i].connection_d.account_no;
		
		a[i].termination_type  = gsm_cdr_block[i].call_termination_type;
		
		a[i].units = gsm_cdr_block[i].billing.units;
		a[i].charged_units = gsm_cdr_block[i].billing.charged_units;
		a[i].charge = gsm_cdr_block[i].billing.charge;
		strcpy(a[i].call_partner_id,gsm_cdr_block[i].call_partner_identity.substr(0,20).c_str());
		a[i].duration = gsm_cdr_block[i].call_duration;
		reng_date d=gsm_cdr_block[i].d_circuit_allocation_date;
		reng_time t=gsm_cdr_block[i].d_circuit_allocation_time;
		
		sprintf(buf,"%04d%02d%02d%02d%02d%02d",d.year,d.month,d.day,t.hour,t.min,t.second); 
		strcpy(a[i].call_time, buf);
		
		strcpy(a[i].ms_location, gsm_cdr_block[i].ms_location_identity.substr(0,20).c_str() );									//
		strcpy(a[i].msc_identity, gsm_cdr_block[i].msc_identity.substr(0,20).c_str());	
		a[i].call_type_id = gsm_cdr_block[i].type_of_call; 
		strcpy(a[i].network_id, gsm_cdr_block[i].call_partner_network_id.substr(0,5).c_str());
		strcpy(a[i].bearer_capability, gsm_cdr_block[i].required_bearer_capability.c_str());
		a[i].bearer_service = gsm_cdr_block[i].required_bearer_service;
		strcpy(a[i].rate_rule_id, gsm_cdr_block[i].billing.rate_rule_id.substr(0,20).c_str());
		a[i].service_type_id = gsm_cdr_block[i].required_tele_service;
		a[i].locale_id = gsm_cdr_block[i].origin_of_call_indicator;
		strcpy(a[i].imsi, gsm_cdr_block[i].mobile_subscriber_identity.substr(0,20).c_str());													//
		strcpy(a[i].imei, gsm_cdr_block[i].mobile_station_identity.substr(0,20).c_str());
		a[i].result_code = gsm_cdr_block[i].billing.rate_result;
		strcpy(a[i].discount_type, gsm_cdr_block[i].billing.discount_type.substr(0,1).c_str());
		
		strcpy(a[i].mcc, gsm_cdr_block[i].mcc.c_str());
		strcpy(a[i].mnc, gsm_cdr_block[i].mnc.c_str());
		strcpy(a[i].link_information, gsm_cdr_block[i].link_information.c_str());
		
		a[i].lac = gsm_cdr_block[i].lac;
		a[i].ci = gsm_cdr_block[i].ci;
		a[i].charging_indicator = gsm_cdr_block[i].charging_indicator;
		
		//-- allocate cdr to correct partion
		if(gsm_cdr_block[i].billing.rate_result != R_RATED)
		{
			a[i].part = 3;	//-- unrated
			sprintf(buf,"%d",gsm_cdr_block[i].call_partner_extension);
			string a_s;
			a_s = gsm_cdr_block[i].link_information;
			a_s = a_s + ":";
			a_s = a_s + buf;
			strcpy(a[i].rate_rule_id, a_s.c_str());
		}
		//-- roaming zero & non zero charge cdrs 
		else if (gsm_cdr_block[i].billing.rate_result == R_RATED && gsm_cdr_block[i].rate_group_id == "ROAM") 
			a[i].part = 1;	//-- roaming
		else if (gsm_cdr_block[i].billing.rate_result == R_RATED && a[i].charge == 0)
			a[i].part = 2;	//-- zero charge
		else
			a[i].part = 0;	//-- normal
	} 
	//--RERATE
		//--EXEC SQL  AT RATING FOR :rows_to_insert INSERT INTO R_RE_RATED_CDRS_5 VALUES (:a);
		 //EXEC SQL  AT RATING FOR :rows_to_insert INSERT INTO R_RATED_CDR4 VALUES (:a);
		 /* EXEC SQL  AT RATING FOR :rows_to_insert INSERT INTO R_RATED_CDR_or VALUES (:a); */ 

{
   struct sqlexd sqlstm;

   sqlstm.sqlvsn = 10;
   sqlstm.arrsiz = 30;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "insert into R_RATED_CDR_or values (:s1 ,:s2 ,:s3 ,:s4 ,:s5\
 ,:s6 ,:s7 ,:s8 ,:s9 ,:s10 ,:s11 ,:s12 ,:s13 ,:s14 ,:s15 ,:s16 ,:s17 ,:s18 ,:s\
19 ,:s20 ,:s21 ,:s22 ,:s23 ,:s24 ,:s25 ,:s26 ,:s27 ,:s28 ,:s29 ,:s30 )";
   sqlstm.iters = (unsigned int  )rows_to_insert;
   sqlstm.offset = (unsigned int  )782;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (         void  *)&a->file_id;
   sqlstm.sqhstl[0] = (unsigned int  )4;
   sqlstm.sqhsts[0] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[0] = (         void  *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (         void  *)&a->file_pos;
   sqlstm.sqhstl[1] = (unsigned int  )4;
   sqlstm.sqhsts[1] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[1] = (         void  *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned int  )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (         void  *)&a->account_no;
   sqlstm.sqhstl[2] = (unsigned int  )4;
   sqlstm.sqhsts[2] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[2] = (         void  *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned int  )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (         void  *)&a->termination_type;
   sqlstm.sqhstl[3] = (unsigned int  )4;
   sqlstm.sqhsts[3] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[3] = (         void  *)0;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned int  )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (         void  *)&a->units;
   sqlstm.sqhstl[4] = (unsigned int  )4;
   sqlstm.sqhsts[4] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[4] = (         void  *)0;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned int  )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (         void  *)&a->charge;
   sqlstm.sqhstl[5] = (unsigned int  )4;
   sqlstm.sqhsts[5] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[5] = (         void  *)0;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned int  )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (         void  *)a->call_partner_id;
   sqlstm.sqhstl[6] = (unsigned int  )100;
   sqlstm.sqhsts[6] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[6] = (         void  *)0;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned int  )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (         void  *)&a->duration;
   sqlstm.sqhstl[7] = (unsigned int  )4;
   sqlstm.sqhsts[7] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[7] = (         void  *)0;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned int  )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (         void  *)a->call_time;
   sqlstm.sqhstl[8] = (unsigned int  )100;
   sqlstm.sqhsts[8] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[8] = (         void  *)0;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned int  )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (         void  *)a->ms_location;
   sqlstm.sqhstl[9] = (unsigned int  )100;
   sqlstm.sqhsts[9] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[9] = (         void  *)0;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned int  )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (         void  *)a->msc_identity;
   sqlstm.sqhstl[10] = (unsigned int  )100;
   sqlstm.sqhsts[10] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[10] = (         void  *)0;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned int  )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (         void  *)&a->call_type_id;
   sqlstm.sqhstl[11] = (unsigned int  )4;
   sqlstm.sqhsts[11] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[11] = (         void  *)0;
   sqlstm.sqinds[11] = (         int  )0;
   sqlstm.sqharm[11] = (unsigned int  )0;
   sqlstm.sqadto[11] = (unsigned short )0;
   sqlstm.sqtdso[11] = (unsigned short )0;
   sqlstm.sqhstv[12] = (         void  *)a->network_id;
   sqlstm.sqhstl[12] = (unsigned int  )100;
   sqlstm.sqhsts[12] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[12] = (         void  *)0;
   sqlstm.sqinds[12] = (         int  )0;
   sqlstm.sqharm[12] = (unsigned int  )0;
   sqlstm.sqadto[12] = (unsigned short )0;
   sqlstm.sqtdso[12] = (unsigned short )0;
   sqlstm.sqhstv[13] = (         void  *)a->bearer_capability;
   sqlstm.sqhstl[13] = (unsigned int  )100;
   sqlstm.sqhsts[13] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[13] = (         void  *)0;
   sqlstm.sqinds[13] = (         int  )0;
   sqlstm.sqharm[13] = (unsigned int  )0;
   sqlstm.sqadto[13] = (unsigned short )0;
   sqlstm.sqtdso[13] = (unsigned short )0;
   sqlstm.sqhstv[14] = (         void  *)&a->bearer_service;
   sqlstm.sqhstl[14] = (unsigned int  )4;
   sqlstm.sqhsts[14] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[14] = (         void  *)0;
   sqlstm.sqinds[14] = (         int  )0;
   sqlstm.sqharm[14] = (unsigned int  )0;
   sqlstm.sqadto[14] = (unsigned short )0;
   sqlstm.sqtdso[14] = (unsigned short )0;
   sqlstm.sqhstv[15] = (         void  *)a->rate_rule_id;
   sqlstm.sqhstl[15] = (unsigned int  )100;
   sqlstm.sqhsts[15] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[15] = (         void  *)0;
   sqlstm.sqinds[15] = (         int  )0;
   sqlstm.sqharm[15] = (unsigned int  )0;
   sqlstm.sqadto[15] = (unsigned short )0;
   sqlstm.sqtdso[15] = (unsigned short )0;
   sqlstm.sqhstv[16] = (         void  *)&a->service_type_id;
   sqlstm.sqhstl[16] = (unsigned int  )4;
   sqlstm.sqhsts[16] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[16] = (         void  *)0;
   sqlstm.sqinds[16] = (         int  )0;
   sqlstm.sqharm[16] = (unsigned int  )0;
   sqlstm.sqadto[16] = (unsigned short )0;
   sqlstm.sqtdso[16] = (unsigned short )0;
   sqlstm.sqhstv[17] = (         void  *)&a->locale_id;
   sqlstm.sqhstl[17] = (unsigned int  )4;
   sqlstm.sqhsts[17] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[17] = (         void  *)0;
   sqlstm.sqinds[17] = (         int  )0;
   sqlstm.sqharm[17] = (unsigned int  )0;
   sqlstm.sqadto[17] = (unsigned short )0;
   sqlstm.sqtdso[17] = (unsigned short )0;
   sqlstm.sqhstv[18] = (         void  *)a->imsi;
   sqlstm.sqhstl[18] = (unsigned int  )100;
   sqlstm.sqhsts[18] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[18] = (         void  *)0;
   sqlstm.sqinds[18] = (         int  )0;
   sqlstm.sqharm[18] = (unsigned int  )0;
   sqlstm.sqadto[18] = (unsigned short )0;
   sqlstm.sqtdso[18] = (unsigned short )0;
   sqlstm.sqhstv[19] = (         void  *)a->imei;
   sqlstm.sqhstl[19] = (unsigned int  )100;
   sqlstm.sqhsts[19] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[19] = (         void  *)0;
   sqlstm.sqinds[19] = (         int  )0;
   sqlstm.sqharm[19] = (unsigned int  )0;
   sqlstm.sqadto[19] = (unsigned short )0;
   sqlstm.sqtdso[19] = (unsigned short )0;
   sqlstm.sqhstv[20] = (         void  *)&a->result_code;
   sqlstm.sqhstl[20] = (unsigned int  )4;
   sqlstm.sqhsts[20] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[20] = (         void  *)0;
   sqlstm.sqinds[20] = (         int  )0;
   sqlstm.sqharm[20] = (unsigned int  )0;
   sqlstm.sqadto[20] = (unsigned short )0;
   sqlstm.sqtdso[20] = (unsigned short )0;
   sqlstm.sqhstv[21] = (         void  *)a->discount_type;
   sqlstm.sqhstl[21] = (unsigned int  )100;
   sqlstm.sqhsts[21] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[21] = (         void  *)0;
   sqlstm.sqinds[21] = (         int  )0;
   sqlstm.sqharm[21] = (unsigned int  )0;
   sqlstm.sqadto[21] = (unsigned short )0;
   sqlstm.sqtdso[21] = (unsigned short )0;
   sqlstm.sqhstv[22] = (         void  *)a->mcc;
   sqlstm.sqhstl[22] = (unsigned int  )100;
   sqlstm.sqhsts[22] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[22] = (         void  *)0;
   sqlstm.sqinds[22] = (         int  )0;
   sqlstm.sqharm[22] = (unsigned int  )0;
   sqlstm.sqadto[22] = (unsigned short )0;
   sqlstm.sqtdso[22] = (unsigned short )0;
   sqlstm.sqhstv[23] = (         void  *)a->mnc;
   sqlstm.sqhstl[23] = (unsigned int  )100;
   sqlstm.sqhsts[23] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[23] = (         void  *)0;
   sqlstm.sqinds[23] = (         int  )0;
   sqlstm.sqharm[23] = (unsigned int  )0;
   sqlstm.sqadto[23] = (unsigned short )0;
   sqlstm.sqtdso[23] = (unsigned short )0;
   sqlstm.sqhstv[24] = (         void  *)&a->lac;
   sqlstm.sqhstl[24] = (unsigned int  )4;
   sqlstm.sqhsts[24] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[24] = (         void  *)0;
   sqlstm.sqinds[24] = (         int  )0;
   sqlstm.sqharm[24] = (unsigned int  )0;
   sqlstm.sqadto[24] = (unsigned short )0;
   sqlstm.sqtdso[24] = (unsigned short )0;
   sqlstm.sqhstv[25] = (         void  *)&a->ci;
   sqlstm.sqhstl[25] = (unsigned int  )4;
   sqlstm.sqhsts[25] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[25] = (         void  *)0;
   sqlstm.sqinds[25] = (         int  )0;
   sqlstm.sqharm[25] = (unsigned int  )0;
   sqlstm.sqadto[25] = (unsigned short )0;
   sqlstm.sqtdso[25] = (unsigned short )0;
   sqlstm.sqhstv[26] = (         void  *)&a->part;
   sqlstm.sqhstl[26] = (unsigned int  )4;
   sqlstm.sqhsts[26] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[26] = (         void  *)0;
   sqlstm.sqinds[26] = (         int  )0;
   sqlstm.sqharm[26] = (unsigned int  )0;
   sqlstm.sqadto[26] = (unsigned short )0;
   sqlstm.sqtdso[26] = (unsigned short )0;
   sqlstm.sqhstv[27] = (         void  *)&a->charging_indicator;
   sqlstm.sqhstl[27] = (unsigned int  )4;
   sqlstm.sqhsts[27] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[27] = (         void  *)0;
   sqlstm.sqinds[27] = (         int  )0;
   sqlstm.sqharm[27] = (unsigned int  )0;
   sqlstm.sqadto[27] = (unsigned short )0;
   sqlstm.sqtdso[27] = (unsigned short )0;
   sqlstm.sqhstv[28] = (         void  *)a->link_information;
   sqlstm.sqhstl[28] = (unsigned int  )100;
   sqlstm.sqhsts[28] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[28] = (         void  *)0;
   sqlstm.sqinds[28] = (         int  )0;
   sqlstm.sqharm[28] = (unsigned int  )0;
   sqlstm.sqadto[28] = (unsigned short )0;
   sqlstm.sqtdso[28] = (unsigned short )0;
   sqlstm.sqhstv[29] = (         void  *)&a->charged_units;
   sqlstm.sqhstl[29] = (unsigned int  )4;
   sqlstm.sqhsts[29] = (         int  )sizeof(struct db_cdr);
   sqlstm.sqindv[29] = (         void  *)0;
   sqlstm.sqinds[29] = (         int  )0;
   sqlstm.sqharm[29] = (unsigned int  )0;
   sqlstm.sqadto[29] = (unsigned short )0;
   sqlstm.sqtdso[29] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	
	/* EXEC SQL AT RATING COMMIT; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )923;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	delete a;
	
}



void network_groups::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct network_member 
	{ 
		char	network_id[BUF_LEN]; 
		char	net_group_id[BUF_LEN]; 
	} a, *nm_ptr; 
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	nm_ptr=&a;
	
	/* EXEC SQL  AT CUSTOMER_CARE DECLARE c_network_group CURSOR FOR 
		SELECT NETWORK_ID, GROUP_ID
		FROM R_network_members_V; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_network_group; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0016;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )944;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 
	
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_network_group INTO :nm_ptr; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )972;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)nm_ptr->network_id;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)nm_ptr->net_group_id;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		insert(nm_ptr->network_id, nm_ptr->net_group_id);
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_network_group; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1008;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<i<<" network members loaded."<<endl;
}



void celebration_discounts::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct celebration_discount 
	{ 
		char	discount_id[BUF_LEN];
		int 	account_no;
		float	t_operand;
		int 	t_operator;
		char	cele_date[BUF_LEN];
		char	start_date[BUF_LEN];
		char	end_date[BUF_LEN];
		char	rate_group_id[BUF_LEN]; 
	} a, *c_d_ptr; 
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	c_d_ptr=&a;
	
	/* EXEC SQL  AT CUSTOMER_CARE DECLARE c_celebration_discount CURSOR FOR 
		SELECT DISCOUNT_ID, ACCOUNT_NO,  OPERAND, OPERATOR, CELE_DATE, START_DATE,
		END_DATE, RATE_GROUP_ID
		FROM R_CELEBRATION_DISCOUNTS_V; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_celebration_discount; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0017;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1036;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 

	celebration_discount_key k;
	celebration_discount_data d;
	
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_celebration_discount INTO :c_d_ptr; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1064;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)c_d_ptr->discount_id;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&c_d_ptr->account_no;
  sqlstm.sqhstl[1] = (unsigned int  )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&c_d_ptr->t_operand;
  sqlstm.sqhstl[2] = (unsigned int  )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&c_d_ptr->t_operator;
  sqlstm.sqhstl[3] = (unsigned int  )4;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)c_d_ptr->cele_date;
  sqlstm.sqhstl[4] = (unsigned int  )100;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)c_d_ptr->start_date;
  sqlstm.sqhstl[5] = (unsigned int  )100;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)c_d_ptr->end_date;
  sqlstm.sqhstl[6] = (unsigned int  )100;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         void  *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)c_d_ptr->rate_group_id;
  sqlstm.sqhstl[7] = (unsigned int  )100;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         void  *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		
		k.account_no=c_d_ptr->account_no;
		k.cele_date.set_date(c_d_ptr->cele_date);
		
		d.discount_id=c_d_ptr->discount_id;
		d.dis_operand=c_d_ptr->t_operand;																																													
		d.dis_operator=(e_operator)c_d_ptr->t_operator;
		d.start_date.set_date(c_d_ptr->start_date);
		d.end_date.set_date(c_d_ptr->end_date);
		d.rate_group_id=c_d_ptr->rate_group_id; 
		
		insert(k,d);
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_celebration_discount; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1124;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<i<<" celebration discounts loaded."<<endl;
}


void cell_groups::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct route
	{ 
		int 	cell_id;
		char	route_group_id[BUF_LEN];
	} a[FETCH_SIZE];
	
	struct route_ind
	{ 
		short 	cell_id;
		short	route_group_id;
	} ind[FETCH_SIZE]; 
 
	int rows_to_fetch, rows_before, rows_this_time; 
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	rows_to_fetch = FETCH_SIZE; 	// number of rows in each "batch"  
	rows_before = 0;				// previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 
	
	
	/* EXEC SQL  AT CUSTOMER_CARE DECLARE c_routes CURSOR FOR 
		SELECT NVL(CELL_ID,0), NVL(ROUTE_GROUP_ID,'UNDEF')
		FROM R_ROUTES; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_routes; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0018;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1152;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	cell_group_key cgk;
	
	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL  AT CUSTOMER_CARE  FETCH c_routes INTO :a INDICATOR :ind; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1000;
  sqlstm.offset = (unsigned int  )1180;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&a->cell_id;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct route);
  sqlstm.sqindv[0] = (         void  *)&ind->cell_id;
  sqlstm.sqinds[0] = (         int  )sizeof(struct route_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqharc[0] = (unsigned int   *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->route_group_id;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct route);
  sqlstm.sqindv[1] = (         void  *)&ind->route_group_id;
  sqlstm.sqinds[1] = (         int  )sizeof(struct route_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqharc[1] = (unsigned int   *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		
		for (i=0; i<rows_this_time; i++) 
		{ 
			insert(a[i].route_group_id, a[i].cell_id);
		}
	} 
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_routes; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1216;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<rows_before<<" route groups loaded."<<endl;
}




void discount_numbers::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct discount_number 
	{ 
		char	discount_type_id[BUF_LEN];
		int		account_no;
		char	client_code[BUF_LEN];
		char	network_id[BUF_LEN];
		int		phone_number;
		char	rate_group_id[BUF_LEN]; 
		int		t_operator;
		float	t_operand;
		char	start_date[BUF_LEN];
		char	end_date[BUF_LEN];
	} a, *d_n_ptr; 
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	d_n_ptr=&a;
	
	/* EXEC SQL  AT CUSTOMER_CARE DECLARE c_discount_number CURSOR FOR 
		SELECT DISCOUNT_TYPE_ID, ACCOUNT_NO, CLIENT_CODE, NETWORK_ID, PHONE_NUMBER,
		RATE_GROUP_ID, OPERATOR, OPERAND,
		TO_CHAR(START_DATE,'YYYYMMDDHH24MISS'), 
		TO_CHAR(END_DATE,'YYYYMMDDHH24MISS')
		FROM R_DISCOUNT_NUMBERS_V; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_discount_number; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0019;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1244;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 
		
	discount_number_key k;
	discount_number_data d;
	
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_discount_number INTO :d_n_ptr; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1272;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)d_n_ptr->discount_type_id;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&d_n_ptr->account_no;
  sqlstm.sqhstl[1] = (unsigned int  )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)d_n_ptr->client_code;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)d_n_ptr->network_id;
  sqlstm.sqhstl[3] = (unsigned int  )100;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)&d_n_ptr->phone_number;
  sqlstm.sqhstl[4] = (unsigned int  )4;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)d_n_ptr->rate_group_id;
  sqlstm.sqhstl[5] = (unsigned int  )100;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)&d_n_ptr->t_operator;
  sqlstm.sqhstl[6] = (unsigned int  )4;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         void  *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)&d_n_ptr->t_operand;
  sqlstm.sqhstl[7] = (unsigned int  )4;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         void  *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)d_n_ptr->start_date;
  sqlstm.sqhstl[8] = (unsigned int  )100;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         void  *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)d_n_ptr->end_date;
  sqlstm.sqhstl[9] = (unsigned int  )100;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         void  *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		
		k.account_no=d_n_ptr->account_no;
		k.phone_number=d_n_ptr->phone_number;
		k.network_id=d_n_ptr->network_id; 
		
		d.discount_type_id=d_n_ptr->discount_type_id;
		d.client_code=d_n_ptr->client_code;
		d.rate_group_id=d_n_ptr->rate_group_id; 
		d.dis_operator=(e_operator)d_n_ptr->t_operator;
		d.dis_operand=d_n_ptr->t_operand;
		d.start_date=d_n_ptr->start_date;
		d.end_date=d_n_ptr->end_date;
		insert(k,d);
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_discount_number; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1340;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<i<<" discount numbers loaded."<<endl;
}




void group_discounts::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct group_discount 
	{ 
		char		orig_group_code[BUF_LEN];
		char		term_group_code[BUF_LEN];
		char		rate_group_id[BUF_LEN];
		int 		t_operator;
		float		t_operand;
	} a, *g_d_ptr; 
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	g_d_ptr=&a;
	
	/* EXEC SQL  AT CUSTOMER_CARE DECLARE c_group_discount CURSOR FOR 
		SELECT ORIG_GROUP_CODE, TERM_GROUP_CODE, RATE_GROUP_ID,
		OPERATOR, OPERAND 
		FROM R_group_discountS_V; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_group_discount; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0020;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1368;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 

	group_discount_key k;
	group_discount_data d;
	
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_group_discount INTO :g_d_ptr; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1396;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)g_d_ptr->orig_group_code;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)g_d_ptr->term_group_code;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)g_d_ptr->rate_group_id;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&g_d_ptr->t_operator;
  sqlstm.sqhstl[3] = (unsigned int  )4;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)&g_d_ptr->t_operand;
  sqlstm.sqhstl[4] = (unsigned int  )4;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


		
		k.orig_group=g_d_ptr->orig_group_code;
		k.term_group=g_d_ptr->term_group_code;
		
		d.rate_group_id=g_d_ptr->rate_group_id;
		d.dis_operand=g_d_ptr->t_operand;																																													
		d.dis_operator=(e_operator)g_d_ptr->t_operator;
		
		insert(k,d);
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_group_discount; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1444;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<i<<" group discount pairs loaded."<<endl;
}



void holiday_priorities::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct time_band 
	{ 
		char	holiday_date[BUF_LEN]; 
		char	day_id[BUF_LEN];
		int 	priority;
	} a, *hpp; 
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	hpp=&a;
	
	/* EXEC SQL  AT CUSTOMER_CARE DECLARE c_holiday_priority CURSOR FOR 
		SELECT HOLIDAY_DATE, DAY_ID, PRIORITY
		FROM r_holiday_priorities_v; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_holiday_priority; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0021;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1472;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 

	holiday_priority_key k;
	
	
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_holiday_priority INTO :hpp; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1500;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)hpp->holiday_date;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)hpp->day_id;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&hpp->priority;
  sqlstm.sqhstl[2] = (unsigned int  )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
		k.day_id=hpp->day_id;
		k.date.set_date(hpp->holiday_date);
		insert(k, hpp->priority);
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_holiday_priority; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1540;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<i<<" holiday priorities loaded."<<endl;
}


void package_services::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct package_service 
	{ 
		float	rental;
		char	service_code[BUF_LEN];
		char	package_code[BUF_LEN];
		char	rate_group_id[BUF_LEN];
	} a, *psp; 
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	
	psp=&a;
	
	/* EXEC SQL  AT CUSTOMER_CARE DECLARE c_package_service CURSOR FOR 
		SELECT RENTAL, SERVICE_CODE, PACKAGE_CODE,
		RATE_GROUP_ID
		FROM R_PACKAGE_SERVICES_V; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_package_service; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0022;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1568;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 

	package_services_key k;
	package_services_data d;
	
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_package_service INTO :psp; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1596;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&psp->rental;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)psp->service_code;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)psp->package_code;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)psp->rate_group_id;
  sqlstm.sqhstl[3] = (unsigned int  )100;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		
		k.package_code=psp->package_code;
		k.service_code=psp->service_code;
		
		d.rate_group_id=psp->rate_group_id;
		d.rental=psp->rental;
		insert(k,d);
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_package_service; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1640;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<i<<" package services loaded."<<endl;
}


void rate_groups::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct rate_group
	{ 
		char	rate_group_id[BUF_LEN]; 	// not null varchar2(5)
		char	re_rate_group_id[BUF_LEN];	// varchar2(5)
		int 	time_threshold; 			// not null number(3)
	} a, *rgp; 
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	rgp=&a;
	
	/* EXEC SQL  AT CUSTOMER_CARE DECLARE c_rate_group CURSOR FOR 
		SELECT	RATE_GROUP_ID, RE_RATE_GROUP_ID, TIME_THRESHOLD
		FROM R_RATE_GROUPS_V; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_rate_group; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0023;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1668;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 
	
	rate_group_data rgd;

	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_rate_group INTO :rgp; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1696;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)rgp->rate_group_id;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)rgp->re_rate_group_id;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&rgp->time_threshold;
  sqlstm.sqhstl[2] = (unsigned int  )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 

		rgd.re_rate_group_id = rgp->re_rate_group_id; 
		rgd.time_threshold = rgp->time_threshold; 
		
		insert(rgp->rate_group_id, rgd);
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_rate_group; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1736;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<i<<" rate groups loaded."<<endl;
}


void rates::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct rate 
	{ 
		char	rate_group_id[BUF_LEN];
		char	rate_id[BUF_LEN];
		int 	priority;
		char	default_rate[BUF_LEN];
		char	call_type_id[BUF_LEN];
		char	locale_id[BUF_LEN];
		char	day_id[BUF_LEN];
		char	route_group_id[BUF_LEN];
		char	net_group_id[BUF_LEN];
		char	service_type_id[BUF_LEN];
		char	time_band_group[BUF_LEN];
		char	time_band_type[BUF_LEN];
		char	time_block_id[BUF_LEN];
		char	discount_group_id[BUF_LEN];
		char	unit_rate_id[BUF_LEN];
		int 	unit_duration;
		float	cost_unit;
		int 	billable_duration;
		char	start_date[BUF_LEN];
		char	end_date[BUF_LEN];
		char	start_time[BUF_LEN];
		char	end_time[BUF_LEN];
		int 	call_duration;
	} a, *rp; 
	/* EXEC SQL END DECLARE SECTION; */ 

	
	int i;
	rp=&a;
	
	/* EXEC SQL  AT CUSTOMER_CARE DECLARE c_rate CURSOR FOR 
		SELECT	RATE_GROUP_ID, RATE_ID, PRIORITY,
		DEFAULT_RATE, CALL_TYPE_ID,
		LOCALE_ID, DAY_ID,
		ROUTE_GROUP_ID, NET_GROUP_ID,				
		SERVICE_TYPE_ID, TIME_BAND_GROUP,				
		TIME_BAND_TYPE, TIME_BLOCK_ID,				
		DISCOUNT_GROUP_ID, UNIT_RATE_ID,
		UNIT_DURATION, COST_UNIT, BILLABLE_DURATION,
		START_DATE,
		END_DATE,
		START_TIME,
		END_TIME,
		CALL_DURATION							 
		FROM R_RATE_RULE_V; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_rate; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0024;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1764;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 
	
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_rate INTO :rp; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1792;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)rp->rate_group_id;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)rp->rate_id;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&rp->priority;
  sqlstm.sqhstl[2] = (unsigned int  )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)rp->default_rate;
  sqlstm.sqhstl[3] = (unsigned int  )100;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)rp->call_type_id;
  sqlstm.sqhstl[4] = (unsigned int  )100;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)rp->locale_id;
  sqlstm.sqhstl[5] = (unsigned int  )100;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)rp->day_id;
  sqlstm.sqhstl[6] = (unsigned int  )100;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         void  *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)rp->route_group_id;
  sqlstm.sqhstl[7] = (unsigned int  )100;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         void  *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)rp->net_group_id;
  sqlstm.sqhstl[8] = (unsigned int  )100;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         void  *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)rp->service_type_id;
  sqlstm.sqhstl[9] = (unsigned int  )100;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         void  *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)rp->time_band_group;
  sqlstm.sqhstl[10] = (unsigned int  )100;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         void  *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (         void  *)rp->time_band_type;
  sqlstm.sqhstl[11] = (unsigned int  )100;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         void  *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned int  )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (         void  *)rp->time_block_id;
  sqlstm.sqhstl[12] = (unsigned int  )100;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         void  *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned int  )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (         void  *)rp->discount_group_id;
  sqlstm.sqhstl[13] = (unsigned int  )100;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         void  *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned int  )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (         void  *)rp->unit_rate_id;
  sqlstm.sqhstl[14] = (unsigned int  )100;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         void  *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned int  )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (         void  *)&rp->unit_duration;
  sqlstm.sqhstl[15] = (unsigned int  )4;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         void  *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned int  )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (         void  *)&rp->cost_unit;
  sqlstm.sqhstl[16] = (unsigned int  )4;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         void  *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned int  )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (         void  *)&rp->billable_duration;
  sqlstm.sqhstl[17] = (unsigned int  )4;
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         void  *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned int  )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (         void  *)rp->start_date;
  sqlstm.sqhstl[18] = (unsigned int  )100;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         void  *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned int  )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (         void  *)rp->end_date;
  sqlstm.sqhstl[19] = (unsigned int  )100;
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         void  *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned int  )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (         void  *)rp->start_time;
  sqlstm.sqhstl[20] = (unsigned int  )100;
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         void  *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned int  )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (         void  *)rp->end_time;
  sqlstm.sqhstl[21] = (unsigned int  )100;
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         void  *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned int  )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (         void  *)&rp->call_duration;
  sqlstm.sqhstl[22] = (unsigned int  )4;
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         void  *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned int  )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		
		rate_key rk;
		rk.rate_group_id=rp->rate_group_id;
		rk.call_type_id=rp->call_type_id; 
		rk.locale_id=rp->locale_id; 
		rk.service_type_id=rp->service_type_id; 
		
		rate_detail rd;
		rd.time_band_group=rp->time_band_group; 
		rd.unit_rate_id=rp->unit_rate_id; 
		rd.default_rate=rp->default_rate; 
		rd.rate_id=rp->rate_id; 
		rd.day_id=rp->day_id;
		rd.priority=rp->priority; 
		rd.route_group_id=rp->route_group_id;
		rd.net_group_id=rp->net_group_id;
		rd.time_band_type=rp->time_band_type;
		rd.time_block_id=rp->time_block_id;
		rd.discount_group_id=rp->discount_group_id;
		rd.unit_duration=rp->unit_duration;
		rd.unit_cost=rp->cost_unit;
		rd.billable_duration=rp->billable_duration;
		
		rd.start_date=rp->start_date; 
		rd.end_date=rp->end_date; 
		rd.active_period.start.set_time(rp->start_time);
		rd.active_period.end.set_time(rp->end_time);
		rd.call_duration=rp->call_duration;
		
		insert(rk,rd);
		
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_rate; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1912;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<i<<" rate rules loaded."<<endl;
}


void time_discount_bands::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct time_discount_band 
	{ 
		char	band_id[BUF_LEN];
		int 	start_second;
		int 	end_second;
		int 	t_operator;
		float	t_operand;
		char	time_discount_group_id[BUF_LEN]; 
	} a, *tdb_ptr; 
	
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	tdb_ptr=&a;
	
	/* EXEC SQL  AT CUSTOMER_CARE DECLARE c_time_discount_band CURSOR FOR 
		SELECT BAND_ID, START_SECOND, END_SECOND, OPERATOR, OPERAND, DISCOUNT_GROUP_ID
		FROM R_TIME_DISCOUNT_BANDS_V; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_time_discount_band; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0025;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1940;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 

	time_discount_band_data d;
	
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_time_discount_band INTO :tdb_ptr; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1968;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)tdb_ptr->band_id;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&tdb_ptr->start_second;
  sqlstm.sqhstl[1] = (unsigned int  )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&tdb_ptr->end_second;
  sqlstm.sqhstl[2] = (unsigned int  )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&tdb_ptr->t_operator;
  sqlstm.sqhstl[3] = (unsigned int  )4;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)&tdb_ptr->t_operand;
  sqlstm.sqhstl[4] = (unsigned int  )4;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)tdb_ptr->time_discount_group_id;
  sqlstm.sqhstl[5] = (unsigned int  )100;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		
		d.start_second	= tdb_ptr->start_second;
		d.end_second	= tdb_ptr->end_second;
		d.dis_operator	= (e_operator)tdb_ptr->t_operator;
		d.dis_operand	= tdb_ptr->t_operand;
		
		insert(tdb_ptr->time_discount_group_id,d);
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_time_discount_band; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2020;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<i<<" time discount bands loaded."<<endl;
}


void value_added_services::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct value_added_service
	{ 
		int 	account_no;
		char	service_code[BUF_LEN];
		char	rate_group_id[BUF_LEN];
		char	start_date[BUF_LEN];
		char	end_date[BUF_LEN];
	} a[FETCH_SIZE];

	struct value_added_service_ind
	{ 
		short 	account_no;
		short	service_code;
		short	rate_group_id;
		short	start_date;
		short	end_date;
	} ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time, i; 
	/* EXEC SQL END DECLARE SECTION; */ 

	
	rows_to_fetch = FETCH_SIZE; 	// number of rows in each "batch"  
	rows_before = 0;				// previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 
	
	
	//--RERATE
	/* EXEC SQL  AT CUSTOMER_CARE DECLARE c_value_added_service CURSOR FOR 
		SELECT ACCOUNT_NO, SERVICE_CODE, RATE_GROUP_ID,
		START_DATE, END_DATE
		FROM R_VALUE_ADDED_SERVICES_V; */ 
 
//--	FROM R_VALUE_ADDED_SERVICES_R_V; 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_value_added_service; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0026;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2048;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	value_added_services_key k;
	value_added_services_data d;
	
	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL  AT CUSTOMER_CARE  
		FETCH c_value_added_service INTO :a INDICATOR :ind; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1000;
  sqlstm.offset = (unsigned int  )2076;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )4;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct value_added_service);
  sqlstm.sqindv[0] = (         void  *)&ind->account_no;
  sqlstm.sqinds[0] = (         int  )sizeof(struct value_added_service_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqharc[0] = (unsigned int   *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->service_code;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct value_added_service);
  sqlstm.sqindv[1] = (         void  *)&ind->service_code;
  sqlstm.sqinds[1] = (         int  )sizeof(struct value_added_service_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqharc[1] = (unsigned int   *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->rate_group_id;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct value_added_service);
  sqlstm.sqindv[2] = (         void  *)&ind->rate_group_id;
  sqlstm.sqinds[2] = (         int  )sizeof(struct value_added_service_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqharc[2] = (unsigned int   *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->start_date;
  sqlstm.sqhstl[3] = (unsigned int  )100;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct value_added_service);
  sqlstm.sqindv[3] = (         void  *)&ind->start_date;
  sqlstm.sqinds[3] = (         int  )sizeof(struct value_added_service_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqharc[3] = (unsigned int   *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->end_date;
  sqlstm.sqhstl[4] = (unsigned int  )100;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct value_added_service);
  sqlstm.sqindv[4] = (         void  *)&ind->end_date;
  sqlstm.sqinds[4] = (         int  )sizeof(struct value_added_service_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqharc[4] = (unsigned int   *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		
		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		
		for (i=0; i<rows_this_time; i++) 
		{ 
			k.account_no=a[i].account_no;
			k.service_code=a[i].service_code;
			
			d.rate_group_id=a[i].rate_group_id;
			d.start_date.set_date(a[i].start_date);
			d.end_date.set_date(a[i].end_date);
			insert(k, d);
		}
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_value_added_service; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2124;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	cout<<setw(8)<<rows_before<<" value added services loaded."<<endl;
}



void roaming_networks::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct network 
	{ 
		char	mcc[BUF_LEN];
		char	mnc[BUF_LEN];
		char	rate_group_id[BUF_LEN];
	} a, *n_w; 
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	n_w = &a;
	
	/* EXEC SQL  AT CUSTOMER_CARE DECLARE c_roam_network CURSOR FOR 
		SELECT NVL(MCC,''), NVL(MNC,''), NVL(RATE_GROUP_ID,'')
		FROM GSM_NETWORKS; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_roam_network; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0027;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2152;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 
	
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_roam_network INTO :n_w; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2180;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)n_w->mcc;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)n_w->mnc;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)n_w->rate_group_id;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		insert(n_w->mcc, n_w->mnc, n_w->rate_group_id);
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_roam_network; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2220;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	cout<<setw(8)<<i<<" roaming networks loaded."<<endl;
}



void historic_package::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct h_package
	{ 
		char	package_code[BUF_LEN];
		int 	account_no;
		char	start[BUF_LEN];
		char	end[BUF_LEN];
	} a[FETCH_SIZE]; 

	struct h_package_ind
	{ 
		short	package_code;
		short 	account_no;
		short	start;
		short	end;
	} ind[FETCH_SIZE]; 

	int rows_to_fetch, rows_before, rows_this_time, i; 

	/* EXEC SQL END DECLARE SECTION; */ 

	
	rows_to_fetch = FETCH_SIZE; 	// number of rows in each "batch"  
	rows_before = 0;				// previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 
	
	// get all closed out records
	/* EXEC SQL  AT CUSTOMER_CARE DECLARE c_his_package CURSOR FOR 
		SELECT PACKAGE_CODE, ACCOUNT_NO, 
		TO_CHAR(START_DATE,'YYYYMMDDHH24MISS'), 
		TO_CHAR(END_DATE,'YYYYMMDDHH24MISS')
		FROM PACKAGE_HISTORY WHERE END_DATE IS NOT NULL; */ 
 
	
	/* EXEC SQL AT CUSTOMER_CARE OPEN  c_his_package; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0028;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2248;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	historic_package_key k;
	historic_package_data d;
	
	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL  AT CUSTOMER_CARE  FETCH c_his_package INTO :a INDICATOR :ind; */ 

{
  struct sqlexd sqlstm;

  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1000;
  sqlstm.offset = (unsigned int  )2276;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (         void  *)a->package_code;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct h_package);
  sqlstm.sqindv[0] = (         void  *)&ind->package_code;
  sqlstm.sqinds[0] = (         int  )sizeof(struct h_package_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqharc[0] = (unsigned int   *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->account_no;
  sqlstm.sqhstl[1] = (unsigned int  )4;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct h_package);
  sqlstm.sqindv[1] = (         void  *)&ind->account_no;
  sqlstm.sqinds[1] = (         int  )sizeof(struct h_package_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqharc[1] = (unsigned int   *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->start;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct h_package);
  sqlstm.sqindv[2] = (         void  *)&ind->start;
  sqlstm.sqinds[2] = (         int  )sizeof(struct h_package_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqharc[2] = (unsigned int   *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->end;
  sqlstm.sqhstl[3] = (unsigned int  )100;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct h_package);
  sqlstm.sqindv[3] = (         void  *)&ind->end;
  sqlstm.sqinds[3] = (         int  )sizeof(struct h_package_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqharc[3] = (unsigned int   *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		
		for (i=0; i<rows_this_time; i++) 
		{
			k.account_no=a[i].account_no;
			d.start=a[i].start;
			d.end = a[i].end;
			d.package_code=a[i].package_code;
			insert(k,d);
		}
	} 
	
	/* EXEC SQL  AT CUSTOMER_CARE CLOSE c_his_package; */ 

{
 struct sqlexd sqlstm;

 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2320;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 

	cout<<setw(8)<<i<<" historic packages loaded."<<endl;
}

