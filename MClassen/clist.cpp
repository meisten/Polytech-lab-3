#pragma once
#include <iostream>
#include "clist.h"
#include "stack.h"
#include <fstream>
#include <string>

clist::clist(const char *pathFile)
{
	this->CList = NULL;
	Pointer** InitList = &(this->CList);
	*InitList = new Pointer;

	(*InitList)->item = 0;	
	(*InitList)->next = NULL;
}

int clist::Write(const char *pathFile) {
	Pointer* readableList = this->CList;
	int lenPoints = clist::Len();
	char * buffer = new char[lenPoints];

	int i = 0;
	try {
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
	}
	catch (char * Exception) {
		std::cout << Exception << std::endl;
		return 1;
	}
	readableList = NULL;
	delete readableList;
	return 0;
}
int clist::Read(const char *pathFile) {
	this->CList = NULL;
	Pointer** InitList = &(this->CList);
	*InitList = new Pointer;
	Pointer* filledList = new Pointer;
	Pointer* readItem = new Pointer;
	Pointer* delDefPointer = this->CList;

	clist::Free();

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
			int lenPoints = clist::Len();

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
							clist::Insert(atoi(digit), lenPoints);
						}
						else {
							clist::Insert(int(buffer[i] - '0'), lenPoints);
						}
						lenPoints++;
					}
				}
				i++;
			}
			clist::Delete(0);
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
	delete filledList;
	delete readItem;

	return 0;
}

int clist::Free(void)
{
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

	return 0;
}

clist::~clist(void)
{
	clist::Free();
	this->CList = NULL;
	delete this->CList;
}


void clist::Output(void)
{
	Pointer* Output = this->CList;
	std::cout << "[ ";
	while (Output)
	{
		std::cout << Output->item << " ";
		Output =Output->next;
	}
	std::cout << "]\n";

	Output = NULL;
	delete Output;
}

int clist::Len(void)
{
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

int clist::Insert(const int &num, const int &pos)
{
	int length = clist::Len();
	Pointer* InsertBlock = new Pointer;
	Pointer* CopyList = this->CList;

	try {
		if (length == 0) {
			this->CList->item = num;
			this->CList->next = NULL;
		}
		else if (pos == 0) {
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
				throw "# Traceback (INSERT): Incorrect arguments \n";
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
		else {
			throw "# Traceback (INSERT): Invalid second argument \n";
		}
	}
	catch (char * exception) {
		std::cout << exception << std::endl;

		InsertBlock = NULL;
		CopyList = NULL;
		delete CopyList;
		delete InsertBlock;

		return 1;
	}

	InsertBlock = NULL;
	CopyList = NULL;
	delete CopyList;
	delete InsertBlock;

	return 0;
}

int clist::Delete(const int &pos) {
	int length = clist::Len();
	Pointer* DeleteBlock = new Pointer;
	Pointer* CopyList = this->CList;

	try {
		if (pos == 0 && pos < length) {
			if (!CopyList)
			{
				throw "# Traceback (DELETE): List is empty \n";
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
			return 0;
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
			return 0;
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
			return 0;
		}
		else {
			throw "# Traceback (DELETE): Invalid second argument \n";
		}
	}
	catch(char* exception){
		std::cout << exception << std::endl;

		DeleteBlock = NULL;
		CopyList = NULL;
		delete CopyList;
		delete DeleteBlock;

		return -1;
	}

	DeleteBlock = NULL;
	CopyList = NULL;
	delete CopyList;
	delete DeleteBlock;

	return 0;

}
Pointer* clist::endPoint(void) {
	Pointer* endPointer = this->CList;
	while (endPointer)
	{
		if (endPointer->next == NULL) {
			return endPointer;
		}
		endPointer = endPointer->next;
	}

	endPointer = NULL;
	delete endPointer;

	return NULL;
}