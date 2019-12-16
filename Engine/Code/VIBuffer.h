#ifndef VIBuffer_h__ 
#define VIBuffer_h__ 

#include "Renderer.h"

BEGIN(ENGINE)

class ENGINE_DLL CVIBuffer : public CRenderer
{
public:
	enum BUFFER_TYPE
	{
		BUFFER_TRICOL,
		BUFFER_RCCOL,
		BUFFER_RCTEX,
		BUFFER_TERRAIN
	};

protected:
	explicit CVIBuffer(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CVIBuffer(const CVIBuffer& rhs);
	virtual ~CVIBuffer();

public:
	virtual void Render_Buffer();
	virtual HRESULT CreateBuffer();

public:
	void Get_VertexInfo(void* pVertex);

public:
	void Set_VertexInfo(void* pVertex);

public:
	virtual void Free();

protected:
	LPDIRECT3DVERTEXBUFFER9 m_pVB;
	LPDIRECT3DINDEXBUFFER9 m_pIB;

	_ulong		m_dwVtxFVF;

	_ulong		m_dwVtxSize;
	_ulong		m_dwVtxCount;
	_ulong		m_dwTriCount;

	_ulong		m_dwIdxSize;
	D3DFORMAT	m_IdxFmt;
};

END

#endif // VIBuffer_h__ 
