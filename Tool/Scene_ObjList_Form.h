#pragma once



// CScene_ObjList_Form �� ���Դϴ�.

class CScene_ObjList_Form : public CFormView
{
	DECLARE_DYNCREATE(CScene_ObjList_Form)

protected:
	CScene_ObjList_Form();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CScene_ObjList_Form();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCENE_OBJLIST_FORM };
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


