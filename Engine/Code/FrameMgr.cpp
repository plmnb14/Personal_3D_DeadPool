#include "FrameMgr.h"
#include "GraphicDev.h"
#include "TimerMgr.h"

USING(ENGINE)
IMPLEMENT_SINGLETON(CFrameMgr)


CFrameMgr::CFrameMgr()
	:m_fTimeCount(FNULL), m_iFrame(NULL), m_szFPS(L""), m_fTimeCount2(FNULL)
{
	ZeroMemory(&m_CurTime, sizeof(LARGE_INTEGER));
	ZeroMemory(&m_OldTime, sizeof(LARGE_INTEGER));
	ZeroMemory(&m_FixedTime, sizeof(LARGE_INTEGER));
	ZeroMemory(&m_CPU_Tick, sizeof(LARGE_INTEGER));
}


CFrameMgr::~CFrameMgr()
{
}

bool CFrameMgr::Lock_Frame(_float _LockValue, _float _DeltaTime)
{
	m_fTimeCount += _DeltaTime;
	//ENGINE::CTimerMgr::GetInstance()->Set_DeltaTime(L"FrameTime");
	//m_fTimeCount += ENGINE::CTimerMgr::GetInstance()->Get_DeltaTime(L"FrameTime");

	if (FONE / _LockValue < m_fTimeCount)
	{
		++m_iFrame;
		m_fTimeCount = FNULL;
		return true;
	}

	return false;
}

void CFrameMgr::Render_Frame(_float _DeltaTime)
{
	ENGINE::CTimerMgr::GetInstance()->Set_DeltaTime(L"FrameTime2");
	m_fTimeCount2 += ENGINE::CTimerMgr::GetInstance()->Get_DeltaTime(L"FrameTime2");

	if (1.f <= m_fTimeCount2)
	{
		swprintf_s(m_szFPS, L"FPS: %d", m_iFrame);
		m_iFrame = 0;
		m_fTimeCount2 = 0.f;
	}

	_mat matTrans;
	D3DXMatrixTranslation(&matTrans, 640.f, 100, 10.f);

	CGraphicDev::GetInstance()->Get_Sprite()->SetTransform(&matTrans);

	CGraphicDev::GetInstance()->Get_Font()->DrawText(
		CGraphicDev::GetInstance()->Get_Sprite(),
		m_szFPS, lstrlen(m_szFPS), nullptr, 0,
		D3DCOLOR_ARGB(255, 255, 0, 0));
}

void CFrameMgr::Free()
{
}
