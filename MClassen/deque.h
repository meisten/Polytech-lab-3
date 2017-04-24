#ifndef DEQUE_CL
#define DEQUE_CL
#include "clist.h"

namespace list {

	/**
	* @class deque
	* @extends CList
	* Реализация связного Deque-списка на основе
	* абстрактного класса CList
	*/
	class deque : public CList {  
	public:
		/**
		* @action конструктор, инициализация нулевым указателем
		*/
		deque() : CList() {};

		/**
		* @action деструктор, освобождение памяти
		*/
		~deque() {};

		/**
		* @action Добавление элемента в конец
		* @param first - Элемент, который следует добавить
		* @return 0, если успешно, и 1, если возникла ошибка.
		*/
		virtual int Push(const int &) override final;

		/**
		* @action Добавление элемента в начало
		* @param first - Элемент, который следует добавить
		* @return 0, если успешно, и 1, если возникла ошибка.
		*/
		int PushFront(const int &);

		/**
		* @action Удаление элемента из списка
		* @return выбранный элемент
		*/
		virtual int Pop(void) override final;

		/**
		* @action Удаление элемента из начала списка
		* @return выбранный элемент
		*/
		int PopFront(void);
	};
}

#endif