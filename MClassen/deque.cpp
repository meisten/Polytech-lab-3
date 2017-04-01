#include "stdafx.h"
#include "deque.h"

int list::deque::Push(const int &num) {
	int length = clist::Len();
	if (!clist::Insert(num, length))
		return 0;
	return 1;
}

int list::deque::PushFront(const int &num) {
	if (!clist::Insert(num, 0))
		return 0;
	return 1;
}

int list::deque::PopFront(void) {
	try{
		if (this->CList != nullptr) {
			auto CopyList = this->CList;
			auto ReturnItem = new Pointer;

			ReturnItem = CopyList;
			clist::Delete(0);

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
		if (this->CList != nullptr) {
			int length = clist::Len();
			auto CopyList = this->CList;
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

			clist::Delete(length - 1);
			return ReturnItem->item;
		}

		throw "# Traceback (QUEUE-POPBACK): The list is empty";

	}
	catch (char* exception) {
		std::cout << exception << std::endl;
		return 0;
	}
}