#ifndef ComponentMgr_h__
#define ComponentMgr_h__

#include "Engine_Defines.h"
#include "Base.h"

#include "Component.h"
#include "Renderer.h"
#include "Transform.h"
#include "Collider.h"


BEGIN(ENGINE)

class ENGINE_DLL CComponentMgr : public CBase
{
	DECLARE_SINGLETON(CComponentMgr)

private:
	explicit CComponentMgr(void);
	virtual ~CComponentMgr(void);

public:
	HRESULT Ready_ComponentMgr();
	HRESULT	Reserve_ContainerSize(const _ushort& wSize);

	HRESULT	Ready_Component(
						  const _ushort& wContainerIdx,
						  const _tchar* pComponentTag,
						  COMP_TYPE eID);

	CComponent*	Clone(const _ushort& wContainerIdx, const _tchar* pComponentTag);

private:
	CComponent*	Find_Component(const _ushort& wContainerIdx, const _tchar* pComponentTag);

private:
	map<const _tchar*, CComponent*>*		m_pmapComponent;
	_ushort									m_wContainerSize;

public:
	virtual void Free(void);

};

END
#endif // ComponentMgr_h__
