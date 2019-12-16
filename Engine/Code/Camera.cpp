#include "Camera.h"

USING(ENGINE)

CCamera::CCamera(LPDIRECT3DDEVICE9 pGraphicDev)
	: ENGINE::CGameObject(pGraphicDev),
	m_pTransform(nullptr),
	m_eCamClass(STATIC_CAM), m_eCamView(THIRD_VIEW), m_eCamMode(DEFAULT_MODE),
	m_fNear(0), m_fFar(0), m_fFov(0)
{
	D3DXMatrixIdentity(&m_MatView);
}


CCamera::~CCamera()
{
}

void CCamera::Walk_V(_float _Speed)
{
	switch (m_eCamMode)
	{
	case DEFAULT_MODE:
	{
		m_pTransform->Set_Pos(_v3(m_pTransform->Get_Right().x, 0.f, m_pTransform->Get_Right().z) * _Speed);
		m_pTransform->Set_At(_v3(m_pTransform->Get_Right().x, 0.f, m_pTransform->Get_Right().z) * _Speed);

		break;
	}
	case FLY_MODE:
	{
		m_pTransform->Set_Pos(m_pTransform->Get_Right() * _Speed);
		m_pTransform->Set_At(m_pTransform->Get_Right() * _Speed);
		break;
	}
	}
}

void CCamera::Walk_H(_float _Speed)
{
	_v3 vDir, vWorldUp;
	vWorldUp = { 0.f , 1.f ,0.f };

	D3DXVec3Cross(&vDir, &m_pTransform->Get_Right(), &vWorldUp);

	switch (m_eCamMode)
	{
	case DEFAULT_MODE:
	{
		m_pTransform->Set_Pos(_v3(vDir.x, 0.f, vDir.z) * _Speed);
		m_pTransform->Set_At(_v3(vDir.x, 0.f, vDir.z) * _Speed);

		break;
	}
	case FLY_MODE:
	{
		m_pTransform->Set_Pos(vDir * _Speed);
		m_pTransform->Set_At(vDir * _Speed);

		break;
	}
	}
}

void CCamera::Rotate_X(_float _Angle)
{
	_mat T;
	_v3 tmpUp, tmpLook;

	D3DXMatrixRotationAxis(&T, &m_pTransform->Get_Right(), D3DXToRadian(_Angle));

	D3DXVec3TransformCoord(&tmpUp, &m_pTransform->Get_Up(), &T);
	D3DXVec3TransformCoord(&tmpLook, &m_pTransform->Get_Look(), &T);

	m_pTransform->Set_Up(tmpUp);
	m_pTransform->Set_Look(tmpLook);
}

void CCamera::Rotate_Y(_float _Angle)
{
	_v3  vView, vWorldUp;
	_mat T;

	switch (m_eCamMode)
	{
	case DEFAULT_MODE:
	{
		vWorldUp = { 0,1,0 };

		vView = m_pTransform->Get_At()- m_pTransform->Get_Pos();

		D3DXMatrixRotationAxis(&T, &vWorldUp, D3DXToRadian(_Angle));
		D3DXVec3TransformCoord(&vView, &vView, &T);

		m_pTransform->Set_At(m_pTransform->Get_Pos() + vView);
		break;
	}
	case FLY_MODE:
	{
		D3DXMatrixRotationAxis(&T, &m_pTransform->Get_Up(), D3DXToRadian(_Angle));
		break;
	}
	}


	_v3 vTmpRight, vTempLook;

	D3DXVec3TransformCoord(&vTmpRight, &m_pTransform->Get_Right(), &T);
	D3DXVec3TransformCoord(&vTempLook, &m_pTransform->Get_Look(), &T);

	m_pTransform->Set_Right(vTmpRight);
	m_pTransform->Set_Look(vTempLook);
}

void CCamera::Rotate_Z(_float _Angle)
{
	_mat T;

	switch (m_eCamMode)
	{
	case DEFAULT_MODE:
	{
		_v3  vView;

		vView = m_pTransform->Get_At() - m_pTransform->Get_Pos();

		D3DXMatrixRotationAxis(&T, &m_pTransform->Get_Look(), D3DXToRadian(_Angle));
		D3DXVec3TransformCoord(&vView, &vView, &T);

		m_pTransform->Set_At(m_pTransform->Get_Pos() + vView);
		break;
	}
	case FLY_MODE:
	{
		D3DXMatrixRotationAxis(&T, &m_pTransform->Get_Look(), D3DXToRadian(_Angle));
		break;
	}
	}

	_v3 vTmpRight, vTmpUp;

	D3DXVec3TransformCoord(&vTmpRight, &m_pTransform->Get_Right(), &T);
	D3DXVec3TransformCoord(&vTmpUp, &m_pTransform->Get_Up(), &T);

	m_pTransform->Set_Right(vTmpRight);
	m_pTransform->Set_Up(vTmpUp);
}

