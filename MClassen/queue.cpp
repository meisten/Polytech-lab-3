#pragma once
#include "queue.h"

int queue::Push(const int &num) {
	int length = clist::Len();

	if (clist::Insert(num, length) == 0)
		return 0;
	else
		return 1;
}

int queue::Pop(void) {
	Pointer* CopyList = this->CList;
	Pointer* ReturnItem = new Pointer;

	ReturnItem = CopyList;
	clist::Delete(0);

	return ReturnItem->item;
}