#include "StdAfx.h"
#include "DeviceTreePane.h"
#include "Resource.h"

IMPLEMENT_DYNAMIC(CDeviceTreePane, CDockablePane)

BEGIN_MESSAGE_MAP(CDeviceTreePane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()
CDeviceTreePane::CDeviceTreePane(void)
{
}

CDeviceTreePane::~CDeviceTreePane(void)
{
}

int CDeviceTreePane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;
	CRect rc;
	GetClientRect(&rc);
	DWORD dwStyle = TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT | TVS_DISABLEDRAGDROP | TVS_SHOWSELALWAYS | WS_BORDER | WS_HSCROLL | WS_TABSTOP;
	m_DeviceTreeCtrl.Create(WS_CHILD | WS_VISIBLE | dwStyle, rc, this, ID_VIEW_DEVICE_TREECTRL);

	/** 树列表图标初始化 */
	CBitmap bmpFaces;
	bmpFaces.LoadBitmap(IDB_BITMAP_DEVICETREEIMAGES);
	m_pImageList.Create(20, 20, ILC_COLOR24 | ILC_MASK, 16, 1);
	m_pImageList.Add(&bmpFaces, RGB(255, 255, 255));
	bmpFaces.Detach();
	bmpFaces.DeleteObject();
	m_DeviceTreeCtrl.SetImageList(&m_pImageList, LVSIL_NORMAL);
	LoadData();
	return 0;
}

void CDeviceTreePane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	if (m_DeviceTreeCtrl.GetSafeHwnd())
	{
		m_DeviceTreeCtrl.MoveWindow(0,0,cx,cy);
	}
}

void CDeviceTreePane::LoadData()
{
	//insert node
	HTREEITEM hRoot, hsub, hsub1;
	hRoot = m_DeviceTreeCtrl.InsertItem(_T("我的电脑"));
	hsub = m_DeviceTreeCtrl.InsertItem(_T("1"), 0, 0, hRoot );
	hsub1 = m_DeviceTreeCtrl.InsertItem(_T("1_01"), 1, 1, hsub );
}