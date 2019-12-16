#include "Dynamic_Camera.h"

USING(ENGINE)

CDynamic_Camera::CDynamic_Camera(LPDIRECT3DDEVICE9 pGraphicDev)
	: ENGINE::CCamera(pGraphicDev)
{
}


CDynamic_Camera::~CDynamic_Camera()
{
}

void CDynamic_Camera::KeyInput()
{
	if (m_eCamMode != FLY_MODE)
		return;

	float fMoveSpeed = 0.05f;
	if (GetAsyncKeyState('W') & 0x8000)
	{
		Walk_H(fMoveSpeed);
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		Walk_H(-fMoveSpeed);
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		Walk_V(-fMoveSpeed);
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		Walk_V(fMoveSpeed);
	}

	if (GetAsyncKeyState('R') & 0x8000)
	{
		Rotate_X(-fMoveSpeed * 1.5f);
	}

	if (GetAsyncKeyState('F') & 0x8000)
	{
		Rotate_X(fMoveSpeed * 1.5f);
	}

	if (GetAsyncKeyState('Q') & 0x8000)
	{
		Rotate_Y(-fMoveSpeed * 1.5f);
	}

	if (GetAsyncKeyState('E') & 0x8000)
	{
		Rotate_Y(fMoveSpeed * 1.5f);
	}

	if (GetAsyncKeyState('C') & 0x8000)
	{
		m_fFov -= fMoveSpeed;
	}

	if (GetAsyncKeyState('V') & 0x8000)
	{
		m_fFov += fMoveSpeed;
	}

	if (GetAsyncKeyState(VK_LSHIFT) & 0x8000)
	{
		m_pTransform->Add_Pos(fMoveSpeed, _v3(0, 1, 0));
		m_pTransform->Add_At(-fMoveSpeed, _v3(0, 1, 0));
	}

	if (GetAsyncKeyState(VK_LCONTROL) & 0x8000)
	{
		m_pTransform->Add_Pos(-fMoveSpeed, _v3(0, 1, 0));
		m_pTransform->Add_At(-fMoveSpeed, _v3(0, 1, 0));
	}
}

_int CDynamic_Camera::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;

	SetUp_ViewType(m_eCamView);
	SetUp_MouseRotate();
	CKeyMgr::GetInstance()->Set_MouseLock();

	CCamera::SetUp_ViewMat();
	CCamera::SetUp_ProjMat();

	m_pGraphicDev->SetTransform(D3DTS_VIEW, &m_MatView);
	m_pGraphicDev->SetTransform(D3DTS_PROJECTION, &m_MatProj);

	return NO_EVENT;
}

void CDynamic_Camera::LateUpdate()
{
}

void CDynamic_Camera::Render()
{
}

HRESULT CDynamic_Camera::Initialize()
{
	FAILED_CHECK_RETURN(AddComponent(), E_FAIL);
	CCamera::SetUp_Default();
	CCamera::SetUp_ViewMat();
	CCamera::SetUp_ProjMat();

	m_pTransform->Set_Pos({ 0,0,0 });

	m_pGraphicDev->SetTransform(D3DTS_VIEW, &m_MatView);
	m_pGraphicDev->SetTransform(D3DTS_PROJECTION, &m_MatProj);

	ShowCursor(false);

	return S_OK;
}

HRESULT CDynamic_Camera::LateInit()
{
	return S_OK;
}

void CDynamic_Camera::Free()
{
	ENGINE::CGameObject::Free();
}

HRESULT CDynamic_Camera::AddComponent()
{
	ENGINE::CComponent* pComponent = nullptr;

	pComponent = ENGINE::CComponentMgr::GetInstance()->Clone(ENGINE::RESOURCE_STATIC, L"Transform");
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent.insert({ L"Transform", pComponent });

	m_pTransform = static_cast<ENGINE::CTransform*>(pComponent);
	NULL_CHECK_RETURN(m_pTransform, E_FAIL);

	return S_OK;
}

CDynamic_Camera * CDynamic_Camera::Create(LPDIRECT3DDEVICE9 pGraphicDev, 
										  CameraView _CameraViewType, 
										  CameraMode _CameraMode)
{
	CDynamic_Camera* pInstance = new CDynamic_Camera(pGraphicDev);

	if (FAILED(pInstance->Initialize()))
	{
		ENGINE::Safe_Release(pInstance);
		return nullptr;
	}

	pInstance->m_eCamView = _CameraViewType;
	pInstance->m_eCamMode = _CameraMode;

	return pInstance;
}
