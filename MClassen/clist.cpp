#include "stdafx.h"
#include "clist.h"
#include <vector>

#define _c_INFINITY 1

int list::clist::Write(const char *pathFile) {
	try {
		if (this->CList != nullptr) {
			auto *readableList = this->CList;
			int lenPoints = this->Len();
			char *buffer = new char[lenPoints];

			int i = 0;
			FILE *f = new FILE;
			fopen_s(&f, pathFile, "w");

			if (f == nullptr)
				throw "# Traceback (READ): File doesn't exist";

			while (i < lenPoints && readableList != nullptr) {
				std::string s = std::to_string(readableList->item);
				char const *pchar = s.c_str();
				readableList = readableList->next;
				fwrite(pchar, sizeof(char), strlen(pchar) + 1, f);
				i++;
			}

			fclose(f);
			this->malloc(readableList);
			return 0;
		}

		throw "# Traceback (Write): The list is empty";

	}
	catch (char * Exception) {
		std::cout << Exception << std::endl;
		return 1;
	}
}

int list::clist::Read(const char *pathFile) {

	auto *readItem = new Pointer;
	auto *ptrFile = new FILE;

	this->Rebuild();
	this->Free();

	try {
		fopen_s(&ptrFile, pathFile, "r");
		if (ptrFile == nullptr)
			throw "# Traceback (READ): File doesn't exist";
		else{
			fseek(ptrFile, 0, SEEK_END);
			auto length = ftell(ptrFile);
			fseek(ptrFile, 0, SEEK_SET);

			char *buffer = new char[length];
			fgets(buffer, length+1, ptrFile);;
			auto lenPoints = this->Len();

			for (auto i(0); i < length; i++) {
				if (!isspace(buffer[i]) && isdigit(buffer[i])) {
					if (i < length && isdigit(buffer[i])) {
						char *digit = new char[length];

						for (auto r(0); i < length && isdigit(buffer[i]); i++, r++)
							digit[r] = buffer[i];

						this->Insert(atoi(digit), lenPoints);
						delete[] digit;
					}
					else
						this->Insert(int(buffer[i] - '0'), lenPoints);
					lenPoints++;
				}
			}

			delete[] buffer;
			fclose(ptrFile);
		}
	}
	catch (char * Exception){
		std::cout << Exception << std::endl;
		return 1;
	}

	this->malloc(readItem);
	return 0;
}

int list::clist::Free(void)
{
	try{
		if (this->CList != nullptr) {
			auto FreeList = this->CList;
			auto DelPoint = new Pointer;;

			DelPoint = FreeList->next;
			FreeList->next = nullptr;
			FreeList = nullptr;
			FreeList = DelPoint;

			while (FreeList)
			{
				DelPoint = FreeList;
				FreeList = FreeList->next;
				delete DelPoint;
			}

			this->malloc(FreeList);
			this->malloc(DelPoint);

			this->Rebuild(true);
			this->Delete(0);

			return 0;
		}

		throw "# Traceback (FREE): The list is empty";

	}
	catch (char * Exception) {
		std::cout << Exception << std::endl;
		return 1;
	}

}

list::clist::~clist(void)
{
	list::clist::Free();
	this->CList = nullptr;
	delete this->CList;
}

void list::clist::Output(void)
{
	if (this->CList != nullptr) {
		auto Output = this->CList;

		std::cout << "[ ";
		while (Output){
			std::cout << Output->item << " ";
			Output = Output->next;
		}
		std::cout << "]\n";
		this->malloc(Output);
	}
	else
		std::cout << "[]\n";
}

int list::clist::Len(void)
{
	if (this->CList != nullptr) {
		auto CopyList = this->CList;
		auto length(0);

		while (CopyList) {
			length++;
			if (CopyList->next == nullptr) {
				return length;
				CopyList = nullptr;
				delete CopyList;
			}
			CopyList = CopyList->next;
		}

	}

	return 0;

}

int list::clist::Rebuild(bool freeOption) {
	if (this->CList == nullptr || freeOption == true) {
		this->CList = nullptr;
		auto InitList = &(this->CList);
		*InitList = new Pointer;
		(*InitList)->item = 0;
		(*InitList)->next = nullptr;
		return 0;
	}
	return 1;
}

int list::clist::Insert(const int &num, const int &pos)
{
	try {
		int length = list::clist::Len();
		auto InsertBlock = new Pointer;
		auto CopyList = this->CList;

		if (this->CList == nullptr && pos == 0) {
			int a = this->Rebuild();
			this->CList->item = num;
			this->CList->next = nullptr;
		}
		else{
			InsertBlock->item = num;
			InsertBlock->next = nullptr;

			if (pos == 0) {
				InsertBlock->next = this->CList;
				this->CList = InsertBlock;
			}
			else if (pos == length) {
				if (InsertBlock && CopyList) {

					while (CopyList) {
						if (!CopyList->next){
							CopyList->next = InsertBlock;
							break;
						}
						CopyList = CopyList->next;
					}

				}
				else
					throw "# Traceback (INSERT): Incorrect arguments";
			}
			else if (pos > 0 && pos < length) {
				int curp(0);

				while (_c_INFINITY)
				{
					if (pos - 1 == curp){
						InsertBlock->next = CopyList->next;
						CopyList->next = InsertBlock;
						break;
					}
					curp++;
					CopyList = CopyList->next;
				}
			}
			else
				throw "# Traceback (INSERT): Invalid second argument";
		}

		this->malloc(InsertBlock);
		this->malloc(CopyList);
		return 0;
	}
	catch (char * exception) {
		std::cout << exception << std::endl;
		return 1;
	}
}

