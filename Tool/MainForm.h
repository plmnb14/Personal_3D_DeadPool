#pragma once



// CMainForm �� ���Դϴ�.

class CMainForm : public CFormView
{
	DECLARE_DYNCREATE(CMainForm)

protected:
	CMainForm();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CMainForm();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAINFORM };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};


