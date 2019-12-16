#include "Scene.h"

USING(ENGINE)

CScene::CScene(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_pGraphicDev(pGraphicDev)
{
	m_pGraphicDev->AddRef();
}

CScene::~CScene(void)
{

}

HRESULT CScene::Ready_Scene(void)
{
	return S_OK;
}

void CScene::Update_Scene(const _float& fTimeDelta)
{
	for (auto& iter : m_mapLayer)
		iter.second->Update_Layer(fTimeDelta);
}

void CScene::LateUpdate_Scene()
{
	for (auto& iter : m_mapLayer)
		iter.second->LateUpdate_Layer();
}

void CScene::Render_Scene()
{
	for (auto& iter : m_mapLayer)
		iter.second->Render_Layer();
}

void CScene::Free()
{
	ENGINE::Safe_Release(m_pGraphicDev);

	for_each(m_mapLayer.begin(), m_mapLayer.end(), CDeleteMap());
	m_mapLayer.clear();

}

