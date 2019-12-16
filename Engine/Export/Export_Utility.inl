// Management
// Get
// Set
// General
HRESULT		Create_Management(CManagement** ppManagement)
{
	CManagement*		pManagement = CManagement::GetInstance();

	NULL_CHECK_RETURN(pManagement, E_FAIL);

	*ppManagement = pManagement;

	return S_OK;
}

CManagement* Get_Management()
{
	return CManagement::GetInstance();
}

// ComponentMgr

HRESULT	Ready_ComponentMgr()
{
	return CComponentMgr::GetInstance()->Ready_ComponentMgr();
}

HRESULT	Reserve_Size_Component(const _ushort& wSize)
{
	return CComponentMgr::GetInstance()->Reserve_ContainerSize(wSize);
}

HRESULT	Ready_Component(
	const _ushort& wContainerIdx,
	const _tchar* pComponentTag,
	COMP_TYPE eID)
{
	return CComponentMgr::GetInstance()->Ready_Component(wContainerIdx, pComponentTag, eID);
}

CComponent*	Clone_Com(const _ushort& wContainerIdx, const _tchar* pComponentTag)
{
	return  CComponentMgr::GetInstance()->Clone(wContainerIdx, pComponentTag);
}

// CameraMgr

const _mat& Get_ViewMat()
{
	return CCameraMgr::GetInstance()->Get_ViewMat();
}

const _mat& Get_ProjMat()
{
	return CCameraMgr::GetInstance()->Get_ProjMat();
}

const _v3& Get_Right()
{
	return CCameraMgr::GetInstance()->Get_Right();
}
const _v3& Get_Up()
{
	return CCameraMgr::GetInstance()->Get_Up();
}
const _v3& Get_Look()
{
	return CCameraMgr::GetInstance()->Get_Look();
}

const _v3& Get_Pos()
{
	return CCameraMgr::GetInstance()->Get_Pos();
}

const _float& Get_XAngle()
{
	return CCameraMgr::GetInstance()->Get_XAngle();
}

HRESULT	Reserve_Size_Camera(const _ushort& wSize)
{
	return CCameraMgr::GetInstance()->Reserve_ContainerSize(wSize);
}

HRESULT	Ready_Camera(LPDIRECT3DDEVICE9 pGraphicDev,
	const _ushort& _eCameraClass,
	const _tchar* pCameraTag,
	CameraView _CameraView,
	CameraMode _CameraMode)
{
	return CCameraMgr::GetInstance()->Ready_Camera(pGraphicDev, _eCameraClass, pCameraTag, _CameraView, _CameraMode);
}

HRESULT Set_CamTarget(CGameObject* _pTarget)
{
	return CCameraMgr::GetInstance()->Set_Target(_pTarget);
}

void Set_MainCamera(const _ushort & _eCameraClass, const _tchar * pCameraTag)
{
	CCameraMgr::GetInstance()->Set_MainCamera(_eCameraClass, pCameraTag);
}

void Change_MainCam(const _ushort& _eCameraClass, const _tchar* pCameraTag, _bool _bDelay)
{
	CCameraMgr::GetInstance()->Change_MainCam(_eCameraClass, pCameraTag, _bDelay);
}

void Set_CamView(ENGINE::CameraView _eCamViewType)
{
	CCameraMgr::GetInstance()->Set_CamView(_eCamViewType);
}

void Set_CamMode(ENGINE::CameraMode _eCamMode)
{
	CCameraMgr::GetInstance()->Set_CamMode(_eCamMode);
}

// Release Utility
void			Release_Utility(void)
{
	CCameraMgr::GetInstance()->DestroyInstance();
	CComponentMgr::GetInstance()->DestroyInstance();
	CManagement::GetInstance()->DestroyInstance();
}