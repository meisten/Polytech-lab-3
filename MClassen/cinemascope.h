#ifndef SCOPE_SP
#define SCOPE_SP
#include "deque.h"
#include "stack.h"
#include "queue.h"

namespace Scope {

	/**
	* @action вывод списка команд на экран
	*/
	void overallMenu(int b);

	/**
	* @action выполнение введенной команды, общей
	* для всех типов реализаций списка
	* @return 1 в случае выполнения команды и 0, если
	* соответствующая введенная команда найдена не была
	*/
	int overallChoose(char c, int b, list::CList&);

	/**
	* @action выполнение введенной команды, присущей
	* только двухсторонней очереди
	* @param ссылка на объект класса deque
	*/
	void deque(list::deque&);

	/**
	* @action выполнение введенной команды, присущей
	* только очереди
	* @param ссылка на объект класса queue
	*/
	void queue(list::queue&);

	/**
	* @action выполнение введенной команды, присущей
	* только стеку
	* @param ссылка на объект класса stack
	*/
	void stack(list::stack&);
}
#endif