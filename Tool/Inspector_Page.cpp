// Inspector_Page.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tool.h"
#include "Inspector_Page.h"
#include "afxdialogex.h"


// CInspector_Page ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CInspector_Page, CPropertyPage)

CInspector_Page::CInspector_Page()
	: CPropertyPage(IDD_INSPECTOR_PAGE)
{

}

CInspector_Page::~CInspector_Page()
{
}

void CInspector_Page::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInspector_Page, CPropertyPage)
END_MESSAGE_MAP()


// CInspector_Page �޽��� ó�����Դϴ�.
