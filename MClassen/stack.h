#ifndef STACK_CL
#define STACK_CL

#include "clist.h"
namespace list {
	class stack : public clist {
	public:
		stack() : clist() {};
		~stack() {};

		int Push(const int &);
		int Pop(void);
	};
}

#endif