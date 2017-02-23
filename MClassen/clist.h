#pragma once
#include <fstream>

class Pointer
{
public:
	int item;
	Pointer* next;
};

class clist
{
protected:
	Pointer* CList;
	// Engine
	Pointer* endPoint();
	// Virtual methods
	virtual int Push(const int &) = 0;
	virtual int Pop(void) = 0;
public:
	// Methods
	clist(const char *pathFile = "list.txt");
	virtual ~clist(void);
	int Read(const char *pathFile = "list.txt");
	int Write(const char *pathFile = "result.txt");
	int Free(void);
	void Output(void);
	int Len(void);
	int Insert(const int &, const int &);
	int Delete(const int &);
};