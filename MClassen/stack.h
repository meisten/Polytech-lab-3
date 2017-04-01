#ifndef STACK_CL
#define STACK_CL

#include "clist.h"
namespace list {
	class stack : public clist {
	public:
		stack() : clist() {};
		~stack() {};

		virtual int Push(const int &) override final;
		virtual int Pop(void) override final;
	};
}

#endif