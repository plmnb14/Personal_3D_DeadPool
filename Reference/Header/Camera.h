#ifndef Camera_h__
#define Camera_h__

#include "GameObject.h"
#include "ComponentMgr.h"
#include "KeyMgr.h"

BEGIN(ENGINE)

class CTransform;
class ENGINE_DLL CCamera : public CGameObject
{

protected:
	explicit CCamera(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CCamera();

	// 이동
public:
	void Walk_H(_float _Speed);
	void Walk_V(_float _Speed);

	// 축 회전
public:
	void Rotate_X(_float _Angle);
	void Rotate_Y(_float _Angle);
	void Rotate_Z(_float _Angle);

public:
	void SetUp_ViewMat	();
	void SetUp_ProjMat	();
	void SetUp_ViewType	(CameraView _CameraViewType);
	void SetUp_Zoom();
	void SetUp_MouseRotate();
	void SetUp_Default();

public:
	void Set_CameraMode(CameraMode _CameraType);
	void Set_CameraViewType(CameraView _CameraViewType);

private:
	void Change_Type_Option(CameraView _CameraViewType);

public:
	_float		Get_XAngle();

public:
	_v3			Get_Pos();
	_v3			Get_LookAt();
	_v3			Get_Look();
	_v3			Get_Right();
	_v3			Get_Up();

public:
	CameraView	Get_ViewType() { return m_eCamView; }
	_mat		Get_ViewMat();
	_mat		Get_ProjMat();



public:
	void KeyInput();

public:
	virtual _int Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

private:
	virtual HRESULT Initialize() override;
	virtual HRESULT LateInit() override;

public:
	virtual void Free() override;

protected:
	CTransform*		m_pTransform;

protected:	// State
	ENGINE::CameraClass		m_eCamClass;
	ENGINE::CameraMode		m_eCamMode;
	ENGINE::CameraView		m_eCamView;

protected:	// Device Setting
	_mat			m_MatView;
	_mat			m_MatProj;

protected:
	//POINT m_MousePoint;

protected:	// Camera Position Setting
	_float m_fDistance;			// Camera to target distance
	_float m_fEyeHeight;		// Camera height from target
	_float m_fLength;			// Cur camera to old camera vec3 lenth
	_bool  m_bChange;


protected:	// Zoom Setting
	_float m_fZoom_Max;
	_float m_fZoom_Min;
	_float m_fZoom_Cur;
	_float m_fZoom_Speed;


protected:	// Projectile Setting
	_float m_fNear;
	_float m_fFar;
	_float m_fFov;


protected:	// Rotate Value
	_float m_fX_Angle;
	_float m_fY_Angle;
	_float m_fX_LockAngle;
	_float m_fY_LockAngle;
	_float m_fX_MaxLockAngle;
	_float m_fY_MaxLockAngle;

protected:
	_bool m_bMainCamera;
	_bool m_bGetMp;
};

END

#endif // Camera_h__

