#ifndef LIST_CL
#define LIST_CL

#include "pointer.h"
namespace list {

	/**
	* @class CList
	* ��������� ��� ���������� ������� Stack- Deque- Queue-�������
	*/
	class CList {
	protected:
		Pointer* ioList;
		
		/**
		* @action �����-����������� ������� ��� ���������� ��������
		* @param first - �������, ������� ������� ��������
		* @return 0, ���� �������, � 1, ���� �������� ������.
		*/
		virtual int Push(const int &) = 0;

		/**
		* @action �����-����������� ������� ��� �������� �������� �� ������
		* @return ��������� �������
		*/
		virtual int Pop(void) = 0;

		/**
		* @action ����������� ��������� �������, ������������
		* ��� ������ ������� ����������
		* @param first - ��������� �� ������
		* @param second - ������� �������� �������� 1
		* @param third - ������� �������� �������� 2
		* @return ������
		*/
		void swap(int *, const int&, const int&);

		/**
		* @action ������������� ������
		* @param first - ������� ��� ������������� ������ ���������
		* @return 0
		*/
		int malloc(Pointer*);

	public:
		
		/**
		* @action �����������: ������������� ������� ����������
		* @param first - ��������� �� ������ ������� ������
		*/
		CList();

		/**
		* @action ����������: ������������� ������
		*/
		virtual ~CList(void);

		/**
		* @action ������ ����� ����� �� �����
		* @param first - ��� ����� �� ���������
		* @return 0, ���� �������, � 1, ���� �������� ������
		*/
		int Read(const char *pathFile = "list.txt");

		/**
		* @action ������ ���������� ������ � ����
		* @param first - ��� ����� �� ���������
		* @return 0, ���� �������, � 1, ���� �������� ������
		*/
		int Write(const char *pathFile = "result.txt");

		/**
		* @action ����� ������� ������� ��������� ����������
		* ��������
		* @param first - ��������� ��� ������ ��������
		* @return ������� ��������, ���� �������, � -1, ���� �������� ������
		* ��� ���� ��������� �������� �� ���� �������
		*/
		int Search(const int &);

		/**
		* @action ����� ������������� ������, ������������� ������
		* @return 0, ���� �������, � 1, ���� �������� ������
		*/
		int Free(void);

		/**
		* @action ����� ������������� ������ �� �����
		*/
		void Output(void);

		/**
		* @action ��������� ����� ������
		* @return ����� ������
		*/
		int Len(void);

		/**
		* @action ������� ���������� �������� �� ��������� 
		* �������
		* @param first - �������� 
		* @param second - �������
		* @return 0, ���� �������, � 1, ���� �������� ������.
		*/
		int Insert(const int &, const int &);

		/**
		* @action �������� ������� �� ������ �� ���������
		* �������
		* @param first - �������
		* @return 0, ���� �������, � 1, ���� �������� ������.
		*/
		int Delete(const int &);

		/**
		* @action ������� ���������� ������
		* @return 0, ���� �������, � 1, ���� �������� ������.
		*/
		int Sort(void);

	};
}

#endif