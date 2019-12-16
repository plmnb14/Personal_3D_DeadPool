#ifndef RcCol_h__
#define RcCol_h__

#include "VIBuffer.h"

BEGIN(ENGINE)

class ENGINE_DLL CRcCol : public CVIBuffer
{
private:
	explicit CRcCol(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CRcCol(const CRcCol& rhs);
	virtual ~CRcCol();

public:
	virtual HRESULT CreateBuffer();

public:
	static CRcCol* Create(LPDIRECT3DDEVICE9 pGraphicDev);

public:
	virtual CRenderer* Clone();
	virtual void Free();
};

END

#endif // RcCol_h__
