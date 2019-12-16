#ifndef Export_System_h__
#define Export_System_h__

#include "GraphicDev.h"
#include "TimerMgr.h"
#include "FrameMgr.h"
#include "KeyMgr.h"

BEGIN(ENGINE)

// GraphicDev
inline HRESULT		InitDevice(HWND hWnd, const DWORD& dwWinCX, const DWORD& dwWinCY, ENGINE::DISPLAY_MODE eMode, ENGINE::CGraphicDev** ppGraphicDev);
inline void			Render_Begin();
inline void			Render_End();

// FrameMgr
inline bool Lock_Frame(_float _LockValue, _float _DeltaTime);
inline void Render_Frame(_float _DeltaTime);


// TimerMgr
inline _float	Get_Deltatime(const _tchar* _pTimerTag);
inline void		Set_Deltatime(const _tchar* _pTimerTag);
inline HRESULT	initialize_Timer(const _tchar* _pTimerTag);


// KeyMgr
inline bool KeyPressing(DWORD dwKey);
inline bool KeyDown(DWORD dwKey);
inline bool KeyUp(DWORD dwKey);
inline bool KeyCombined(DWORD dwFirst, DWORD dwSecond);
void  Set_Handle(HWND _g_hWnd);
void  Set_DPI(_float _DPI);
void  Set_MouseLock();
POINT Get_MouseGap();


// Release System
inline void	Release_System();

#include "Export_System.inl"

END
#endif // Export_System_h__
