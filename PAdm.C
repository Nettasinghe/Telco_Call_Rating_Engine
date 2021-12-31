

//////////////////////////////////////////////////////////////////////
//
// PAdm.C :
//				implementation of the PAdm class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#include "PAdm.H"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fstream.h>


PAdm::PAdm()
{
	p_Listener = NULL;
	p_HBSender = NULL;
	p_HBTimer = NULL;
}


PAdm::~PAdm()
{
	delete p_Listener;
	delete p_HBSender;
	delete p_HBTimer;
}


bool PAdm::CreatePAdm(RvSession* pRvSess, char* zName, int iHBInterval, 
		char* zVer, char* zMode)
{
	i_HBInterval = iHBInterval;
	workaround.p_Parent = this;

	strncpy(z_Name, zName, 30);
	z_Name[29] = '\0';
	strncpy(z_Version, zVer, 20);
	z_Version[19] = '\0';
    p_RvSession = pRvSess; 

	b_Primary = strcmp(zMode, "PRIMARY") == 0;

	char zSubject[50];
	sprintf(zSubject, "GSM.PROCESS.SERVICE.CHANNEL.%s", z_Name);
	p_Listener = p_RvSession->newListener(zSubject, &workaround);

	p_RvSession->newListener("_RV.ERROR.>", &workaround);
	p_RvSession->newListener("_RV.WARN.>", &workaround);

	sprintf(zSubject, "GSM.HEARTBEAT.%s", z_Name);
	p_HBSender = p_RvSession->newSender(zSubject);

	char zHostName[256];
	gethostname(zHostName, 256);

	rvm_Heartbeat.append("_MsgName_", "PROCESS_HEARTBEAT");
	rvm_Heartbeat.append("NAME", z_Name);
	rvm_Heartbeat.append("PID", (int)getpid());
	rvm_Heartbeat.append("MODE", zMode);
	rvm_Heartbeat.append("VERSION", z_Version);
	rvm_Heartbeat.append("MACHINE_NAME", zHostName);

	return true;
}


void PAdm::Ready()
{
	if (i_HBInterval > 0)
	{
		p_HBTimer = p_RvSession->newTimer(i_HBInterval, RV_TRUE, &workaround);
		p_HBSender->send(rvm_Heartbeat);
	}
}


void PAdm::SendHeartbeat()
{
	if (i_HBInterval > 0)
	{
		p_HBTimer->reset(i_HBInterval);
		p_HBSender->send(rvm_Heartbeat);
	}
}


void PAdm::OnPrimary(){}
void PAdm::OnSecondary(){}
void PAdm::OnShutDown(){ Terminate(); }
void PAdm::OnConfig(char*, char* , char* , char* ){}

bool PAdm::IsPrimary()
{
	return b_Primary;
}



void PAdm::SendError(char* zErrNo, char* zFormat, ...)
{
	va_list ap;
	char zDesc[1000];
	va_start(ap, zFormat);
	vsprintf(zDesc, zFormat, ap);
	va_end(ap);
	SendMessage("ERROR", zErrNo, zDesc);
}


void PAdm::SendWarning(char* zWarNo, char* zFormat, ...)
{
	va_list ap;
	char zDesc[1000];
	va_start(ap, zFormat);
	vsprintf(zDesc, zFormat, ap);
	va_end(ap);
	SendMessage("WARNING", zWarNo, zDesc);
}


void PAdm::SendText(char* zTxtNo, char* zFormat, ...)
{
	va_list ap;
	char zDesc[1000];
	va_start(ap, zFormat);
	vsprintf(zDesc, zFormat, ap);
	va_end(ap);
	SendMessage("TEXT", zTxtNo, zDesc);
}


void PAdm::SendMessage(char* zType, char* zNo, char* zDesc)
{
	char zTime[30];
	time_t t;
	time(&t);
	strftime(zTime, 30, "%H:%M:%S", localtime(&t));

	RvMsg rvmMsg;
	rvmMsg.append("_MsgName_", zType);
	rvmMsg.append("PROCESS_NAME", z_Name);
	rvmMsg.append("NO", zNo);
	rvmMsg.append("DESC", zDesc);
	rvmMsg.append("TIME", zTime);

    char zSubject[50];
    sprintf(zSubject, "GSM.PROCESS.MESSAGES.%s", z_Name);
    RvSender* pSender = p_RvSession->newSender(zSubject);
	pSender->send(rvmMsg);
	delete pSender;
}


