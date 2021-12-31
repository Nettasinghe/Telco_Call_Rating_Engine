

//////////////////////////////////////////////////////////////////////
//
// PAdm.H :
//				definition of PAdm class.
// Telco Call Rating Engine
// developer	- Chandika Nettasinghe
// development	- Jan 1999
//
//////////////////////////////////////////////////////////////////////


#ifndef PADM_HEADER
#define PADM_HEADER

#include <stdarg.h>
#include <rvcpp.h>

class PAdm
{
	public:
	PAdm();
	virtual ~PAdm();
	virtual void OnPrimary();
	virtual void OnSecondary();
	virtual void OnShutDown();
	virtual void OnConfig(char* zGroup, char* zSection, char* zParam, char* zValue);

	bool CreatePAdm(RvSession* pRvSess,char* zProcID,int iHBInterval,
			char* zVer, char* zMode);
	void Ready();
	void SendError(char* zErrNo, char* zFormat, ...);
	void SendWarning(char* zWarNo, char* Format, ...);
	void SendText(char* zTxtNo, char* Format, ...);
	void SendStat(char* zStatName, char* Format, ...);
	void SendHeartbeat();
	void Terminate();
	bool IsPrimary();

	//private:
	RvSession* 	p_RvSession;
	RvSender* 	p_HBSender;
	RvListener* p_Listener;
	RvTimer*	p_HBTimer;
	RvMsg 		rvm_Heartbeat;
	char 		z_Name[30];
	char 		z_Version[20];
	bool		b_Primary;
	int			i_HBInterval;

	void SendMessage(char* zType, char* zNo, char* zDesc);
	void OnTimer(RvTimer*);
    void OnData(const char*, class RvSender* pReplySender,
            const class RvDatum& rvdData, class RvListener*);
	void OnRvAdvice(char* zSubject, RvMsg& rMsg);

	class RVCB :public RvDataCallback, public RvTimerCallback
	{
		public:
		PAdm* p_Parent;
		void onTimer(RvTimer*);
		void onData(const char*, class RvSender* pReplySender,
				const class RvDatum& rvdData, class RvListener*);
	};
	RVCB workaround;
};

#endif
