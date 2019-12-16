#ifndef TerrainTex_h__
#define TerrainTex_h__

#include "VIBuffer.h"

BEGIN(ENGINE)

class ENGINE_DLL CTerrainTex : public CVIBuffer
{
private:
	explicit CTerrainTex(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CTerrainTex(const CTerrainTex& rhs);
	virtual ~CTerrainTex();

private:
	_ulong* Load_HeightMap();

public:
	virtual HRESULT CreateBuffer(const WORD& wCntX,
								 const WORD& wCntZ,
								 const WORD& wItv);

public:
	static CTerrainTex* Create(LPDIRECT3DDEVICE9 pGraphicDev, 
							   const WORD& wCntX,
							   const WORD& wCntZ,
							   const WORD& wItv);

public:
	virtual CRenderer* Clone();
	virtual void		Free();
};

END

#define TerrainTex_h__
#endif
