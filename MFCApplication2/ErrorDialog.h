#pragma once
#include "afxdialogex.h"


// Диалоговое окно ErrorDialog

class ErrorDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ErrorDialog)

public:
	ErrorDialog(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~ErrorDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString errorMessage;
};