void CCamera::SetUp_ViewMat()
{
	D3DXMatrixLookAtLH(&m_MatView, &m_pTransform->Get_Pos(), &m_pTransform->Get_At(), &m_pTransform->Get_Up());
}

void CCamera::SetUp_ProjMat()
{
	D3DXMatrixPerspectiveFovLH(&m_MatProj, D3DXToRadian(m_fFov), WINCX / (float)WINCY, m_fNear, m_fFar);
}

void CCamera::Set_CameraMode(CameraMode _CameraType)
{
}

_float CCamera::Get_XAngle()
{
	return m_fX_LockAngle;
}

void CCamera::SetUp_ViewType(CameraView _CameraViewType)
{
	switch (_CameraViewType)
	{
	case FIRST_VIEW:
	{
		switch (m_eCamMode)
		{
		case DEFAULT_MODE:
		{
			_v3 vTemp_TargetPos = dynamic_cast<ENGINE::CTransform*>(m_pTarget->Get_Component(L"Transform"))->Get_Pos();
			m_pTransform->Set_Pos({ vTemp_TargetPos.x, vTemp_TargetPos.y + 5 ,vTemp_TargetPos.z });
			m_pTransform->Set_At({ vTemp_TargetPos.x, vTemp_TargetPos.y + 2 ,vTemp_TargetPos.z + 1 });
		}

		}

		//SetUp_MouseRotate();

		//POINT pt;
		//pt.x = WINCX / 2;
		//pt.y = WINCY / 2;

		//ClientToScreen(g_hWnd, &pt);
		//SetCursorPos(pt.x, pt.y);

		break;
	}
	case THIRD_VIEW:
	{
		//_v3 vTemp_TargetPos = dynamic_cast<ENGINE::CTransform*>(m_pTarget->Get_Component(L"Transform"))->Get_Pos();
		//m_pTransform->Set_Pos({ vTemp_TargetPos.x, vTemp_TargetPos.y - 1 ,vTemp_TargetPos.z });
		//m_pTransform->Set_At({ vTemp_TargetPos.x, vTemp_TargetPos.y + 1 ,vTemp_TargetPos.z + 1 });
		break;

	}

	case BACK_VIEW:
	{
		CTransform* vTrans = static_cast<ENGINE::CTransform*>(m_pTarget->Get_Component(L"Transform"));

		D3DXMATRIX matRotAxis;
		_v3 vDir, vRight_2;
		_v3 vEyePos = m_pTransform->Get_Pos();
		_v3 vRight = m_pTransform->Get_Right();
		_v3 vUp = m_pTransform->Get_Up();
		_v3 vAt = vTrans->Get_Pos();
		_v3 vWorldRight = { 1,0,0 };
		_v3 vWorldUp = { 0,1,0 };

		vEyePos = -m_pTransform->Get_Look();
		V3_NORMAL_S(&vEyePos);

		vEyePos *= m_fDistance;

		CALC::V3_Axis_Normal(&matRotAxis, &vEyePos, &vRight, m_fY_LockAngle, true);
		CALC::V3_Axis_Normal(&matRotAxis, &vEyePos, &vWorldUp, m_fX_LockAngle - 22.5f, true);

		CALC::V3_Dir_Normal(&vDir, &m_pTransform->Get_Pos(), &vTrans->Get_Pos());
		CALC::V3_Cross_Normal(&vRight_2, &_v3{ 0,1,0 }, &vDir);

		vEyePos += vTrans->Get_Pos();
		vAt = vTrans->Get_Pos() + _v3{ vRight_2.x * -3.f  , 4.f , vRight_2.z * -3.f };

		m_pTransform->Set_Pos(vEyePos);
		m_pTransform->Set_At(vAt);

		// 화면 중앙 레이

		//D3DVIEWPORT9 vp = {};
		//D3DXMATRIX matProj, matView, matInView;
		//POINT ptCursor;
		//_v3 vOriginal = m_pTransform->Get_Pos();
		//_v3 vDirection = {};
		//
		//m_pGraphicDev->GetViewport(&vp); 
		//m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);
		//
		//GetCursorPos(&ptCursor); 
		//ScreenToClient(ENGINE::CKeyMgr::GetInstance()->Get_Handle(), &ptCursor);
		//
		//vDirection.x = ((2.0f * ptCursor.x) / vp.Width - 1.0f) / matProj._11;
		//vDirection.y = ((-2.0f * ptCursor.y) / vp.Height + 1.0f) / matProj._22;
		//vDirection.z = 1.f;
		//
		//m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
		//D3DXMatrixInverse(&matInView, 0, &matView);
		//
		//D3DXVec3TransformCoord(&vOriginal, &vOriginal, &matInView);
		//D3DXVec3TransformNormal(&vDirection, &vDirection, &matInView);
		//D3DXVec3Normalize(&vDirection, &vDirection);
		//
		//
		//cout << m_pTransform->Get_Pos().x << endl;
		//cout << vOriginal.x << endl;
		//cout << vOriginal.y << endl;

		m_pTransform->Set_At(vAt);

		break;

	}

	}

}

