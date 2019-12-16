#include "Collider.h"

USING(ENGINE)

CCollider::CCollider()
	:m_eColType(ENGINE::COL_AABB)
{
	ZeroMemory(&m_tColInfo, sizeof(COL_INFO));
}

CCollider::~CCollider()
{
}

void CCollider::LateUpdate(_v3 _Pos)
{
	Set_CenterPos(_Pos);
	Set_UnderPos();
	SetUp_Box();
	m_tColInfo.vMaxPos.y = m_tColInfo.vMaxPos.y;
}

void CCollider::SetUp_Box()
{
	m_tColInfo.vMinPos = { m_tColInfo.vCenterPos - m_tColInfo.vRadius };
	m_tColInfo.vMaxPos = { m_tColInfo.vCenterPos + m_tColInfo.vRadius };
}

void CCollider::Set_Radius(_v3 _Radius)
{
	m_tColInfo.vRadius = _Radius;
}

void CCollider::Set_Length(_v3 _Length)
{
	m_tColInfo.vLength = _Length;
}

void CCollider::Set_CenterPos(_v3 _CenterPos)
{
	m_tColInfo.vCenterPos = _CenterPos;
}

void CCollider::Set_UnderPos()
{
	m_tColInfo.vUnderPos = { m_tColInfo.vCenterPos.x ,
		m_tColInfo.vCenterPos.y - m_tColInfo.vRadius.y ,
		m_tColInfo.vCenterPos.z };
}

void CCollider::Set_Dynamic(bool _Dynamic)
{
	m_tColInfo.bIsDynamic = _Dynamic;
}

void CCollider::Set_Trigger(bool _Trigger)
{
	m_tColInfo.bIsTrigger = _Trigger;
}

void CCollider::Set_IsCol(bool _Collision)
{
	m_tColInfo.bIsCol = _Collision;
}

CCollider* CCollider::Create()
{
	return new CCollider();
}

void CCollider::Free()
{
}
