#ifndef TmpTerrain_h__
#define TmpTerrain_h__

#include "GameObject.h"

class CTmpTerrain : public ENGINE::CGameObject
{
private:
	explicit CTmpTerrain(LPDIRECT3DDEVICE9 _pGraphicDev);
	virtual ~CTmpTerrain();

private:
	HRESULT Initialize();
	HRESULT LateInit();

private:
	HRESULT Add_Component();

private:
	ENGINE::CTransform*		m_pTransform;
	ENGINE::CTexture*		m_pTexture;
	ENGINE::CVIBuffer*		m_pBuffer;

	ENGINE::VTX_TEX*		m_pOriginVtx;
	ENGINE::VTX_TEX*		m_pConvertVtx;
	_ulong					m_dwVtxCount;

public:
	_int Update();
	void LateUpdate();
	void Render();

public:
	virtual void Free();

public:
	static CTmpTerrain*	Create(LPDIRECT3DDEVICE9 _pGraphicDev);
};

#endif TmpTerrain_h__