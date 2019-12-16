#include "Management.h"

USING(ENGINE)

IMPLEMENT_SINGLETON(CManagement)

CManagement::CManagement()
	:m_pCameraMgr(CCameraMgr::GetInstance())
{

}

CManagement::~CManagement()
{
	Free();
}

void CManagement::Ready_Management(LPDIRECT3DDEVICE9 pGraphicDev)
{
}

HRESULT CManagement::SetUp_Scene(CScene* pScene)
{
	ENGINE::Safe_Release(m_pScene);

	m_pScene = pScene;

	return S_OK;
}

void CManagement::Update_Scene(const _float& fTimeDelta)
{
	if (nullptr == m_pScene)
		return;

	m_pCameraMgr->Update();
	m_pScene->Update_Scene(fTimeDelta);
}

void CManagement::LateUpdate_Scene()
{
	if (nullptr == m_pScene)
		return;

	m_pScene->LateUpdate_Scene();
}

void CManagement::Render_Scene(void)
{
	if (nullptr == m_pScene)
		return;

	m_pScene->Render_Scene();
}

void CManagement::Free()
{
	ENGINE::Safe_Release(m_pScene);
}

