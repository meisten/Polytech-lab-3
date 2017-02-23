#include <iostream>
#include "clist.h"

list::clist::clist()
{
	this->CList = NULL;
}

int list::clist::Write(const char *pathFile) {
	try {
		if (this->CList != NULL) {
			Pointer* readableList = this->CList;
			int lenPoints = list::clist::Len();
			char * buffer = new char[lenPoints];

			int i = 0;
			std::ofstream writeFile(pathFile, std::ios_base::out, std::ios_base::trunc);
			if (!writeFile.is_open()) {
				throw "# Traceback (READ): File doesn't exist";
			}
			while (i < lenPoints && readableList) {

				std::string s = std::to_string(readableList->item);
				char const *pchar = s.c_str();
				readableList = readableList->next;
				writeFile << pchar;
				writeFile << " ";
				i++;
			}
			writeFile.close();


			readableList = NULL;
			delete readableList;

			return 0;
		}
		else
			throw "# Traceback (Write): The list is empty";
	}
	catch (char * Exception) {
		std::cout << Exception << std::endl;
		return 1;
	}
}

int list::clist::Read(const char *pathFile) {
	list::clist::Rebuild();
	Pointer* filledList = new Pointer;
	Pointer* readItem = new Pointer;
	Pointer* delDefPointer = this->CList;

	list::clist::Free();

	try {
		std::ifstream inputFile(pathFile, std::ifstream::binary);
		if (!inputFile.is_open()) {
			throw "# Traceback (READ): File doesn't exist";
		}
		if (inputFile) {

			inputFile.seekg(0, inputFile.end);
			int length = inputFile.tellg();
			inputFile.seekg(0, inputFile.beg);

			char * buffer = new char[length];
			inputFile.read(buffer, length);
			int digit = 0;
			int spaces = 0;
			int i = 0;
			int lenPoints = list::clist::Len();

			while (i < length) {
				if (!isspace(buffer[i])){
					if(isdigit(buffer[i])){
						if (i + 1 < length && isdigit(buffer[i + 1])) {
							char * digit = new char[length];
							int r(1);
							digit[0] = buffer[i];
							while (i + 1 < length && isdigit(buffer[i + 1])) {
								digit[r] = buffer[i+1];
								r++;
								i++;
							}
							list::clist::Insert(atoi(digit), lenPoints);
						}
						else {
							list::clist::Insert(int(buffer[i] - '0'), lenPoints);
						}
						lenPoints++;
					}
				}
				i++;
			}
			delete[] buffer;
			inputFile.close();
		}
	}
	catch (char * Exception){
		std::cout << Exception << std::endl;
		return 1;
	}

	filledList = NULL;
	readItem = NULL;
	delDefPointer = NULL;

	delete filledList;
	delete delDefPointer;
	delete readItem;

	return 0;
}

