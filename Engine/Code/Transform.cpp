#include "Transform.h"

USING(ENGINE)

CTransform::CTransform()
{
	ZeroMemory(&m_tInfo, sizeof(T_INFO));

	D3DXMatrixIdentity(&m_tInfo.matTrans);
	D3DXMatrixIdentity(&m_tInfo.matScale);
	D3DXMatrixIdentity(&m_tInfo.matRot[ANGLE_X]);
	D3DXMatrixIdentity(&m_tInfo.matRot[ANGLE_Y]);
	D3DXMatrixIdentity(&m_tInfo.matRot[ANGLE_Z]);
	D3DXMatrixIdentity(&m_tInfo.matWorld);

	m_tInfo.vAt		= { 0.f, 0.f, 1.f };
	m_tInfo.vRight	= { 1.f, 0.f, 0.f };
	m_tInfo.vUp		= { 0.f, 1.f, 0.f };
	m_tInfo.vLook	= { 0.f, 0.f, 1.f };
}

CTransform::CTransform(const CTransform & rhs)
	: CComponent(rhs)
{
	memcpy(&m_tInfo, &rhs.m_tInfo, sizeof(T_INFO));
}

CTransform::~CTransform()
{
}

HRESULT CTransform::Ready_Transform()
{
	D3DXMatrixIdentity(&m_tInfo.matWorld);

	// Matrix Setup
	memcpy(m_tInfo.vRight, &m_tInfo.matWorld.m[0][0], sizeof(_v3));
	memcpy(m_tInfo.vUp, &m_tInfo.matWorld.m[1][0], sizeof(_v3));
	memcpy(m_tInfo.vLook, &m_tInfo.matWorld.m[2][0], sizeof(_v3));
	memcpy(m_tInfo.vPos, &m_tInfo.matWorld.m[3][0], sizeof(_v3));

	return S_OK;
}

const T_INFO CTransform::Get_Info() const
{
	return m_tInfo;
}

const _v3& CTransform::Get_Pos() const
{
	return m_tInfo.vPos;
}

const _v3 & CTransform::Get_Right() const
{
	return m_tInfo.vRight;
}

const _v3 & CTransform::Get_Up() const
{
	return m_tInfo.vUp;
}

const _v3& CTransform::Get_Look() const
{
	return m_tInfo.vLook;
}

const _v3& CTransform::Get_Size() const
{
	return m_tInfo.vScale;
}

const _v3 & CTransform::Get_At() const
{
	return m_tInfo.vAt;
}

const _v3 & CTransform::Get_Origin() const
{
	return m_tInfo.vOrigin;
}

const _mat& CTransform::Get_WorldMat() const
{
	return m_tInfo.matWorld;
}

const _v3 & CTransform::Get_Angle() const
{
	return m_tInfo.vAngle;
}

const float& CTransform::Get_Angle(ANGLE_TYPE eAxis) const
{
	return m_tInfo.vAngle[eAxis];
}

void CTransform::Set_Pos(const _v3& vPos)
{
	m_tInfo.vPos = vPos;
}

void CTransform::Set_Right(const _v3 & _vRight)
{
	m_tInfo.vRight = _vRight;
}

void CTransform::Set_Up(const _v3 & _vUp)
{
	m_tInfo.vUp = _vUp;
}

void CTransform::Set_Look(const _v3& vLook)
{
	m_tInfo.vLook = vLook;
}

void CTransform::Set_Scale(const _v3& vScale)
{
	m_tInfo.vScale = vScale;
}

void CTransform::Set_WorldMat(const _mat& matWorld)
{
	m_tInfo.matWorld = matWorld;
}

void CTransform::Set_At(const _v3 & _At)
{
	m_tInfo.vAt = _At;
}

void CTransform::Set_Origin(const _v3 & _Origin)
{
	m_tInfo.vOrigin = _Origin;
}

void CTransform::Set_Angle(const _v3 & vAngle)
{
	m_tInfo.vAngle = vAngle;
}

void CTransform::Set_Angle(const  _float& fAngle, ANGLE_TYPE eAxis)
{
	m_tInfo.vAngle[eAxis] = fAngle;
}

void CTransform::Add_Pos(const float fSpeed)
{
	D3DXVec3Normalize(&m_tInfo.vLook, &m_tInfo.vLook);
	m_tInfo.vPos += m_tInfo.vLook * fSpeed;
}

void CTransform::Add_Pos(const float fSpeed , const _v3& _vDir)
{
	m_tInfo.vPos += _vDir * fSpeed;
}

void CTransform::Add_Pos(const _v3& _vPos)
{
	m_tInfo.vPos += _vPos;
}

void CTransform::Add_PosY(const float fSpeed)
{
	D3DXVec3Normalize(&m_tInfo.vLook, &m_tInfo.vLook);
	m_tInfo.vPos.y += m_tInfo.vLook.y * fSpeed;
}

