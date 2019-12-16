#ifndef Renderer_h__
#define Renderer_h__

#include "Component.h"
#include "Engine_Defines.h"

BEGIN(ENGINE)

class ENGINE_DLL CRenderer : public CComponent
{
protected:
	explicit CRenderer(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CRenderer(const CRenderer& rhs);
	virtual ~CRenderer(void);

protected:
	LPDIRECT3DDEVICE9		m_pGraphicDev;

public:
	virtual CRenderer*		Clone() { return nullptr; }
	virtual void Free();
};

END
#endif // Renderer_h__
