// Scene_ObjList_Form.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tool.h"
#include "Scene_ObjList_Form.h"


// CScene_ObjList_Form

IMPLEMENT_DYNCREATE(CScene_ObjList_Form, CFormView)

CScene_ObjList_Form::CScene_ObjList_Form()
	: CFormView(IDD_SCENE_OBJLIST_FORM)
{

}

CScene_ObjList_Form::~CScene_ObjList_Form()
{
}

void CScene_ObjList_Form::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CScene_ObjList_Form, CFormView)
END_MESSAGE_MAP()


// CScene_ObjList_Form �����Դϴ�.

#ifdef _DEBUG
void CScene_ObjList_Form::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CScene_ObjList_Form::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CScene_ObjList_Form �޽��� ó�����Դϴ�.
