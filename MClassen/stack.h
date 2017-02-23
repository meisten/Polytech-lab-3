#pragma once
#include "clist.h"

class stack : public clist {
public:
	stack(const char *pathFile = "list.txt") : clist(pathFile) {};
	~stack() {};

	int Push(const int &);
	int Pop(void);
};