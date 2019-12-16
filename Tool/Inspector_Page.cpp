// Inspector_Page.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Tool.h"
#include "Inspector_Page.h"
#include "afxdialogex.h"


// CInspector_Page 대화 상자입니다.

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


// CInspector_Page 메시지 처리기입니다.
