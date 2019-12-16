#ifndef Timer_h__
#define Timer_h__

#include "Engine_Defines.h"
#include "Base.h"

BEGIN(ENGINE)

class ENGINE_DLL CTimer : public CBase
{
private:
	explicit CTimer();
	virtual ~CTimer();

private:
	HRESULT Initialize();

public:
	void	Set_DeltaTime();
	_float	Get_DeltaTime();

private:
	LARGE_INTEGER	m_CurTime;
	LARGE_INTEGER	m_OldTime;
	LARGE_INTEGER	m_FixedTime;
	LARGE_INTEGER	m_CPU_Tick;

	_float			m_fDeltaTime;

public:
	static CTimer* Create();
	virtual void Free();
};

END

#endif // Timer_h__


