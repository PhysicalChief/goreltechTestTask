// ErrorDialog.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplication2.h"
#include "afxdialogex.h"
#include "ErrorDialog.h"


// Диалоговое окно ErrorDialog

IMPLEMENT_DYNAMIC(ErrorDialog, CDialogEx)

ErrorDialog::ErrorDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, errorMessage(_T(""))
{

}

ErrorDialog::~ErrorDialog()
{
}

void ErrorDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, errorMessage);
}


BEGIN_MESSAGE_MAP(ErrorDialog, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений ErrorDialog