int list::clist::Free(void)
{
	try{
		if (this->CList != NULL) {
			Pointer* FreeList = this->CList;
			Pointer* DelPoint = NULL;

			DelPoint = FreeList->next;
			FreeList->next = NULL;
			FreeList = NULL;
			FreeList = DelPoint;

			while (FreeList)
			{
				DelPoint = FreeList;
				FreeList = FreeList->next;
				delete DelPoint;
			}

			FreeList = NULL;
			DelPoint = NULL;
			delete FreeList;
			delete DelPoint;

			list::clist::Rebuild(true);
			list::clist::Delete(0);
			return 0;
		}
		else
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
	this->CList = NULL;
	delete this->CList;
}

void list::clist::Output(void)
{
	if (this->CList != NULL) {
		Pointer* Output = this->CList;
		std::cout << "[ ";
		while (Output)
		{
			std::cout << Output->item << " ";
			Output = Output->next;
		}
		std::cout << "]\n";

		Output = NULL;
		delete Output;
	}
	else {
		std::cout << "[]\n";
	}
}

int list::clist::Len(void)
{
	if (this->CList != NULL) {
		Pointer* CopyList = this->CList;
		int length = 0;

		while (1)
		{
			length++;
			if (!CopyList || !CopyList->next)
			{
				CopyList = NULL;
				delete CopyList;
				return length;
			}
			CopyList = CopyList->next;
		}

	}
	else {
		return 0;
	}
}

int list::clist::Rebuild(bool freeOption) {
	if (this->CList == NULL || freeOption == true) {
		this->CList = NULL;
		Pointer** InitList = &(this->CList);
		*InitList = new Pointer;
		(*InitList)->item = 0;
		(*InitList)->next = NULL;
		return 0;
	}
	return 1;
}

int list::clist::Insert(const int &num, const int &pos)
{
	try {
		int length = list::clist::Len();
		Pointer* InsertBlock = new Pointer;
		Pointer* CopyList = this->CList;

		if (this->CList == NULL && pos == 0) {
			int a = list::clist::Rebuild();
			this->CList->item = num;
			this->CList->next = NULL;
		}
		else{
			if (pos == 0) {
				InsertBlock->item = num;
				InsertBlock->next = this->CList;
				this->CList = InsertBlock;
			}
			else if (pos == length) {
				InsertBlock->item = num;
				InsertBlock->next = NULL;
				if (InsertBlock && CopyList) {
					while (1)
					{
						if (!CopyList->next)
						{
							CopyList->next = InsertBlock;
							break;
						}
						CopyList = CopyList->next;
					}
				}
				else {
					throw "# Traceback (INSERT): Incorrect arguments";
				}
			}
			else if (pos > 0 && pos < length) {
				InsertBlock->item = num;
				InsertBlock->next = NULL;

				int curp = 0;

				while (1)
				{
					if (pos - 1 == curp)
					{
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

		InsertBlock = NULL;
		CopyList = NULL;
		delete CopyList;
		delete InsertBlock;
		return 0;
	}
	catch (char * exception) {
		std::cout << exception << std::endl;
		return 1;
	}
}

int list::clist::Delete(const int &pos) {

	try {
		if (this->CList != NULL) {
			int length = list::clist::Len();
			Pointer* DeleteBlock = new Pointer;
			Pointer* CopyList = this->CList;
			if (pos == 0 && pos < length) {
				if (!CopyList)
				{
					throw "# Traceback (DELETE): List is empty";
					return -1;
				}
				else if (CopyList)
				{
					this->CList = this->CList->next;
					CopyList = NULL;
				}
				else if (CopyList && CopyList->next)
				{
					this->CList = this->CList->next;
					CopyList = NULL;
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

				int curp = 0;

				while (1)
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

			DeleteBlock = NULL;
			CopyList = NULL;
			delete CopyList;
			delete DeleteBlock;

			return 0;
		}
		else {
			throw "# Traceback (DELETE): The list is empty";
		}

	}
	catch(char* exception){
		std::cout << exception << std::endl;
		return 1;
	}
}

int list::clist::Sort() {
	try {
		if (this->CList != NULL) {
			int length = list::clist::Len();
			Pointer *GetList = this->CList;
			Pointer *WriteList = this->CList;

			int* listed = new int[length];
			for (int i(0); i < length; i++) {
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
		else {
			throw "# Traceback (SORT): The list is empty";
		}
	}
	catch (char *exception) {
		std::cout << exception << std::endl;
		return 1;
	}

	return 0;

}

int list::clist::Search(const int &num) {
	try {
		if (this->CList != NULL) {
			Pointer *SearchList = this->CList;
			int length = list::clist::Len();

			int pos(0);
			while (pos < length && SearchList) {
				if (SearchList->item == num) {
					SearchList = NULL;
					delete SearchList;
					return pos;
				}
				SearchList = SearchList->next;
				pos++;
			}

			SearchList = NULL;
			delete SearchList;
			throw "# Traceback (SEARCH): The input value wasn't found";
		}
		else {
			throw "# Traceback (SEARCH): The list is empty";
		}
	}
	catch (char *exception) {
		std::cout << exception << std::endl;
		return -1;
	}
}

void list::clist::swap(int *listArray, const int &i, const int  &j)
{
	int glass = listArray[i];
	listArray[i] = listArray[j];
	listArray[j] = glass;
}