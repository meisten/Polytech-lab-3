#ifndef POINTER_CL
#define POINTER_CL
#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
#include <cstdio>

/**
* @class Pointer
* Реализация элемента списка
*/
class Pointer
{
	public:
		int item;
		Pointer* next;
};

#endif