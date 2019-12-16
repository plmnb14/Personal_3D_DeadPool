#include "stdafx.h"
#include "LogoBack.h"

#include "Component.h"


CLogoBack::CLogoBack(LPDIRECT3DDEVICE9 pGraphicDev)
	:ENGINE::CGameObject(pGraphicDev), m_pTexture(nullptr)
{
}

CLogoBack::~CLogoBack()
{
}

int CLogoBack::Update()
{
	ENGINE::CGameObject::LateInit();
	ENGINE::CGameObject::Update();

	return NO_EVENT;
}

void CLogoBack::LateUpdate()
{
	ENGINE::CGameObject::LateUpdate();
}

void CLogoBack::Render()
{
	m_pBuffer->Render_Buffer();
	m_pTexture->Render_Texture();
}

HRESULT CLogoBack::Initialize()
{
	ENGINE::CComponent* pComponent = nullptr;

	pComponent = ENGINE::Clone(ENGINE::RESOURCE_STATIC, L"DOGE");
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent.insert({ L"Texture", pComponent });

	m_pTexture = dynamic_cast<ENGINE::CTexture*>(pComponent);
	NULL_CHECK_RETURN(m_pTexture, E_FAIL);


	pComponent = ENGINE::Clone(ENGINE::RESOURCE_STATIC, L"Buffer_RcTex");
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent.insert({ L"Buffer", pComponent });

	m_pBuffer = dynamic_cast<ENGINE::CVIBuffer*>(pComponent);
	NULL_CHECK_RETURN(m_pBuffer, E_FAIL);

	return S_OK;
}

HRESULT CLogoBack::LateInit()
{
	return S_OK;
}

CLogoBack * CLogoBack::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CLogoBack*	pInstance = new CLogoBack(pGraphicDev);

	if (FAILED(pInstance->Initialize()))
		ENGINE::Safe_Release(pInstance);

	return pInstance;
}

void CLogoBack::Free()
{
	ENGINE::CGameObject::Free();
}
