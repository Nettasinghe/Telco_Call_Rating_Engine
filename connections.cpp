

//////////////////////////////////////////////////////////////////////
//
// connections.cpp : 
//			implementation of the connections class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"

extern	historic_imsi		*gsm_historic_imsi;
extern	historic_package		*gsm_historic_package;

// keep two associations
//	a) imsi
//	b) phone number
void connections::insert(string imsi, connection_detail &a)
{
	connection_key c_k;
	c_k = imsi; // no copy constructor

	pair<CONNECTION_DEF::iterator, bool> p=conn.insert(make_pair(c_k,a));
	if (p.second == false)
	{
		cout<<"ERR: Duplicate imsi "<<imsi<<endl;
	}

	// inter group discounting
	pair<PHONE_NO_TO_GRP_DEF::iterator, bool> q=ph_to_grp.insert(make_pair(a.phone_no, a.group_code));
	if (q.second == false)
	{
		cout<<"ERR: Duplicate phone no "<<a.phone_no<<endl;
	}

	// call partner phone imisi inter tie
	pair<PHONE_NO_TO_IMSI_DEF::iterator, bool> r=ph_to_imsi.insert(make_pair(a.phone_no, imsi));
	if (r.second == false)
	{
		;
		//cout<<"ERR: Duplicate phone no "<<a.phone_no<<endl;  // duplicate condition
	}


	pair<ACC_NO_TO_IMSI_DEF::iterator, bool> s=ac_to_imsi.insert(make_pair(a.account_no, imsi));
	if (s.second == false)
	{
		cout<<"ERR: Duplicate account no "<<a.account_no<<endl;  // duplicate condition
	}
}

// set all connection details of client given key
// Does the historic client look up via the imsi (sim) change history table for clients who 
// may have changed their sim numbers. (valid only for 3 months). and clients who may have changed
// their packages
//	a) check if in imsi history for imsi assignment at call time get account no.
//		1) imsi, call_time -> account_no
//  b) from account number map do two stage look up and get client details.
//		1) account_no -> cuurent_imsi.
//		2) cuuurent_imsi -> conection_detail.
//  c) get the correct package applicable to the account at the time of call.
//		1) call_time, ac_no -> package.
bool connections::get_client(connection_key c_k, connection_detail &a, string call_time)
{
	CONNECTION_DEF::iterator i;
	i=conn.find(c_k);

	if( i != conn.end())
	{
		a = (*i).second;
	}
	else
	{
		// account not found
		return false;
	}

#ifdef HISTORIC
	// try to find account no from historic imsi records
	int account_no;
	if(gsm_historic_imsi->get_account_no(c_k.imsi_no, call_time, account_no))
	{
		ACC_NO_TO_IMSI_DEF::iterator j;
		// connections use imsi as key hence, from current account_no need to get current imsi to
		// locate record in connections.
		j = ac_to_imsi.find(account_no);
		if(j != ac_to_imsi.end())  
		{
			// find connection details with new imsi
			c_k.imsi_no = (*j).second;
			i = conn.find(c_k);
			if(i != conn.end() )
			{
				a = (*i).second;
			}
			else
			{
				cout<<"ERR: Cant find connection for imsi in historic imsi find "<<c_k.imsi_no<<endl;
				return false;
			}
		}
		else // dud account
		{
			cout<<"ERR: Cant find current imsi for account "<<account_no<<endl;
			return false;
		}
	}
#endif


#ifdef HISTORIC
	string package_code;
	// Get the correct package for the account_no
	if(gsm_historic_package->get_package(a.account_no, call_time, package_code))
	{
		a.package_code=package_code;
	}
#endif
		return true;
}



// given a phone number get the group id
bool connections::get_group(int ph_no, string &grp)
{
	PHONE_NO_TO_GRP_DEF::iterator i;
	i=ph_to_grp.find(ph_no);
	
	bool found;
	found = (i != ph_to_grp.end());

	if(found)
		grp=(*i).second;
	return found;
}


