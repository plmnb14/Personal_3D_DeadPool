#include "ComponentMgr.h"

USING(ENGINE)

IMPLEMENT_SINGLETON(CComponentMgr)

CComponentMgr::CComponentMgr(void)
{

}

CComponentMgr::~CComponentMgr(void)
{
	Free();
}

HRESULT CComponentMgr::Ready_ComponentMgr()
{
	Reserve_ContainerSize(ENGINE::_COMP_END);

	Ready_Component(ENGINE::RESOURCE_STATIC, L"Transform", ENGINE::_TRANSFORM);

	return S_OK;
}

HRESULT CComponentMgr::Reserve_ContainerSize(const _ushort& wSize)
{
	if (nullptr != m_pmapComponent)
		return E_FAIL;

	m_pmapComponent = new map<const _tchar*, CComponent*>[wSize];

	m_wContainerSize = wSize;

	return S_OK;
}

HRESULT CComponentMgr::Ready_Component(
	const _ushort& wContainerIdx,
	const _tchar* pComponentTag,
	COMP_TYPE eID)
{
	if (nullptr == m_pmapComponent)
	{
		MSG_BOX("Renderer Container not Reserved");
		return E_FAIL;
	}

	CComponent* pComponent = Find_Component(wContainerIdx, pComponentTag);

	if (nullptr != pComponent)
		return E_FAIL;

	switch (eID)
	{
	case _TRANSFORM:
	{
		pComponent = CTransform::Create();
		break;
	}

	case _COLLIDER:
	{
		pComponent = CCollider::Create();
		break;
	}
	}

	NULL_CHECK_RETURN(pComponent, E_FAIL);

	m_pmapComponent[wContainerIdx].emplace(pComponentTag, pComponent);

	return S_OK;
}

CComponent* CComponentMgr::Find_Component(const _ushort& wContainerIdx, const _tchar* pComponentTag)
{
	auto	iter = find_if(m_pmapComponent[wContainerIdx].begin(), m_pmapComponent[wContainerIdx].end(), CTag_Finder(pComponentTag));

	if (iter == m_pmapComponent[wContainerIdx].end())
		return nullptr;

	return iter->second;
}

void CComponentMgr::Free(void)
{
	for (_ushort i = 0; i < m_wContainerSize; ++i)
	{
		for_each(m_pmapComponent[i].begin(), m_pmapComponent[i].end(), CDeleteMap());
		m_pmapComponent[i].clear();
	}

	Safe_Delete_Array(m_pmapComponent);
}

CComponent* CComponentMgr::Clone(const _ushort& wContainerIdx, const _tchar* pComponentTag)
{
	if (nullptr == m_pmapComponent)
		return nullptr;

	CComponent* pPrototype = Find_Component(wContainerIdx, pComponentTag);

	return dynamic_cast<CComponent*>(pPrototype->Clone());
}



