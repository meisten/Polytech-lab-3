#pragma once
#include "clist.h"

class stack : public clist {
public:
	stack() : clist() {};
	~stack() {};

	int Push(const int &);
	int Pop(void);
};