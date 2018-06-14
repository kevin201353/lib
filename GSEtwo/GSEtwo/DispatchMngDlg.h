#pragma once
#include "afxdialogex.h"
#include "resource.h"

#include "OperatorListView.h"
#include "DispatchPlanView.h"

class CDispatchMngDlg :
	public CDialogEx
{
	DECLARE_DYNAMIC(CDispatchMngDlg);
public:
	CDispatchMngDlg(CWnd * pParent= NULL);
	virtual ~CDispatchMngDlg(void);

	enum { IDD = IDD_AIRMAP_DLG };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
protected:
	CFrameWnd*			m_pFrameWnd;
	CSplitterWnd		m_wndSpliterWnd;
	COperatorListView*   m_pOperListView;
	CDispatchPlanView*   m_pDsptPlanView;
};
