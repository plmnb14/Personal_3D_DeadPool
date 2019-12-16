#include "RcTex.h"

USING(ENGINE)

CRcTex::CRcTex(LPDIRECT3DDEVICE9 pGraphicDev)
	: CVIBuffer(pGraphicDev)
{

}

CRcTex::CRcTex(const CRcTex& rhs)
	: CVIBuffer(rhs)
{

}

CRcTex::~CRcTex(void)
{

}

HRESULT CRcTex::Ready_Buffer(void)
{
	m_dwVtxCount = 4;
	m_dwVtxFVF = VTXFVF_TEX;
	m_dwTriCount = 2;
	m_dwVtxSize = sizeof(VTX_TEX);

	m_IdxFmt = D3DFMT_INDEX32;
	m_dwIdxSize = sizeof(INDEX32);

	FAILED_CHECK_RETURN(CVIBuffer::CreateBuffer(), E_FAIL);


	VTX_TEX*		pVertex = nullptr;

	m_pVB->Lock(0, 0, (void**)&pVertex, 0);

	pVertex[0].vPos = _v3(-1.f, 1.f, 0.f);
	pVertex[0].vTex = _v2(0.f, 0.f);

	pVertex[1].vPos = _v3(1.f, 1.f, 0.f);
	pVertex[1].vTex = _v2(1.f, 0.f);

	pVertex[2].vPos = _v3(1.f, -1.f, 0.f);
	pVertex[2].vTex = _v2(1.f, 1.f);

	pVertex[3].vPos = _v3(-1.f, -1.f, 0.f);
	pVertex[3].vTex = _v2(0.f, 1.f);

	m_pVB->Unlock();

	INDEX32*		pIndex = nullptr;

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

CRcTex* CRcTex::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CRcTex*	pInstance = new CRcTex(pGraphicDev);

	if (FAILED(pInstance->Ready_Buffer()))
		ENGINE::Safe_Release(pInstance);


	return pInstance;
}

void CRcTex::Free()
{
	CVIBuffer::Free();
}

CRenderer* CRcTex::Clone()
{
	return new CRcTex(*this);
}