void CCamera::SetUp_Zoom()
{
	//if (m_pKeyMgr->KeyPressing(ENGINE::KEY_SPACE))
	//{
	//	if (m_tCamInfo.fDistance > m_fZoom_Min)
	//		m_tCamInfo.fDistance += -0.1f;
	//}
	//
	//if (GetAsyncKeyState('X'))
	//{
	//	if (m_tCamInfo.fDistance < m_fZoom_Max)
	//		m_tCamInfo.fDistance += 0.1f;
	//}
}

void CCamera::SetUp_MouseRotate()
{
	m_MousePoint = CKeyMgr::GetInstance()->Get_MouseGap();

	float	fAngle = 0.f;
	_mat	matRot;
	_v3		vDir;

	if (m_eCamView == FIRST_VIEW || m_eCamView == THIRD_VIEW)
	{
		if (m_MousePoint.x != 0)
		{
			_v3 tmpRight, tmpUp, tmpLook;
			_v3 tmpEyePos;

			m_fX_Angle = m_MousePoint.x * 0.5f;
			m_fX_LockAngle += m_fX_Angle;

			D3DXMatrixRotationY(&matRot, D3DXToRadian(m_fX_Angle));

			memcpy(&matRot._41, &m_pTransform->Get_Pos(), sizeof(_v3));

			vDir = m_pTransform->Get_At() - m_pTransform->Get_Pos();

			// x 축 재조정
			D3DXVec3TransformNormal(&tmpRight, &m_pTransform->Get_Right(), &matRot);
			D3DXVec3Normalize(&tmpRight, &tmpRight);
			m_pTransform->Set_Right(tmpRight);

			// y 축 재조정
			D3DXVec3TransformNormal(&tmpUp, &m_pTransform->Get_Up(), &matRot);
			D3DXVec3Normalize(&tmpUp, &tmpUp);
			m_pTransform->Set_Up(tmpUp);

			// z 축 재조정
			D3DXVec3TransformNormal(&tmpLook, &m_pTransform->Get_Look(), &matRot);
			D3DXVec3Normalize(&tmpLook, &tmpLook);
			m_pTransform->Set_Look(tmpLook);

			// 카메라 위치 재조정
			D3DXVec3TransformCoord(&tmpEyePos, &vDir, &matRot);
			m_pTransform->Set_At(tmpEyePos);

		}

		if (m_MousePoint.y != 0)
		{
			m_fY_Angle = m_MousePoint.y * 0.5f;

			if (fabs(m_fY_LockAngle) < fabs(m_fY_MaxLockAngle))
			{
				m_fY_LockAngle += m_fY_Angle;
			}

			else if (fabs(m_fY_LockAngle) >= fabs(m_fY_MaxLockAngle))
			{
				if (m_fY_LockAngle >= m_fY_MaxLockAngle && m_fY_Angle < 0)
				{
					m_fY_LockAngle += m_fY_Angle;
				}

				if (m_fY_LockAngle <= m_fY_MaxLockAngle && m_fY_Angle > 0)
				{
					m_fY_LockAngle += m_fY_Angle;
				}
			}

			_v3 tmpRight, tmpUp, tmpLook;
			_v3 tmpEyePos;

			D3DXMatrixRotationAxis(&matRot, &m_pTransform->Get_Right(), D3DXToRadian(m_fY_Angle));
			memcpy(&matRot._41, &m_pTransform->Get_Pos(), sizeof(_v3));

			vDir = m_pTransform->Get_At() - m_pTransform->Get_Pos();

			// x 축 재조정
			D3DXVec3TransformNormal(&tmpRight, &m_pTransform->Get_Right(), &matRot);
			D3DXVec3Normalize(&tmpRight, &tmpRight);
			m_pTransform->Set_Right(tmpRight);
			
			// z 축 재조정
			D3DXVec3TransformNormal(&tmpLook, &m_pTransform->Get_Look(), &matRot);
			D3DXVec3Normalize(&tmpLook, &tmpLook);
			m_pTransform->Set_Look(tmpLook);

			// 카메라 위치 재조정
			D3DXVec3TransformCoord(&tmpEyePos, &vDir, &matRot);
			m_pTransform->Set_At(tmpEyePos);
		}
	}

	else
	{
		if (m_MousePoint.x != 0)
		{
			m_fX_Angle = m_MousePoint.x * 0.5f;
			m_fX_LockAngle += m_fX_Angle;
		}

		if (m_MousePoint.y != 0)
		{
			m_fY_Angle = m_MousePoint.y * 0.5f;

			if (fabs(m_fY_LockAngle) < fabs(m_fY_MaxLockAngle))
			{
				m_fY_LockAngle += m_fY_Angle;
			}

			else if (fabs(m_fY_LockAngle) >= fabs(m_fY_MaxLockAngle))
			{
				if (m_fY_LockAngle >= m_fY_MaxLockAngle && m_fY_Angle < 0)
				{
					m_fY_LockAngle += m_fY_Angle;
				}

				if (m_fY_LockAngle <= m_fY_MaxLockAngle && m_fY_Angle > 0)
				{
					m_fY_LockAngle += m_fY_Angle;
				}
			}
		}
	}
}

