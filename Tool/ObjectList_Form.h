#pragma once



// CObjectList_Form �� ���Դϴ�.

class CObjectList_Form : public CFormView
{
	DECLARE_DYNCREATE(CObjectList_Form)

protected:
	CObjectList_Form();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CObjectList_Form();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OBJECTLIST_FORM };
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
};


