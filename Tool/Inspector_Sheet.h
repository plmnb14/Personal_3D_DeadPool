#pragma once



// CInspector_Sheet

#include "Inspector_Page.h"
#include "Animator_Page.h"
#include "Collider_Page.h"

class CInspector_Sheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CInspector_Sheet)

public:
	CInspector_Sheet(CWnd* pParentWnd = NULL);
	//CInspector_Sheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	//CInspector_Sheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CInspector_Sheet();

protected:
	DECLARE_MESSAGE_MAP()

public:
	CInspector_Page		m_Page_Inspector;
	CAnimator_Page		m_Page_Animator;
	CCollider_Page		m_Page_Collider;
};


