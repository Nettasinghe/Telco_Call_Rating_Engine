

//////////////////////////////////////////////////////////////////////
//
// discount_expression.cpp: 
//			implementation of the discount_expression class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"

bool discount_expression::compute(float x, float & result)
{
	bool valid=true;

	switch(dis_operator)
	{
		case O_PLUS:	result = x+dis_operand; break;
		case O_MINUS:	result = x-dis_operand; break;
		case O_DIV:
			{
				if(dis_operand != 0)
					result = x / dis_operand; 
				else
				{
					result = x;
					valid=false;
					cout<<"discount_expression::compute zero divide"<<endl;
				}
				break;
			}
		case O_MUL:		result = x*dis_operand; break;
		case O_ASSIGN:	result = dis_operand; break;	
		case O_AT:		result = dis_operand; break;
		case O_UNDEF:	result = x; valid=false; break;		

		default:
			{
			cout<<"discount expression::compute un handled conversion {"<<dis_operator<<"}"<<endl;
			valid=false;
			}
	}
	return valid;
}


ostream& operator<<(ostream& out, e_operator x)
{
	string a;
	switch(x)
	{
	case O_PLUS:	a	=	"+";	break;
	case O_MINUS:	a	=	"-";	break;
	case O_DIV:		a	=	"/";	break;
	case O_MUL:		a	=	"*";	break;
	case O_ASSIGN:	a	=	"=";	break;	
	case O_AT:		a	=	"@";	break;
	case O_UNDEF:	a	=	"#";	break;		

	default:
		{
			a="?";
		}
		cout<<"ERR: discount no conversion defined"<<endl;
	}
	
	out<<a;
    return(out);
}



