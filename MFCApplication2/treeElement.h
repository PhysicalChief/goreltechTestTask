#pragma once
#include <CommCtrl.h>
#include <cstring>

class treeElement
{
private:
	int idElement;
	CString nameElement;
	CString aboutElement;
	int parentIdElement;

	HTREEITEM treeCtrlElement;
public:
	treeElement();
	treeElement(int id, CString name, CString about, int parent) : idElement(id), nameElement(name), aboutElement(about), parentIdElement(parent) {
		treeCtrlElement = NULL;
	};
	void SetTreeCtrlElement(HTREEITEM treeCtrlElement);
	HTREEITEM GetTreeCtrlElement();
	CString getName();
	void setName(CString name);
	int getId();
	void setInfo(CString info);
	CString getInfo();
	int getPid();
};

