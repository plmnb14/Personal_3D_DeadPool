// ObjectList_Form.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tool.h"
#include "ObjectList_Form.h"


// CObjectList_Form

IMPLEMENT_DYNCREATE(CObjectList_Form, CFormView)

CObjectList_Form::CObjectList_Form()
	: CFormView(IDD_OBJECTLIST_FORM)
{

}

CObjectList_Form::~CObjectList_Form()
{
}

void CObjectList_Form::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CObjectList_Form, CFormView)
END_MESSAGE_MAP()


// CObjectList_Form �����Դϴ�.

#ifdef _DEBUG
void CObjectList_Form::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CObjectList_Form::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CObjectList_Form �޽��� ó�����Դϴ�.
