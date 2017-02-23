#include "cinemascope.h"
#include "stack.h"
#include "queue.h"
#include "deque.h"

void Scope::overallMenu(int b) {

	std::cout << "Enter a command: \n";
	std::cout << "q - Return back\n";
	std::cout << "0 - Sort \n";
	std::cout << "1 - Read from file\n";
	std::cout << "2 - Write in a file\n";
	std::cout << "3 - Clear\n";
	std::cout << "4 - Insert item\n";
	std::cout << "5 - Delete item\n";
	std::cout << "6 - Get the length of the list\n";
	std::cout << "7 - Print \n";

	switch (b) {
		case 1:
			std::cout << "8 - Push Front \n";
			std::cout << "9 - Push Back \n";
			std::cout << "A - Pop Front \n";
			std::cout << "B - Pop Back \n";
			break;
		case 2:
			std::cout << "8 - Push Back \n";
			std::cout << "9 - Pop Back \n";
			break;
		case 3:
			std::cout << "8 - Push Back \n";
			std::cout << "9 - Pop Front \n";
		default:
			break;
	}
}

int Scope::overallChoose(char c, int b, list::clist& x){
	int item = 0;
	int position = 0;

	switch (tolower(c)) {
	case 'q':
		system("cls");
		return -1;
		break;

	case '0':
		if (!x.Sort())
			std::cout << "::: Done!" << std::endl;
		break;

	case '1':
		if (!x.Read())
			std::cout << "::: Done!" << std::endl;
		break;

	case '2':
		if (!x.Write())
			std::cout << "::: Done!" << std::endl;
		break;

	case '3':
		if (!x.Free())
			std::cout << "::: Done!" << std::endl;
		break;

	case '4':
		std::cout << "::: Insert -> Input Item: ";
		std::cin >> item;
		std::cout << "::: Insert -> Input Position: ";
		std::cin >> position;
		if (x.Insert(item, position))
			std::cout << "::: Done" << std::endl;
		break;

	case '5':
		std::cout << "::: Insert -> Input Position: ";
		std::cin >> position;
		if (x.Delete(position))
			std::cout << "::: Done" << std::endl;
		break;

	case '6':
		std::cout << "::: Len: " << x.Len() << std::endl;
		break;

	case '7':
		x.Output();
		break;

	default:
		return 0;
		break;
	}
	return 1;
}


void Scope::deque(list::deque& x) {
	while (1) {
		Scope::overallMenu(1);
		std::cout << ">>> ";
		char d = _getch();
		std::cout << d << std::endl;
		bool returnBack = false;
		int item = 0;

		switch (Scope::overallChoose(d, 1, x)){
			case -1:
				returnBack = true;
				break;
			case 0:
				switch (int(tolower(d))){
				case 56:
					std::cout << "PushFront -> Enter value: ";
					std::cin >> item;
					if (!x.PushFront(item))
						std::cout << "::: Done!" << std::endl;
					break;
				case 57:
					std::cout << "PushBack -> Enter value: ";
					std::cin >> item;

					if (!x.Push(item))
						std::cout << "::: Done!" << std::endl;
					break;

				case 97:
					std::cout << "::: PopFront -> The obtained value: " << x.PopFront() << std::endl;
					break;
				case 98:
					std::cout << "::: PopBack -> The obtained value: " << x.Pop() << std::endl;
					break;
				default:
					std::cout << "# Traceback (OPERATIONS-DEQUE): Wrong command" << std::endl;
					break;
				}
				break;
			case 1:
				break;

			default:
				break;
		}

		while (_kbhit())
			_getch();

		std::cout << "::: Press any key to continue...";
		_getch();
		system("cls");
		if (returnBack)
			break;
	}
}

void Scope::stack(list::stack& x) {
	while (1) {
		Scope::overallMenu(1);
		std::cout << ">>> ";
		char d = _getch();
		std::cout << d << std::endl;

		bool returnBack = false;
		int item = 0;

		switch (Scope::overallChoose(d, 2, x)) {
			case -1:
				returnBack = true;
				break;
			case 0:
				switch (tolower(d)) {
				case '8':
					std::cout << "::: Push (Back) -> Enter value: ";
					std::cin >> item;
					if (x.Push(item))
						std::cout << "::: Done!" << std::endl;
					break;
				case '9':
					std::cout << "::: Pop (Back) -> The obtained value: " << x.Pop() << std::endl;
					break;
				default:
					std::cout << "# Traceback (OPERATIONS-QUEUE): Wrong command" << std::endl;
					break;
				}
				break;
			case 1:
				break;

			default:
				break;
		}

		std::cout << "::: Press any key to continue...";
		_getch();
		system("cls");
		if (returnBack)
			break;

	}
}

void Scope::queue(list::queue& x) {
	while (1) {
		Scope::overallMenu(3);
		std::cout << ">>> ";
		char d = _getch();
		std::cout << d << std::endl;

		bool returnBack = false;
		int item = 0;

		switch (Scope::overallChoose(d, 3, x)) {
		case -1:
			returnBack = true;
			break;
		case 0:
			switch (tolower(d)) {
			case '8':
				std::cout << "::: Push (Back) -> Enter value: "; 
				std::cin >> item;

				if (!x.Push(item))
					std::cout << "::: Done!" << std::endl;
				break;

			case '9':
				std::cout << "::: Pop (Front) -> The obtained value: " << x.Pop() << std::endl;
				break;

			default:
				std::cout << "# Traceback (OPERATIONS-QUEUE): Wrong command" << std::endl;
				break;

			}
			break;
		case 1:
			break;

		default:
			break;
		}
		std::cout << "::: Press any key to continue...";
		_getch();
		system("cls");
		if (returnBack)
			break;
	}
}