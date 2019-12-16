
#ifndef CalculateMgr_h__
#define CalculateMgr_h__

#include "Engine_Defines.h"

BEGIN(ENGINE)

typedef class ENGINE_DLL CCalculateMgr
{
private:
	CCalculateMgr();
	~CCalculateMgr();

public:
	static void V3_Axis_Normal(_mat* _pOut_1 , _v3* _pOut_2, const _v3* _pIn_1, const _float _pAngle, _bool _bRadian = false);
	static void V3_Dir_Normal(_v3* _pOut, const _v3* _pIn_1, const _v3* _pIn_2);
	static void V3_Cross_Normal(_v3* _pOut, const _v3* _pIn_1, const _v3* _pIn_2);

}CALC;

END

#endif // CalculateMgr_h__
