// Collider_Page.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tool.h"
#include "Collider_Page.h"
#include "afxdialogex.h"


// CCollider_Page ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CCollider_Page, CPropertyPage)

CCollider_Page::CCollider_Page()
	: CPropertyPage(IDD_COLLIDER_PAGE)
{

}

CCollider_Page::~CCollider_Page()
{
}

void CCollider_Page::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCollider_Page, CPropertyPage)
END_MESSAGE_MAP()


// CCollider_Page �޽��� ó�����Դϴ�.


BOOL CCollider_Page::OnInitDialog()
{
	CPropertyPage::OnInitDialog();



	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
