HRESULT	InitDevice(HWND hWnd, const DWORD& dwWinCX, const DWORD& dwWinCY, ENGINE::DISPLAY_MODE eMode , ENGINE::CGraphicDev** ppGraphicDev)
{
	return CGraphicDev::GetInstance()->InitDevice(hWnd, dwWinCX, dwWinCY, eMode, ppGraphicDev);
}
void	Render_Begin()
{
	CGraphicDev::GetInstance()->Render_Begin();
}
void	Render_End()
{
	CGraphicDev::GetInstance()->Render_End();
}

_float	Get_Deltatime(const _tchar* _pTimerTag)
{
	return CTimerMgr::GetInstance()->Get_DeltaTime(_pTimerTag);
}

void	Set_Deltatime(const _tchar* _pTimerTag)
{
	CTimerMgr::GetInstance()->Set_DeltaTime(_pTimerTag);
}

HRESULT	initialize_Timer(const _tchar* _pTimerTag)
{
	return CTimerMgr::GetInstance()->initialize_Timer(_pTimerTag);
}

void	Release_System()
{
	CFrameMgr::GetInstance()->DestroyInstance();
	CTimerMgr::GetInstance()->DestroyInstance();
	CGraphicDev::GetInstance()->DestroyInstance();
	CKeyMgr::GetInstance()->DestroyInstance();
}

// KeyMgr

bool KeyPressing(DWORD dwKey)
{
	return CKeyMgr::GetInstance()->KeyPressing(dwKey);
}

bool KeyDown(DWORD dwKey)
{
	return CKeyMgr::GetInstance()->KeyDown(dwKey);
}

bool KeyUp(DWORD dwKey)
{
	return CKeyMgr::GetInstance()->KeyUp(dwKey);
}

bool KeyCombined(DWORD dwFirst, DWORD dwSecond)
{
	return CKeyMgr::GetInstance()->KeyCombined(dwFirst, dwSecond);
}

void  Set_Handle(HWND _g_hWnd)
{
	CKeyMgr::GetInstance()->Set_Handle(_g_hWnd);
}
void  Set_DPI(_float _DPI)
{
	CKeyMgr::GetInstance()->Set_DPI(_DPI);
}
void  Set_MouseLock()
{
	CKeyMgr::GetInstance()->Set_MouseLock();
}
POINT Get_MouseGap()
{
	return CKeyMgr::GetInstance()->Get_MouseGap();
}

// FrameMgr

bool Lock_Frame(_float _LockValue, _float _DeltaTime)
{
	return CFrameMgr::GetInstance()->Lock_Frame(_LockValue, _DeltaTime);
}
void Render_Frame(_float _DeltaTime)
{
	CFrameMgr::GetInstance()->Render_Frame(_DeltaTime);
}