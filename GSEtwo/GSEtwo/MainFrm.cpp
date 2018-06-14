// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// ("Fluent UI")，该示例仅作为参考资料提供， 
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://msdn.microsoft.com/officeui。
//
// 版权所有 (C) Microsoft Corporation
// 保留所有权利。

// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "GSEtwo.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_OFF_2007_AQUA, &CMainFrame::OnApplicationLook)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_OFF_2007_AQUA, &CMainFrame::OnUpdateApplicationLook)
	ON_COMMAND_RANGE(ID_SYSTEM_LOGOUT, ID_SYSTEM_EXIT, &CMainFrame::OnSystemCommandRange)
END_MESSAGE_MAP()

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
	theApp.m_nAppLook = theApp.GetInt(_T("ApplicationLook"), ID_VIEW_APPLOOK_OFF_2003);
	m_GsetwoView = NULL;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	BOOL bNameValid;
	// 基于持久值设置视觉管理器和样式
	OnApplicationLook(theApp.m_nAppLook);

	m_wndRibbonBar.Create(this);
	InitializeRibbon();

	// 启用 Visual Studio 2005 样式停靠窗口行为
	CDockingManager::SetDockingMode(DT_SMART);
	// 启用 Visual Studio 2005 样式停靠窗口自动隐藏行为
	EnableAutoHidePanes(CBRS_ALIGN_ANY);
	m_GsetwoView = (CGSEtwoView *)this->GetActiveView();
	//
	InitializeNavigationBar();
	InitializeStatusBar();
	InitializeOutputPane();
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	//cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
	//	 | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);   // 获得工作区大小 

	cs.cx = rect.right - rect.left;
	cs.cy = rect.bottom - rect.top;

	cs.style |= WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	cs.style &= ~(LONG)FWS_ADDTOTITLE;

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.dwExStyle |= WS_EX_CONTROLPARENT;
	return TRUE;
}

void CMainFrame::InitializeRibbon()
{
	BOOL bNameValid;

	CString strTemp;
	bNameValid = strTemp.LoadString(IDS_RIBBON_FILE);
	ASSERT(bNameValid);

	// 加载面板图像:
	m_PanelImages.SetImageSize(CSize(16, 16));
	m_PanelImages.Load(IDB_BUTTONS);
	// 初始主按钮:
	m_MainButton.SetImage(IDB_MAIN);
	m_MainButton.SetText(_T("\nf"));
	m_MainButton.SetToolTipText(strTemp);

	m_wndRibbonBar.SetApplicationButton(&m_MainButton, CSize (45, 45));

	CMFCRibbonMainPanel* pMainPanel = m_wndRibbonBar.AddMainCategory(_T("客户端面板"), IDB_MAINBUTTON_SMALL, IDB_MAINBUTTON_LARGE);
	pMainPanel->Add(new CMFCRibbonButton(ID_SYSTEM_LOGOUT, _T("注销"), 1, 1));
	pMainPanel->Add(new CMFCRibbonSeparator(TRUE));
	pMainPanel->Add(new CMFCRibbonButton(ID_SYSTEM_CONFIG, _T("系统配置"), 2, 2));
	pMainPanel->Add(new CMFCRibbonButton(ID_SYSTEM_SHOWCFG, _T("显示配置"), 3, 3));
	pMainPanel->Add(new CMFCRibbonButton(ID_SYSTEM_REFRESH, _T("重载数据"), 4, 4));
	pMainPanel->Add(new CMFCRibbonButton(ID_SYSTEM_ABOUT, _T("关于客户端"), 5, 5));
	pMainPanel->Add(new CMFCRibbonSeparator(TRUE));
	pMainPanel->Add(new CMFCRibbonButton(ID_SYSTEM_EXIT, _T("退出"), 6, 6));

	CMFCRibbonCategory* pCategoryMap = m_wndRibbonBar.AddCategory(_T("机场状态监控"), IDB_AIRMAP_SMALL, IDB_AIRMAP_LARGE);

	CMFCRibbonPanel* pPanelSys = pCategoryMap->AddPanel(_T("系统设置"));
	CMFCRibbonButton* pBtn = new CMFCRibbonButton(ID_SYSTEM_CONFIG, _T("系统设置"), 0,0);
	pPanelSys->Add(pBtn);
	pBtn = new CMFCRibbonButton(ID_SYSTEM_REFRESH, _T("重载数据"), 2, 2);
	pBtn->SetToolTipText(_T("重新加载客户端所有数据"));
	pPanelSys->Add(pBtn);
	//视图显示
	CMFCRibbonPanel* pPanelview = pCategoryMap->AddPanel(_T("视图显示"));
	CMFCRibbonCheckBox* pCheck = NULL;
	pCheck = new CMFCRibbonCheckBox(ID_VIEW_DEVICELIST, _T("显示设备栏"));
	pCheck->SetToolTipText(_T("显示/隐藏设备栏"));
	pPanelview->Add(pCheck);
	pCheck = new CMFCRibbonCheckBox(ID_VIEW_ALARMLIST, _T("显示消息栏"));
	pCheck->SetToolTipText(_T("显示/隐藏消息栏"));
	pPanelview->Add(pCheck);
	//
	pPanelview->Add(new CMFCRibbonSeparator(TRUE));
	pCheck = new CMFCRibbonCheckBox(ID_VIEW_CAPTIONBAR, _T("显示提示栏"));
	pCheck->SetToolTipText(_T("显示/隐藏提示栏"));
	pPanelview->Add(pCheck);
	pCheck = new CMFCRibbonCheckBox(ID_VIEW_STATUSBAR, _T("显示状态栏"));
	pCheck->SetToolTipText(_T("显示/隐藏状态栏"));
	pPanelview->Add(pCheck);
	pPanelview->SetCenterColumnVert(TRUE);

	//服务进程监控
	CMFCRibbonCategory* pCategoryDisp = m_wndRibbonBar.AddCategory(_T("服务进程监控"), IDB_AIRMAP_SMALL, IDB_AIRMAP_LARGE);
	pPanelSys = pCategoryDisp->AddPanel(_T("系统设置"));
	pBtn = new CMFCRibbonButton(ID_SYSTEM_CONFIG, _T("系统设置"), 0,0);
	pPanelSys->Add(pBtn);
	pBtn = new CMFCRibbonButton(ID_SYSTEM_REFRESH, _T("重载数据"), 2, 2);
	pBtn->SetToolTipText(_T("重新加载客户端所有数据"));
	pPanelSys->Add(pBtn);

	m_wndRibbonBar.AddToTabs(new CMFCRibbonButton(ID_APP_ABOUT, _T("\na"), m_PanelImages.ExtractIcon (0)));
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnApplicationLook(UINT id)
{
	CWaitCursor wait;

	theApp.m_nAppLook = id;

	switch (theApp.m_nAppLook)
	{
	case ID_VIEW_APPLOOK_WIN_2000:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManager));
		break;

	case ID_VIEW_APPLOOK_OFF_XP:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOfficeXP));
		break;

	case ID_VIEW_APPLOOK_WIN_XP:
		CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
		break;

	case ID_VIEW_APPLOOK_OFF_2003:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2003));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_VS_2005:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	default:
		switch (theApp.m_nAppLook)
		{
		case ID_VIEW_APPLOOK_OFF_2007_BLUE:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_BLACK:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_SILVER:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_AQUA:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Aqua);
			break;
		}

		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
		CDockingManager::SetDockingMode(DT_SMART);
	}

	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

	theApp.WriteInt(_T("ApplicationLook"), theApp.m_nAppLook);
}

