#ifndef SceneSelector_h__
#define SceneSelector_h__

#include "Scene_Logo.h"
#include "Scene_Stage_01.h"

class CSceneSelector
{
public:
	enum SCENE_TYPE { LOGO, STAGE_01, STAGE_02, STAGE_BOSS, SCENE_END };

public:
	explicit CSceneSelector(SCENE_TYPE eType)
		: m_eCurrentScene(eType)
	{}

public:
	HRESULT operator()(ENGINE::CScene** ppScene, LPDIRECT3DDEVICE9 pGraphicDev)
	{
		switch (m_eCurrentScene)
		{
		case LOGO:
			*ppScene = CScene_Logo::Create(pGraphicDev);
			break;
		case STAGE_01:
			*ppScene = CScene_Stage_01::Create(pGraphicDev);
			break;
		}

		NULL_CHECK_RETURN(*ppScene, E_FAIL);
		return S_OK;
	}

private:
	SCENE_TYPE	m_eCurrentScene;	
};

#endif // SceneSelector_h__
