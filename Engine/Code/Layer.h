#ifndef Layer_h__
#define Layer_h__

#include "GameObject.h"

BEGIN(ENGINE)

class ENGINE_DLL CLayer : public CBase
{
private:
	explicit CLayer();
	virtual ~CLayer();
public:
	HRESULT		Ready_Layer();
	void		Update_Layer(const _float& fTimeDelta);
	void		LateUpdate_Layer();
	void		Render_Layer();

public:
	HRESULT AddObject(ENGINE::OBJ_TYPE _ObjType, CGameObject* pObject);

private:
	typedef list<CGameObject*>			OBJECT_LIST;
	typedef map<ENGINE::OBJ_TYPE, OBJECT_LIST>	MAP_GAMEOBJECT;
	MAP_GAMEOBJECT		m_mapGameObject;

public:
	static CLayer*	Create();
	virtual void	Free();
};


END

#endif // Layer_h__
