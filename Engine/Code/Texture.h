#ifndef Texture_h__
#define Texture_h__

#include "Renderer.h"

BEGIN(ENGINE)

class ENGINE_DLL CTexture : public CRenderer
{
protected:
	explicit CTexture(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CTexture(const CTexture& rhs);
	virtual ~CTexture(void);


public:
	HRESULT		Ready_Texture(const _tchar* pPath, 
							TEXTURETYPE eType, 
							const _uint& iCnt);

	void		Render_Texture(const _uint& iIndex = 0);

private:
	vector<IDirect3DBaseTexture9*>		m_vecTexture;

public:
	virtual CRenderer*	Clone();
	static CTexture*	Create(LPDIRECT3DDEVICE9 pGraphicDev, const _tchar* pPath, TEXTURETYPE eType, const _uint& iCnt = 1);
	virtual void Free();

};

END

#endif // Texture_h__
