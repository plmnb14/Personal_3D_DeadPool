#include "stdafx.h"
#include "MainApp.h"
#include "SceneSelector.h"

#include "Player.h"
#include "Monster.h"

CMainApp::CMainApp()
	: m_pDeviceMgr(nullptr), m_pManagement(nullptr)
{
}

CMainApp::~CMainApp()
{
}

HRESULT CMainApp::Ready_MainApp()
{
	HRESULT hr = 0;

	ENGINE::CKeyMgr::GetInstance()->Set_Handle(g_hWnd);

	hr = ENGINE::InitDevice(g_hWnd, WINCX, WINCY, ENGINE::MODE_WIN, &m_pDeviceClass);
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL, L"InitDevice Failed");

	m_pDeviceMgr = m_pDeviceClass->Get_Device();
	m_pDeviceMgr->AddRef();

	ENGINE::Create_Management(&m_pManagement);
	m_pManagement->Addref();

	m_pManagement->SceneChange(CSceneSelector(CSceneSelector::LOGO), m_pDeviceMgr);
	m_pDeviceMgr->AddRef();

	return S_OK;
}

_int CMainApp::Update_MainApp(const _float& fDeltaTime)
{
	m_pManagement->Update_Scene(fDeltaTime);

	return 0;
}

void CMainApp::Render_MainApp()
{
	ENGINE::Render_Begin();

	m_pManagement->Render_Scene();

	ENGINE::Render_End();
}

void CMainApp::LateUpdate_MainApp()
{
	m_pManagement->LateUpdate_Scene();
	ENGINE::CKeyMgr::GetInstance()->Update();
}

CMainApp* CMainApp::Create()
{
	CMainApp*	pInstance = new CMainApp;

	if (FAILED(pInstance->Ready_MainApp()))
		ENGINE::Safe_Release(pInstance);

	return pInstance;
}

void CMainApp::Free()
{
	ENGINE::Safe_Release(m_pDeviceMgr);

	ENGINE::Safe_Release(m_pManagement);

	ENGINE::Release_Utility();
	ENGINE::Release_Resources();
	ENGINE::Release_System();

	//_CrtMemDumpAllObjectsSince(0);
}

