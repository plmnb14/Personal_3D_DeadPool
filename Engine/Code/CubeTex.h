#ifndef CubeTex_h__
#define CubeTex_h__

#include "VIBuffer.h"

BEGIN(ENGINE)

class ENGINE_DLL CCubeTex : public CVIBuffer
{
private:
	explicit CCubeTex(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CCubeTex(const CCubeTex& rhs);
	virtual ~CCubeTex();

public:
	virtual HRESULT CreateBuffer();

public:
	static CCubeTex* Create(LPDIRECT3DDEVICE9 pGraphicDev);

public:
	virtual CRenderer* Clone();
	virtual void	Free();
};

END

#define CubeTex_h__
#endif
