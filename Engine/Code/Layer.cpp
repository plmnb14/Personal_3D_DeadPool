#include "Layer.h"

USING(ENGINE)

CLayer::CLayer(void)
{

}

CLayer::~CLayer(void)
{

}

HRESULT CLayer::Ready_Layer(void)
{
	return S_OK;
}

void CLayer::Update_Layer(const _float& fTimeDelta)
{
	MAP_GAMEOBJECT::iterator iter_begin = m_mapGameObject.begin();
	MAP_GAMEOBJECT::iterator iter_end = m_mapGameObject.end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		auto& iter_begin_Obj = iter_begin->second.begin();
		auto& iter_end_Obj = iter_begin->second.end();
		for (; iter_begin_Obj != iter_end_Obj; )
		{
			int iEvent = (*iter_begin_Obj)->Update();

			if (DEAD_OBJ == iEvent)
			{
				ENGINE::Safe_Release(*iter_begin_Obj);
				iter_begin_Obj = iter_begin->second.erase(iter_begin_Obj);
			}
			else
			{
				++iter_begin_Obj;
			}
		}
	}
}

void CLayer::LateUpdate_Layer()
{
	MAP_GAMEOBJECT::iterator iter_begin = m_mapGameObject.begin();
	MAP_GAMEOBJECT::iterator iter_end = m_mapGameObject.end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		for (auto& pObject : iter_begin->second)
		{
			pObject->LateUpdate();
		}
	}
}

void CLayer::Render_Layer(void)
{
	MAP_GAMEOBJECT::iterator iter_begin = m_mapGameObject.begin();
	MAP_GAMEOBJECT::iterator iter_end = m_mapGameObject.end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		for (auto& pObject : iter_begin->second)
			pObject->Render();
	}
}

HRESULT CLayer::AddObject(ENGINE::OBJ_TYPE _ObjType, CGameObject * pObject)
{
	NULL_CHECK_RETURN(pObject, E_FAIL);
	m_mapGameObject[_ObjType].push_back(pObject);


	return S_OK;
}

CLayer* CLayer::Create(void)
{
	CLayer*		pInstance = new CLayer;

	if (FAILED(pInstance->Ready_Layer()))
		ENGINE::Safe_Release(pInstance);

	return pInstance;
}

void CLayer::Free(void)
{
	for_each(m_mapGameObject.begin(), m_mapGameObject.end(),
		[](auto& MyPair)
	{
		for_each(MyPair.second.begin(), MyPair.second.end(), ENGINE::Safe_Release<CGameObject*>);
		MyPair.second.clear();
	});

	m_mapGameObject.clear();
}

