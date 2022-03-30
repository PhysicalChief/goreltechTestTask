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

void treeElement::setName(CString name)
{
	nameElement = name;
}

int treeElement::getId()
{
	return idElement;
}

void treeElement::setInfo(CString info) {
	aboutElement = info;
}

CString treeElement::getInfo()
{
	return aboutElement;
}

int treeElement::getPid()
{
	return parentIdElement;
}
