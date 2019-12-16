#ifndef MainApp_h__
#define MainApp_h__

#include "Define.h"
#include "Base.h"

namespace ENGINE
{
	class CGraphicDev;
	class CVIBuffer;
	class CGameObject;
	class CManagement;
}

class CMainApp : public CBase
{
private:
	explicit CMainApp();
	virtual	~CMainApp();

public:
	HRESULT			Ready_MainApp();
	_int			Update_MainApp(const _float& fDeltaTime);
	void			Render_MainApp();
	void			LateUpdate_MainApp();

private:
	void			Global_KeyInput();

private:
	LPDIRECT3DDEVICE9		m_pDeviceMgr;
	ENGINE::CGraphicDev*	m_pDeviceClass;
	ENGINE::CManagement*	m_pManagement;
	ENGINE::CKeyMgr*		m_pKeyMgr;

public:
	static CMainApp*		Create();

private: 
	virtual void			Free();
};

#endif // MainApp_h__
