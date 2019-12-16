#ifndef CScene_Logo_h__
#define CScene_Logo_h__

#include "Scene.h"

class CScene_Logo : public ENGINE::CScene
{
private:
	explicit CScene_Logo(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CScene_Logo();

public:
	virtual void Update_Scene(const _float& fTimeDelta);
	virtual void LateUpdate_Scene();
	virtual void Render_Scene();

private:
	virtual HRESULT Add_Environment_Layer();
	virtual HRESULT Add_Object_Layer();
	virtual HRESULT Add_UI_Layer();
	virtual HRESULT Initialize();

private:
	HRESULT SetUp_PineLine();
	HRESULT SetUp_Camera();
	HRESULT SetUp_Buffer();
	HRESULT SetUp_Texture();

public:
	static CScene_Logo* Create(LPDIRECT3DDEVICE9 pGraphicDev);

public:
	virtual void Free();

private:
	ENGINE::CManagement*	m_pManagement;
};

#endif // CScene_Logo_h__
