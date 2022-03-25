#pragma once
#include "afxdialogex.h"


// Диалоговое окно newelement

class newelement : public CDialogEx
{
	DECLARE_DYNAMIC(newelement)

public:
	newelement(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~newelement();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGBAR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
