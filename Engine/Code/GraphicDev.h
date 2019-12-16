#ifndef GraphicDev_h__
#define GraphicDev_h__

#include "Engine_Defines.h"
#include "Base.h"

// dllimport
// dllexport

BEGIN(ENGINE)

class ENGINE_DLL CGraphicDev : public CBase
{
	DECLARE_SINGLETON(CGraphicDev)

private:
	explicit CGraphicDev();
	virtual ~CGraphicDev();

public:
	LPDIRECT3DDEVICE9	Get_Device();
	LPD3DXSPRITE		Get_Sprite();
	LPD3DXFONT			Get_Font();

public:
	HRESULT InitDevice( HWND hWnd, const DWORD& dwWinCX, const DWORD& dwWinCY, ENGINE::DISPLAY_MODE eMode , CGraphicDev** ppGraphicDev);
	void Render_Begin();
	void Render_End(HWND hWnd = nullptr);
	void Render_Sprite_Begin();
	void Render_Sprite_End();
	virtual void Free();

private:
	void Release();

private:
	LPDIRECT3D9				m_pSDK;
	LPDIRECT3DDEVICE9		m_pGraphicDev;
	LPD3DXSPRITE			m_pSprite;
	LPD3DXFONT				m_pFont;
};

END

#endif // GraphicDev_h__