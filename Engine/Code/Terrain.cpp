#include "Terrain.h"

USING(ENGINE)

CTerrain::CTerrain(LPDIRECT3DDEVICE9 pGraphicDev)
	: CGameObject(pGraphicDev)
{
}

CTerrain::~CTerrain()
{
}

int CTerrain::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;

	return NO_EVENT;
}

void CTerrain::LateUpdate()
{
}

void CTerrain::Render()
{
}

HRESULT CTerrain::Initialize()
{
	return S_OK;
}

HRESULT CTerrain::LateInit()
{
	return S_OK;
}

void CTerrain::Free()
{
	ENGINE::CGameObject::Free();
}