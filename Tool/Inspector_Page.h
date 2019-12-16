#pragma once


// CInspector_Page 대화 상자입니다.

class CInspector_Page : public CPropertyPage
{
	DECLARE_DYNAMIC(CInspector_Page)

public:
	CInspector_Page();
	virtual ~CInspector_Page();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSPECTOR_PAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
