#pragma once
#include <iostream>
#include <conio.h>
#include "clist.h"
#include "deque.h"
#include "stack.h"
#include "queue.h"

namespace Scope {
	void overallMenu(int b);

	int overallChoose(char c, int b, list::clist&);

	void deque(list::deque&);

	void queue(list::queue&);

	void stack(list::stack&);
}