
// cg2020SZTDrawLine.h: cg2020SZTDrawLine 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// Ccg2020SZTDrawLineApp:
// 有关此类的实现，请参阅 cg2020SZTDrawLine.cpp
//

class Ccg2020SZTDrawLineApp : public CWinApp
{
public:
	Ccg2020SZTDrawLineApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ccg2020SZTDrawLineApp theApp;
