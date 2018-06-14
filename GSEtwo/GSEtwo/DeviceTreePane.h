#pragma once
#include "afxdockablepane.h"

class CDeviceTreePane :
	public CDockablePane
{
	DECLARE_DYNAMIC(CDeviceTreePane)
public:
	CDeviceTreePane(void);
	~CDeviceTreePane(void);
protected:
	//here msg map
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
protected:
	void LoadData();
	CTreeCtrl m_DeviceTreeCtrl;
	CImageList m_pImageList;
};
