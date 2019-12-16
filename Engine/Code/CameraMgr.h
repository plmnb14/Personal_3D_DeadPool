#ifndef CameraMgr_h__
#define CameraMgr_h__

#include "Engine_Defines.h"
#include "Base.h"

#include "Camera.h"
#include "Dynamic_Camera.h"


BEGIN(ENGINE)

class ENGINE_DLL CCameraMgr : public CBase
{
	DECLARE_SINGLETON(CCameraMgr)

public:

private:
	explicit CCameraMgr(void);
	virtual ~CCameraMgr(void);

public:
	void Update();

public:
	HRESULT	Reserve_ContainerSize(const _ushort& wSize);

	HRESULT	Ready_Camera(LPDIRECT3DDEVICE9 pGraphicDev,
						const _ushort& _eCameraClass,
						const _tchar* pCameraTag,
						CameraView _CameraView,
						CameraMode _CameraMode);

	void Set_MainCamera(const _ushort& _eCameraClass, const _tchar* pCameraTag);

	HRESULT Set_Target(CGameObject* _Target);

public:
	void Change_MainCam(const _ushort& _eCameraClass, const _tchar* pCameraTag, _bool _bDelay = false);
	void Set_CamView(ENGINE::CameraView _eCamViewType);
	void Set_CamMode(ENGINE::CameraMode _eCamMode);

public:
	const _mat& Get_ViewMat();
	const _mat& Get_ProjMat();

	const _v3& Get_Right();
	const _v3& Get_Up();
	const _v3& Get_Look();
	const _v3& Get_Pos();

	const _float& Get_XAngle();

private:
	CCamera* Find_Camera(const _ushort& _eCameraClass, const _tchar* pCameraTag);
	_bool Calc_Distance(CCamera* _pOld , CCamera* _pNew, _v3* _Distance);
	

private:
	CCamera*							m_MainCamera;
	map<const _tchar*, CCamera*>*		m_pmapCamera;
	_ushort								m_wContainerSize;

private:
	_mat	m_matView;
	_mat	m_matProj;
	_v3		m_vRight;
	_v3		m_vUp;
	_v3		m_vLook;
	_v3		m_vPos;
	_v3		m_vDistance;

	_float  m_fX_Angle;
	_float	m_fLength;

	_bool	m_bDelay;
	_bool	m_bChange;

	_ushort m_sCamClass;
	_tchar* m_pCamTag;

public:
	virtual void Free(void);

};

END
#endif // ComponentMgr_h__
