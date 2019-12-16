#ifndef Terrain_h__
#define Terrain_h__

#include "GameObject.h"

BEGIN(ENGINE)

class ENGINE_DLL CTerrain : public CGameObject
{
protected:
	explicit CTerrain(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CTerrain();

public:
	virtual int		Update();
	virtual void	LateUpdate();
	virtual void	Render();

protected:
	virtual HRESULT Initialize();
	virtual HRESULT LateInit();

public:
	virtual void Free();
};

END

#endif	// GameObejct_h__