#pragma once
#include "queue.h"

int list::queue::Push(const int &num) {
	int length = clist::Len();

	if (clist::Insert(num, length) == 0)
		return 0;
	else
		return 1;
}

int list::queue::Pop(void) {
	try{
		if(this->CList != NULL){
			Pointer* CopyList = this->CList;
			Pointer* ReturnItem = new Pointer;

			ReturnItem = CopyList;
			clist::Delete(0);

			return ReturnItem->item;
		}
		else
			throw "# Traceback (STACK-POP): The list is empty";
		}
	catch (char* exception) {
		std::cout << exception << std::endl;
		return NULL;
	}
}