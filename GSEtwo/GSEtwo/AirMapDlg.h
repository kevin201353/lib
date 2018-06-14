#pragma once


// CAirMapDlg dialog

class CAirMapDlg : public CDialog
{
	DECLARE_DYNAMIC(CAirMapDlg)

public:
	CAirMapDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAirMapDlg();

// Dialog Data
	enum { IDD = IDD_AIRMAP_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};
