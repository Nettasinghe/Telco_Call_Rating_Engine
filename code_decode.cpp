

//////////////////////////////////////////////////////////////////////
//
// code_decode.cpp : 
//			implementation of the cdr decoding functions.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"



char* decode_type_msc(int tmsc)
{
	char *m;
	switch(tmsc)
	{
	case 0x0: m="MSC"; break;
	case 0x1: m="GMSC"; break;
	case 0x3: m="IWGMSC"; break;
	default:  m="UNDEF";
	}
	return m;
}

		
char* decode_type_of_call(int toc)
{
	char *m;
	switch(toc)
	{
	case 0x00:	m = "ORIGIN"; break;
	case 0x01:	m = "TERMI"; break;
	case 0x02:	m = "MSC_FOR"; break;
	case 0x04:	m = "REROU_TER"; break;
	case 0x05:	m = "REROU_FOR"; break;
//	case 0x06:	m = "GMSC_FOR_TER"; break;
	case 0x06:	m = "GMSC_F_TER"; break;
	case 0x0d:	m = "HOT_ORIGIN"; break;
	case 0x0e:	m = "HOT_TERMI"; break;
//	case 0x0f:	m = "GMSC_HOT_TERMI"; break;
	case 0x0f:	m = "GMSC_H_T"; break;  //original
	default:	m = "UNDEF";
	}
	return m;
}


char* decode_call_termination_type(int ctt)
{
	char *m;
	switch(ctt) 
	{ 
		case 0x00:	m="NORMAL"; break;
		case 0x01:	m="NET_FAIL"; break;
		case 0x03:	m="SYS_FAIL"; break;
		case 0x04:	m="RADIO_FAIL"; break;
		case 0x05:	m="HANDOVR_FAIL"; break;
		case 0x06:	m="BLACK_IMEI"; break;
		case 0x07:	m="DURA_OVER"; break;
		default:	m="UNDEF";
	}
	return m;
}

char* decode_origin_of_call_indicator(int ooci)
{
	char* m;
	switch(ooci)  
	{  
		case 0x00:	m="NATIONAL";		break;
		case 0x01:	m="INTERNATIO";		break; // note missing N
		case 0x02:	m="MAN_NATION";		break;
		case 0x03:	m="MAN_INTER";		break;
		case 0x0f:	m="NOT_APPLIC";		break;
		default:	m="UNDEF";
	}
	return m;
}

char* decode_charging_indicator(int ci)
{
	char* m;
	switch(ci)  
	{  
		case 0x00:	m="NO_INDICATION"; break;
		case 0x01:	m="CHARGE"; break;
		case 0x02:	m="NO_CHARGE"; break;
		case 0x0f:	m="NOT_APPLIC"; break;
		default:	m="UNDEF";
	}
	return m;
}


char* decode_required_tele_service(int rts)
{
	char *m;
	switch(rts)  
	{  
	case 0x11:	m="TELEPHONY";	break;
	case 0x12:	m="EMERGENCY";	break;
	case 0x21:	m="SMS_MT";		break;
	case 0x22:	m="SMS_MO";		break;
	case 0x61:	m="FAX";		break;
	case 0x62:	m ="AUTO_FAX";	break;
	case 0x77:  m ="VOICE_MAIL"; break; // added
	case 0xff:	m ="NOT_USED";	break;
	default:	m = "UNDEF";
	}
	return m;
}

	
char* decode_required_bearer_service(int rbs)
{	
	char *m;
	switch(rbs)
	{
	case 0xff: m="NOT_APPLIC"; break;
	case 0x11: m="BS21_300";  break;
	case 0x12: m="BS22_1200"; break;
	case 0x14: m="BS24_2400"; break;
	case 0x15: m="BS25_4800"; break;
	case 0x16: m="BS26_9600"; break;
	case 0x1a: m="BS31_1200"; break;
	case 0x1c: m="BS32_2400"; break;
	case 0x1d: m="BS33_4800"; break;
	case 0x1e: m="BS34_9600"; break;
	default: m = "UNDEF";
	}
	return m;
}

char* decode_required_bearer_capability(int rbc)
{
	char *m;
	switch(rbc)
	{
	case 0x00: m="FR_TCH"; break;
	case 0x02: m="FR_TCH_P_A";  break;
	case 0x80: m="FR_TCH_HR"; break;
	default: m = "UNDEF";
	}
	return m;
}


