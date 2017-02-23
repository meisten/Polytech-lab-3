#ifndef LIST_CL
#define LIST_CL

#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
#include "pointer.h"
namespace list {
	class clist
	{
	protected:
		Pointer* CList;
		// Virtual methods
		int Rebuild(bool freeOption = false);
		virtual int Push(const int &) = 0;
		virtual int Pop(void) = 0;
		// Engines
		void swap(int *, const int&, const int&);
	public:
		// Methods
		clist();
		virtual ~clist(void);
		int Read(const char *pathFile = "list.txt");
		int Write(const char *pathFile = "result.txt");
		int Search(const int &);
		int Free(void);
		void Output(void);
		int Len(void);
		int Insert(const int &, const int &);
		int Delete(const int &);
		int Sort();
	};
}

#endif