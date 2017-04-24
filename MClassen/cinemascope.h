#ifndef SCOPE_SP
#define SCOPE_SP
#include "deque.h"
#include "stack.h"
#include "queue.h"

namespace Scope {

	/**
	* @action ����� ������ ������ �� �����
	*/
	void overallMenu(int b);

	/**
	* @action ���������� ��������� �������, �����
	* ��� ���� ����� ���������� ������
	* @return 1 � ������ ���������� ������� � 0, ����
	* ��������������� ��������� ������� ������� �� ����
	*/
	int overallChoose(char c, int b, list::CList&);

	/**
	* @action ���������� ��������� �������, ��������
	* ������ ������������� �������
	* @param ������ �� ������ ������ deque
	*/
	void deque(list::deque&);

	/**
	* @action ���������� ��������� �������, ��������
	* ������ �������
	* @param ������ �� ������ ������ queue
	*/
	void queue(list::queue&);

	/**
	* @action ���������� ��������� �������, ��������
	* ������ �����
	* @param ������ �� ������ ������ stack
	*/
	void stack(list::stack&);
}
#endif