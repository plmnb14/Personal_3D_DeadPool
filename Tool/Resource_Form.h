#pragma once



// CResource_Form �� ���Դϴ�.

class CResource_Form : public CFormView
{
	DECLARE_DYNCREATE(CResource_Form)

protected:
	CResource_Form();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CResource_Form();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESOURCE_FORM };
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
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};


