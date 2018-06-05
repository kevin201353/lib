/************************************************/
/*lib
/*author:kevin
/*date:2018/6/05
/*discription: 字符串编码字符集转换
/************************************************/
#ifndef __LIB_STRING_CONVERT
#define __LIB_STRING_CONVERT

static int ascii_to_unicode(char *szSour, wchar_t *wszDst, int size)
{
	int nMinSize = 0;
	nMinSize = MultiByteToWideChar (CP_ACP, 0, szSour, -1, NULL, 0);
	if (size < nMinSize)
		return -1;
	MultiByteToWideChar(CP_ACP, 0, szSour, -1, wszDst, nMinSize);
	return 0;
}

static int unicode_to_ascii(wchar_t *wszSour, char *szDst, int size)
{
	int nMinSize = 0;
	nMinSize = WideCharToMultiByte(CP_OEMCP, NULL, wszSour, -1, NULL, 0, NULL, FALSE);
	if (size < nMinSize)
		return -1;
	WideCharToMultiByte(CP_OEMCP, NULL, wszSour, -1, szDst, size, NULL, FALSE);
	return 0;
}
#endif