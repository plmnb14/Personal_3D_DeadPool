#include "CameraMgr.h"

USING(ENGINE)

IMPLEMENT_SINGLETON(CCameraMgr)

CCameraMgr::CCameraMgr(void)
	: m_bDelay(false), m_bChange(false)
{

}

CCameraMgr::~CCameraMgr(void)
{
	Free();
}

void CCameraMgr::Update()
{
	if (m_MainCamera != nullptr)
	{
		m_MainCamera->Update();

		if(m_bChange)
			Set_MainCamera(m_sCamClass, m_pCamTag);
	}
}


HRESULT CCameraMgr::Reserve_ContainerSize(const _ushort& wSize)
{
	if (nullptr != m_pmapCamera)
		return E_FAIL;

	m_pmapCamera = new map<const _tchar*, CCamera*>[wSize];

	m_wContainerSize = wSize;

	return S_OK;
}

HRESULT CCameraMgr::Ready_Camera(LPDIRECT3DDEVICE9 pGraphicDev,
								const _ushort& _eCameraClass,
								const _tchar* pCameraTag,
								CameraView _eCameraView,
								CameraMode _eCameraMode)
{
	if (nullptr == m_pmapCamera)
	{
		MSG_BOX("Renderer Container not Reserved");
		return E_FAIL;
	}

	CCamera* pCamera = Find_Camera(_eCameraClass, pCameraTag);

	if (nullptr != pCamera)
		return E_FAIL;

	switch (_eCameraClass)
	{
	case ENGINE::DYNAMIC_CAM:
	{
		pCamera = CDynamic_Camera::Create(pGraphicDev, _eCameraView, _eCameraMode);
		break;
	}
	}

	NULL_CHECK_RETURN(pCamera, E_FAIL);

	m_pmapCamera[_eCameraClass].emplace(pCameraTag, pCamera);

	return S_OK;
}

void CCameraMgr::Set_MainCamera(const _ushort & _eCameraClass, const _tchar * pCameraTag)
{
	if (m_MainCamera == nullptr)
	{
		m_MainCamera = Find_Camera(_eCameraClass, pCameraTag);
		m_bChange = false;
		return;
	}

	else if (m_MainCamera != nullptr)
	{
		CCamera* tmpCam = Find_Camera(_eCameraClass, pCameraTag);

		if (Calc_Distance(m_MainCamera, tmpCam, &m_vDistance))
		{
			m_MainCamera = Find_Camera(_eCameraClass, pCameraTag);
			m_bChange = false;
			return;
		}
	}
}

HRESULT CCameraMgr::Set_Target(CGameObject * _Target)
{
	if (m_MainCamera != nullptr)
	{
		m_MainCamera->Set_Target(_Target);
	}

	return S_OK;
}

void CCameraMgr::Change_MainCam(const _ushort & _eCameraClass, const _tchar * pCameraTag, _bool _bDelay)
{
	if (!m_bChange)
	{
		if(m_pCamTag != nullptr)
			m_pCamTag = nullptr;

		_tchar* tmpChar = new _tchar[128];

		lstrcpy(tmpChar, pCameraTag);
		m_pCamTag = tmpChar;

		m_bDelay = _bDelay;
		m_sCamClass = _eCameraClass;
		m_bChange = true;
	}
}

void CCameraMgr::Set_CamView(ENGINE::CameraView _eCamViewType)
{
	m_MainCamera->Set_CameraViewType(_eCamViewType);
}

void CCameraMgr::Set_CamMode(ENGINE::CameraMode _eCamMode)
{
	m_MainCamera->Set_CameraMode(_eCamMode);
}



const _mat& CCameraMgr::Get_ViewMat()
{
	m_matView = m_MainCamera->Get_ViewMat();
	return m_matView;
}

const _mat& CCameraMgr::Get_ProjMat()
{
	m_matProj = m_MainCamera->Get_ProjMat();
	return m_matProj;
}

const _v3 & CCameraMgr::Get_Right()
{
	m_vRight = m_MainCamera->Get_Right();
	return m_vRight;
}

const _v3 & CCameraMgr::Get_Up()
{
	m_vUp = m_MainCamera->Get_Up();
	return m_vUp;
}

const _v3 & CCameraMgr::Get_Look()
{
	m_vLook = m_MainCamera->Get_Look();
	return m_vLook;
}

const _v3 & CCameraMgr::Get_Pos()
{
	m_vPos = m_MainCamera->Get_Pos();
	return m_vPos;
}

const _float & CCameraMgr::Get_XAngle()
{
	m_fX_Angle = m_MainCamera->Get_XAngle();
	return m_fX_Angle;
}

CCamera* CCameraMgr::Find_Camera(const _ushort& _eCameraClass, const _tchar* pCameraTag)
{
	auto	iter = find_if(m_pmapCamera[_eCameraClass].begin(), m_pmapCamera[_eCameraClass].end(), CTag_Finder(pCameraTag));

	if (iter == m_pmapCamera[_eCameraClass].end())
		return nullptr;

	return iter->second;
}

_bool CCameraMgr::Calc_Distance(CCamera * _pOld, CCamera * _pNew, _v3 * _Distance)
{
	_v3 tmpDir , vOld, vNew;

	vOld = TARGET_TO_TRANS(_pOld)->Get_Pos();
	vNew = TARGET_TO_TRANS(_pNew)->Get_Pos();


	*_Distance = vOld - vNew;
	m_fLength = D3DXVec3Length(&(vOld - vNew));


	CALC::V3_Dir_Normal(&tmpDir, &vOld, &vNew);

	TARGET_TO_TRANS(_pOld)->Add_Pos(10.f, tmpDir);

	return (m_fLength <= 0 ? true : false);
}

void CCameraMgr::Free(void)
{
	for (_ushort i = 0; i < m_wContainerSize; ++i)
	{
		for_each(m_pmapCamera[i].begin(), m_pmapCamera[i].end(), CDeleteMap());
		m_pmapCamera[i].clear();
	}

	Safe_Delete_Array(m_pmapCamera);
}



