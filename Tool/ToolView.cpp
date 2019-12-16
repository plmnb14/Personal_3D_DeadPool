
// ToolView.cpp : CToolView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Tool.h"
#endif

#include "ToolDoc.h"
#include "ToolView.h"
#include "MainFrm.h"

#include "Camera.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ��������
HWND g_hWnd;

// CToolView

IMPLEMENT_DYNCREATE(CToolView, CView)

BEGIN_MESSAGE_MAP(CToolView, CView)
	// ǥ�� �μ� �����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CToolView ����/�Ҹ�

CToolView::CToolView()
	:m_pDeviceMgr(nullptr)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CToolView::~CToolView()
{
	ENGINE::Release_System();
}

BOOL CToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CToolView �׸���

void CToolView::OnDraw(CDC* /*pDC*/)
{
	CToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CToolView �μ�

BOOL CToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CToolView ����

#ifdef _DEBUG
void CToolView::AssertValid() const
{
	CView::AssertValid();
}

void CToolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToolDoc* CToolView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToolDoc)));
	return (CToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CToolView �޽��� ó����


void CToolView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	g_hWnd = m_hWnd;

	HRESULT hr = ENGINE::InitDevice(g_hWnd, WINCX, WINCY, ENGINE::MODE_WIN, &m_pDeviceMgr);

	m_pDeviceClass = m_pDeviceMgr->Get_Device();

	m_pDeviceClass->SetRenderState(D3DRS_LIGHTING, FALSE);

	CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(::AfxGetApp()->GetMainWnd());

	// GetWindowRect: �������� ��� �׵θ��� ������ �簢�� ũ�⸦ ���´�.
	// �� �� ��ǥ�� ��ũ�� ��ǥ �����̴�.
	RECT rcMain = {};
	pMainFrm->GetWindowRect(&rcMain); // MainFrame�� ũ�⸦ ����.

									  // �̷��� ���� Main�� left, top�� 0, 0�������� ����.
	::SetRect(&rcMain, 0, 0, rcMain.right - rcMain.left, rcMain.bottom - rcMain.top);

	// GetClientRect: �������� �׵θ��� ������ ���� Ŭ���̾�Ʈ ������ �簢�� ũ�⸦ ���´�.
	// �� �� ��ǥ�� Ŭ���̾�Ʈ ��ǥ �����̴�. �� �� left, top�� ������ 0, 0���� ����.
	RECT rcView = {};
	GetClientRect(&rcView);

	// MainFrm�� View�� ������ ���Ѵ�.
	int iGapX = rcMain.right - rcView.right;
	int iGapY = rcMain.bottom - rcView.bottom;

	// MainFrame�� ũ�� ����.
	pMainFrm->SetWindowPos(
		nullptr, 0, 0, 1580 + iGapX, 900 + iGapY, SWP_NOZORDER);


	//m_pCam = CCamera::Create(m_pDeviceClass, CCamera::NO_CLIP);


	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}

void CToolView::Function()
{
	Update();
	Render();
}

void CToolView::Update()
{
	cout << "�ɴϴ�" << endl;
}

void CToolView::Render()
{
	m_pDeviceMgr->Render_Begin();


	m_pDeviceMgr->Render_End();
}