#ifndef Engine_Struct_h__
#define Engine_Struct_h__

namespace ENGINE
{
	typedef struct tagVertexColor
	{
		_v3 vPos;		// 버텍스 위치
		DWORD		dwColor;	// 버텍스 색상
	}VTX_COL;

	const DWORD VTXFVF_COL = D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX0;

	typedef struct tagVertexTexture
	{
		_v3	vPos;
		D3DXVECTOR2 vTex;	// UV좌표.
	}VTX_TEX;

	const DWORD VTXFVF_TEX = D3DFVF_XYZ | D3DFVF_TEX1;

	typedef struct tagVertexCube
	{
		_v3 vPos;
		_v3 vTex;
	}VTX_CUBE;

	const DWORD VTXFVF_CUBE = D3DFVF_XYZ | D3DFVF_TEX1 | D3DFVF_TEXCOORDSIZE3(0);

	typedef struct tagIndex16
	{
		WORD _1, _2, _3;
	}INDEX16;

	typedef struct tagIndex32
	{
		DWORD _1, _2, _3;
	}INDEX32;

	//

	typedef struct tagTransform
	{
		_v3		vPos;
		_v3		vScale;

		_v3		vLook;
		_v3		vRight;
		_v3		vUp;
		_v3		vAngle;

		_v3		vAt;
		_v3		vOrigin;

		_mat	matScale;
		_mat	matRot[ANGLE_END];
		_mat	matTrans;
		_mat	matWorld;

	}T_INFO;


	typedef struct tagCamera
	{
		_v3 vRight;
		_v3 vUp;
		_v3 vLook;

		_v3 vEyePos;
		_v3 vLookAt;

		int			iIndex;
		float		fDistance;

		bool		bMainCamera;

	}CAM_INFO;

	typedef struct tagCollider
	{
		_v3 vCenterPos;
		_v3 vUnderPos;

		// AABB 충돌 검사 시 사용
		_v3 vMaxPos;
		_v3 vMinPos;

		_v3 vLength;
		_v3 vRadius;

		bool bIsDynamic;
		bool bIsCol;
		bool bIsTrigger;
		bool bIsEnabled;

	}COL_INFO;

	typedef struct tagPathInfo
	{
		wstring wstrObjectKey = L"";
		wstring wstrStateKey = L"";
		wstring wstrImgPath = L"";
		wstring wstrFileName = L"";
		int iImgCount = 0;
	}PATH_INFO;

}

#endif // Engine_Struct_h__
