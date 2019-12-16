#include "stdafx.h"
#include "Scene_Logo.h"
#include "SceneSelector.h"

#include "LogoBack.h"
#include "Camera_Master.h"
#include "Player.h"
#include "Camera.h"
#include "Dynamic_Camera.h"
#include "TmpTerrain.h"

CScene_Logo::CScene_Logo(LPDIRECT3DDEVICE9 pGraphicDev)
	: ENGINE::CScene(pGraphicDev), m_pManagement(nullptr)
{
}

CScene_Logo::~CScene_Logo()
{
}

void CScene_Logo::Update_Scene(const _float& fTimeDelta)
{
	ENGINE::CScene::Update_Scene(fTimeDelta);

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		//ENGINE::Set_MainCamera(ENGINE::DYNAMIC_CAM, L"Player_SholderCam");
		//ENGINE::Set_Cam
	}
}

void CScene_Logo::LateUpdate_Scene()
{
	ENGINE::CScene::LateUpdate_Scene();

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		m_pGraphicDev->AddRef();
		HRESULT hr = m_pManagement->SceneChange(CSceneSelector(CSceneSelector::STAGE_01), m_pGraphicDev);
	}
}

void CScene_Logo::Render_Scene()
{
	ENGINE::CScene::Render_Scene();
}

HRESULT CScene_Logo::Add_Environment_Layer()
{
	return S_OK;
}

HRESULT CScene_Logo::Add_Object_Layer()
{
	// Object Layer
	ENGINE::CLayer* pObject_Layer = ENGINE::CLayer::Create();
	NULL_CHECK_RETURN(pObject_Layer, E_FAIL);
	m_mapLayer.insert({ ENGINE::LAYER_OBJ, pObject_Layer });

	// Add Object
	ENGINE::CGameObject* pObject = CPlayer::Create(m_pGraphicDev);
	m_mapLayer[ENGINE::LAYER_OBJ]->AddObject(ENGINE::PLAYER, pObject);
	NULL_CHECK_RETURN(pObject, E_FAIL);

	ENGINE::Set_CamTarget(pObject);

	//pObject = CLogoBack::Create(m_pGraphicDev);
	//m_mapLayer[ENGINE::LAYER_OBJ]->AddObject(ENGINE::UI, pObject);
	//NULL_CHECK_RETURN(pObject, E_FAIL);

	pObject = CTmpTerrain::Create(m_pGraphicDev);
	m_mapLayer[ENGINE::LAYER_OBJ]->AddObject(ENGINE::BACKGORUND, pObject);
	NULL_CHECK_RETURN(pObject, E_FAIL);

	return S_OK;
}

HRESULT CScene_Logo::Add_UI_Layer()
{
	return S_OK;
}

HRESULT CScene_Logo::Initialize()
{
	HRESULT hr = 0;

	FAILED_CHECK_RETURN(SetUp_PineLine(), E_FAIL);
	FAILED_CHECK_RETURN(SetUp_Camera(), E_FAIL);
	FAILED_CHECK_RETURN(SetUp_Buffer(), E_FAIL);
	FAILED_CHECK_RETURN(SetUp_Texture(), E_FAIL);

	FAILED_CHECK_RETURN(Add_Environment_Layer(), E_FAIL);
	FAILED_CHECK_RETURN(Add_Object_Layer(), E_FAIL);
	FAILED_CHECK_RETURN(Add_UI_Layer(), E_FAIL);

	return S_OK;
}

HRESULT CScene_Logo::SetUp_PineLine()
{
	HRESULT hr = 0;

	ENGINE::Ready_ComponentMgr();
	ENGINE::Reserve_Size_Render(ENGINE::RESOURCE_END);
	ENGINE::Reserve_Size_Camera(ENGINE::RESOURCE_END);

	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, FALSE);
	m_pGraphicDev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	m_pManagement = ENGINE::Get_Management();
	m_pManagement->Addref();

	return S_OK;
}

HRESULT CScene_Logo::SetUp_Camera()
{
	HRESULT hr = 0;

	ENGINE::Ready_Camera(m_pGraphicDev,
		ENGINE::DYNAMIC_CAM, L"Player_BackCam",
		ENGINE::BACK_VIEW,
		ENGINE::DEFAULT_MODE);

	ENGINE::Ready_Camera(m_pGraphicDev,
		ENGINE::DYNAMIC_CAM, L"Player_SholderCam",
		ENGINE::SHOLDER_VIEW,
		ENGINE::DEFAULT_MODE);

	ENGINE::Ready_Camera(m_pGraphicDev,
		ENGINE::DYNAMIC_CAM, L"Player_QuaterCam",
		ENGINE::QUATER_VIEW,
		ENGINE::DEFAULT_MODE);

	ENGINE::Set_MainCamera(ENGINE::DYNAMIC_CAM, L"Player_BackCam");

	return S_OK;
}

HRESULT CScene_Logo::SetUp_Buffer()
{
	HRESULT hr = 0;

	_short sTerrainX = 129;
	_short sTerrainZ = 129;
	_short sIn		= 1;

	ENGINE::Ready_Buffers(m_pGraphicDev, ENGINE::RESOURCE_STATIC, L"Buffer_TriCol", ENGINE::BUFFER_TRICOL);
	ENGINE::Ready_Buffers(m_pGraphicDev, ENGINE::RESOURCE_STATIC, L"Buffer_RcCol", ENGINE::BUFFER_RCCOL);
	ENGINE::Ready_Buffers(m_pGraphicDev, ENGINE::RESOURCE_STATIC, L"Buffer_RcTex", ENGINE::BUFFER_RCTEX);
	ENGINE::Ready_Buffers(m_pGraphicDev, ENGINE::RESOURCE_STATIC, L"Buffer_TerrainTex", ENGINE::BUFFER_TERRAINTEX, sTerrainX, sTerrainZ, sIn);

	return S_OK;
}

HRESULT CScene_Logo::SetUp_Texture()
{
	HRESULT hr = 0;

	ENGINE::Ready_Texture(
		m_pGraphicDev,
		ENGINE::RESOURCE_STATIC,
		L"DOGE",
		ENGINE::TEX_NORMAL,
		L"../Texture/UI/Logo/DOGE.png", 1);
	FAILED_CHECK_MSG(hr, L"DOGE.png");

	ENGINE::Ready_Texture(
		m_pGraphicDev,
		ENGINE::RESOURCE_STATIC,
		L"Texture_Terrain",
		ENGINE::TEX_NORMAL,
		L"../Texture/Terrain/Terrain_0.png", 1);
	FAILED_CHECK_MSG(hr, L"Texture_Terrain.png");

	return S_OK;
}

CScene_Logo* CScene_Logo::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	NULL_CHECK_RETURN(pGraphicDev, nullptr);

	CScene_Logo* pInstance = new CScene_Logo(pGraphicDev);

	if (FAILED(pInstance->Initialize()))
	{
		ENGINE::Safe_Release(pInstance);
		return nullptr;
	}

	return pInstance;
}

void CScene_Logo::Free()
{
	ENGINE::Safe_Release(m_pGraphicDev);
	
	ENGINE::Safe_Release(m_pManagement);

	ENGINE::CScene::Free();
}
