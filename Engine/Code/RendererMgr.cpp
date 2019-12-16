#include "RendererMgr.h"

USING(ENGINE)

IMPLEMENT_SINGLETON(CRendererMgr)

CRendererMgr::CRendererMgr(void)
{

}

CRendererMgr::~CRendererMgr(void)
{
	Free();
}

void CRendererMgr::Get_VertexInfo(const _ushort & wContainerIdx, const _tchar * pBufferTag, void * pVertex)
{
	auto	iter = find_if(m_pmapRenderer[wContainerIdx].begin(), m_pmapRenderer[wContainerIdx].end(), CTag_Finder(pBufferTag));

	if (iter == m_pmapRenderer[wContainerIdx].end())
		return;

	dynamic_cast<CVIBuffer*>(iter->second)->Get_VertexInfo(pVertex);
}

void CRendererMgr::Set_VertexInfo(const _ushort & wContainerIdx, const _tchar * pBufferTag, void * pVertex)
{
	auto	iter = find_if(m_pmapRenderer[wContainerIdx].begin(), m_pmapRenderer[wContainerIdx].end(), CTag_Finder(pBufferTag));

	if (iter == m_pmapRenderer[wContainerIdx].end())
		return;

	dynamic_cast<CVIBuffer*>(iter->second)->Set_VertexInfo(pVertex);
}

HRESULT CRendererMgr::Reserve_ContainerSize(const _ushort& wSize)
{
	if (nullptr != m_pmapRenderer)
		return E_FAIL;

	m_pmapRenderer = new map<const _tchar*, CRenderer*>[wSize];

	m_wContainerSize = wSize;

	return S_OK;
}

HRESULT CRendererMgr::Ready_Buffers(LPDIRECT3DDEVICE9 pGraphicDev,
	const _ushort& wContainerIdx,
	const _tchar* pBufferTag,
	BUFFERID eID,
	const _ulong& dwCntX,
	const _ulong& dwCntZ,
	const _ulong& dwVtxItv)
{
	if (nullptr == m_pmapRenderer)
	{
		MSG_BOX("Renderer Container not Reserved");
		return E_FAIL;
	}

	CRenderer*		pRenderer = Find_Renderer(wContainerIdx, pBufferTag);

	if (nullptr != pRenderer)
		return E_FAIL;

	switch (eID)
	{
	case BUFFER_TRICOL:
		pRenderer = CTriCol::Create(pGraphicDev);
		break;

	case BUFFER_RCCOL:
		pRenderer = CRcCol::Create(pGraphicDev);
		break;

	case BUFFER_RCTEX:
		pRenderer = CRcTex::Create(pGraphicDev);
		break;

	case BUFFER_TERRAINTEX:
		pRenderer = CTerrainTex::Create(pGraphicDev, dwCntX , dwCntZ, dwVtxItv);
		break;
	}

	NULL_CHECK_RETURN(pRenderer, E_FAIL);

	m_pmapRenderer[wContainerIdx].emplace(pBufferTag, pRenderer);

	return S_OK;
}

CRenderer* CRendererMgr::Find_Renderer(const _ushort& wContainerIdx, const _tchar* pRendererTag)
{
	auto	iter = find_if(m_pmapRenderer[wContainerIdx].begin(), m_pmapRenderer[wContainerIdx].end(), CTag_Finder(pRendererTag));

	if (iter == m_pmapRenderer[wContainerIdx].end())
		return nullptr;

	return iter->second;
}

void CRendererMgr::Free(void)
{

	for (_ushort i = 0; i < m_wContainerSize; ++i)
	{
		for_each(m_pmapRenderer[i].begin(), m_pmapRenderer[i].end(), CDeleteMap());
		m_pmapRenderer[i].clear();
	}

	Safe_Delete_Array(m_pmapRenderer);
}

void CRendererMgr::Render_Buffer(const _ushort& wContainerIdx,
	const _tchar* pBufferTag)
{
	CRenderer*		pRenderer = Find_Renderer(wContainerIdx, pBufferTag);

	if (nullptr == pRenderer)
		return;

	dynamic_cast<CVIBuffer*>(pRenderer)->Render_Buffer();
}

CRenderer* CRendererMgr::Clone(const _ushort& wContainerIdx,
	const _tchar* pResourceTag)
{
	if (nullptr == m_pmapRenderer)
		return nullptr;

	CRenderer*		pPrototype = Find_Renderer(wContainerIdx, pResourceTag);

	return dynamic_cast<CRenderer*>(pPrototype->Clone());
}

HRESULT CRendererMgr::Ready_Texture(LPDIRECT3DDEVICE9 pGraphicDev,
	const _ushort& wContainerIdx,
	const _tchar* pTextureTag,
	TEXTURETYPE eType,
	const _tchar* pPath,
	const _uint& iCnt /*= 1*/)
{
	if (nullptr == m_pmapRenderer)
	{
		MSG_BOX("Renderer Container not Reserved");
		return E_FAIL;
	}

	CRenderer*		pRenderer = Find_Renderer(wContainerIdx, pTextureTag);

	if (nullptr != pRenderer)
		return E_FAIL;

	pRenderer = CTexture::Create(pGraphicDev, pPath, eType, iCnt);
	NULL_CHECK_RETURN(pRenderer, E_FAIL);

	m_pmapRenderer[wContainerIdx].emplace(pTextureTag, pRenderer);

	return S_OK;
}

void CRendererMgr::Render_Texture(const _ushort& wContainerIdx,
	const _tchar* pTextureTag,
	const _uint& iIndex /*= 0*/)
{
	CRenderer*		pRenderer = Find_Renderer(wContainerIdx, pTextureTag);

	if (nullptr == pRenderer)
		return;

	dynamic_cast<CTexture*>(pRenderer)->Render_Texture(iIndex);
}



