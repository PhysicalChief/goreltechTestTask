
// MFCApplication2Dlg.cpp: файл реализации
//

#pragma once
#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include "Add_El_Tree_Dialog.h"
#include "treeElement.h"
#include "ErrorDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CMFCApplication2Dlg



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_tree);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCApplication2Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDCLEAR, &CMFCApplication2Dlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCApplication2Dlg

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	int id = -1;
	treeElement rootElement(id, CString("root"), CString("root"), id);
	rootElement.SetTreeCtrlElement(TVI_ROOT);

	structTree[id] = rootElement;

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnBnClickedOk()
{
	
	// TODO: добавьте свой код обработчика уведомлений

	Add_El_Tree_Dialog addElementDialog;
	addElementDialog.idNew = getNextID() - 1;
	if (addElementDialog.DoModal() == 901) {
		int id = addElementDialog.idNew;
		CString cap = addElementDialog.captionNew;
		CString info = addElementDialog.infoNew;
		int p = addElementDialog.pidNew;
		treeElement newElement(id, cap, info, p);
		if (id < 0) {
			ErrorDialog error;
			error.errorMessage = L"ID must be more or equal 0";
			error.DoModal();
			return;
		}
		if (p < -1) {
			ErrorDialog error;
			error.errorMessage = L"Parent ID must be more or equal -1";
			error.DoModal();
			return;
		}
		try {
			treeElement parent = structTree.at(p);
		}
		catch (std::out_of_range ex) {
			ErrorDialog error;
			error.errorMessage = L"Don't find parent";
			error.DoModal();
			return;
		}
		try {
			treeElement el = structTree.at(id);
			ErrorDialog error;
			error.errorMessage = L"This id exists";
			error.DoModal();
			return;
		}
		catch (std::out_of_range ex) {
			HTREEITEM tmp = m_tree.InsertItem(newElement.getName(), structTree[p].GetTreeCtrlElement());
			newElement.SetTreeCtrlElement(tmp);
			structTree[id] = newElement;
			//m_tree.UpdateData();
			m_tree.UpdateWindow();
		}
	}

	addElementDialog.DestroyWindow();
}


void CMFCApplication2Dlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}


void CMFCApplication2Dlg::OnBnClickedClear()
{
	// TODO: добавьте свой код обработчика уведомлений
		// TODO: добавьте свой код обработчика уведомлений
	m_tree.DeleteAllItems();
	structTree.clear();
	int id = -1;
	treeElement rootElement(id, CString("root"), CString("root"), id);
	rootElement.SetTreeCtrlElement(TVI_ROOT);
	structTree[id] = rootElement;
}

int CMFCApplication2Dlg::getNextID()
{
	return structTree.size();
}


void CMFCApplication2Dlg::OnBnClickedButton1()
{
	m_tree.DeleteAllItems();
	structTree.clear();
	int id = -1;
	treeElement rootElement(id, CString("root"), CString("root"), id);
	rootElement.SetTreeCtrlElement(TVI_ROOT);
	structTree[id] = rootElement;

	CFileDialog fileDialog(TRUE);
	fileDialog.m_ofn.Flags |= OFN_FILEMUSTEXIST;
	fileDialog.m_ofn.lpstrInitialDir = NULL;
	int result = fileDialog.DoModal();	
	if (result == IDOK)	//если файл выбран
	{
		CStdioFile fileStream;
		CString fileName = fileDialog.m_ofn.lpstrFile;
		fileStream.Open(fileName, CFile::modeRead | CFile::shareExclusive | CFile::typeText);
		CString readStr;
		while (fileStream.ReadString(readStr)) {
			int id, pid;
			CString caption, info;
			
			int n = 0;
			int m = 0;

			n = readStr.Find(';', n);
			CString tmp = readStr.Left(n);
			id = _wtoi(tmp);
			m = n + 1;

			n = readStr.Find(';', n + 1);
			caption = readStr.Mid(m, n - m);
			m = n + 1;

			n = readStr.Find(';', n + 1);
			info = readStr.Mid(m, n - m);
			m = n + 1;

			tmp = readStr.Right(readStr.GetLength() - n - 1);
			pid = _wtoi(tmp);

			treeElement newEl(id, caption, info, pid);

			HTREEITEM tmp1 = m_tree.InsertItem(newEl.getName(), structTree[pid].GetTreeCtrlElement());
			newEl.SetTreeCtrlElement(tmp1);
			structTree[id] = newEl;
		}
		m_tree.UpdateWindow();
		fileStream.Close();
	}
}
