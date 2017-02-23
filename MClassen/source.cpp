#include <iostream>
#include "clist.h"
#include "stack.h"

int main() {
	stack x;
	x.Read();
	x.Output();
	x.Push(5);
	x.Output();
	std::cout << x.Pop() << std::endl;
	x.Output();

	system("pause");
	return 0;
}