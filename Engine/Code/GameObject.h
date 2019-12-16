#ifndef GameObejct_h__
#define GameObejct_h__

#include "Base.h"
#include "Engine_Defines.h"

BEGIN(ENGINE)

class CComponent;
class ENGINE_DLL CGameObject : public CBase
{
protected:
	explicit CGameObject(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CGameObject();

public:
	virtual int		Update();
	virtual void	LateUpdate();
	virtual void	Render();

protected:
	virtual HRESULT Initialize();
	virtual HRESULT LateInit();

public:
	ENGINE::CComponent*		Get_Component(wstring _key) { return m_mapComponent[_key]; }
	ENGINE::CGameObject*	Get_Target()				{ return m_pTarget; }

public:
	void	Set_Target(CGameObject* _Target) { m_pTarget = _Target; }

public:
	int Get_Dead();

public:
	void Set_Dead(bool _Dead = 1);

public:
	virtual void Free();

protected:
	LPDIRECT3DDEVICE9 m_pGraphicDev;

protected:
	typedef map<wstring, CComponent*>	MAP_COMPONENT;
	MAP_COMPONENT	m_mapComponent;

protected:
	CGameObject*	m_pTarget;

	bool			m_bIsDead;
	bool			m_bIsInit;
};

END

#endif	// GameObejct_h__