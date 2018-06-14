#include "StdAfx.h"
#include "DispatchMngDlg.h"

IMPLEMENT_DYNAMIC(CDispatchMngDlg, CDialogEx)

CDispatchMngDlg::CDispatchMngDlg(CWnd * pParent)
:CDialogEx(IDD_AIRMAP_DLG, pParent)
{
	m_pFrameWnd = NULL;
	m_pOperListView = NULL;
	m_pDsptPlanView = NULL;
}

CDispatchMngDlg::~CDispatchMngDlg(void)
{
}

void CDispatchMngDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDispatchMngDlg, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	ON_WM_SIZE()
END_MESSAGE_MAP()

BOOL CDispatchMngDlg::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

BOOL CDispatchMngDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CCreateContext pContext;
	pContext.m_pNewViewClass      = NULL;//RUNTIME_CLASS(CMyTreeView);
	pContext.m_pCurrentDoc        = NULL;
	pContext.m_pNewDocTemplate    = NULL;
	pContext.m_pLastView          = NULL;
	pContext.m_pCurrentFrame      = NULL;

	m_pFrameWnd = new CFrameWnd;
	m_pFrameWnd->Create(AfxRegisterWndClass(CS_VREDRAW | CS_HREDRAW), _T(""), WS_CHILD|WS_VISIBLE, CRect(0,0,1,1), this);
	if(!m_wndSpliterWnd.CreateStatic(m_pFrameWnd, 1, 2))
		return FALSE;
	if(!m_wndSpliterWnd.CreateView(0, 0, RUNTIME_CLASS(CDispatchPlanView), CSize(0, 0), &pContext))
		return FALSE;
	if(!m_wndSpliterWnd.CreateView(0, 1, RUNTIME_CLASS(COperatorListView), CSize(0, 0), &pContext))
		return FALSE;

	m_pDsptPlanView = (CDispatchPlanView*)m_wndSpliterWnd.GetPane(0,0);
	m_pOperListView = (COperatorListView*)m_wndSpliterWnd.GetPane(0,1);
	return TRUE;
}

void CDispatchMngDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	if (m_pFrameWnd && m_pFrameWnd->GetSafeHwnd())
	{
		m_pFrameWnd->DestroyWindow();
	}
}

void CDispatchMngDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	if (m_pFrameWnd && m_pFrameWnd->GetSafeHwnd())
	{
		m_pFrameWnd->MoveWindow(0,0,cx,cy);
	}
	if (m_wndSpliterWnd.GetSafeHwnd())
	{
		m_wndSpliterWnd.MoveWindow(0,0,cx,cy);
		if (cx - 510 < 0)
			return;
		m_wndSpliterWnd.SetColumnInfo(0, cx-500, 10);
		m_wndSpliterWnd.RecalcLayout();
	}
}