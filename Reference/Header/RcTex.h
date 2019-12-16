#ifndef RcTex_h__
#define RcTex_h__

#include "VIBuffer.h"

BEGIN(ENGINE)

class ENGINE_DLL CRcTex : public CVIBuffer
{
private:
	explicit CRcTex(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CRcTex(const CRcTex& rhs);
	virtual ~CRcTex();

public:
	virtual HRESULT		Ready_Buffer();

public:
	static CRcTex*	Create(LPDIRECT3DDEVICE9 pGraphicDev);

public:
	virtual CRenderer* Clone();
	virtual void	Free();
};


END
#endif // RcTex_h__
