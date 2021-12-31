# ------------------------------------------------------------------------------
# Copyright 1999 Millennium IT Software
# GNUmakefile 1.0.51 
# Rate Eng 
# ------------------------------------------------------------------------------
#
# rate engine: a  C++ application with Rv 4.X, STL & Oracle8i PRO*C calls.
#

#include env_rdbms.mk # Local file copied from ORACLE_HOME/rdbms/lib

# COMPILE TIME PARAS.
# -------------------
ANSIFLAG	=   -ansi 				# For ANSI C programs.
DEBUGFLAG 	=   -ggdb 				# Specific to GDB on Solaris.
INHIBWRN  	=   -w
CHARWRN  	=   -Wchar-subscripts
FORMATWRN	=   -Wformat
NOTYPWRN 	=   -Wimplicit-int
FULLWARN 	=   -Wall
GCOVFLAGS	=   -fprofile-arcs -ftest-coverage 	# For perfomance monitoring tool.
OPTIMIZE 	=   -O3 				# -O -O1 -O2 -O3 Full optimization.

#CCFLAGS=         $(DEBUGFLAG) $(FULLWARN) 
CCFLAGS=          $(OPTIMISE) $(FULLWARN) 

# GNU C++ COMPILTER
CC =   g++ 	# GNU C++ compiler
RM =   rm       # rm (for cleanup)

# ORACLE LIBs & INCLUDE DIRECTORIES.
PCCI=-I$(ORACLE_HOME)/network/public -I$(ORACLE_HOME)/rdbms/demo -I$(ORACLE_HOME)/precomp/public
OCI_LIB_PATHS = -L/usr/oracle8/lib/ -L/usr/oracle8/rdbms/lib


# LIBRARIES & INCLUDE DIRECTORIES.
# -lg++ -lstdc++ libs have been replaced by libgcc.a
# g++ compiler uses LIBRARY_PATH & CPLUS_INLCUDE_PATH env. vars to locate
# include files & libs. These should be defined in .cshrc file in  root.

SOCKET_LIBS 	= -lsocket -lgen -lnsl
STD_LIB 	= -L . -L/usr/local/lib -L/usr/openwin/lib $(SOCKET_LIBS)
RV_LIBS 	= -lrvcpp -lrv
RV_INCLUDE 	= -I/usr/rv/include 

OCI_DYNAMIC_LIBS = -lclntsh -lnbeq8 -lnhost8 -ln8 -lnoss8 -lnus8 -lnldap8 -lldapclnt8 -lnsslb8 -lnoname8 -lntcp8 -lntcps8 -lntns8 -lnl8 -lnro8 -lnbeq8 -lnhost8 -lnldap8 -lldapclnt8 -lnoname8 -lntcps8 -lntns8 -lclient8 -lvsn8 -lcommon8 -lskgxp8 -lgeneric8 -lmm -lnls8 -lcore8 -lnbeq8 -lnhost8 -lnldap8 -lldapclnt8 -lntcps8 -lntns8 -lnro8 -lnbeq8 -lnhost8 -lnus8 -lnldap8 -lldapclnt8 -lntns8 -lclient8 -lvsn8 -lskgxp8 -lgeneric8 -ltrace8 -lvsn8 -lskgxp8 -lgeneric8 -lnls8 -lsocket -lgen -ldl -lsched -R /usr/oracle8/lib -YP,/usr/openwin/lib:/usr/rv/lib:/usr/oracle8/lib:/usr/ccs/lib:/usr/lib -Qy -lc -laio -lposix4 -lkstat -lm -lthread

# CXXFLAGS is used by g++ to locate include files at compile time. 
# ----------------------------------------------------------------
CXXFLAGS  = $(RV_INCLUDE) $(CCFLAGS) $(PCCI)
#CXXFLAGS = $(CCFLAGS) $(PCCI)


OBJECTS  = PAdm.o \
call_partner_networks.o \
celebration_discounts.o \
cell_groups.o \
code_decode.o \
connections.o \
db.o \
dev_history.o \
discount_expression.o \
discount_numbers.o \
fixed_rate_numbers.o \
group_discounts.o \
historic_imsi.o \
historic_package.o \
holiday_priorities.o \
identity.o \
network_groups.o \
package_services.o \
r4_cdr_buffer.o \
r4_cdr_decode.o \
cdr_file_locations.o \
cdr_file_statistics.o \
cdr_files.o \
cdr_imsi_filter.o \
cdr_rejects.o \
cdr_unpack.o \
rate_eng.o \
rate_groups.o \
rated_cdr.o \
rates.o \
rating_observer.o \
reng_date_time.o \
roaming_networks.o \
time_discount_bands.o \
token.o \
value_added_services.o 
 
rate_eng: $(OBJECTS)
	$(CXX) $(OCI_LIB_PATHS) $(STD_LIB) -o$@ $(OBJECTS) $(OCI_DYNAMIC_LIBS) $(RV_LIBS)

clean:
