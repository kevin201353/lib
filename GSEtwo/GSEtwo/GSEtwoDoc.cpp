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

// GSEtwoDoc.cpp : CGSEtwoDoc ���ʵ��
//

#include "stdafx.h"
#include "GSEtwo.h"

#include "GSEtwoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGSEtwoDoc

IMPLEMENT_DYNCREATE(CGSEtwoDoc, CDocument)

BEGIN_MESSAGE_MAP(CGSEtwoDoc, CDocument)
END_MESSAGE_MAP()


// CGSEtwoDoc ����/����

CGSEtwoDoc::CGSEtwoDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CGSEtwoDoc::~CGSEtwoDoc()
{
}

BOOL CGSEtwoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CGSEtwoDoc ���л�

void CGSEtwoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CGSEtwoDoc ���

#ifdef _DEBUG
void CGSEtwoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGSEtwoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGSEtwoDoc ����
