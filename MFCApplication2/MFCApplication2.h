
// MFCApplication2.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCApplication2App:
// Сведения о реализации этого класса: MFCApplication2.cpp
//

class CMFCApplication2App : public CWinApp
{
public:
	CMFCApplication2App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication2App theApp;
