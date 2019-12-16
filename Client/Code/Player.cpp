#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer(LPDIRECT3DDEVICE9 pGraphicDev)
	:ENGINE::CGameObject(pGraphicDev) , 
	m_pTexture(nullptr), m_pBuffer(nullptr) , m_pTransform(nullptr),
	m_bFront(false), m_bBack(false), m_bLeft(false), m_bRight(false),
	m_fAngle_Recover(0)
{
}

CPlayer::~CPlayer()
{
}

int CPlayer::Update()
{
	ENGINE::CGameObject::LateInit();
	ENGINE::CGameObject::Update();

	KeyInput();
	Movement();

	return NO_EVENT;
}

void CPlayer::LateUpdate()
{
	ENGINE::CGameObject::LateUpdate();
}

void CPlayer::Render()
{
	m_pGraphicDev->SetTransform(D3DTS_WORLD, &(m_pTransform->Get_WorldMat()));

	m_pTexture->Render_Texture();
	m_pBuffer->Render_Buffer();
}

void CPlayer::KeyInput()
{
	KeyDown();
	KeyUp();
}

void CPlayer::KeyDown()
{
	if (ENGINE::KeyDown(ENGINE::KEY_W))
	{
		m_bFront = true;
	}

	else if (ENGINE::KeyDown(ENGINE::KEY_S))
	{
		m_bBack = true;
	}

	if (ENGINE::KeyDown(ENGINE::KEY_A))
	{
		m_bLeft = true;
	}

	else if (ENGINE::KeyDown(ENGINE::KEY_D))
	{
		m_bRight = true;
	}
}

void CPlayer::KeyUp()
{
	if (ENGINE::KeyUp(ENGINE::KEY_W))
	{
		m_bFront = false;
	}

	if (ENGINE::KeyUp(ENGINE::KEY_S))
	{
		m_bBack = false;
	}

	if (ENGINE::KeyUp(ENGINE::KEY_A))
	{
		m_bLeft = false;
	}

	if (ENGINE::KeyUp(ENGINE::KEY_D))
	{
		m_bRight = false;
	}
}

