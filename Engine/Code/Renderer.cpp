#include "Renderer.h"

USING(ENGINE)

CRenderer::CRenderer(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_pGraphicDev(pGraphicDev)
{
	m_pGraphicDev->AddRef();
}

CRenderer::CRenderer(const CRenderer& rhs)
	: m_pGraphicDev(rhs.m_pGraphicDev)
{
	m_pGraphicDev->AddRef();
}

CRenderer::~CRenderer()
{

}

void CRenderer::Free()
{
	Safe_Release(m_pGraphicDev);
}

