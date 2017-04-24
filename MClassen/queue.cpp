#include "stdafx.h"
#include "queue.h"

int list::queue::Push(const int &num) {
	int length = CList::Len();

	if (!CList::Insert(num, length))
		return 0;
	return 1;
}

int list::queue::Pop(void) {
	try{
		if(this->ioList->next != nullptr){
			auto CopyList = this->ioList->next;
			auto ReturnItem = new Pointer;

			ReturnItem = CopyList;
			CList::Delete(0);

			return ReturnItem->item;
		}

		throw "# Traceback (STACK-POP): The list is empty";

	}
	catch (char* exception) {
		std::cout << exception << std::endl;
		return 0;
	}
}