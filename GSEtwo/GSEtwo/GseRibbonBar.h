#pragma once
#include "afxribbonbar.h"

class CGseRibbonBar :
	public CMFCRibbonBar
{
	DECLARE_DYNAMIC(CGseRibbonBar)
public:
	CGseRibbonBar(void);
	~CGseRibbonBar(void);

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP( )
protected:
	virtual BOOL SetActiveCategory(CMFCRibbonCategory* pCategory, BOOL bForceRestore = FALSE);
};
