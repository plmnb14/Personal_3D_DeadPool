// Resource_Form.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tool.h"
#include "Resource_Form.h"


// CResource_Form

IMPLEMENT_DYNCREATE(CResource_Form, CFormView)

CResource_Form::CResource_Form()
	: CFormView(IDD_RESOURCE_FORM)
{

}

CResource_Form::~CResource_Form()
{
}

void CResource_Form::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CResource_Form, CFormView)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CResource_Form::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// CResource_Form �����Դϴ�.

#ifdef _DEBUG
void CResource_Form::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CResource_Form::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CResource_Form �޽��� ó�����Դϴ�.


void CResource_Form::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}
