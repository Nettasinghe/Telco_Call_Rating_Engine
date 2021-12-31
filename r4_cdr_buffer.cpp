

//////////////////////////////////////////////////////////////////////
//
// r4_cdr_buffer.cpp :
//				implementation of the r4_cdr_buffer class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "r4_cdr.h"
#include "defines.h"


extern cdr_rejects *gsm_cdr_rejects;

// from 5 th byte in CDR
//#define FF_OFFSET 4		  // 4 bytes from start of cdr to 0xff
#define CDR_VERSION 0x04
#define FIXED_LENGTH_PORTION_SIZE 23

unsigned char bcd_to_int(unsigned char a)
{
	return ((unsigned char) ((((a & 0xf0)>>4)*10) + (a & 0x0f)));
}


// open a vaild file pointer and collects a bit of statistics as well
bool r4_cdr_buffer::read_cdr_file(FILE *fp, cdr_file_statistics *s)
{
	bool found = false;
	// read_cdr_file();
	bytes_read = fread(buffer, sizeof(unsigned char), buffer_size, fp);
	statistics = s;
	statistics->bytes_read = bytes_read;

	if(bytes_read == 0)
	{
		return false;
	}
	else if (bytes_read == buffer_size)
	{
		cout<<"<ERROR> possible cdr buffer overflow "<<bytes_read<<endl;
		return false;
		//exit(1);
	}

	data_end = buffer + bytes_read;
	current =  buffer;
	cdr_length=0;	// start of cdr
	//FLAG

	return found; // all data files read
}


void r4_cdr_buffer::init()
{
	bytes_read		= 0;
	current			= buffer;
	data_end		= buffer;
	cdr_length		= 0;
	cdr_count		= 0;
	cdr_position	= 0;				// location of cdr from start of file

// inialise buffer area, useful for debugging only
//	for(unsigned char* a=buffer; a<end_of_buffer; a++)
//		*a=0x00;
}


// object lives for lifetime of program
r4_cdr_buffer::r4_cdr_buffer(int size)
{
	buffer_size = size;
	buffer = new unsigned char[buffer_size];
	if (!buffer)
	{
		cout<<"ERR: FATAL cant allocate "<<buffer_size/1024<<" KB  for CDR buffer"<<endl;
		exit(1);
	}

	end_of_buffer = buffer+buffer_size;
	init();
}

class cdr_tm
{
public:
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
	
	bool check_from_year();
	bool check_from_month();
};


bool cdr_tm::check_from_month()
{
	bool valid = true;
	if ( !(month >=1 && month <= 12))
		valid = false;
	else if ( !(day >=1 && day <= 31))
		valid = false;
	else if (!(hour >= 0 && hour <= 23))
		valid = false;
	else if (!(min >=0 && min <= 59 ))
		valid = false;
	else if (!(sec >= 0 && sec <= 59))
		valid = false;
	
	return valid;
}


bool cdr_tm::check_from_year()
{
	bool valid=check_from_month();

	if (!(year >= 0 && year <= 99))
		valid = false;
	
	return valid;
}


// see ALCATEL document 
// Feature specification ALCATEL 1300 specific applications, call related data format
// #32931STD.CEA-29/10/97
// for R3 CDR format specification
// search for start signature

// find start of vaild cdr in buffer for subsequnet decode
bool r4_cdr_buffer::get_cdr_start()
{
	// The cdr start signature (*=don't care nibble, x is hex)
	// length is two bytes
	//     0x**    0x04       <- signature value
	//		0		1		  <- location in array
	//			   -3		  = current and offsets from current
	// cdr length is in (byte0 byte2)  byte 1 is not used, due to compatibility issues
	
	unsigned char *b_ptr, *start_of_cdr;		// buffer pointer
	
	unsigned char record_length;
	if(cdr_length ==0)							// for first time entry to loop
		b_ptr = current + SIGNATURE_OFFSET - 1;	// max look back is 3 subtract 1 for auto increment (b_ptr++)
	else										// as you enter the while loop 
		b_ptr = current + cdr_length;
	
	cdr_tm circuit, call;
	
	do {
		b_ptr++;
		
		if(*b_ptr != CDR_VERSION)		// move along till CDR_VERSION is found
			continue;
		
		// sanity of length must be greater than fixed portion of
		// 22 bytes, typically 44 to 77 bytes
		record_length=*(b_ptr+1)*256 + *(b_ptr-1)+2; // +2 adj for length of cdr
		if (record_length < FIXED_LENGTH_PORTION_SIZE)
			continue;
		
		start_of_cdr = b_ptr - SIGNATURE_OFFSET;
		if(data_end >= start_of_cdr + record_length) // data end is end of buffer.
		{
			// circuit allocation time stamp
			circuit.year	= bcd_to_int( *(start_of_cdr+cdr_start_of_circuit_allocation_time_stamp));
			circuit.month	= bcd_to_int( *(start_of_cdr+cdr_start_of_circuit_allocation_time_stamp+1));
			circuit.day		= bcd_to_int( *(start_of_cdr+cdr_start_of_circuit_allocation_time_stamp+2));
			circuit.hour	= bcd_to_int( *(start_of_cdr+cdr_start_of_circuit_allocation_time_stamp+3));
			circuit.min		= bcd_to_int( *(start_of_cdr+cdr_start_of_circuit_allocation_time_stamp+4));
			circuit.sec		= bcd_to_int( *(start_of_cdr+cdr_start_of_circuit_allocation_time_stamp+5));
			
			if (!circuit.check_from_year())
				continue;
			
			// call time stamp
			call.month	= bcd_to_int( *(start_of_cdr+cdr_start_of_call_time_stamp));
			call.day	= bcd_to_int( *(start_of_cdr+cdr_start_of_call_time_stamp+1));
			call.hour	= bcd_to_int( *(start_of_cdr+cdr_start_of_call_time_stamp+2));
			call.min	= bcd_to_int( *(start_of_cdr+cdr_start_of_call_time_stamp+3));
			call.sec	= bcd_to_int( *(start_of_cdr+cdr_start_of_call_time_stamp+4));
			
			if (!call.check_from_month())
				continue;
		}
		else
		{
			// cdr has exceed file end
			cout<<"WARN ------------PARTIAL CDR AT END OF FILE----------"<<endl;
			statistics->reject_cdr_count++;
			continue;
		}
		
		//	all dates seem to pass initial sanity check
		current		= start_of_cdr;
		cdr_length	= record_length;//+2;		// are we missing a two here ?
		cdr_count++;
		statistics->valid_cdr_count++;
		cdr_position = start_of_cdr - buffer;	// the cdr loaction in bytes from start of file
#ifdef RE_RATE
		if(gsm_cdr_rejects->is_reject(statistics->file_id, cdr_position))
#endif
		{
			return true;  // cdr start signature found
		}
	}while (b_ptr < data_end);
	return false;
}


// current must be at start of cdr 
// or else premature exit
void r4_cdr_buffer::print_cdr_in_hex()
{
	int k=0;
	
	for(unsigned char *i=current; i<current+cdr_length; i++)
	{
		if(i > data_end)
		{
			printf(" ERR: Out of vaild data sequence ");
			return;
		}
		if (!(k%8))
			printf("   ");
		if (!(k%16))
			printf("\n %04x  ",i-buffer);
		printf(" %02x",(int)(*i));
		k++;
	}
	printf("\n");
}

int r4_cdr_buffer::get_cdr_position()
{
	return cdr_position;
}

