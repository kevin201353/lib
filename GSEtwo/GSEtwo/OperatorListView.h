#pragma once
#include "afxwin.h"

class COperatorListView :
	public CView
{
	DECLARE_DYNCREATE(COperatorListView)
public:
	COperatorListView(void);
	virtual ~COperatorListView(void);
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpcs);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnDraw(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};
