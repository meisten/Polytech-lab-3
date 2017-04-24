#ifndef QUEUE_CL
#define QUEUE_CL
#include "clist.h"

namespace list {

	/**
	* @class queue
	* @extends CList
	* Реализация связного Queue-списка на основе
	* абстрактного класса CList
	*/
	class queue : public CList {

		public:

			/**
			* @action конструктор, инициализация нулевым указателем
			*/
			queue() : CList() {};

			/**
			* @action деструктор, освобождение памяти
			*/
			~queue() {};

			/**
			* @action Добавления элемента в конец
			* @param first - Элемент, который следует добавить
			* @return 0, если успешно, и 1, если возникла ошибка.
			*/
			virtual int Push(const int &) override final;

			/**
			* @action Удаление элемента из начала списка
			* @return выбранный элемент
			*/
			virtual int Pop(void) override final;
	};
}

#endif