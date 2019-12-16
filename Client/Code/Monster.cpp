#include "stdafx.h"
#include "Monster.h"

//#include "Component.h"
//#include "Transform.h"


CMonster::CMonster(LPDIRECT3DDEVICE9 pGraphicDev)
	:ENGINE::CGameObject(pGraphicDev), m_pTexture(nullptr) , m_pTarget(nullptr)
{
}

CMonster::~CMonster()
{
}

int CMonster::Update()
{
	float fMoveSpeed = 200.f * 0.0001f;

	// 걍 따라가기 [ 잘 작동함 ]
	{
		//ENGINE::CTransform* tmpTrans = dynamic_cast<ENGINE::CTransform*>(m_pTarget->Get_Component(L"Transform"));
		//m_pTarget->Get_Component(L"Transform");

		//float tmpX = static_cast<ENGINE::CTransform*>(m_pTarget->Get_Component(L"Transform"))->Get_Angle(ENGINE::ANGLE_X);
		//float tmpY = static_cast<ENGINE::CTransform*>(m_pTarget->Get_Component(L"Transform"))->Get_Angle(ENGINE::ANGLE_Y);
		//float tmpZ = static_cast<ENGINE::CTransform*>(m_pTarget->Get_Component(L"Transform"))->Get_Angle(ENGINE::ANGLE_Z);

		//m_pTransform->SetAngle(tmpX, ENGINE::ANGLE_X);
		//m_pTransform->SetAngle(tmpY, ENGINE::ANGLE_Y);
		//m_pTransform->SetAngle(tmpZ, ENGINE::ANGLE_Z);
	}

	_v3 targetPos = static_cast<ENGINE::CTransform*>(m_pTarget->Get_Component(L"Transform"))->Get_Pos();
	_v3 targetDir = static_cast<ENGINE::CTransform*>(m_pTarget->Get_Component(L"Transform"))->Get_Look();

	_v3 tmpPos = m_pTransform->Get_Pos();
	_v3 tmpDir = targetPos - tmpPos;

	D3DXVec3Normalize(&tmpDir, &tmpDir);

	// Acosf
	{
		//vLook = targetPos - tmpPos;
		//D3DXVec3Normalize(&vLook, &vLook);
		//
		//D3DXVec3Cross(&vRight, &vUp, &vLook);
		//D3DXVec3Normalize(&vRight, &vRight);
		//
		//D3DXVec3Cross(&vUp, &vLook, &vRight);
		//D3DXVec3Normalize(&vUp, &vUp);
		//
		//float tmpX = -D3DXToDegree(acosf(D3DXVec3Dot(&tmpPos, &vRight)));
		//float tmpY = -D3DXToDegree(acosf(D3DXVec3Dot(&tmpPos, &vUp)));
		//float tmpZ = -D3DXToDegree(acosf(D3DXVec3Dot(&tmpPos, &vLook)));
		//
		//D3DXMatrixIdentity(&tmpWorld);
		//
		//tmpWorld._11 = vRight.x;
		//tmpWorld._12 = vUp.x;
		//tmpWorld._13 = vLook.x;
		//tmpWorld._14 = 0.f;
		//
		//tmpWorld._21 = vRight.y;
		//tmpWorld._22 = vUp.y;
		//tmpWorld._23 = vLook.y;
		//tmpWorld._24 = 0.f;
		//
		//tmpWorld._31 = vRight.z;
		//tmpWorld._32 = vUp.z;
		//tmpWorld._33 = vLook.z;
		//tmpWorld._34 = 0.f;
		//
		//tmpWorld._41 = tmpPos.x;
		//tmpWorld._42 = tmpPos.y;
		//tmpWorld._43 = tmpPos.z;
		//tmpWorld._44 = 1.f;
		//
		//m_pTransform->SetWorldMatrix(tmpWorld);
	}


	// 상수 박기 [ 잘 작동됨 ]
	{
		//m_pTransform->Set_Angle(_v3{ 0,0,tmpDir.z * 90 }, ENGINE::ANGLE_X);
		//
		//if (tmpPos.x > targetPos.x)
		//	m_pTransform->Set_Angle(_v3{ 0,-tmpDir.y * 90 + 90,0 }, ENGINE::ANGLE_X);
		//
		//else if (tmpPos.x <= targetPos.x)
		//	m_pTransform->Set_Angle(_v3{ 0,tmpDir.y * 90 + 270,0 }, ENGINE::ANGLE_X);
	}


	m_pTransform->Add_Pos(fMoveSpeed , tmpDir);

	ENGINE::CGameObject::LateInit();
	ENGINE::CGameObject::Update();

	return NO_EVENT;
}

void CMonster::LateUpdate()
{
	ENGINE::CGameObject::LateUpdate();
}

void CMonster::Render()
{
	m_pGraphicDev->SetTransform(D3DTS_WORLD, &(m_pTransform->Get_WorldMat()));

	m_pBuffer->Render_Buffer();

	//m_pGraphicDev->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
}

HRESULT CMonster::Initialize()
{
	ENGINE::CComponent* pComponent = nullptr;

	//pComponent = ENGINE::Clone(ENGINE::RESOURCE_STATIC, L"Buffer_RcTex");
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent.insert({ L"Texture", pComponent });
	//
	//m_pTexture = dynamic_cast<ENGINE::CTexture*>(pComponent);
	//NULL_CHECK_RETURN(m_pTexture, E_FAIL);


	pComponent = ENGINE::Clone(ENGINE::RESOURCE_STATIC, L"Buffer_TriCol");
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent.insert({ L"Buffer", pComponent });

	m_pBuffer = dynamic_cast<ENGINE::CVIBuffer*>(pComponent);
	NULL_CHECK_RETURN(m_pBuffer, E_FAIL);


	pComponent = ENGINE::Clone_Com(ENGINE::RESOURCE_STATIC, L"Transform");
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent.insert({ L"Transform", pComponent });

	m_pTransform = dynamic_cast<ENGINE::CTransform*>(pComponent);
	NULL_CHECK_RETURN(m_pTransform, E_FAIL);

	m_pTransform->Set_Scale(_v3{ 0.5f, 0.5f, 0.5f });
	m_pTransform->Set_Pos(_v3{ 5.f, 0.f, 10.f });

	return S_OK;
}

HRESULT CMonster::LateInit()
{
	return S_OK;
}

CMonster * CMonster::Create(LPDIRECT3DDEVICE9 pGraphicDev, CGameObject* _Target)
{
	CMonster*	pInstance = new CMonster(pGraphicDev);

	if (FAILED(pInstance->Initialize()))
		ENGINE::Safe_Release(pInstance);

	pInstance->Set_Target(_Target);

	return pInstance;
}

void CMonster::Free()
{
	ENGINE::Safe_Release(m_pTransform);
	ENGINE::Safe_Release(m_pTexture);
	ENGINE::Safe_Release(m_pBuffer);
}
