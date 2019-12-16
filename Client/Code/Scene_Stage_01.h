#ifndef CScene_Stage_01_h__
#define CScene_Stage_01_h__

#include "Scene.h"

class CScene_Stage_01 : public ENGINE::CScene
{
private:
	explicit CScene_Stage_01(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CScene_Stage_01();

public:
	virtual void Update_Scene();
	virtual void LateUpdate_Scene();
	virtual void Update_Render();

private:
	virtual HRESULT Add_Environment_Layer();
	virtual HRESULT Add_Object_Layer();
	virtual HRESULT Add_UI_Layer();
	virtual HRESULT Initialize();

private:
	void PipeLineSetUp();

public:
	static CScene_Stage_01* Create(LPDIRECT3DDEVICE9 pGraphicDev);

public:
	virtual void Free();

private:
	ENGINE::CManagement*	m_pManagement;

	_mat m_matWorld;
	_mat m_matView;
	_mat m_matProj;

	ENGINE::CGameObject* m_pPlayer;
	ENGINE::CGameObject* m_pMonster;
};

#endif // CScene_Stage_01_h__
