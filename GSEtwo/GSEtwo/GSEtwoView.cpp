// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// ("Fluent UI")����ʾ������Ϊ�ο������ṩ�� 
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ���� (C) Microsoft Corporation
// ��������Ȩ����

// GSEtwoView.cpp : CGSEtwoView ���ʵ��
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

// CGSEtwoView ����/����

CGSEtwoView::CGSEtwoView()
{
	// TODO: �ڴ˴���ӹ������

}

CGSEtwoView::~CGSEtwoView()
{
}

BOOL CGSEtwoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	
	return CView::PreCreateWindow(cs);
}

// CGSEtwoView ����

void CGSEtwoView::OnDraw(CDC* /*pDC*/)
{
	CGSEtwoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


// CGSEtwoView ���

#ifdef _DEBUG
void CGSEtwoView::AssertValid() const
{
	CView::AssertValid();
}

void CGSEtwoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGSEtwoDoc* CGSEtwoView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGSEtwoDoc)));
	return (CGSEtwoDoc*)m_pDocument;
}
#endif //_DEBUG


// CGSEtwoView ��Ϣ�������
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