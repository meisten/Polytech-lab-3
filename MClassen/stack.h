#ifndef STACK_CL
#define STACK_CL

#include "clist.h"
namespace list {
	class stack : public CList {
	public:
		/**
		* @action конструктор, инициализация нулевым указателем
		*/
		stack() : CList() {};

		/**
		* @action деструктор, освобождение памяти
		*/
		~stack() {};

		/**
		* @action Добавления элемента в конец
		* @param first - Элемент, который следует добавить
		* @return 0, если успешно, и 1, если возникла ошибка.
		*/
		virtual int Push(const int &) override final;

		/**
		* @action Удаление элемента из конца списка
		* @return выбранный элемент
		*/
		virtual int Pop(void) override final;
	};
}

#endif