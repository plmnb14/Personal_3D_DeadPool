
// ToolView.cpp : CToolView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// 전역변수
HWND g_hWnd;

// CToolView

IMPLEMENT_DYNCREATE(CToolView, CView)

BEGIN_MESSAGE_MAP(CToolView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CToolView 생성/소멸

CToolView::CToolView()
	:m_pDeviceMgr(nullptr)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CToolView::~CToolView()
{
	ENGINE::Release_System();
}

BOOL CToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CToolView 그리기

void CToolView::OnDraw(CDC* /*pDC*/)
{
	CToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CToolView 인쇄

BOOL CToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CToolView 진단

#ifdef _DEBUG
void CToolView::AssertValid() const
{
	CView::AssertValid();
}

void CToolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToolDoc* CToolView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToolDoc)));
	return (CToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CToolView 메시지 처리기


void CToolView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	g_hWnd = m_hWnd;

	HRESULT hr = ENGINE::InitDevice(g_hWnd, WINCX, WINCY, ENGINE::MODE_WIN, &m_pDeviceMgr);

	m_pDeviceClass = m_pDeviceMgr->Get_Device();

	m_pDeviceClass->SetRenderState(D3DRS_LIGHTING, FALSE);

	CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(::AfxGetApp()->GetMainWnd());

	// GetWindowRect: 윈도우의 모든 테두리를 포함한 사각형 크기를 얻어온다.
	// 이 때 좌표는 스크린 좌표 기준이다.
	RECT rcMain = {};
	pMainFrm->GetWindowRect(&rcMain); // MainFrame의 크기를 얻어옴.

									  // 이렇게 얻어온 Main의 left, top을 0, 0기준으로 셋팅.
	::SetRect(&rcMain, 0, 0, rcMain.right - rcMain.left, rcMain.bottom - rcMain.top);

	// GetClientRect: 윈도우의 테두리를 제외한 순수 클라이언트 영역의 사각형 크기를 얻어온다.
	// 이 때 좌표는 클라이언트 좌표 기준이다. 이 때 left, top은 무조건 0, 0부터 시작.
	RECT rcView = {};
	GetClientRect(&rcView);

	// MainFrm과 View의 간격을 구한다.
	int iGapX = rcMain.right - rcView.right;
	int iGapY = rcMain.bottom - rcView.bottom;

	// MainFrame의 크기 조정.
	pMainFrm->SetWindowPos(
		nullptr, 0, 0, 1580 + iGapX, 900 + iGapY, SWP_NOZORDER);


	//m_pCam = CCamera::Create(m_pDeviceClass, CCamera::NO_CLIP);


	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}

void CToolView::Function()
{
	Update();
	Render();
}

void CToolView::Update()
{
	cout << "옵니다" << endl;
}

void CToolView::Render()
{
	m_pDeviceMgr->Render_Begin();


	m_pDeviceMgr->Render_End();
}
