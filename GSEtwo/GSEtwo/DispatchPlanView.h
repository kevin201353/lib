#pragma once
#include "afxwin.h"

class CDispatchPlanView :
	public CView
{
	DECLARE_DYNCREATE(CDispatchPlanView)
public:
	CDispatchPlanView(void);
	virtual ~CDispatchPlanView(void);
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpcs);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnDraw(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};
