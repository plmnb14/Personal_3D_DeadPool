#include "GameObject.h"
#include "Component.h"

USING(ENGINE)

CGameObject::CGameObject(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_pGraphicDev(pGraphicDev), m_bIsDead(false), m_pTarget(nullptr)
{
	m_pGraphicDev->AddRef();
}

CGameObject::~CGameObject()
{
}

int CGameObject::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;

	MAP_COMPONENT::iterator iter_begin = m_mapComponent.begin();
	MAP_COMPONENT::iterator iter_end = m_mapComponent.end();

	for (; iter_begin != iter_end; ++iter_begin)
		iter_begin->second->Update();

	return NO_EVENT;
}

void CGameObject::LateUpdate()
{
	MAP_COMPONENT::iterator iter_begin = m_mapComponent.begin();
	MAP_COMPONENT::iterator iter_end = m_mapComponent.end();

	for (; iter_begin != iter_end; ++iter_begin)
		iter_begin->second->LateUpdate();
}

void CGameObject::Render()
{
}

HRESULT CGameObject::Initialize()
{
	return S_OK;
}

HRESULT CGameObject::LateInit()
{
	HRESULT hr = 0;

	if (!m_bIsInit)
	{
		hr = this->LateInit();
		m_bIsInit = true;
	}

	return hr;
}

void CGameObject::Free()
{
	Safe_Release(m_pGraphicDev);

	for_each(m_mapComponent.begin(), m_mapComponent.end(), CDeleteMap());
	m_mapComponent.clear();
}

int CGameObject::Get_Dead()
{
	return m_bIsDead;
}

void CGameObject::Set_Dead(bool _Dead)
{
	m_bIsDead = _Dead;
}
