#ifndef Dynamic_Camera_h__
#define Dynamic_Camera_h__

#include "Camera.h"

BEGIN(ENGINE)

class ENGINE_DLL CDynamic_Camera : public CCamera
{

protected:
	explicit CDynamic_Camera(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CDynamic_Camera();

public:
	void KeyInput();

public:
	virtual _int Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

private:
	virtual HRESULT Initialize() override;
	virtual HRESULT LateInit() override;

private:
	HRESULT AddComponent();

public:
	virtual void Free() override;

public:
	static CDynamic_Camera* Create(LPDIRECT3DDEVICE9 pGraphicDev, 
								   CameraView _CameraViewType, 
								   CameraMode _CameraMode);
};

END

#endif // Dynamic_Camera_h__

