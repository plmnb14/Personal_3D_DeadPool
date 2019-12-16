#include "GraphicDev.h"

USING(ENGINE)
IMPLEMENT_SINGLETON(CGraphicDev)

CGraphicDev::CGraphicDev()
{
}

CGraphicDev::~CGraphicDev()
{
	Free();
}

LPDIRECT3DDEVICE9 CGraphicDev::Get_Device()
{
	return m_pGraphicDev;
}

LPD3DXSPRITE CGraphicDev::Get_Sprite()
{
	return m_pSprite;
}

LPD3DXFONT CGraphicDev::Get_Font()
{
	return m_pFont;
}

HRESULT CGraphicDev::InitDevice(
	HWND hWnd,
	const DWORD& dwWinCX,
	const DWORD& dwWinCY,
	ENGINE::DISPLAY_MODE eMode ,
	CGraphicDev** ppGraphicDev)
{
	// IDirect3D9 객체 생성.
	m_pSDK = Direct3DCreate9(D3D_SDK_VERSION);
	//NULL_CHECK_MSG_RETURN(m_pSDK, L"Direct3DCreate9 Failed", E_FAIL);

	// 장치 검증 및 조사 진행.
	D3DCAPS9	d3dcaps;
	ZeroMemory(&d3dcaps, sizeof(D3DCAPS9));

	// HAL (Hardware Abstraction Layer, 하드웨어 추상 계층)
	HRESULT hr = m_pSDK->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &d3dcaps);
	FAILED_CHECK_RETURN_MSG(hr ,E_FAIL, L"GetDeviceCaps Failed");

	DWORD vp = 0;

	if (d3dcaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		vp |= D3DCREATE_HARDWARE_VERTEXPROCESSING;
	else
		vp |= D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	vp |= D3DCREATE_MULTITHREADED;


	D3DPRESENT_PARAMETERS	d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));

	d3dpp.BackBufferWidth = dwWinCX;
	d3dpp.BackBufferHeight = dwWinCY;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount = 1;

	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.Windowed = eMode;

	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;

	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;


	hr = m_pSDK->CreateDevice(
		D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, vp, &d3dpp, &m_pGraphicDev);
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL, L"CreateDevice Failed");


	hr = D3DXCreateSprite(m_pGraphicDev, &m_pSprite);
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL ,L"D3DXCreateSprite Failed");

	D3DXFONT_DESC tFontInfo;
	ZeroMemory(&tFontInfo, sizeof(D3DXFONT_DESC));

	tFontInfo.Width = 10;
	tFontInfo.Height = 20;
	tFontInfo.Weight = FW_HEAVY;
	tFontInfo.CharSet = HANGEUL_CHARSET;
	lstrcpy(tFontInfo.FaceName, L"궁서");

	hr = D3DXCreateFontIndirect(m_pGraphicDev, &tFontInfo, &m_pFont);
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL, L"D3DXCreateFont Failed");

	*ppGraphicDev = this;

	return S_OK;
}

void CGraphicDev::Render_Begin()
{
	m_pGraphicDev->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL,
		D3DCOLOR_ARGB(255, 120, 120, 120), 1.f, 0);

	m_pGraphicDev->BeginScene();
	//m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void CGraphicDev::Render_End(HWND hWnd)
{
	//m_pSprite->End();
	m_pGraphicDev->EndScene();

	m_pGraphicDev->Present(nullptr, nullptr, hWnd, nullptr);
}

void CGraphicDev::Render_Sprite_Begin()
{
	//m_pSprite->SetWorldViewLH(NULL, m_pGraphicDev->)
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND); // | D3DXSPRITE_OBJECTSPACE);
}

void CGraphicDev::Render_Sprite_End()
{
	m_pSprite->End();
}

void CGraphicDev::Free()
{
	_ulong dwRefCnt = 0;

	if (dwRefCnt = ENGINE::Safe_Release(m_pFont))
		MSG_BOX("m_pGraphicDev Release Failed");

	if (dwRefCnt = ENGINE::Safe_Release(m_pSprite))
		MSG_BOX("m_pGraphicDev Release Failed");

	if (dwRefCnt = ENGINE::Safe_Release(m_pGraphicDev))
		MSG_BOX("m_pGraphicDev Release Failed");

	if (dwRefCnt = ENGINE::Safe_Release(m_pSDK))
		MSG_BOX("m_pSDK Release Failed");
}

void CGraphicDev::Release()
{
}
