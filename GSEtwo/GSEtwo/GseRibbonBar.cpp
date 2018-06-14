#include "StdAfx.h"
#include "GseRibbonBar.h"
#include "GSEtwo.h"

IMPLEMENT_DYNAMIC(CGseRibbonBar, CMFCRibbonBar)
BEGIN_MESSAGE_MAP(CGseRibbonBar, CMFCRibbonBar)
	ON_WM_CREATE()
END_MESSAGE_MAP()
CGseRibbonBar::CGseRibbonBar(void)
{
}

CGseRibbonBar::~CGseRibbonBar(void)
{
}

int CGseRibbonBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMFCRibbonBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}

BOOL CGseRibbonBar::SetActiveCategory(CMFCRibbonCategory* pCategory, BOOL bForceRestore)
{
	CMFCRibbonBar::SetActiveCategory(pCategory, bForceRestore);
	if (theApp.m_pMainWnd && theApp.m_pMainWnd->GetSafeHwnd())
	{
		int nIndex = 0;
		if (wcscmp(pCategory->GetName(), GSE_PAGE_TILE1) == 0) {
			nIndex = 0;
		}
		else if (wcscmp(pCategory->GetName(), GSE_PAGE_TILE2) == 0) {
			nIndex = 1;
		}
		theApp.m_pMainWnd->SendMessage(MSG_RIBBONBAR_CATEGORY_CHANGED, (WPARAM)nIndex, NULL);
	}
	return TRUE;
}

