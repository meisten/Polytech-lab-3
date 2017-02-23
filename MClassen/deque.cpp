#pragma once
#include "deque.h"

int deque::Push(const int &num) {
	int length = clist::Len();
	if (clist::Insert(num, length) == 0) {
		return 0;
	}
}

int deque::PushFront(const int &num) {
	clist::Insert(num, 0);

	return 0;
}

int deque::PopFront(void) {
	Pointer* CopyList = this->CList;
	Pointer* ReturnItem = new Pointer;

	ReturnItem = CopyList;
	clist::Delete(0);

	return ReturnItem->item;
}

int deque::Pop(void) {
	int length = clist::Len();
	Pointer* CopyList = this->CList;
	Pointer* ReturnItem = new Pointer;

	int i(0);
	while (i < length - 2) {
		CopyList = CopyList->next;
		i++;
	}

	ReturnItem = CopyList->next;
	clist::Delete(length - 1);

	return ReturnItem->item;
}