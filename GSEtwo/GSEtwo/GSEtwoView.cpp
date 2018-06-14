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

// GSEtwoView.cpp : CGSEtwoView 类的实现
//

#include "stdafx.h"
#include "GSEtwo.h"

#include "GSEtwoDoc.h"
#include "GSEtwoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGSEtwoView

IMPLEMENT_DYNCREATE(CGSEtwoView, CView)

BEGIN_MESSAGE_MAP(CGSEtwoView, CView)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CGSEtwoView 构造/析构

CGSEtwoView::CGSEtwoView()
{
	// TODO: 在此处添加构造代码

}

CGSEtwoView::~CGSEtwoView()
{
}

BOOL CGSEtwoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	
	return CView::PreCreateWindow(cs);
}

// CGSEtwoView 绘制

void CGSEtwoView::OnDraw(CDC* /*pDC*/)
{
	CGSEtwoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CGSEtwoView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGSEtwoView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CGSEtwoView 诊断

#ifdef _DEBUG
void CGSEtwoView::AssertValid() const
{
	CView::AssertValid();
}

void CGSEtwoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGSEtwoDoc* CGSEtwoView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGSEtwoDoc)));
	return (CGSEtwoDoc*)m_pDocument;
}
#endif //_DEBUG


// CGSEtwoView 消息处理程序
void CGSEtwoView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	TRACE(_T("CGSEtwoView::OnSize------cx=%d, cy=%d.\n"), cx, cy);
	if (m_AirMapDlg.GetSafeHwnd())
	{
		m_AirMapDlg.MoveWindow(0,0,cx,cy);
		m_AirMapDlg.ShowWindow(SW_HIDE);
	}
	if (m_DispathMngDlg.GetSafeHwnd())
	{
		m_DispathMngDlg.MoveWindow(0,0,cx,cy);
		m_DispathMngDlg.ShowWindow(SW_SHOW);
	}
}


int CGSEtwoView::OnCreate(LPCREATESTRUCT lpcs)
{
	if (CView::OnCreate(lpcs) == -1)
		return -1;
	m_AirMapDlg.Create(IDD_AIRMAP_DLG, this);
	m_DispathMngDlg.Create(IDD_AIRMAP_DLG, this);
	return 0;
}