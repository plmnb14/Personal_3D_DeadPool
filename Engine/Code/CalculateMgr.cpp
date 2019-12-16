#include "CalculateMgr.h"

USING(ENGINE)

CCalculateMgr::CCalculateMgr()
{
}


CCalculateMgr::~CCalculateMgr()
{
}


void CCalculateMgr::V3_Axis_Normal(_mat * _pOut_1, _v3 * _pOut_2, const _v3 * _pIn_1, const _float _pAngle, _bool _bRadian)
{
	_mat pOut_1 = *_pOut_1;
	_v3 pOut_2 = *_pOut_2;
	_v3 pIn_1 = *_pIn_1;
	_float fRadian = 0;
	(_bRadian ? fRadian = D3DXToRadian(_pAngle) : fRadian = _pAngle);

	D3DXMatrixRotationAxis(&pOut_1, &pIn_1, fRadian);
	D3DXVec3TransformNormal(&pOut_2, &pOut_2, &pOut_1);

	*_pOut_1 = pOut_1;
	*_pOut_2 = pOut_2;
}

void CCalculateMgr::V3_Dir_Normal(_v3 * _pOut, const _v3 * _pIn_1, const _v3 * _pIn_2)
{
	_v3 pOut = *_pOut;
	_v3 pIn_1 = *_pIn_1;
	_v3 pIn_2 = *_pIn_2;

	pOut = pIn_1 - pIn_2;
	D3DXVec3Normalize(&pOut, &pOut);

	*_pOut = pOut;
}

void CCalculateMgr::V3_Cross_Normal(_v3* _pOut, const _v3* _pIn_1, const _v3* _pIn_2)
{
	_v3 pOut = *_pOut;
	_v3 pIn_1 = *_pIn_1;
	_v3 pIn_2 = *_pIn_2;

	D3DXVec3Cross(&pOut, &pIn_1, &pIn_2);
	D3DXVec3Normalize(&pOut, &pOut);

	*_pOut = pOut;
}
