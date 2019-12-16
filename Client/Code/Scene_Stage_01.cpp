#include "stdafx.h"
#include "Scene_Logo.h"
#include "SceneSelector.h"

#include "LogoBack.h"

CScene_Stage_01::CScene_Stage_01(LPDIRECT3DDEVICE9 pGraphicDev)
	: ENGINE::CScene(pGraphicDev), m_pManagement(nullptr),
	m_pMonster(nullptr), m_pPlayer(nullptr)
{
	D3DXMatrixIdentity(&m_matWorld);
	D3DXMatrixIdentity(&m_matView);
	D3DXMatrixIdentity(&m_matProj);
}

CScene_Stage_01::~CScene_Stage_01()
{
	Free();
}

void CScene_Stage_01::Update_Scene()
{
	ENGINE::CScene::Update_Scene(0);
}

void CScene_Stage_01::LateUpdate_Scene()
{
	ENGINE::CScene::LateUpdate_Scene();
}

void CScene_Stage_01::Update_Render()
{
	//m_pDeviceMgr->SetTransform(D3DTS_WORLD, &m_matWorld);
	//m_pDeviceMgr->SetTransform(D3DTS_VIEW, &m_matView);
	//m_pDeviceMgr->SetTransform(D3DTS_PROJECTION, &m_matProj);

	ENGINE::CScene::Render_Scene();
}

HRESULT CScene_Stage_01::Add_Environment_Layer()
{
	return S_OK;
}

HRESULT CScene_Stage_01::Add_Object_Layer()
{
	// Object Layer
	ENGINE::CLayer* pObject_Layer = ENGINE::CLayer::Create();
	NULL_CHECK_RETURN(pObject_Layer, E_FAIL);
	m_mapLayer.insert({ ENGINE::LAYER_OBJ, pObject_Layer });


	return S_OK;
}

HRESULT CScene_Stage_01::Add_UI_Layer()
{
	return S_OK;
}

HRESULT CScene_Stage_01::Initialize()
{
	HRESULT hr = 0;

	PipeLineSetUp();

	//ENGINE::Reserve_ContainerSize(ENGINE::RESOURCE_END);
	//
	//ENGINE::Ready_Buffers(m_pDeviceMgr, ENGINE::RESOURCE_STATIC, L"Buffer_TriCol", ENGINE::BUFFER_TRICOL);
	//ENGINE::Ready_Buffers(m_pDeviceMgr, ENGINE::RESOURCE_STATIC, L"Buffer_RcCol", ENGINE::BUFFER_RCCOL);
	//ENGINE::Ready_Buffers(m_pDeviceMgr, ENGINE::RESOURCE_STATIC, L"Buffer_RcTex", ENGINE::BUFFER_RCTEX);


	////Environment Layer
	hr = Add_Environment_Layer();
	FAILED_CHECK_RETURN(hr, E_FAIL);
	
	// Object Layer
	hr = Add_Object_Layer();
	FAILED_CHECK_RETURN(hr, E_FAIL);
	
	// UI Layer
	hr = Add_UI_Layer();
	FAILED_CHECK_RETURN(hr, E_FAIL);

	return S_OK;
}

void CScene_Stage_01::PipeLineSetUp()
{
	//m_pDeviceMgr->SetRenderState(D3DRS_LIGHTING, FALSE);
	//m_pDeviceMgr->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	//_vec4			vRight, vUp, vLook, vPos;
	//
	//vRight = _vec4(1.f, 0.f, 0.f, 0.f);
	//vUp = _vec4(0.f, 1.f, 0.f, 0.f);
	//vLook = _vec4(0.f, 0.f, 1.f, 0.f);
	//vPos = _vec4(0.f, 0.f, 5.f, 1.f);
	//
	//memcpy(&m_matWorld.m[0][0], &vRight, sizeof(_vec4));
	//memcpy(&m_matWorld.m[1][0], &vUp, sizeof(_vec4));
	//memcpy(&m_matWorld.m[2][0], &vLook, sizeof(_vec4));
	//memcpy(&m_matWorld.m[3][0], &vPos, sizeof(_vec4));
	//
	//// 뷰스페이스 변환 행렬
	//D3DXMatrixLookAtLH(&m_matView,
	//	&_v3(0.f, 0.f, 0.f),
	//	&_v3(0.f, 0.f, 10.f),
	//	&_v3(0.f, 1.f, 0.f));
	//
	//// 원근 투영 변환 행렬
	//D3DXMatrixPerspectiveFovLH(&m_matProj,
	//	D3DXToRadian(60.f),
	//	_float(WINCX) / WINCY,
	//	0.1f,
	//	1000.f);
}

CScene_Stage_01* CScene_Stage_01::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	NULL_CHECK_RETURN(pGraphicDev, nullptr);

	CScene_Stage_01* pInstance = new CScene_Stage_01(pGraphicDev);

	if (FAILED(pInstance->Initialize()))
	{
		ENGINE::Safe_Release(pInstance);
		return nullptr;
	}

	return pInstance;
}

void CScene_Stage_01::Free()
{
	ENGINE::CScene::Free();
}
