#pragma once


// CInspector_Page ��ȭ �����Դϴ�.

class CInspector_Page : public CPropertyPage
{
	DECLARE_DYNAMIC(CInspector_Page)

public:
	CInspector_Page();
	virtual ~CInspector_Page();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSPECTOR_PAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
