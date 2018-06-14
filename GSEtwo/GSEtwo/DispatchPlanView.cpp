#include "StdAfx.h"
#include "DispatchPlanView.h"

IMPLEMENT_DYNCREATE(CDispatchPlanView, CView)


BEGIN_MESSAGE_MAP(CDispatchPlanView, CView)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

CDispatchPlanView::CDispatchPlanView(void)
{
}

CDispatchPlanView::~CDispatchPlanView(void)
{
}


int CDispatchPlanView::OnCreate(LPCREATESTRUCT lpcs)
{
	if (CView::OnCreate(lpcs) == -1)
		return -1;
	return 0;
}

void CDispatchPlanView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
}

void CDispatchPlanView::OnDraw(CDC* pDC)
{
	CView::OnDraw(pDC);
}