// does the call partner belong to the same group as the caller
// for inter group discounting
bool connections::set_call_partner_group(rated_cdr &rated_cdr)
{
	// if same group get group id
	//		1) get imsi from phone no
	//		2) using imsi get group & rate plan fro group discount

	string call_partner_group;

	PHONE_NO_TO_IMSI_DEF::iterator i;
	i = ph_to_imsi.find(atoi(rated_cdr.call_partner_telephone_no.c_str()));
	
	bool found=false;
	found = (i != ph_to_imsi.end());

	// Get the call partner phone details
	if(found)
	{
		connection_key c_k;
		c_k = (*i).second; // imsi no copy constructor

		CONNECTION_DEF::iterator j;
		j = conn.find(c_k);
		
		found = (j != conn.end());

		if (found)
		{
			connection_detail c_d = (*j).second;

			// use the group discount call partner rate group
			if(	c_d.group_code != WILD_CARD && 
				rated_cdr.connection_d.group_code == c_d.group_code &&
				rated_cdr.call_partner_network_id == "077") // dialog HACK TODO (bell, telecom may have same number)
			{
				// clunky assignment re-write
				rated_cdr.group_discount_rate_plan_id = rated_cdr.connection_d.group_rate_plan_id;
				return found;
			}
		}
	}

	// not in same group so try inter group discounts

	return(get_group(atoi(rated_cdr.call_partner_telephone_no.c_str()), rated_cdr.call_partner_group));
}


void connections::print()
{
	for(CONNECTION_DEF::iterator i=conn.begin(); i!=conn.end(); i++)
		cout<<"{"<<(*i).first<<"} {"<<(*i).second<<"}"<<endl;
}


bool connections::set_detail(rated_cdr *cdr)
{
	connection_detail cd;
	connection_key ck;
	ck = cdr->mobile_subscriber_identity;

	if (get_client(ck, cdr->connection_d, cdr->circuit_allocation_time_stamp))
	{
		cdr->imsi_found=true;
	}
	else
		cdr->imsi_found = false;
	
	return cdr->imsi_found;
}


// ccbs clients ( > 100000) && roaming
bool connections::is_new_client(string imsi)
{
	CONNECTION_DEF::iterator i;

	connection_key c_k;
	connection_detail a;

	c_k = imsi;

	i=conn.find(c_k);
	
	if(i != conn.end())
	{
		a = (*i).second;
//		if(a.account_no >= 100000 || a.account_no == 999999)
		if(a.account_no < 300 )
		{
			//cout<<" "<<a.account_no<<endl;
			return true;
		}
		else
			return false;
	}
	return false;
}


void connection_detail::init()
{
	account_no = 0;
	client_code = "";
	phone_no = 0;
	imei_no = ""; 
	sim_no = ""; 
	group_code = ""; 
	package_code = "";
	gross_charge_for_run = 0;
	group_rate_plan_id = WILD_CARD;
}


ostream& operator<<(ostream& out, connection_detail x)
{
    out<<x.account_no<<", "<<x.client_code<<", "<<x.phone_no<<", "<<
		x.imei_no<<", "<<x.sim_no<<", "<<x.group_code<<", "<<
		x.package_code<<", "<<x.gross_charge_for_run<<", "<<x.group_rate_plan_id;
    return(out);
}


ostream& operator<<(ostream& out, connection_key x)
{
    out<<x.imsi_no;
    return(out);
}

// total as encountered all charges for risk management
bool connections::add_gross_call_charge(connection_key k, float call_charge)
{
	CONNECTION_DEF::iterator i;

	i = conn.find(k);
	
	bool found;
	found = (i != conn.end());

	if(found)
	{
		(*i).second.gross_charge_for_run += call_charge;
	}

	return found;
}


bool connection_key::operator < (const connection_key &s) const
{
	if(imsi_no < s.imsi_no)
		return true;
	return false;
}


inline connection_key& connection_key::operator = (const string &s)
{
	imsi_no = s;
	return *this;
}

