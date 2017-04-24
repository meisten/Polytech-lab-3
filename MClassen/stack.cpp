#include "stdafx.h"
#include "stack.h"

int list::stack::Push(const int &num) {
	int length = CList::Len();
	if (!CList::Insert(num, length))
		return 0;
	return 1;
}

int list::stack::Pop(void) {
	try{
		if(this->ioList->next != nullptr){
			int length = CList::Len();
			auto CopyList = this->ioList;
			auto ReturnItem = new Pointer;

			int i(0);
			while (i < length - 2) {
				CopyList = CopyList->next;
				i++;
			}
	
			ReturnItem = CopyList->next;
			CList::Delete(length - 1);

			return ReturnItem->item;
		}
		
		throw "# Traceback (STACK-POP): The list is empty";

	}
	catch (char* exception) {
		std::cout << exception << std::endl;
		return 0;
	}
}