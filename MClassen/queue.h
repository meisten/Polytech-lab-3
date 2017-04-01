#ifndef QUEUE_CL
#define QUEUE_CL
#include "clist.h"

namespace list {
	class queue : public clist {
	public:
		queue() : clist() {};
		~queue() {};

		virtual int Push(const int &) override final;
		virtual int Pop(void) override final;
	};
}

#endif