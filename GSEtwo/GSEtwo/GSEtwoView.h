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

// GSEtwoView.h : CGSEtwoView ��Ľӿ�
//


#pragma once
#include "AirMapDlg.h"
#include "DispatchMngDlg.h"

class CGSEtwoView : public CView
{
protected: // �������л�����
	CGSEtwoView();
	DECLARE_DYNCREATE(CGSEtwoView)

// ����
public:
	CGSEtwoDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CGSEtwoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpcs);
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()

protected:
	CAirMapDlg   m_AirMapDlg;
	CDispatchMngDlg  m_DispathMngDlg;
};

#ifndef _DEBUG  // GSEtwoView.cpp �еĵ��԰汾
inline CGSEtwoDoc* CGSEtwoView::GetDocument() const
   { return reinterpret_cast<CGSEtwoDoc*>(m_pDocument); }
#endif

