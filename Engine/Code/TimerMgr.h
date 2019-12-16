#ifndef TimerMgr_h_
#define TimerMgr_h__

#include "Timer.h"

BEGIN(ENGINE)

class ENGINE_DLL CTimerMgr : public CBase
{

DECLARE_SINGLETON(CTimerMgr)

private:
	explicit CTimerMgr();
	virtual ~CTimerMgr();

public:
	void Set_DeltaTime(const _tchar* _TimerTag);
	_float Get_DeltaTime(const _tchar* _TimerTag);
	HRESULT initialize_Timer(const _tchar* _TimerTag);

private:
	CTimer* Find_Timer(const _tchar* _TimerTag);

private:
	map<const _tchar*, CTimer*>		m_mTimer;

public:
	virtual void Free();

};

END

#endif // TimerMgr_h__
