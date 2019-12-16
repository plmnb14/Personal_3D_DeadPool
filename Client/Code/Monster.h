#ifndef Monster_h__
#define Monster_h__

#include "GameObject.h"

namespace ENGINE
{
	class CTexture;
	class CVIBuffer;
	class CTransform;
}

class CMonster : public ENGINE::CGameObject
{
protected:
	explicit CMonster(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CMonster();

public:
	virtual int		Update();
	virtual void	LateUpdate();
	virtual void	Render();

protected:
	virtual HRESULT Initialize();
	virtual HRESULT LateInit();

private:
	void Set_Target(CGameObject* _Target) { m_pTarget = _Target;}

public:
	static CMonster* Create(LPDIRECT3DDEVICE9 pGraphicDev , CGameObject* _Target);

private:
	virtual void Free();

private:
	ENGINE::CTexture*		m_pTexture;
	ENGINE::CVIBuffer*		m_pBuffer;
	ENGINE::CTransform*		m_pTransform;
	ENGINE::CGameObject*	m_pTarget;
	_mat tmpWorld;

	_v3 vRight = { 1,0,0 };
	_v3 vUp	   = { 0,1,0 };
	_v3 vLook  = { 0,0,1 };
};

#endif	// Monster_h__