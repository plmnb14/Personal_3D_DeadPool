// Inspector_Form.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tool.h"
#include "Inspector_Form.h"
#include "Inspector_Sheet.h"


// CInspector_Form

IMPLEMENT_DYNCREATE(CInspector_Form, CFormView)

CInspector_Form::CInspector_Form()
	: CFormView(IDD_INSPECTOR_FORM)
{

}

CInspector_Form::~CInspector_Form()
{
}

void CInspector_Form::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CInspector_Form, CFormView)
	ON_STN_CLICKED(IDC_PLACEHOLDER, &CInspector_Form::OnStnClickedPlaceholder)
END_MESSAGE_MAP()


// CInspector_Form �����Դϴ�.

#ifdef _DEBUG
void CInspector_Form::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CInspector_Form::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CInspector_Form �޽��� ó�����Դϴ�.


void CInspector_Form::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	GetParentFrame()->RecalcLayout();

	//ResizeParentToFit();

	CWnd* m_pPlaceHolder = GetDlgItem(IDC_PLACEHOLDER);

	m_Inspector_Sheet = new CInspector_Sheet(m_pPlaceHolder);

	if (!m_Inspector_Sheet->Create(m_pPlaceHolder, WS_CHILD | WS_VISIBLE, 0))
	{

		delete m_Inspector_Sheet;

		m_Inspector_Sheet = NULL;

		return;
	}

	CRect rcSheet;

	rcSheet.SetRect(0,0,280,850);
	//m_Inspector_Sheet->MoveWindow(rcSheet);
	//m_pPlaceHolder->GetWindowRect(&rcSheet);

	//ScreenToClient(&rcSheet);

	CTabCtrl *TabCtrl = m_Inspector_Sheet->GetTabControl();

	TabCtrl->MoveWindow(0, 0, rcSheet.Width(), rcSheet.Height());

	m_Inspector_Sheet->SetWindowPos(NULL, 12, 0, rcSheet.Width(), rcSheet.Height(), SWP_NOZORDER | SWP_NOACTIVATE);

	m_Inspector_Sheet->ModifyStyleEx(0, WS_EX_CONTROLPARENT);

	m_Inspector_Sheet->ModifyStyle(0, WS_TABSTOP);

	m_Inspector_Sheet->SetActivePage(0);

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}


void CInspector_Form::OnStnClickedPlaceholder()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
