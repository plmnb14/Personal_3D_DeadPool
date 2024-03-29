#ifndef KeyMgr_h__
#define KeyMgr_h__


#include "Engine_Defines.h"


BEGIN(ENGINE)

const DWORD KEY_UP = 0x00000001;	// 0000 0000 0000 0000 0000 0000 0000 0001
const DWORD KEY_DOWN = 0x00000002;	// 0000 0000 0000 0000 0000 0000 0000 0010
const DWORD KEY_LEFT = 0x00000004;	// 0000 0000 0000 0000 0000 0000 0000 0100
const DWORD KEY_RIGHT = 0x00000008;	// 0000 0000 0000 0000 0000 0000 0000 1000

const DWORD KEY_SPACE = 0x00000010;	// 0000 0000 0000 0000 0000 0000 0001 0000
const DWORD KEY_RETURN = 0x00000020;	// 0000 0000 0000 0000 0000 0000 0010 0000
const DWORD KEY_LBUTTON = 0x00000040;	// 0000 0000 0000 0000 0000 0000 0100 0000
const DWORD KEY_RBUTTON = 0x00000080;	// 0000 0000 0000 0000 0000 0000 1000 0000

const DWORD KEY_W = 0x00000100;
const DWORD KEY_S = 0x00000200;
const DWORD KEY_A = 0x00000400;
const DWORD KEY_D = 0x00000800;

const DWORD KEY_LSHIFT = 0x00001000;
const DWORD KEY_LCTRL = 0x00002000;
const DWORD KEY_Q = 0x00004000;
const DWORD KEY_E = 0x00008000;

const DWORD KEY_R = 0x00010000;
const DWORD KEY_F = 0x00020000;
const DWORD KEY_X = 0x00040000;
const DWORD KEY_Z = 0x00080000;

const DWORD KEY_1 = 0x00100000;
const DWORD KEY_2 = 0x00200000;
const DWORD KEY_3 = 0x00400000;
const DWORD KEY_4 = 0x00800000;

const DWORD KEY_5 = 0x01000000;
const DWORD KEY_6 = 0x02000000;
const DWORD KEY_7 = 0x04000000;
const DWORD KEY_8 = 0x08000000;

const DWORD KEY_G = 0x10000000;

class ENGINE_DLL CKeyMgr
{
	DECLARE_SINGLETON(CKeyMgr)

private:
	explicit CKeyMgr();
	~CKeyMgr();

public:
	void Update();

public:
	bool KeyPressing(DWORD dwKey);
	bool KeyDown(DWORD dwKey);
	bool KeyUp(DWORD dwKey);
	bool KeyCombined(DWORD dwFirst, DWORD dwSecond);

public:
	void  Set_Handle(HWND _g_hWnd);
	HWND  Get_Handle();
	void  Set_DPI(_float _DPI);
	void  Set_MouseLock();
	POINT Get_ScreenCenter();
	POINT Get_MouseGap();

private:
	DWORD m_dwKey;		// 현재 눌린 키 정보
	DWORD m_dwKeyDown;	// 과거 눌린 키 정보
	DWORD m_dwKeyUp;	// 과거 눌린 키 정보

private:
	POINT m_CurMousePos;
	POINT m_OldMousePos;
	POINT m_MouseGap;

private:
	_float m_fDPI;

private:
	HWND m_hWnd;
};

END

#endif	// KeyMgr_h__