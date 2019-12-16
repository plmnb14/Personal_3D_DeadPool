#ifndef Export_Utility_h__
#define Export_Utility_h__

#include "Management.h"
#include "ComponentMgr.h"
#include "CameraMgr.h"

BEGIN(ENGINE)

// Management
// Get
// Set
// General
inline HRESULT		Create_Management(CManagement** ppManagement);

inline CManagement* Get_Management();

// ComponentMgr

inline HRESULT	Ready_ComponentMgr();

inline HRESULT	Reserve_Size_Component(const _ushort& wSize);

inline HRESULT	Ready_Component(
	const _ushort& wContainerIdx,
	const _tchar* pComponentTag,
	COMP_TYPE eID);

inline CComponent*	Clone_Com(const _ushort& wContainerIdx, const _tchar* pComponentTag);


// CameraMgr

inline const _mat& Get_ViewMat();
inline const _mat& Get_ProjMat();
inline const _v3& Get_Right();
inline const _v3& Get_Up();
inline const _v3& Get_Look();
inline const _v3& Get_Pos();
inline const _float& Get_XAngle();

inline HRESULT	Reserve_Size_Camera(const _ushort& wSize);

inline HRESULT	Ready_Camera(LPDIRECT3DDEVICE9 pGraphicDev,
	const _ushort& _eCameraClass,
	const _tchar* pCameraTag,
	CameraView _CameraView,
	CameraMode _CameraMode);

inline HRESULT Set_CamTarget(CGameObject* _pTarget);

inline void Set_MainCamera(const _ushort & _eCameraClass, const _tchar * pCameraTag);
inline void Change_MainCam(const _ushort& _eCameraClass, const _tchar* pCameraTag, _bool _bDelay = false);
inline void Set_CamView(ENGINE::CameraView _eCamViewType);
inline void Set_CamMode(ENGINE::CameraMode _eCamMode);

// Release Utility
inline void			Release_Utility(void);

#include "Export_Utility.inl"

END
#endif // Export_Utility_h__