int list::clist::Delete(const int &pos) {

	try {
		if (this->CList != nullptr) {
			int length = this->Len();
			auto DeleteBlock = new Pointer;
			auto CopyList = this->CList;
			if (pos == 0 && pos < length) {
				if (!CopyList)
					throw "# Traceback (DELETE): List is empty";
				else if (CopyList)
				{
					this->CList = this->CList->next;
					CopyList = nullptr;
				}
				else if (CopyList && CopyList->next)
				{
					this->CList = this->CList->next;
					CopyList = nullptr;
				}
				delete CopyList;
			}
			else if (pos == length - 1 && pos != 0) {
				DeleteBlock = CopyList->next;
				while (DeleteBlock)
				{
					if (!DeleteBlock->next)
					{
						CopyList->next = DeleteBlock->next;
						delete DeleteBlock;
						return 1;
					}
					CopyList = DeleteBlock;
					DeleteBlock = DeleteBlock->next;
				}
			}
			else if (pos > 0 && pos < length - 1) {
				DeleteBlock = this->CList;
				CopyList = DeleteBlock->next;

				int curp(0);

				while (_c_INFINITY)
				{
					if (pos - 1 == curp)
					{
						DeleteBlock->next = CopyList->next;
						delete CopyList;
						break;
					}
					curp++;
					DeleteBlock = CopyList;
					CopyList = CopyList->next;
				}
			}
			else
				throw "# Traceback (DELETE): Invalid second argument";

			this->malloc(DeleteBlock);
			this->malloc(CopyList);

			return 0;
		}

		throw "# Traceback (DELETE): The list is empty";

	}
	catch(char* exception){
		std::cout << exception << std::endl;
		return 1;
	}
}

int list::clist::Sort() {
	try {
		if (this->CList != nullptr) {
			int length = this->Len();

			auto GetList = this->CList;
			auto WriteList = this->CList;

			int* listed = new int[length];

			for (auto i(0); i < length; i++) {
				listed[i] = GetList->item;
				GetList = GetList->next;
			}

			long rSubarray, lSubarray;
			long leftEdge, rightEdge;
			long llEdgeB[64], lrEdgeB[64];

			long bufPossition = 1;
			long middle = 0;
			long bearing = 0;
			llEdgeB[1] = 0;
			lrEdgeB[1] = length - 1;
			do {

				leftEdge = llEdgeB[bufPossition];
				rightEdge = lrEdgeB[bufPossition];
				bufPossition--;

				do {

					middle = (leftEdge + rightEdge) / 2;
					rSubarray = leftEdge;
					lSubarray = rightEdge;
					bearing = listed[middle];
					if (rSubarray - lSubarray != 0) {
						do {
							do {
								if (listed[rSubarray] < bearing) {
									rSubarray++;
								}
							} while (listed[rSubarray] < bearing);
							do {
								if (bearing < listed[lSubarray]) {
									lSubarray--;
								}
							} while (bearing < listed[lSubarray]);

							if (rSubarray <= lSubarray) {
								if ((rSubarray != lSubarray) && (listed[rSubarray] != listed[lSubarray])) {
									swap(listed, rSubarray, lSubarray);
								}
								rSubarray++; lSubarray--;
							}
						} while (rSubarray <= lSubarray);

						if (rSubarray < middle) {
							if (rSubarray < rightEdge) {
								bufPossition++;
								llEdgeB[bufPossition] = rSubarray;
								lrEdgeB[bufPossition] = rightEdge;
							}
							rightEdge = lSubarray;
						}
						else {
							if (lSubarray > leftEdge) {
								bufPossition++;
								llEdgeB[bufPossition] = leftEdge;
								lrEdgeB[bufPossition] = lSubarray;
							}
							leftEdge = rSubarray;
						}
					}
				} while (leftEdge < rightEdge);
			} while (bufPossition != 0);

			for (int i(0); i < length; i++) {
				WriteList->item = listed[i];
				WriteList = WriteList->next;
			}
			return 0;
		}

		throw "# Traceback (SORT): The list is empty";

	}
	catch (char *exception) {
		std::cout << exception << std::endl;
		return 1;
	}

	return 0;

}

int list::clist::Search(const int &num) {
	auto SearchList = this->CList;

	try {
		if (this->CList != nullptr) {
			int length = this->Len();

			int pos(0);
			while (pos < length && SearchList) {
				if (SearchList->item == num) {
					this->malloc(SearchList);
					return pos;
				}
				SearchList = SearchList->next;
				pos++;
			}

			throw "# Traceback (SEARCH): The input value wasn't found";
		}

		throw "# Traceback (SEARCH): The list is empty";
	}
	catch (char *exception) {
		this->malloc(SearchList);
		std::cout << exception << std::endl;
		return -1;
	}
}

void list::clist::swap(int *listArray, const int &i, const int  &j)
{
	auto glass = listArray[i];
	listArray[i] = listArray[j];
	listArray[j] = glass;
}

int list::clist::malloc(Pointer* ptr) {
	ptr = nullptr;
	delete ptr;
	return 0;
}