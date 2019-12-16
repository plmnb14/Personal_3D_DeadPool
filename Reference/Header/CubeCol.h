#ifndef CubeCol_h__
#define CubeCol_h__

#include "VIBuffer.h"

BEGIN(ENGINE)

class ENGINE_DLL CCubeCol : public CVIBuffer
{
private:
	explicit CCubeCol(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CCubeCol(const CCubeCol& rhs);
	virtual ~CCubeCol();

public:
	virtual HRESULT CreateBuffer();

public:
	static CCubeCol* Create(LPDIRECT3DDEVICE9 pGraphicDev);

public:
	virtual CRenderer* Clone();
	virtual void Free();

private:
	IDirect3DTexture9*		Tex = 0;
};

END

#endif // CubeCol_h__
