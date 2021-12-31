
/*
Any note worthy changes with warts and all.

27-dec-1999 ver 1.0.07
1)	time granularity not working fixed.
2)	call partner for international calls 4 digits made 
	to approriate variable length fixed. 
3)	msc location identity field populated.
4)	array insert failed with call partner network id over flowing varchar 2 field
	temp fix for local call is to substring to 4 char (Redo ajit).

28-dec-1999 ver 1.0.08
1)	time discounts fixed by removing discount > original cost check.
2)	time granulrity re-visted variables renamed.

30-dec-1999	ver 1.0.09
1)	call partner identification re written with look up for both
	local and foreign caller networks, telephone numbers now can be 
	variable lengths.
2)	guards on strings to prevent value too large error on database inserts.

30-dec-1999	ver 1.0.10
1)	case where call partner is not found retunn "NODG" to 
	match a genral rule. check implication where call 
	partners are not present on international calls.

30-dec-1999	ver 1.0.11
1)	voice mail decode to decoded_service_type="VM"

31-dec-1999	ver 1.0.12
1)	time bands map and load up moved to rates with 
	introduction of new view R_RATE_RULE_V. 
	Makes things a bit tighter.

04-feb-2000	ver 1.0.13
1)	array reads for client and rate information. performance boosted
	for perodic restart mode of operations.

06-feb-2000	ver 1.0.14
1)	array insert for last record less than array size bug fixed to avoid
	duplicate cdr data.

10-feb-2000	ver 1.0.15
1)	Out of scope variable gives bad values for "VOICE MAIL". 
	made all relevant variables declrations within block  
	to avoid scope problems in future

11-feb-2000	ver 1.0.16
1)	medation buffer class simplified from a two stage ring bufer to linear buffer, 
	number of buffer management code lines shrink by 70% at the 
	expense of a higher initial memory requirement
2)	location of cdr in bytes from start of file put in.

15-feb-2000	ver 1.0.17
1)	All data base read ups made class methods ::db_read() a long delayed mop up
2)	cdr file list read from inventroy table with updates to it on rate cdr count etc

16-feb-2000	ver 1.0.18
1)	bcd and tbcd conversion methods re written to increase error checking as the
	fillers are allways not '0xf' as specified in the ALCATEL EB10 switch doc's.

17-feb-2000	ver 1.0.19
1)	rated cdr table format changed for higher information density. most
	fields are codefied as per "gsm" guidelines.

18-feb-2000	ver 1.0.20
1)	decoded cell id and lac in anticipation of cell based rateing.

20-feb-2000	ver 1.0.21
1)	time threshold introduced to rate group from system wide parameter.
2)	replaced rule level re-rate rule with group level re rate group for 
	easy maintennance.
3)	rate_group class introduced to handle time thresholds and re rating.

21-feb-2000	ver 1.0.22
1)	process mangement introduced for UNIX version. (Chaminda)

22-feb-2000	ver 1.0.23
1)	bad imei decode fixed last character over-run. how did this go uncaught for
	long ??
2)	for IDD local unit cost is added to bill.
3)	deleted match by rule id function.
4)	profile run says string memory alloc takes a lot of time

24-feb-2000 ver 1.0.24
1)	generate new cdr for termination types 6 and 2. post 

26-feb-2000 ver 1.0.25
1)	introduce AIRR and AIRA service types for un-limited , and zone limited roaming, IDD reorg

01-mar-2000 ver 1.0.26
1)	new roaming types given local air time component.

02-mar-2000 ver 1.0.27
1)	new origin of call indicator decode.

03-mar-2000 ver 1.0.28
1)	re-routed terminated international calls, re-issue idd cdr.

04-mar-2000 ver 1.0.29
1)	re-routed terminated international calls, re-issue local terminating cdr.
	note now 2 cdrs issued for incomming cdr.

06-mar-2000 ver 1.0.30
1)	cell based rating inluded.

10-mar-2000 ver 1.0.31
1)	risk management for credit limit exhaustion (thivanka@gsm).

12-mar-2000 ver 1.0.32
1)	dual data base support for customer care and cdr data, to solve stall during
	cdr inserts.

17-mar-2000 ver 1.0.33
1)	re-write risk management to handle gross revenue.
2)	introduce threshold.
3)	introduce concept of risk percentage (requested by lalith@gsm)

20-mar-2000 ver 1.0.34
1)	write account number bases gross totals to un billed charge table.

26-mar-2000 ver 1.0.35
1)	Bearer capability full decode
2)	Granularity for first unit only.

29-mar-2000 ver 1.0.36
1)	stack exhaustion overcome by reducing fetch size to 10 records.

30-mar-2000 ver 1.0.37
1)	cell based rating wild card match rationalised.

02-apr-2000 ver 1.0.38
1)	same discount group with different call partner rate plans.

04-apr-2000 ver 1.0.39
1)	carry over group discount setting bug in generated cdr's fixed.

06-apr-2000 ver 1.0.40
1)	group discount to pick same side rate rule.

16-apr-2000 ver 1.0.41
1)	cdr table paritioned.

21-apr-2000 ver 1.0.42
1)	fixed rate numbers added.
2)	voice mail cdr generation added.

24-apr-2000 ver 1.0.43
1)	all time approximations changed from unit duration to block duration.
	to support pre paid.

25-apr-2000 ver 1.0.44
1)	rate rules to support call duration dimension.
2)  rule scoring changed for added variable.

26-apr-2000 ver 1.0.45
1)	local charge from package for IDD calls

27-apr-2000 ver 1.0.46
1)	rate rule score method changed from two numbers, to set of priority variables
		a.	day_type
		b.	network_group
		c.	cell_group
		e.	duration

28-apr-2000 ver 1.0.47
1)	cdr file locations and dabase logon passwords moved to a seperate file.

02-may-2000 ver 1.0.48
1)	Voice mail number substring 3 removed.
2)	ms_location bad assignment for generated calls fixed.
3)	fax_g3 speech decode added.

03-may-2000 ver 1.0.49
1)	roaming networks to have indivdual rate plans.

05-may-2000 ver 1.0.50
1)	networks can belong to multiple groups.
2)	-1 gost network introduced to catch no call partner calls to refer "non dialog" group.

06-may-2000 ver 1.0.51
1)	clean up rate rule insert code.

07-may-2000 ver 1.0.52
1)	ghost call partner made char, was int a static check warning was ignored here.

08-may-2000 ver 1.0.53
1)	locale 0xf handler for national calls.

09-may-2000 ver 1.0.54
1)	sms to handle mobile originated, terminated or both seperately.
2)  Roaming customers can roam withoutout IDD.

10-may-2000 ver 1.0.55
1)	masked extention to cater for not 0xa1 and 0x91 cases now will be 0xa0 and 0x90.
	20 call records rejected per day due to this.

17-may-2000 ver 1.0.56
1)	strip leading 77 from phone numbers.

18-may-2000 ver 1.0.57
1)	duplicate 77 striping bug that broke bulk discousnts fixed.

16-jun-2000 ver 1.0.58
1)	zero rated call's dont log.
2)  > 100K A/C# filter.
3)  R_RATED_CDR5 new table for testing.

20-jun-2000 ver 1.0.59
1) zero rated cdrs into roaming. (Balans requires for accounting).

29-jun-2000 ver 1.0.60
1) historic imsi look up for change history tracking.

04-jul-2000 ver 1.0.61
1) instrumented for bug chase of missing re-routed call's

07-jul-2000 ver 1.0.62
1) bug for missing Reouted call's fixed was in zero rate reject code

10-jul-2000 ver 1.0.63 - 1.0.66
1) historic imsi lookup check bug chase
2) bug of missing RRI call's found in new client filter

12-jul-2000 ver 1.0.67
1) charging indicator added

13-jul-2000 ver 1.0.68
1) Forward decode for international fixed
2) Roam added to filter

14-jul-2000 ver 1.0.69 - 70
1) zero charge incative of call > 90 secs
2) Roam added to filter

14-jul-2000 ver 1.0.71
1) sms mo, mt bug fixed
2) emergency calls free

15-jul-2000 ver 1.0.72
1) year check in cdr decode buffer  removed

18-jul-2000 ver 1.0.73
1) array insert size reduced from 100 to 10

19-jul-2000 ver 1.0.74
1) array insert bug of value too large for col but no error message fixed

20-jul-2000 ver 1.0.75
1) run tickets to prevent multiple instances
2) no file found execption handler fixed, a pointer to pointer issue **fp

25-jul-2000 ver 1.0.76, 77
1) look up for previous imsi

13-aug-2000 ver 1.0.78
1) rejected calls re - rate capability with a few has defines

14-aug-2000 ver 1.0.79
1) bug on read up of cdr's from wrong data base fixed

15-sep-2000 ver 1.0.80
1) re-rating made easy by additional view support

30-sep-2000 ver 1.0.81
1) call type support for fixed rate numbers

25-oct-2000 ver 1.0.82
1) all pro*C made to one file for better error reporting

12-nov-2000 ver 1.0.83
1) look up historic package codes

14-jan-2001 ver 1.0.86
1) value added services load up to discard disconnected services

31-may-2001 ver 1.0.87
1) link information field added for inbound TAP3 support.

value added sevices from new view for value added servecs

04-oct-2001 ver 1.0.88
1) Debug discount numbers.

17-dec-2001 ver 1.0.89
1) Discount number history added

--------------------------------- CDR format R4 --------------------
03-mar-2002	 4.0.0	For dialog to validate
1) Accepts R4 CDRs
2) All updates done till ver 1.0.89 on R3 rate engine incorported

27-apr-2002 4.0.1
a) Charged units added
b) cdr table has new field

Outsatnding bug's
CDR over run error is reported at time's were it should not be.

15-jul-2002 4.0.2 - chandika
1) Accomodated changes for phone number change to 10 digits

15-dec-2002 4.0.3 - chandika
1) Accomodated changes for rating and additional cdr generation for Optimal Routing Calls

11-feb-2003 4.0.4 - chandika
1) Removed Local Air Charge from IDD calls

20-feb-2003 4.0.5 - chandika
1) Further changes to OR calls processing - appended "9477" to call partner


*/




