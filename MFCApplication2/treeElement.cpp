#include "pch.h"
#include "treeElement.h"


treeElement::treeElement()
{
}

void treeElement::SetTreeCtrlElement(HTREEITEM element) {
	treeCtrlElement = element;
}

HTREEITEM treeElement::GetTreeCtrlElement() {
	return treeCtrlElement;
}

CString treeElement::getName() {
	return nameElement;
}
