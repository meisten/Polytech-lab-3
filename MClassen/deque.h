#pragma once
#include "clist.h"

class deque : public clist {
public:
	deque() : clist() {};
	~deque() {};

	int Push(const int &);
	int PushFront(const int &);
	int Pop(void);
	int PopFront(void);
};