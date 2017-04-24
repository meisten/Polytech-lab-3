#ifndef STACK_CL
#define STACK_CL

#include "clist.h"
namespace list {
	class stack : public CList {
	public:
		/**
		* @action �����������, ������������� ������� ����������
		*/
		stack() : CList() {};

		/**
		* @action ����������, ������������ ������
		*/
		~stack() {};

		/**
		* @action ���������� �������� � �����
		* @param first - �������, ������� ������� ��������
		* @return 0, ���� �������, � 1, ���� �������� ������.
		*/
		virtual int Push(const int &) override final;

		/**
		* @action �������� �������� �� ����� ������
		* @return ��������� �������
		*/
		virtual int Pop(void) override final;
	};
}

#endif