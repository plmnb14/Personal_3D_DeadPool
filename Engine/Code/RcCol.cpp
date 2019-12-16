#include "RcCol.h"

USING(ENGINE)

CRcCol::CRcCol(LPDIRECT3DDEVICE9 pGraphicDev)
	: CVIBuffer(pGraphicDev)
{
}

CRcCol::CRcCol(const CRcCol& rhs)
	: CVIBuffer(rhs)
{

}

CRcCol::~CRcCol()
{
}

HRESULT CRcCol::CreateBuffer()
{
	m_dwVtxSize = sizeof(VTX_COL);
	m_dwVtxFVF = VTXFVF_COL;
	m_dwTriCount = 2;
	m_dwVtxCount = 4;

	m_dwIdxSize = sizeof(INDEX32);
	m_IdxFmt = D3DFMT_INDEX32;

	FAILED_CHECK_RETURN(CVIBuffer::CreateBuffer(), E_FAIL);

	VTX_COL* pVtxCol = nullptr;

	m_pVB->Lock(0, 0, (void**)&pVtxCol, 0);

	pVtxCol[0].vPos = { -1.0f, 1.f, 0.f };
	pVtxCol[0].dwColor = D3DCOLOR_ARGB(255, 255, 0, 0);

	pVtxCol[1].vPos = { 1.0f, 1.f, 0.f };
	pVtxCol[1].dwColor = D3DCOLOR_ARGB(255, 0, 255, 0);

	pVtxCol[2].vPos = { 1.0f, -1.f, 0.f };
	pVtxCol[2].dwColor = D3DCOLOR_ARGB(255, 0, 0, 255);

	pVtxCol[3].vPos = { -1.0f, -1.f, 0.f };
	pVtxCol[3].dwColor = D3DCOLOR_ARGB(255, 255, 0, 0);

	m_pVB->Unlock();

	INDEX32* pIndex = nullptr;

	m_pIB->Lock(0, 0, (void**)&pIndex, 0);


	pIndex[0]._1 = 0;
	pIndex[0]._2 = 1;
	pIndex[0]._3 = 2;

	pIndex[1]._1 = 0;
	pIndex[1]._2 = 2;
	pIndex[1]._3 = 3;

	m_pIB->Unlock();

	return S_OK;
}

void CRcCol::Free()
{
	CVIBuffer::Free();
}

CRcCol* CRcCol::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CRcCol* pInstance = new CRcCol(pGraphicDev);

	if (FAILED(pInstance->CreateBuffer()))
	{
		Safe_Release(pInstance);
	}

	return pInstance;
}

CRenderer * CRcCol::Clone()
{
	return new CRcCol(*this);
}