void PAdm::SendStat(char* zStatName, char* zFormat, ...)
{
	va_list ap;
	char zValue[1000];
	va_start(ap, zFormat);
	vsprintf(zValue, zFormat, ap);
	va_end(ap);

	char zTime[30];
	time_t t;
	time(&t);
	strftime(zTime, 30, "%H:%M:%S", localtime(&t));

	RvMsg rvmMsg;
	rvmMsg.append("_MsgName_", "STATISTICS");
	rvmMsg.append("PROCESS_NAME", z_Name);
	rvmMsg.append("NAME", zStatName);
	rvmMsg.append("VALUE", zValue);
	rvmMsg.append("TIME", zTime);

    char zSubject[50];
    sprintf(zSubject, "GSM.PROCESS.STATISTICS.%s", z_Name);
    RvSender* pSender = p_RvSession->newSender(zSubject);
	pSender->send(rvmMsg);
	delete pSender;
}


void PAdm::Terminate()
{
	exit(EXIT_SUCCESS);
}


void PAdm::OnRvAdvice(char* zSubject, RvMsg& rMsg)
{
	if (strstr(zSubject, "EXPIRE") != NULL)	
	{
		RvDatum d;
		char zTime[50];
		strcpy(zTime, "");
		rMsg.get("expiretime", d);
		d.convertTo(zTime, 50);
		SendWarning("RV001", "%s: %s", zSubject, zTime);

	}
	else if (strstr(zSubject, "DATALOSS") != NULL)	
	{
		char zHost[256];
		strcpy(zHost, "");
		rMsg.get("host", zHost, 50);
		SendWarning("RV001", "%s: %s", zSubject, zHost);
	}
	else
		SendWarning("RV001", "%s", zSubject);
}


void PAdm::OnData(const char* zSubject, class RvSender* pReplySender,
        const class RvDatum& rvdData, class RvListener*)
{
	if (zSubject == NULL)
		return;

    RvMsg rvmData(rvdData.data());

	if (strstr(zSubject, "_RV.") != NULL)
	{
		OnRvAdvice((char*)zSubject, rvmData);
		return;
	}


	char zMsgName[50];
	*zMsgName = '\0';
	rvmData.get("_MsgName_", zMsgName, 50);

	char zHostName[256];
	gethostname(zHostName, 256);

	if (strcmp(zMsgName, "PING") == 0)
	{
		RvMsg rvmAck;
		rvmAck.append("_MsgName_", "ACK");
		rvmAck.append("NAME", z_Name);
		rvmAck.append("MACHINE_NAME", zHostName);

		if (pReplySender != NULL)
			pReplySender->send(rvmAck);
	}
	else if (strcmp(zMsgName, "SET_PRIMARY") == 0)
	{
		RvMsg rvmHB;
		rvmHB.append("_MsgName_", "PROCESS_HEARTBEAT");
		rvmHB.append("NAME", z_Name);
		rvmHB.append("PID", (int)getpid());
		rvmHB.append("MODE", "PRIMARY");
		rvmHB.append("VERSION", z_Version);
		rvmHB.append("MACHINE_NAME", zHostName);
		rvm_Heartbeat = rvmHB;

		RvMsg rvmReply;
		rvmReply.append("ACCEPTED", 1);

		if (pReplySender != NULL)
			pReplySender->send(rvmReply);

		b_Primary = true;
		OnPrimary();
	}
	else if (strcmp(zMsgName, "SET_SECONDARY") == 0)
	{
		RvMsg rvmHB;
		rvmHB.append("_MsgName_", "PROCESS_HEARTBEAT");
		rvmHB.append("NAME", z_Name);
		rvmHB.append("PID", (int)getpid());
		rvmHB.append("MODE", "SECONDARY");
		rvmHB.append("VERSION", z_Version);
		rvmHB.append("MACHINE_NAME", zHostName);
		rvm_Heartbeat = rvmHB;

		RvMsg rvmReply;
		rvmReply.append("ACCEPTED", 1);

		if (pReplySender != NULL)
			pReplySender->send(rvmReply);

		b_Primary = false;
		OnSecondary();
	}
	else if (strcmp(zMsgName, "SHUT_DOWN") == 0)
		OnShutDown();
	else if (strcmp(zMsgName, "CFG_MODIFY") == 0)
	{
		char zGroup[50], zSec[50], zParam[50], zVal[100];
		strcpy(zGroup, "");
		strcpy(zSec, "");
		strcpy(zParam, "");
		strcpy(zVal, "");

		rvmData.get("GROUP", zGroup, 50);
		rvmData.get("SECTION", zSec, 50);
		rvmData.get("PARAMETER", zParam, 50);
		rvmData.get("VALUE", zVal, 100);

		OnConfig(zGroup, zSec, zParam, zVal);
	}
}


void PAdm::OnTimer(RvTimer*)
{
	p_HBSender->send(rvm_Heartbeat);
}


void PAdm::RVCB::onData(const char* zSubject, class RvSender* pReplySender,
        const class RvDatum& rvdData, class RvListener* pListener)
{
	p_Parent->OnData(zSubject, pReplySender, rvdData, pListener);
}


void PAdm::RVCB::onTimer(RvTimer* pTimer)
{
	p_Parent->OnTimer(pTimer);
}
