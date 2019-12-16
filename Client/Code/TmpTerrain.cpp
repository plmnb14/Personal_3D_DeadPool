#include "stdafx.h"
#include "TmpTerrain.h"


CTmpTerrain::CTmpTerrain(LPDIRECT3DDEVICE9 _pGraphicDev)
	:CGameObject(_pGraphicDev),
	m_pTransform(nullptr) , m_pTexture(nullptr), m_pBuffer(nullptr),
	m_dwVtxCount(0)
{
}


CTmpTerrain::~CTmpTerrain()
{
}

HRESULT CTmpTerrain::Initialize()
{
	FAILED_CHECK_RETURN(Add_Component(), S_FALSE);

	m_pTransform->Set_Pos({ 0, 0, 0 });
	m_pTransform->Set_Scale({ 1, 1, 1 });

	m_dwVtxCount = 129 * 129;
	m_pOriginVtx = new ENGINE::VTX_TEX[m_dwVtxCount];
	m_pConvertVtx = new ENGINE::VTX_TEX[m_dwVtxCount];
	
	ENGINE::CRendererMgr::GetInstance()->Get_VertexInfo(ENGINE::RESOURCE_STATIC,
		L"Buffer_Terrain",
		m_pOriginVtx);
	
	memcpy(m_pConvertVtx, m_pOriginVtx, sizeof(ENGINE::VTX_TEX) * m_dwVtxCount);

	return S_OK;
}

HRESULT CTmpTerrain::LateInit()
{
	return S_OK;
}

HRESULT CTmpTerrain::Add_Component()
{
	ENGINE::CComponent*	pComponent = nullptr;

	pComponent = ENGINE::Clone(ENGINE::RESOURCE_STATIC, L"Texture_Terrain");
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent.insert({ L"Texutre", pComponent });
	
	m_pTexture = CONVERT_TEXTURE(pComponent);
	NULL_CHECK_RETURN(m_pTexture, E_FAIL);
	
	
	pComponent = ENGINE::Clone(ENGINE::RESOURCE_STATIC, L"Buffer_TerrainTex");
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent.insert({L"Buffer", pComponent });
	
	m_pBuffer = CONVERT_BUFFFER(pComponent);
	NULL_CHECK_RETURN(m_pBuffer, E_FAIL);


	pComponent = ENGINE::Clone_Com(ENGINE::RESOURCE_STATIC, L"Transform");
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent.insert({ L"Transform", pComponent });

	m_pTransform = CONVERT_TRANS(pComponent);
	NULL_CHECK_RETURN(m_pTransform, E_FAIL);

	return S_OK;
}

_int CTmpTerrain::Update()
{
	ENGINE::CGameObject::LateInit();
	ENGINE::CGameObject::Update();

	return NO_EVENT;
}

void CTmpTerrain::LateUpdate()
{
	ENGINE::CGameObject::LateUpdate();
}

void CTmpTerrain::Render()
{
	m_pGraphicDev->SetTransform(D3DTS_WORLD, &(m_pTransform->Get_WorldMat()));

	_mat matView, matProj;

	matView = ENGINE::Get_ViewMat();
	matProj = ENGINE::Get_ProjMat();

	for (DWORD i = 0; i < m_dwVtxCount; ++i)
	{
		// 월드행렬 연산
		D3DXVec3TransformCoord(&m_pConvertVtx[i].vPos,
			&m_pOriginVtx[i].vPos,
			&(m_pTransform->Get_WorldMat()));

		// 뷰행렬 연산
		D3DXVec3TransformCoord(&m_pConvertVtx[i].vPos,
			&m_pConvertVtx[i].vPos,
			&matView);

		// 원점과 근평면(Near) 사이에 즉, 보이지 말아야할 것들은 연산에서 제외.
		if (m_pConvertVtx[i].vPos.z <= 1.0f)
			continue;

		// 투영행렬 연산
		D3DXVec3TransformCoord(&m_pConvertVtx[i].vPos,
			&m_pConvertVtx[i].vPos,
			&matProj);
	}

	ENGINE::CRendererMgr::GetInstance()->Set_VertexInfo(ENGINE::RESOURCE_STATIC,
		L"Buffer_Terrain",
		m_pOriginVtx);

	m_pTexture->Render_Texture();
	m_pBuffer->Render_Buffer();
}

void CTmpTerrain::Free()
{
	ENGINE::CGameObject::Free();

	ENGINE::Safe_Delete_Array(m_pOriginVtx);
	ENGINE::Safe_Delete_Array(m_pConvertVtx);
}

CTmpTerrain * CTmpTerrain::Create(LPDIRECT3DDEVICE9 _pGraphicDev)
{
	CTmpTerrain* pInstance = new CTmpTerrain(_pGraphicDev);

	if (FAILED(pInstance->Initialize()))
	{
		ENGINE::Safe_Release(pInstance);
	}

	return pInstance;
}
