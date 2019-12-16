#ifndef Component_h__
#define Component_h__

#include "Base.h"
#include "Engine_Defines.h"

BEGIN(ENGINE)

class ENGINE_DLL CComponent : public CBase
{
protected:
	explicit CComponent();
	explicit CComponent(const CComponent& rhs);
	virtual ~CComponent() PURE;

public:
	virtual void Update() {}
	virtual void LateUpdate() {}

public:
	virtual CComponent*		Clone() { return nullptr; }
	virtual void Free() {};

};

END

#endif // #ifndef Component_h__