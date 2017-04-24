#ifndef DEQUE_CL
#define DEQUE_CL
#include "clist.h"

namespace list {

	/**
	* @class deque
	* @extends CList
	* ���������� �������� Deque-������ �� ������
	* ������������ ������ CList
	*/
	class deque : public CList {  
	public:
		/**
		* @action �����������, ������������� ������� ����������
		*/
		deque() : CList() {};

		/**
		* @action ����������, ������������ ������
		*/
		~deque() {};

		/**
		* @action ���������� �������� � �����
		* @param first - �������, ������� ������� ��������
		* @return 0, ���� �������, � 1, ���� �������� ������.
		*/
		virtual int Push(const int &) override final;

		/**
		* @action ���������� �������� � ������
		* @param first - �������, ������� ������� ��������
		* @return 0, ���� �������, � 1, ���� �������� ������.
		*/
		int PushFront(const int &);

		/**
		* @action �������� �������� �� ������
		* @return ��������� �������
		*/
		virtual int Pop(void) override final;

		/**
		* @action �������� �������� �� ������ ������
		* @return ��������� �������
		*/
		int PopFront(void);
	};
}

#endif