void CTransform::Add_At(const float _fSpeed)
{
	D3DXVec3Normalize(&m_tInfo.vLook, &m_tInfo.vLook);
	m_tInfo.vAt += m_tInfo.vLook * _fSpeed;
}

void CTransform::Add_At(const float _fSpeed, const _v3 & _vDir)
{
	m_tInfo.vAt += _vDir * _fSpeed;
}

void CTransform::Add_At(const _v3 & _At)
{
	D3DXVec3Normalize(&m_tInfo.vLook, &m_tInfo.vLook);
	m_tInfo.vAt += _At;
}

void CTransform::Add_Angle(const ANGLE_TYPE eAxis, const float fSpeed)
{
	m_tInfo.vAngle[eAxis] += D3DXToRadian(fSpeed);
	//m_tInfo.vAngle[eAxis] += fSpeed;
}

void CTransform::LateUpdate()
{
	D3DXMatrixIdentity(&m_tInfo.matWorld);

	memcpy(m_tInfo.vRight, &m_tInfo.matWorld.m[0][0], sizeof(_v3));
	memcpy(m_tInfo.vUp, &m_tInfo.matWorld.m[1][0], sizeof(_v3));
	memcpy(m_tInfo.vLook, &m_tInfo.matWorld.m[2][0], sizeof(_v3));

	// Look, Up, Right
	//m_tInfo.vLook = m_tInfo.vAt - m_tInfo.vPos;
	//D3DXVec3Normalize(&m_tInfo.vLook, &m_tInfo.vLook);
	//
	//D3DXVec3Cross(&m_tInfo.vRight, &m_tInfo.vUp, &m_tInfo.vLook);
	//D3DXVec3Normalize(&m_tInfo.vRight, &m_tInfo.vRight);
	//
	//D3DXVec3Cross(&m_tInfo.vUp, &m_tInfo.vLook, &m_tInfo.vRight);
	//D3DXVec3Normalize(&m_tInfo.vUp, &m_tInfo.vUp);

	// Matrix Setup
	D3DXVec3Normalize(&m_tInfo.vRight, &m_tInfo.vRight);
	m_tInfo.vRight *= *(((_float*)&m_tInfo.vScale) + 0);

	D3DXVec3Normalize(&m_tInfo.vUp, &m_tInfo.vUp);
	m_tInfo.vUp *= *(((_float*)&m_tInfo.vScale) + 1);

	D3DXVec3Normalize(&m_tInfo.vLook, &m_tInfo.vLook);
	m_tInfo.vLook *= *(((_float*)&m_tInfo.vScale) + 2);




	// Rotation
	D3DXMatrixRotationX(&m_tInfo.matRot[ANGLE_X], m_tInfo.vAngle.x);
	D3DXMatrixRotationY(&m_tInfo.matRot[ANGLE_Y], m_tInfo.vAngle.y);
	D3DXMatrixRotationZ(&m_tInfo.matRot[ANGLE_Z], m_tInfo.vAngle.z);

	// Rotation Done
	D3DXVec3TransformNormal(&m_tInfo.vRight, &m_tInfo.vRight, &m_tInfo.matRot[ANGLE_X]);
	D3DXVec3TransformNormal(&m_tInfo.vRight, &m_tInfo.vRight, &m_tInfo.matRot[ANGLE_Y]);
	D3DXVec3TransformNormal(&m_tInfo.vRight, &m_tInfo.vRight, &m_tInfo.matRot[ANGLE_Z]);

	D3DXVec3TransformNormal(&m_tInfo.vUp, &m_tInfo.vUp, &m_tInfo.matRot[ANGLE_X]);
	D3DXVec3TransformNormal(&m_tInfo.vUp, &m_tInfo.vUp, &m_tInfo.matRot[ANGLE_Y]);
	D3DXVec3TransformNormal(&m_tInfo.vUp, &m_tInfo.vUp, &m_tInfo.matRot[ANGLE_Z]);

	D3DXVec3TransformNormal(&m_tInfo.vLook, &m_tInfo.vLook, &m_tInfo.matRot[ANGLE_X]);
	D3DXVec3TransformNormal(&m_tInfo.vLook, &m_tInfo.vLook, &m_tInfo.matRot[ANGLE_Y]);
	D3DXVec3TransformNormal(&m_tInfo.vLook, &m_tInfo.vLook, &m_tInfo.matRot[ANGLE_Z]);


	// Translation
	memcpy(&m_tInfo.matWorld.m[0][0], &m_tInfo.vRight, sizeof(_v3));
	memcpy(&m_tInfo.matWorld.m[1][0], &m_tInfo.vUp, sizeof(_v3));
	memcpy(&m_tInfo.matWorld.m[2][0], &m_tInfo.vLook, sizeof(_v3));
	memcpy(&m_tInfo.matWorld.m[3][0], &m_tInfo.vPos, sizeof(_v3));
}

CTransform* CTransform::Create()
{
	return new CTransform();
}

CComponent * CTransform::Clone()
{
	return new CTransform(*this);
}

void CTransform::Free()
{
	ENGINE::CComponent::Free();
}
