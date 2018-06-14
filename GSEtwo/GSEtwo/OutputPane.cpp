#include "StdAfx.h"
#include "OutputPane.h"
#include "Resource.h"

IMPLEMENT_DYNAMIC(COutputPane, CDockablePane)

BEGIN_MESSAGE_MAP(COutputPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

COutputPane::COutputPane(void)
{
}

COutputPane::~COutputPane(void)
{
}

int COutputPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;
	CRect rectClient;
	GetClientRect(&rectClient);
	m_wndTabControl.Create(CMFCTabCtrl::STYLE_3D_ONENOTE, rectClient, this, ID_VIEW_OUTPUT_TABCTRL, CMFCTabCtrl::LOCATION_BOTTOM);
	m_wndTabControl.EnableTabSwap(FALSE);
	m_OutputBridgeEventDlg.Create(IDD_DIALOG_OUTPUT, &m_wndTabControl);
	m_wndTabControl.AddTab(&m_OutputBridgeEventDlg, _T("µÇ»úÇÅÏûÏ¢"));
	m_wndTabControl.SetActiveTab(0);
	return 0;
}

void COutputPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	if (m_wndTabControl.GetSafeHwnd()) {
		m_wndTabControl.MoveWindow(0, 0, cx, cy);
	}
}