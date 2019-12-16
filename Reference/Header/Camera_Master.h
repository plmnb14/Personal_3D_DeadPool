#ifndef Camera_h__
#define Camera_h__

#include "GameObject.h"

BEGIN(ENGINE)

class ENGINE_DLL CCamera_Master : public CGameObject
{

private:
	explicit CCamera_Master(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CCamera_Master();

public:
	enum CameraMode
	{
		LAND_MODE, FLY_MODE, SPYCAM_MODE, END_MODE
	};

	enum CameraType
	{
		FPS, TPS, NO_CLIP
	};

public:
	void Walk_H(float _Speed);
	void Walk_V(float _Speed);

public:
	void Rotate_X(float _Angle);
	void Rotate_Y(float _Angle);
	void Rotate_Z(float _Angle);

public:
	void SetUp_ViewMatrix(D3DXMATRIX* _ViewMatrix);
	void SetCameraMode(CameraMode _CameraType);

public:
	void SetUp_ViewPoint(CameraType _CameraViewPoint);
	void SetUp_FirstPerson_ViewPoint();
	void SetUp_Zoom();
	void SetUp_MouseRotate();


public:
	D3DXVECTOR3 Get_Pos();
	D3DXVECTOR3 Get_LookAt();
	D3DXVECTOR3 Get_Look();
	D3DXVECTOR3 Get_Right();
	D3DXVECTOR3 Get_Up();
	CameraType Get_ViewPoint() { return m_eCamType; }
	D3DXMATRIX GetViewMatrix();
	D3DXMATRIX GetProjMatrix();
public:
	void KeyInput();



public:
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

private:
	virtual HRESULT Initialize() override;

public:
	virtual void Free() override;

private:
	HRESULT AddComponent();

public:
	void Set_Target(CGameObject* _Target) { m_pTarget = _Target; };

public:
	static CCamera_Master* Create(LPDIRECT3DDEVICE9 pGraphicDev, CameraType _CameraType);

private:
	LPDIRECT3DDEVICE9	m_pGraphicDev;
	CameraMode			m_eCamMode;
	CameraType			m_eCamType;
	D3DXMATRIX			m_MatView;
	D3DXMATRIX			m_MatProj;

private:
	ENGINE::CAM_INFO			m_tCamInfo;

private:
	CGameObject*	m_pTarget;	// 추후 Obj Target 으로 변경 예정

private:
	float m_fEyeHeight;
	float m_fZoom_Max;
	float m_fZoom_Min;
	float m_fZoom_Speed;
	float m_fFov;

private:
	float m_fX_Angle;
	float m_fY_Angle;
};

END

#endif // Camera_h__

