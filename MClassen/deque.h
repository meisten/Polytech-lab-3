#ifndef DEQUE_CL
#define DEQUE_CL
#include "clist.h"

namespace list {
	class deque : public clist {
	public:
		deque() : clist() {};
		~deque() {};

		int Push(const int &);
		int PushFront(const int &);
		int Pop(void);
		int PopFront(void);
	};
}

#endif