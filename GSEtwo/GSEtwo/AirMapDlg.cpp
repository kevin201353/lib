// AirMapDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GSEtwo.h"
#include "AirMapDlg.h"


// CAirMapDlg dialog

IMPLEMENT_DYNAMIC(CAirMapDlg, CDialog)

CAirMapDlg::CAirMapDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAirMapDlg::IDD, pParent)
{

}

CAirMapDlg::~CAirMapDlg()
{
}

void CAirMapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAirMapDlg, CDialog)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CAirMapDlg message handlers

BOOL CAirMapDlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rc;
	GetClientRect(&rc);
	/*
	CBrush brush;
	brush.CreateSolidBrush(RGB(255,255,255));
	CBrush *pOldBrush = pDC->SelectObject(&brush);
	pDC->PatBlt(rc.left, rc.top, rc.Width(),rc.Height(),PATCOPY);
	pDC->SelectObject(pOldBrush);
	brush.DeleteObject();
	*/

	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	MemDC.SelectObject(&bmp);
	MemDC.FillSolidRect(&rc, pDC->GetBkColor());

	Image img(_T("../Debug/AirPort.jpg"));
	Graphics  grap(MemDC.GetSafeHdc());
	grap.SetInterpolationMode(InterpolationModeHighQualityBicubic); 
	grap.DrawImage(&img, Rect(0, 0, rc.Width(), rc.Height()), 0, 0, img.GetWidth(), img.GetHeight(), UnitPixel);
	pDC->BitBlt(0, 0, rc.Width(), rc.Height(), &MemDC, 0, 0, SRCCOPY);
	MemDC.DeleteDC();
	bmp.DeleteObject();
	
	return TRUE;
}