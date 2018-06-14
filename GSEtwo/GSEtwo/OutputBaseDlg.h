#pragma once

#include "resource.h"
// COutputBaseDlg dialog

class COutputBaseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COutputBaseDlg)

public:
	COutputBaseDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~COutputBaseDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_OUTPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
};
