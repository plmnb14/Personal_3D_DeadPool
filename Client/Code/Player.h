#ifndef Player_h__
#define Player_h__

#include "GameObject.h"

namespace ENGINE
{
	class CTexture;
	class CVIBuffer;
	class CTransform;
}

class CPlayer : public ENGINE::CGameObject
{
protected:
	explicit CPlayer(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CPlayer();

public:
	virtual int		Update();
	virtual void	LateUpdate();
	virtual void	Render();

private:
	void KeyInput();
	void KeyDown();
	void KeyUp();
	void Movement();

private:
	virtual HRESULT Initialize();
	virtual HRESULT LateInit();

public:
	static CPlayer* Create(LPDIRECT3DDEVICE9 pGraphicDev);

public:
	virtual void Free();

private:
	ENGINE::CTexture*		m_pTexture;
	ENGINE::CVIBuffer*		m_pBuffer;
	ENGINE::CTransform*		m_pTransform;

private:
	_float m_fAngle_Recover;

private:
	_bool	m_bFront;
	_bool	m_bBack;
	_bool	m_bLeft;
	_bool	m_bRight;
};

#endif	// Player_h__