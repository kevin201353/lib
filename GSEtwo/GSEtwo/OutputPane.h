#pragma once
#include "afxdockablepane.h"
#include "OutputBridgeEventDlg.h"

class COutputPane :
	public CDockablePane
{
	DECLARE_DYNAMIC(COutputPane)
public:
	COutputPane(void);
	~COutputPane(void);
protected:
	//here msg map
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()

protected:
	COutputBridgeEventDlg  m_OutputBridgeEventDlg;
	CMFCTabCtrl		m_wndTabControl;
};
