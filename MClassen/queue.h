#ifndef QUEUE_CL
#define QUEUE_CL
#include "clist.h"

namespace list {

	/**
	* @class queue
	* @extends CList
	* ���������� �������� Queue-������ �� ������
	* ������������ ������ CList
	*/
	class queue : public CList {

		public:

			/**
			* @action �����������, ������������� ������� ����������
			*/
			queue() : CList() {};

			/**
			* @action ����������, ������������ ������
			*/
			~queue() {};

			/**
			* @action ���������� �������� � �����
			* @param first - �������, ������� ������� ��������
			* @return 0, ���� �������, � 1, ���� �������� ������.
			*/
			virtual int Push(const int &) override final;

			/**
			* @action �������� �������� �� ������ ������
			* @return ��������� �������
			*/
			virtual int Pop(void) override final;
	};
}

#endif