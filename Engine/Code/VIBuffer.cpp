#include "VIBuffer.h"

USING(ENGINE)

CVIBuffer::CVIBuffer(LPDIRECT3DDEVICE9 pGraphicDev)
	: CRenderer(pGraphicDev),
	m_pVB(nullptr),
	m_pIB(nullptr),
	m_dwVtxFVF(0),
	m_dwVtxSize(0),
	m_dwVtxCount(0),
	m_dwTriCount(0)
{
}


CVIBuffer::CVIBuffer(const CVIBuffer& rhs)
	: CRenderer(rhs)
	, m_pVB(rhs.m_pVB)
	, m_pIB(rhs.m_pIB)
	, m_dwVtxSize(rhs.m_dwVtxSize)
	, m_dwVtxCount(rhs.m_dwVtxCount)
	, m_dwTriCount(rhs.m_dwTriCount)
	, m_dwVtxFVF(rhs.m_dwVtxFVF)
	, m_dwIdxSize(rhs.m_dwIdxSize)
	, m_IdxFmt(rhs.m_IdxFmt)
{
	m_pVB->AddRef();
	m_pIB->AddRef();
}


CVIBuffer::~CVIBuffer()
{
}

void CVIBuffer::Render_Buffer()
{
	m_pGraphicDev->SetStreamSource(0, m_pVB, 0, m_dwVtxSize);
	m_pGraphicDev->SetFVF(m_dwVtxFVF);

	m_pGraphicDev->SetIndices(m_pIB);

	m_pGraphicDev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, m_dwVtxCount, 0, m_dwTriCount);
}

HRESULT CVIBuffer::CreateBuffer()
{
	HRESULT hr = m_pGraphicDev->CreateVertexBuffer(
		m_dwVtxSize * m_dwVtxCount, 0, m_dwVtxFVF, D3DPOOL_MANAGED, &m_pVB, nullptr);
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL, L"CreateVertexBuffer Failed");

	hr = m_pGraphicDev->CreateIndexBuffer(
		m_dwIdxSize * m_dwTriCount, 0, m_IdxFmt, D3DPOOL_MANAGED, &m_pIB, nullptr);
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL, L"CreateIndexBuffer Failed");

	return S_OK;
}

void CVIBuffer::Get_VertexInfo(void * pVertex)
{
	void* pOriginVtx = nullptr;

	m_pVB->Lock(0, 0, &pOriginVtx, 0);

	memcpy(pVertex, pOriginVtx, m_dwVtxSize * m_dwVtxCount);

	m_pVB->Unlock();
}

void CVIBuffer::Set_VertexInfo(void * pVertex)
{
	void* pOriginVtx = nullptr;

	m_pVB->Lock(0, 0, &pOriginVtx, 0);

	memcpy(pOriginVtx, pVertex, m_dwVtxSize * m_dwVtxCount);

	m_pVB->Unlock();
}

void CVIBuffer::Free()
{
	CRenderer::Free();

	ENGINE::Safe_Release(m_pVB);
	ENGINE::Safe_Release(m_pIB);
}
