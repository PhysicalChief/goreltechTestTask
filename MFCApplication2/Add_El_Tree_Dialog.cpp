// Add_El_Tree_Dialog.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplication2.h"
#include "afxdialogex.h"
#include "Add_El_Tree_Dialog.h"


// Диалоговое окно Add_El_Tree_Dialog

IMPLEMENT_DYNAMIC(Add_El_Tree_Dialog, CDialogEx)

Add_El_Tree_Dialog::Add_El_Tree_Dialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGBAR, pParent)
	, idNew(0)
	, captionNew(_T(""))
	, infoNew(_T(""))
	, pidNew(-1)
{

}

Add_El_Tree_Dialog::~Add_El_Tree_Dialog()
{
}

void Add_El_Tree_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, idNew);
	DDX_Text(pDX, IDC_EDIT2, captionNew);
	DDX_Text(pDX, IDC_EDIT3, infoNew);
	DDX_Text(pDX, IDC_EDIT4, pidNew);
	DDX_Control(pDX, IDC_EDIT1, idCtrl);
	DDX_Control(pDX, IDC_EDIT4, pidCtrl);
}


BEGIN_MESSAGE_MAP(Add_El_Tree_Dialog, CDialogEx)
	ON_BN_CLICKED(IDC_CANCELBUTTON, &Add_El_Tree_Dialog::OnBnClickedCancelbutton)
	ON_BN_CLICKED(IDC_OKBUTTON, &Add_El_Tree_Dialog::OnBnClickedOkbutton)
END_MESSAGE_MAP()


// Обработчики сообщений Add_El_Tree_Dialog


void Add_El_Tree_Dialog::OnBnClickedCancelbutton()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnCancel();
}


void Add_El_Tree_Dialog::OnBnClickedOkbutton()
{
	UpdateData();
	CDialogEx::EndDialog(901);
	// TODO: добавьте свой код обработчика уведомлений
}
