#ifndef LIST_CL
#define LIST_CL

#include "pointer.h"
namespace list {
	class clist {
	protected:
		Pointer* CList;
		// Virtual methods
		virtual int Push(const int &) = 0;
		virtual int Pop(void) = 0;
		// Engines
		int Rebuild(bool freeOption = false);
		void swap(int *, const int&, const int&);
		int malloc(Pointer*);

	public:
		// Methods
		clist() : CList{ nullptr } {};
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