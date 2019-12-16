#include "TimerMgr.h"

USING(ENGINE)
IMPLEMENT_SINGLETON(CTimerMgr)

CTimerMgr::CTimerMgr()
{
}


CTimerMgr::~CTimerMgr()
{
	Free();
}

void CTimerMgr::Set_DeltaTime(const _tchar * _TimerTag)
{
	CTimer* pInstance = Find_Timer(_TimerTag);

	if (nullptr == pInstance)
		return;

	pInstance->Set_DeltaTime();
}

_float CTimerMgr::Get_DeltaTime(const _tchar * _TimerTag)
{
	CTimer* pInstance = Find_Timer(_TimerTag);

	if (nullptr == pInstance)
		return FNULL;

	return pInstance->Get_DeltaTime();
}

CTimer * CTimerMgr::Find_Timer(const _tchar * _TimerTag)
{
	auto iter = find_if(m_mTimer.begin(), m_mTimer.end(), CTag_Finder(_TimerTag));

	if (iter == m_mTimer.end())
		return nullptr;

	return iter->second;
}

HRESULT CTimerMgr::initialize_Timer(const _tchar * _TimerTag)
{
	CTimer* pInstance = Find_Timer(_TimerTag);

	if (nullptr != pInstance)
		return E_FAIL;

	pInstance = CTimer::Create();
	NULL_CHECK_RETURN(pInstance, E_FAIL);

	m_mTimer.emplace(_TimerTag, pInstance);

	return S_OK;
}

void CTimerMgr::Free()
{
	for_each(m_mTimer.begin(), m_mTimer.end(), CDeleteMap());
	m_mTimer.clear();
}
