#include "TriCol.h"

USING(ENGINE)

CTriCol::CTriCol(LPDIRECT3DDEVICE9 pGraphicDev)
	: CVIBuffer(pGraphicDev)
{

}

CTriCol::CTriCol(const CTriCol& rhs)
	: CVIBuffer(rhs)
{

}

CTriCol::~CTriCol()
{

}

HRESULT CTriCol::Ready_Buffer()
{
	m_dwVtxCount = 3;
	m_dwVtxFVF = VTXFVF_COL;
	m_dwTriCount = 1;
	m_dwVtxSize = sizeof(VTX_COL);

	m_IdxFmt = D3DFMT_INDEX32;
	m_dwIdxSize = sizeof(INDEX32);

	FAILED_CHECK_RETURN(CVIBuffer::CreateBuffer(), E_FAIL);

	VTX_COL*		pVertex = nullptr;

	m_pVB->Lock(0, 0, (void**)&pVertex, 0);

	pVertex[0].vPos = _v3(0.0f, 0.5f, 0.f);
	pVertex[0].dwColor = D3DXCOLOR(1.f, 0.f, 0.f, 1.f);

	pVertex[1].vPos = _v3(0.5f, -0.5f, 0.f);
	pVertex[1].dwColor = D3DXCOLOR(0.f, 1.f, 0.f, 1.f);

	pVertex[2].vPos = _v3(-0.5f, -0.5f, 0.f);
	pVertex[2].dwColor = D3DXCOLOR(0.f, 1.f, 0.f, 1.f);

	m_pVB->Unlock();

	INDEX32*		pIndex = nullptr;

	m_pIB->Lock(0, 0, (void**)&pIndex, 0);

	pIndex[0]._1 = 0;
	pIndex[0]._2 = 1;
	pIndex[0]._3 = 2;

	m_pIB->Unlock();

	return S_OK;
}

CTriCol* CTriCol::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CTriCol*	pInstance = new CTriCol(pGraphicDev);

	if (FAILED(pInstance->Ready_Buffer()))
		ENGINE::Safe_Release(pInstance);


	return pInstance;
}

void CTriCol::Free(void)
{
	CVIBuffer::Free();
}

CRenderer* CTriCol::Clone()
{
	return new CTriCol(*this);
}

