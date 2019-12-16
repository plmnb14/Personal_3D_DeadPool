
// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "Tool.h"

#include "MainFrm.h"
#include "ToolView.h"

#include "MainForm.h"

#include "Inspector_Form.h"
#include "Resource_Form.h"
#include "ObjectList_Form.h"
#include "Scene_ObjList_Form.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_DISABLED | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("���� ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}

	SetMenu(NULL);

	::DestroyMenu(GetMenu()->GetSafeHmenu());
	m_wndToolBar.EnableWindow(FALSE);

	this->SetWindowText(L"DD");

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return TRUE;
}

// CMainFrame ����

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame �޽��� ó����



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// ���η� 3�� �����ڴ�.
	m_MainSplitter.CreateStatic(this, 1, 3);
	m_MainSplitter.SetColumnInfo(0, 200, 0);
	m_MainSplitter.SetColumnInfo(1, 1280, 0);
	m_MainSplitter.SetColumnInfo(2, 300, 0);

	m_ThirdSplitter.CreateStatic(&m_MainSplitter, 2, 1,
		WS_CHILD | WS_VISIBLE, m_MainSplitter.IdFromRowCol(0, 0));

	m_ForthSplitter.CreateStatic(&m_MainSplitter, 2, 1,
		WS_CHILD | WS_VISIBLE, m_MainSplitter.IdFromRowCol(0, 1));



	m_ThirdSplitter.CreateView(0, 0, RUNTIME_CLASS(CScene_ObjList_Form), CSize(200, 600), pContext);
	m_ThirdSplitter.CreateView(1, 0, RUNTIME_CLASS(CObjectList_Form), CSize(200, 300), pContext);

	m_ForthSplitter.CreateView(0, 0, RUNTIME_CLASS(CToolView), CSize(1280, 720), pContext);
	m_ForthSplitter.CreateView(1, 0, RUNTIME_CLASS(CResource_Form), CSize(1280, 180), pContext);

	m_MainSplitter.CreateView(0, 2, RUNTIME_CLASS(CInspector_Form), CSize(300, 720), pContext);

	return TRUE;
}
