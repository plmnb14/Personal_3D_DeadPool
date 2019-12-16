// Inspector_Sheet.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Tool.h"
#include "Inspector_Sheet.h"


// CInspector_Sheet

IMPLEMENT_DYNAMIC(CInspector_Sheet, CPropertySheet)



CInspector_Sheet::CInspector_Sheet(CWnd * pParentWnd)
{
	CPropertySheet::AddPage(&m_Page_Inspector);
	CPropertySheet::AddPage(&m_Page_Animator);
	CPropertySheet::AddPage(&m_Page_Collider);
}

//CInspector_Sheet::CInspector_Sheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
//	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
//{
//
//	CPropertySheet::AddPage(&m_Page_Inspector);
//}
//
//CInspector_Sheet::CInspector_Sheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
//	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
//{
//
//}

CInspector_Sheet::~CInspector_Sheet()
{
	CPropertySheet::RemovePage(&m_Page_Inspector);
	CPropertySheet::RemovePage(&m_Page_Animator);
	CPropertySheet::RemovePage(&m_Page_Collider);
}


BEGIN_MESSAGE_MAP(CInspector_Sheet, CPropertySheet)
END_MESSAGE_MAP()


// CInspector_Sheet 메시지 처리기입니다.
