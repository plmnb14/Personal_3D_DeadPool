#pragma once


// CAnimator_Page ��ȭ �����Դϴ�.

class CAnimator_Page : public CPropertyPage
{
	DECLARE_DYNAMIC(CAnimator_Page)

public:
	CAnimator_Page();
	virtual ~CAnimator_Page();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANIMATOR_PAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
