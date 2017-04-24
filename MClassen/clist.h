#ifndef LIST_CL
#define LIST_CL

#include "pointer.h"
namespace list {

	/**
	* @class CList
	* Интерфейс для реализации связных Stack- Deque- Queue-списков
	*/
	class CList {
	protected:
		Pointer* ioList;
		
		/**
		* @action Чисто-виртуальная функция для добавления элемента
		* @param first - Элемент, который следует добавить
		* @return 0, если успешно, и 1, если возникла ошибка.
		*/
		virtual int Push(const int &) = 0;

		/**
		* @action чисто-виртуальная функция для удаления элемента из списка
		* @return выбранный элемент
		*/
		virtual int Pop(void) = 0;

		/**
		* @action перестанока элементов массива, используется
		* для метода быстрой сортировки
		* @param first - указатель на список
		* @param second - позиция целевого элемента 1
		* @param third - позиция целевого элемента 2
		* @return ничего
		*/
		void swap(int *, const int&, const int&);

		/**
		* @action высвобождение памяти
		* @param first - целевой для высвобождения памяти указатель
		* @return 0
		*/
		int malloc(Pointer*);

	public:
		
		/**
		* @action конструктор: инициализация нулевым указателем
		* @param first - указатель на первый элемент списка
		*/
		CList();

		/**
		* @action деструктор: высвобождение памяти
		*/
		virtual ~CList(void);

		/**
		* @action чтение целых чисел из файла
		* @param first - имя файла по умолчанию
		* @return 0, если успешно, и 1, если возникла ошибка
		*/
		int Read(const char *pathFile = "list.txt");

		/**
		* @action запись имеющегося списка в файл
		* @param first - имя файла по умолчанию
		* @return 0, если успешно, и 1, если возникла ошибка
		*/
		int Write(const char *pathFile = "result.txt");

		/**
		* @action поиск позиции первого вхождения выбранного
		* значения
		* @param first - выбранное для поиска значения
		* @return позиция элемента, если успешно, и -1, если возникла ошибка
		* или если введенное значение не было найдено
		*/
		int Search(const int &);

		/**
		* @action сброс существующего списка, высвобождение памяти
		* @return 0, если успешно, и 1, если возникла ошибка
		*/
		int Free(void);

		/**
		* @action вывод существующего списка на экран
		*/
		void Output(void);

		/**
		* @action получение длины списка
		* @return длина списка
		*/
		int Len(void);

		/**
		* @action вставка введенного значения на введенную 
		* позицию
		* @param first - значение 
		* @param second - позиция
		* @return 0, если успешно, и 1, если возникла ошибка.
		*/
		int Insert(const int &, const int &);

		/**
		* @action удаление элемета из списка на введенной
		* позиции
		* @param first - позиция
		* @return 0, если успешно, и 1, если возникла ошибка.
		*/
		int Delete(const int &);

		/**
		* @action быстрая сортировка списка
		* @return 0, если успешно, и 1, если возникла ошибка.
		*/
		int Sort(void);

	};
}

#endif