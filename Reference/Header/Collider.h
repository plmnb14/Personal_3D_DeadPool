#ifndef Collider_h__
#define Collider_h__

#include "Component.h"

BEGIN(ENGINE)

class ENGINE_DLL CCollider : public CComponent
{
private:
	explicit CCollider();
	virtual ~CCollider();

public:
	virtual void LateUpdate(_v3 _Pos);

public:
	void SetUp_Box();

public:
	void Set_Radius(_v3 _Radius);
	void Set_Length(_v3 _Length);
	void Set_CenterPos(_v3 _CenterPos);
	void Set_UnderPos();
	void Set_Dynamic(bool _Dynamic);
	void Set_Trigger(bool _Trigger);
	void Set_IsCol(bool _Collision);
	void Set_Type(ENGINE::COL_TYPE _Type) { m_eColType = _Type; }
	void Set_Enabled(bool _Enabled) { m_tColInfo.bIsEnabled = _Enabled; }

public:
	const _v3 Get_CenterPos()	const { return m_tColInfo.vCenterPos; }
	const _v3 Get_UnderPos()	const { return m_tColInfo.vUnderPos; }
	const _v3 Get_Length()		const { return m_tColInfo.vLength; }
	const _v3 Get_Radius()		const { return m_tColInfo.vRadius; }

	const bool Get_IsCol()				const { return m_tColInfo.bIsCol; }
	const bool Get_Enabled()			const { return m_tColInfo.bIsEnabled; }

	const ENGINE::COL_INFO* Get_ColInfo() const { return &m_tColInfo; }
	const ENGINE::COL_TYPE	Get_ColType() const { return m_eColType; }

public:
	static CCollider* Create();

private:
	virtual void Free();

private:
	ENGINE::COL_INFO	m_tColInfo;
	ENGINE::COL_TYPE	m_eColType;
	ENGINE::VTX_TEX*	m_pVtx;
};

END

#endif	// Collider_h__