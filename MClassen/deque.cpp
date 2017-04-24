#include "stdafx.h"
#include "deque.h"

int list::deque::Push(const int &num) {
	int length = CList::Len();
	if (!CList::Insert(num, length))
		return 0;
	return 1;
}

int list::deque::PushFront(const int &num) {
	if (!CList::Insert(num, 0))
		return 0;
	return 1;
}

int list::deque::PopFront(void) {
	try{
		if (this->ioList->next != nullptr) {
			auto CopyList = this->ioList->next;
			auto ReturnItem = new Pointer;

			ReturnItem = CopyList;
			CList::Delete(0);
			return ReturnItem->item;
		}
		else
			throw "# Traceback (QUEUE-POPFRONT): The list is empty";
		}
		catch (char* exception) {
			std::cout << exception << std::endl;
			return 0;
		}
}

int list::deque::Pop(void) {
	try {
		if (this->ioList->next != nullptr) {
			int length = CList::Len();
			auto CopyList = this->ioList;
			auto ReturnItem = new Pointer;

			int i(0);
			while (i < length - 2) {
				CopyList = CopyList->next;
				i++;
			}

			if(CopyList->next == nullptr && CopyList)
				ReturnItem = CopyList;
			else if(CopyList->next)
				ReturnItem = CopyList->next;

			CList::Delete(length - 1);
			return ReturnItem->item;
		}

		throw "# Traceback (QUEUE-POPBACK): The list is empty";

	}
	catch (char* exception) {
		std::cout << exception << std::endl;
		return 0;
	}
}