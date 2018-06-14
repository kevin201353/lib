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

// GSEtwo.h : GSEtwo Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CGSEtwoApp:
// �йش����ʵ�֣������ GSEtwo.cpp
//
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")

class CGSEtwoApp : public CWinAppEx
{
public:
	CGSEtwoApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	UINT  m_nAppLook;
	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();
	virtual int ExitInstance();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
protected:
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
};

extern CGSEtwoApp theApp;
