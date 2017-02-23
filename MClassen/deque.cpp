#include "deque.h"

int list::deque::Push(const int &num) {
	int length = clist::Len();
	if (clist::Insert(num, length) == 0) {
		return 0;
	}
}

int list::deque::PushFront(const int &num) {
	clist::Insert(num, 0);
	return 0;
}

int list::deque::PopFront(void) {
	try{
		if (this->CList != NULL) {
			Pointer* CopyList = this->CList;
			Pointer* ReturnItem = new Pointer;

			ReturnItem = CopyList;
			clist::Delete(0);

			return ReturnItem->item;
		}
		else
			throw "# Traceback (QUEUE-POPFRONT): The list is empty";
		}
		catch (char* exception) {
			std::cout << exception << std::endl;
			return NULL;
		}
}

int list::deque::Pop(void) {
	try {
		if (this->CList != NULL) {
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
		else
			throw "# Traceback (QUEUE-POPBACK): The list is empty";
	}
	catch (char* exception) {
		std::cout << exception << std::endl;
		return NULL;
	}
}