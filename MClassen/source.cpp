#include <iostream>
#include "clist.h"
#include "stack.h"
#include "queue.h"
#include "deque.h"

int main() {
	std::cout << "Enter a command: \n";
	std::cout << "1 - Push\n";
	std::cout << "2 - Pop\n";
	std::cout << "3 - Free\n";
	std::cout << "4 - Write\n";
	std::cout << "5 - Read\n";
	std::cout << "6 - Insert\n";
	std::cout << "7 - Delete\n";
	std::cout << "8 - Len\n";
	std::cout << "9 - Print\n";
	deque x;
	while(1) {
		int item = 0;
		int position = 0;
		int choose = 0;

		std::cin >> choose;
		switch (choose){
			case 1:
				std::cout << "Input Item: ";
				std::cin >> item;
				x.Push(item);
				break;

			case 2:
				std::cin >> item;
				std::cout << x.Pop() << std::endl;
				break;

			case 3:
				x.Free();
				break;

			case 4:
				x.Write();
				break;

			case 5:
				x.Read();
				break;

			case 6:
				std::cout << "Item: ";
					std::cin >> item;
				std::cout << "Pos: ";
					std::cin >> position;

				x.Insert(item, position);
				break;

			case 7:
				std::cout << "Pos: ";
				std::cin >> position;
				x.Delete(position);
				break;

			case 8:
				std::cout << "Len: " << x.Len() << std::endl;
				break;

			case 9:
				x.Output();
				break;

			default:
				std::cout << "ERROR OPERATION";
				break;
			}
	}

	system("pause");
	return 0;
}