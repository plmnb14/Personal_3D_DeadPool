#pragma once


// CCollider_Page ��ȭ �����Դϴ�.

class CCollider_Page : public CPropertyPage
{
	DECLARE_DYNAMIC(CCollider_Page)

public:
	CCollider_Page();
	virtual ~CCollider_Page();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COLLIDER_PAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
