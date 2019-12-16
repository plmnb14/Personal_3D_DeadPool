#ifndef Transform_h__
#define Transfotm_h__

#include "Component.h"

BEGIN(ENGINE)

class ENGINE_DLL CTransform : public CComponent
{
private:
	explicit	CTransform();
	explicit	CTransform(const CTransform& rhs);
	virtual		~CTransform();

public:
	HRESULT Ready_Transform();

public:
	const T_INFO	Get_Info	()	const;
	const _v3&		Get_Pos		()	const;
	const _v3&		Get_Right	()	const;
	const _v3&		Get_Up		()	const;
	const _v3&		Get_Look	()	const;
	const _v3&		Get_Size	()	const;
	const _v3&		Get_At		()	const;
	const _v3&		Get_Origin	()	const;
	const _mat&		Get_WorldMat()	const;

public:
	const _v3&		Get_Angle()					const;
	const float&	Get_Angle(ANGLE_TYPE eAxis) const;

public:
	void Set_Pos		(const _v3& _vPos);
	void Set_Right		(const _v3& _vRight);
	void Set_Up			(const _v3& _vUp);
	void Set_Look		(const _v3& _vLook);
	void Set_Scale		(const _v3& _vScale);
	void Set_WorldMat	(const _mat& _matWorld);
	void Set_At			(const _v3& _At);
	void Set_Origin		(const _v3& _Origin);

public:
	void Set_Angle		(const _v3& vAngle);
	void Set_Angle		(const _float& fAngle, ANGLE_TYPE eAxis);

public:
	void Add_Pos		(const float _fSpeed);
	void Add_Pos		(const float _fSpeed , const _v3& _vDir);
	void Add_Pos		(const _v3 & _vPos);
	void Add_PosY		(const float fSpeed);

public:
	void Add_At			(const float _fSpeed);
	void Add_At			(const float _fSpeed, const _v3& _vDir);
	void Add_At			(const _v3& _At);

public:
	void Add_Angle		(const ANGLE_TYPE eAxis, const float fSpeed);

public:
	virtual void LateUpdate();

public:
	static	CTransform*		Create();
	virtual CComponent*		Clone();

public:
	virtual void Free();

private:
	T_INFO	m_tInfo;
};

END

#endif // Transform_h__