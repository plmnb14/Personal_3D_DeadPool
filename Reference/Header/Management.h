#ifndef Management_h__
#define Management_h__

#include "Scene.h"

BEGIN(ENGINE)

class ENGINE_DLL CManagement : public CBase
{
	DECLARE_SINGLETON(CManagement)

private:
	explicit	CManagement();
	virtual		~CManagement();

public:
	void		Ready_Management(LPDIRECT3DDEVICE9 pGraphicDev);

public:
	HRESULT		SetUp_Scene(CScene* pScene);
	void		Update_Scene(const _float& fTimeDelta);
	void		LateUpdate_Scene();
	void		Render_Scene();

private:
	CScene*			m_pScene = nullptr;

protected:
	CCameraMgr*		m_pCameraMgr;

public:
	virtual void	Free();

public:
	template <typename T>
	HRESULT SceneChange(T& functor , LPDIRECT3DDEVICE9 _Device)
	{
		ENGINE::Safe_Release(m_pScene);

		HRESULT hr = functor(&m_pScene, _Device);
		FAILED_CHECK_RETURN(hr, E_FAIL);

		return S_OK;
	}

//private:
	//LPDIRECT3DDEVICE9 m_pGraphicDev;
};

END
#endif // Management_h__