void CPlayer::Movement()
{
	_float fMoveSpeed = 10.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");
	_float fRotate = 180.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");
	_float fAngle = (_float)(((_int)ENGINE::Get_XAngle() % 360));
	_float fRadian = 0.f;

	m_fAngle_Recover = (_float)((int)m_fAngle_Recover % 360);


	if (m_bFront)
	{
		if (m_bLeft == true)
		{
			if (m_fAngle_Recover > -45.f)
			{
				m_fAngle_Recover -= 180.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");

				if (m_fAngle_Recover <= -45.f)
				{
					m_fAngle_Recover = -45.f;
				}
			}

			else if (m_fAngle_Recover < -45.f)
			{
				m_fAngle_Recover += 180.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");

				if (m_fAngle_Recover >= -45.f)
				{
					m_fAngle_Recover = -45.f;
				}
			}
		}

		else if (m_bRight == true)
		{
			if (m_fAngle_Recover < 45.f)
			{
				m_fAngle_Recover += 180.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");

				if (m_fAngle_Recover >= 45.f)
				{
					m_fAngle_Recover = 45.f;
				}
			}

			else if (m_fAngle_Recover > 45.f)
			{
				m_fAngle_Recover -= 180.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");

				if (m_fAngle_Recover <= 45.f)
				{
					m_fAngle_Recover = 45.f;
				}
			}
		}

		else
		{
			if (m_fAngle_Recover > 0.f)
			{
				m_fAngle_Recover -= 180.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");

				if (m_fAngle_Recover <= 0.f)
				{
					m_fAngle_Recover = 0.f;
				}
			}

			else if (m_fAngle_Recover < 0.f)
			{
				m_fAngle_Recover += 180.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");

				if (m_fAngle_Recover >= 0.f)
				{
					m_fAngle_Recover = 0.f;
				}
			}
		}

		fRadian = D3DXToRadian(fAngle + m_fAngle_Recover);

		m_pTransform->Set_Angle({ 0, fRadian, 0 });
		m_pTransform->Add_Pos(fMoveSpeed);
	}

	else if (m_bBack)
	{
		if (m_bLeft == true)
		{
			if (m_fAngle_Recover < 225.f)
			{
				m_fAngle_Recover += 180.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");

				if (m_fAngle_Recover >= 225.f)
				{
					m_fAngle_Recover = 225.f;
				}
			}
		}

		else if (m_bRight == true)
		{
			if (m_fAngle_Recover > 135.f)
			{
				m_fAngle_Recover -= 180.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");

				if (m_fAngle_Recover <= 135.f)
				{
					m_fAngle_Recover = 135.f;
				}
			}
		}

		else
		{
			if (m_fAngle_Recover > 180.f)
			{
				m_fAngle_Recover -= 180.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");

				if (m_fAngle_Recover <= 180.f)
				{
					m_fAngle_Recover = 180.f;
				}
			}

			else if (m_fAngle_Recover < 180.f)
			{
				m_fAngle_Recover += 180.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");

				if (m_fAngle_Recover >= 180.f)
				{
					m_fAngle_Recover = 180.f;
				}
			}
		}

		fRadian = D3DXToRadian(fAngle + m_fAngle_Recover);

		m_pTransform->Set_Angle({ 0, fRadian, 0 });
		m_pTransform->Add_Pos(fMoveSpeed);
	}

	else if (m_bLeft)
	{
		if (m_fAngle_Recover <= 0)
		{
			m_fAngle_Recover -= 180.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");

			if (m_fAngle_Recover <= -90.f)
			{
				m_fAngle_Recover = -90.f;
			}
		}

		else if (m_fAngle_Recover > 0)
		{
			m_fAngle_Recover += 180.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");

			if (m_fAngle_Recover >= 90.f)
			{
				m_fAngle_Recover = 90.f;
			}
		}
		
		fRadian = D3DXToRadian(fAngle + m_fAngle_Recover);

		m_pTransform->Set_Angle({ 0, fRadian, 0 });
		m_pTransform->Add_Pos(fMoveSpeed);
	}
	
	else if (m_bRight)
	{
		if (m_fAngle_Recover < 0)
		{
			m_fAngle_Recover -= 180.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");

			if (m_fAngle_Recover <= -180.f)
			{
				m_fAngle_Recover = -180.f;
			}
		}

		else if (m_fAngle_Recover >= 0)
		{
			m_fAngle_Recover += 180.f * ENGINE::Get_Deltatime(L"Timer_Fps_60");

			if (m_fAngle_Recover >= 90.f)
			{
				m_fAngle_Recover = 90.f;
			}
		}

		fRadian = D3DXToRadian(fAngle + m_fAngle_Recover);

		m_pTransform->Set_Angle({ 0, fRadian, 0 });
		m_pTransform->Add_Pos(fMoveSpeed);
	}

	//(m_bLeft ? m_bRight ? 
	//	fRadian = D3DXToRadian(fAngle - 45.f) :	  
	//	fRadian = D3DXToRadian(fAngle + 45.f) :
	//	fRadian = D3DXToRadian(fAngle));

	//(m_bLeft ? m_bRight ? 
	//	fRadian = D3DXToRadian(fAngle - 225.f) :
	//	fRadian = D3DXToRadian(fAngle + 225.f) :
	//	fRadian = D3DXToRadian(fAngle - 180.f));
}

HRESULT CPlayer::Initialize()
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


	pComponent = ENGINE::Clone_Com(ENGINE::RESOURCE_STATIC, L"Transform");
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent.insert({ L"Transform", pComponent });

	m_pTransform = dynamic_cast<ENGINE::CTransform*>(pComponent);
	NULL_CHECK_RETURN(m_pTransform, E_FAIL);


	m_pTransform->Set_At({ 0,1.5f,1 });
	m_pTransform->Set_Scale(_v3{ 1.0f, 3.0f, 1.0f });
	m_pTransform->Set_Pos(_v3{ 0.f, 1.5f, 10.f });

	return S_OK;
}

HRESULT CPlayer::LateInit()
{
	return S_OK;
}

CPlayer * CPlayer::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CPlayer*	pInstance = new CPlayer(pGraphicDev);

	if (FAILED(pInstance->Initialize()))
		ENGINE::Safe_Release(pInstance);

	return pInstance;
}

void CPlayer::Free()
{
	ENGINE::CGameObject::Free();
}
