#ifndef Scene_h__
#define Scene_h__

#include "Layer.h"
#include "CameraMgr.h"

BEGIN(ENGINE)

class ENGINE_DLL CScene : public CBase
{
protected:
	explicit CScene(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CScene();

public:
	virtual HRESULT	Ready_Scene();
	virtual void	Update_Scene(const _float& fTimeDelta);
	virtual void	LateUpdate_Scene();
	virtual void	Render_Scene();

protected:
	LPDIRECT3DDEVICE9				m_pGraphicDev;
	typedef map<ENGINE::OBJ_LAYER, CLayer*>	MAP_LAYER;
	MAP_LAYER m_mapLayer;

public:
	virtual	void	Free(void);

};

END
#endif // Scene_h__
