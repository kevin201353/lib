// OutputBaseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GSEtwo.h"
#include "OutputBaseDlg.h"


// COutputBaseDlg dialog

IMPLEMENT_DYNAMIC(COutputBaseDlg, CDialogEx)

COutputBaseDlg::COutputBaseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COutputBaseDlg::IDD, pParent)
{

}

COutputBaseDlg::~COutputBaseDlg()
{
}

void COutputBaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COutputBaseDlg, CDialogEx)
END_MESSAGE_MAP()


// COutputBaseDlg message handlers
BOOL COutputBaseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	return TRUE;
}