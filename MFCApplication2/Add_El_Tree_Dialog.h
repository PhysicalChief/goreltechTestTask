#pragma once
#include "afxdialogex.h"


// Диалоговое окно Add_El_Tree_Dialog

class Add_El_Tree_Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(Add_El_Tree_Dialog)

public:
	Add_El_Tree_Dialog(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~Add_El_Tree_Dialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGBAR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	int idNew;
	CString captionNew;
	CString infoNew;
	int pidNew;
	afx_msg void OnBnClickedCancelbutton();
	afx_msg void OnBnClickedOkbutton();
	CEdit idCtrl;
	CEdit pidCtrl;
};
