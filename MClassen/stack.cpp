#include "stdafx.h"
#include "stack.h"

int list::stack::Push(const int &num) {
	int length = clist::Len();
	if (!clist::Insert(num, length))
		return 0;
	return 1;
}

int list::stack::Pop(void) {
	try{
		if(this->CList != nullptr){
			int length = clist::Len();
			auto CopyList = this->CList;
			auto ReturnItem = new Pointer;

			int i(0);
			while (i < length - 2) {
				CopyList = CopyList->next;
				i++;
			}
	
			ReturnItem = CopyList->next;
			clist::Delete(length - 1);

			return ReturnItem->item;
		}
		
		throw "# Traceback (STACK-POP): The list is empty";

	}
	catch (char* exception) {
		std::cout << exception << std::endl;
		return 0;
	}
}