void CCamera::SetUp_Default()
{
	// Proj
	m_fFov = 60.f;
	m_fNear = 0.1f;
	m_fFar = 1000.f;

	// Zoom
	m_fZoom_Max = 10.f;
	m_fZoom_Min = 1.0f;
	m_fZoom_Speed = 3.0f;
	m_fZoom_Cur = 0.f;

	// Pos
	m_fDistance = 10.f;;
	m_fEyeHeight = 0.f;
	m_fLength = 0.f;
	m_bChange = false;

	// Rotate
	m_fX_Angle = 0.f;
	m_fY_Angle = 0.f;
	m_fX_LockAngle = 0.f;
	m_fY_LockAngle = 45.f;
	m_fX_MaxLockAngle = 360.f;
	m_fY_MaxLockAngle = 70.f;

	// Position
	m_pTransform->Set_Pos({ 0,0,0 });
	m_pTransform->Set_Right({ 1,0,0 });
	m_pTransform->Set_Up({ 0,1,0 });
	m_pTransform->Set_Look({ 0,0,1 });
	m_pTransform->Set_At({ 0,0,1 });
}

_v3 CCamera::Get_Pos()
{
	return m_pTransform->Get_Pos();
}

_v3 CCamera::Get_LookAt()
{
	return m_pTransform->Get_At();
}

_v3 CCamera::Get_Look()
{
	return m_pTransform->Get_Look();
}

_v3 CCamera::Get_Right()
{
	return m_pTransform->Get_Right();
}

_v3 CCamera::Get_Up()
{
	return m_pTransform->Get_Pos();
}

_mat CCamera::Get_ViewMat()
{
	return m_MatView;
}

_mat CCamera::Get_ProjMat()
{
	return m_MatProj;
}

void CCamera::KeyInput()
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
		m_pTransform->Add_Pos(fMoveSpeed , _v3(0,1,0));
		m_pTransform->Add_At(-fMoveSpeed, _v3(0, 1, 0));
	}

	if (GetAsyncKeyState(VK_LCONTROL) & 0x8000)
	{
		m_pTransform->Add_Pos(-fMoveSpeed, _v3(0, 1, 0));
		m_pTransform->Add_At(-fMoveSpeed, _v3(0, 1, 0));
	}
}

_int CCamera::Update()
{
	return NO_EVENT;
}

void CCamera::LateUpdate()
{
}

void CCamera::Render()
{
}

HRESULT CCamera::Initialize()
{
	return S_OK;
}

HRESULT CCamera::LateInit()
{
	return S_OK;
}

void CCamera::Free()
{
	ENGINE::CGameObject::Free();
}
