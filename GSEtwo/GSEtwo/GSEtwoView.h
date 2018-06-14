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

// GSEtwoView.h : CGSEtwoView 类的接口
//


#pragma once
#include "AirMapDlg.h"
#include "DispatchMngDlg.h"

class CGSEtwoView : public CView
{
protected: // 仅从序列化创建
	CGSEtwoView();
	DECLARE_DYNCREATE(CGSEtwoView)

// 属性
public:
	CGSEtwoDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CGSEtwoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // GSEtwoView.cpp 中的调试版本
inline CGSEtwoDoc* CGSEtwoView::GetDocument() const
   { return reinterpret_cast<CGSEtwoDoc*>(m_pDocument); }
#endif

