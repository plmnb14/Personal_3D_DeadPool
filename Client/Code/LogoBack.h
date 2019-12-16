#ifndef LogoBack_h__
#define LogoBack_h__

#include "GameObject.h"

namespace ENGINE
{
	class CTexture;
	class CVIBuffer;
	class CTransform;
}

class CLogoBack : public ENGINE::CGameObject
{
protected:
	explicit CLogoBack(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CLogoBack();

public:
	virtual int		Update();
	virtual void	LateUpdate();
	virtual void	Render();

protected:
	virtual HRESULT Initialize();
	virtual HRESULT LateInit();

public:
	static CLogoBack* Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free();

private:
	ENGINE::CTexture*		m_pTexture;
	ENGINE::CVIBuffer*		m_pBuffer;
	ENGINE::CTransform*		m_pTransform;
};

#endif	// LogoBack_h__