#pragma once
#include "outputbasedlg.h"

class COutputBridgeEventDlg :
	public COutputBaseDlg
{
	DECLARE_DYNAMIC(COutputBridgeEventDlg)

public:
	COutputBridgeEventDlg(void);
	~COutputBridgeEventDlg(void);
protected:
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
};
