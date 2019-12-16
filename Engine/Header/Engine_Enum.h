#ifndef Engine_Enum_h__
#define Engine_Enum_h__

namespace ENGINE
{
	enum RESOURCEID { RESOURCE_STATIC, RESOURCE_LOGO, RESOURCE_STAGE, RESOURCE_END };
	enum LOADINGID { LOADING_STAGE, LOADING_BOSS, LOADING_END };

	enum DISPLAY_MODE
	{
		MODE_FULL, MODE_WIN
	};

	enum ANGLE_TYPE
	{
		ANGLE_X, ANGLE_Y, ANGLE_Z, ANGLE_END
	};

	enum COL_TYPE
	{
		COL_AABB, COL_SHPERE, COL_PLANE, COL_LINE, COL_CAPSHULE, COL_END
	};

	enum COMP_TYPE
	{
		_TRANSFORM, _COLLIDER, _COMP_END
	};

	enum BUFFERID 
	{
		BUFFER_RCCOL, BUFFER_RCTEX, BUFFER_TRICOL, BUFFER_TERRAINTEX, BUFFER_CUBETEX 
	};

	enum TEXTURETYPE 
	{ 
		TEX_NORMAL, TEX_CUBE, TEX_END 
	};

	enum OBJ_LAYER
	{
		LAYER_ENVIRON, LAYER_OBJ, LAYER_UI
	};

	enum OBJ_TYPE
	{
		BACKGORUND, PLAYER, MONSTER, UI, OBJ_END
	};

	enum CameraMode
	{
		DEFAULT_MODE, RANGE_MODE, AIM_MODE, EXECUTION_MODE, FLY_MODE
	};

	enum CameraView
	{
		FIRST_VIEW, THIRD_VIEW, BACK_VIEW, SHOLDER_VIEW, SIDE_VIEW, TOP_VIEW, QUATER_VIEW
	};

	enum CameraClass
	{
		STATIC_CAM, DYNAMIC_CAM, FREE_CAM
	};
}

#endif // Engine_Enum_h__
