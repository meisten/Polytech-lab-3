#ifndef DEQUE_CL
#define DEQUE_CL
#include "clist.h"

namespace list {
	class deque : public clist {
	public:
		deque() : clist() {};
		~deque() {};

		virtual int Push(const int &) override final;
		int PushFront(const int &);
		virtual int Pop(void) override final;
		int PopFront(void);
	};
}

#endif