void CMainFrame::OnUpdateApplicationLook(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(theApp.m_nAppLook == pCmdUI->m_nID);
}


void CMainFrame::InitializeNavigationBar()
{
	DWORD nStyle = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI;
	if (!m_DeviceTreePane.Create(_T("机位列表"), this, CRect(0, 0, 250, 3200), TRUE, ID_VIEW_DEVICELIST_PANE, nStyle))
	return;
	m_DeviceTreePane.EnableDocking(CBRS_ALIGN_LEFT);
	DockPane(&m_DeviceTreePane);
}

void CMainFrame::InitializeStatusBar()
{
	if (!m_wndStatusBar.Create(this))
	return;

	CString strMessage = _T("FFFFFFFFFFFFFFFFFFFFFFFFFFF, 你好");
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANEL_01, strMessage, TRUE), _T("服务器状态"));
	
}

void CMainFrame::InitializeOutputPane()
{
	if (!m_OutputPane.Create(_T("信息显示"), this, CRect(0, 0, 100, 170), TRUE, ID_VIEW_OUTPUTWND, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_BOTTOM | CBRS_FLOAT_MULTI))
	return;
	m_OutputPane.EnableDocking(CBRS_ALIGN_BOTTOM);
	DockPane(&m_OutputPane);
}

void CMainFrame::OnSystemCommandRange(UINT nID)
{
	switch (nID)
	{
	case ID_SYSTEM_LOGOUT:
		{
			TRACE(_T("you press logout button.\n"));
			break;
		}
	case ID_SYSTEM_CONFIG:
		{
			TRACE(_T("you press config button.\n"));
			break;
		}
	case ID_SYSTEM_SHOWCFG:
		{
			TRACE(_T("you press showconfig button.\n"));
			break;
		}
	case ID_SYSTEM_REFRESH:
		{
			TRACE(_T("you press refresh button.\n"));
			break;
		}
	case ID_SYSTEM_EXIT:
		{
			TRACE(_T("you press exit button.\n"));
			break;
		}
	case ID_SYSTEM_ABOUT:
		{
			TRACE(_T("you press about button.\n"));
		}
	}
}