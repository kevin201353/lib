#include "StdAfx.h"
#include "OperatorListView.h"

IMPLEMENT_DYNCREATE(COperatorListView, CView)

BEGIN_MESSAGE_MAP(COperatorListView, CView)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

COperatorListView::COperatorListView(void)
{
}

COperatorListView::~COperatorListView(void)
{
}

int COperatorListView::OnCreate(LPCREATESTRUCT lpcs)
{
	if (CView::OnCreate(lpcs) == -1)
		return -1;
	return 0;
}

void COperatorListView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType,cx,cy);
}

void COperatorListView::OnDraw(CDC* pDC)
{
	CView::OnDraw(pDC);
}