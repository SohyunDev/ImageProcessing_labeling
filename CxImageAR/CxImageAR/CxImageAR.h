
// CxImageAR.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCxImageARApp:
// �� Ŭ������ ������ ���ؼ��� CxImageAR.cpp�� �����Ͻʽÿ�.
//

class CCxImageARApp : public CWinApp
{
public:
	CCxImageARApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCxImageARApp theApp;