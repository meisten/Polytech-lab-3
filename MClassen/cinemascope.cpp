#include "cinemascope.h"
#include "stack.h"
#include "queue.h"
#include "deque.h"

void Scope::overallMenu(int b) {

	std::cout << "Enter a command: \n";
	std::cout << "esc - Return back\n";
	std::cout << "1 - Read from file\n";
	std::cout << "2 - Write in a file\n";
	std::cout << "3 - Clear\n";
	std::cout << "4 - Insert item\n";
	std::cout << "5 - Delete item\n";
	std::cout << "6 - Get the length of the list\n";
	std::cout << "7 - Print \n";
	std::cout << "8 - Sort \n";
	std::cout << "9 - Search \n";

	switch (b) {
		case 1:
			std::cout << "a - Push Front \n";
			std::cout << "b - Push Back \n";
			std::cout << "c - Pop Front \n";
			std::cout << "d - Pop Back \n";
			break;
		case 2:
			std::cout << "a - Push Back \n";
			std::cout << "b - Pop Back \n";
			break;
		case 3:
			std::cout << "a - Push Back \n";
			std::cout << "b - Pop Front \n";
		default:
			break;
	}
}

int Scope::overallChoose(char c, int b, list::clist& x){
	int item = 0;
	int position = 0;

	if (tolower(c) == 27)
		return -1;
	else if (tolower(c) == '1') {
		if (!x.Read())
			std::cout << "::: Done!" << std::endl;
	}
	else if (tolower(c) == '2') {
		if (!x.Write())
			std::cout << "::: Done!" << std::endl;
	}
	else if (tolower(c) == '3') {
		if (!x.Free())
			std::cout << "::: Done!" << std::endl;
	}
	else if (tolower(c) == '4') {
		std::cout << "::: Insert -> Input Item: ";
		while (!(std::cin >> item) || std::cin.get() != '\n')
		{
			std::cin.clear();
			std::cin.sync();
			std::cin.ignore(10000, '\n');
			std::cout << "::: Insert -> Input Position: ";
		}

		std::cout << "::: Insert -> Input Position: ";
		while (!(std::cin >> position) || std::cin.get() != '\n')
		{
			std::cin.clear();
			std::cin.sync();
			std::cin.ignore(10000, '\n');
			std::cout << "::: Insert -> Input Position: ";
		}

		if (!x.Insert(item, position))
			std::cout << "::: Done" << std::endl;
	}
	else if (tolower(c) == '5') {
		std::cout << "::: Delete -> Input Position: ";
		while (!(std::cin >> position) || std::cin.get() != '\n')
		{
			std::cin.clear();
			std::cin.sync();
			std::cin.ignore(10000, '\n');
			std::cout << "::: Delete -> Input Position: ";
		}
		if (x.Delete(position))
			std::cout << "::: Done" << std::endl;
	}
	else if (tolower(c) == '6') {
		std::cout << "::: Len: " << x.Len() << std::endl;
	}
	else if (tolower(c) == '7') {
		x.Output();
	}
	else if (tolower(c) == '8') {
		if (!x.Sort())
			std::cout << "::: Done!" << std::endl;
	}
	else if (tolower(c) == '9') {
		std::cout << "::: Search -> Input Value: ";
		while (!(std::cin >> item) || std::cin.get() != '\n')
		{
			std::cin.clear();
			std::cin.sync(); std::cin.ignore(10000, '\n');
			std::cout << "::: Insert -> Input Position: ";
		}
		int resultSearch = x.Search(item);
		if (resultSearch >= 0) {
			std::cout << "::: Search -> Position: " << resultSearch << std::endl;
			std::cout << "::: Done" << std::endl;
		}
	}
	else
		return 0;
	return 1;
}

void Scope::deque(list::deque& x) {
	while (1) {

		std::cout << "# DEQUE" << std::endl;
		Scope::overallMenu(1);

		std::cout << ">>> ";
		char d = _getch();
		std::cout << d << std::endl;

		bool returnBack = false;
		int item = 0;
		int position = 0;

		system("cls");
		switch (Scope::overallChoose(d, 1, x)){
			case -1:
				returnBack = true;
				break;
			case 0:
				switch (tolower(d)){
					case 'a':
						std::cout << "::: PushFront -> Enter value: ";

						while (!(std::cin >> item) || std::cin.get() != '\n')
						{
							std::cin.clear();
							std::cin.sync();std::cin.ignore(10000,'\n');

							std::cout << "::: PushFront -> Enter value ";
						}

						if (!x.PushFront(item))
							std::cout << "::: Done!" << std::endl;
						break;
					case 'b':
						std::cout << "::: PushBack -> Enter value: ";
						while (!(std::cin >> item) || std::cin.get() != '\n')
						{
							std::cin.clear();
							std::cin.sync();std::cin.ignore(10000,'\n');
							std::cout << "::: PushBack -> Enter value: ";
						}

						if (!x.Push(item))
							std::cout << "::: Done!" << std::endl;
						break;

					case 'c':
						std::cout << "::: PopFront -> The obtained value: " << x.PopFront() << std::endl;
						break;
					case 'd':
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
		std::cout << "_______________________" << std::endl;
		if (returnBack)
			break;
	}
}

void Scope::stack(list::stack& x) {
	while (1) {
		std::cout << "# STACK" << std::endl;
		Scope::overallMenu(2);

		std::cout << ">>> ";
		char d = _getch();
		std::cout << d << std::endl;

		bool returnBack = false;
		int item = 0;

		system("cls");
		switch (Scope::overallChoose(d, 2, x)) {
			case -1:
				returnBack = true;
				break;
			case 0:
				switch (tolower(d)) {
				case 'a':
					std::cout << "::: Push (Back) -> Enter value: ";
					while (!(std::cin >> item) || std::cin.get() != '\n')
					{
						std::cin.clear();
						std::cin.sync();std::cin.ignore(10000,'\n');
						std::cout << "::: Push (Back) -> Enter value: ";
					}
					if (x.Push(item))
						std::cout << "::: Done!" << std::endl;
					break;
				case 'b':
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
		std::cout << "_______________________" << std::endl;
		if (returnBack)
			break;

	}
}

void Scope::queue(list::queue& x) {
	while (1) {
		std::cout << "# QUEUE" << std::endl;
		Scope::overallMenu(3);

		std::cout << ">>> ";
		char d = _getch();
		std::cout << d << std::endl;

		bool returnBack = false;
		int item = 0;

		system("cls");
		switch (Scope::overallChoose(d, 3, x)) {
		case -1:
			returnBack = true;
			break;
		case 0:
			switch (tolower(d)) {
			case 'a':
				std::cout << "::: Push (Back) -> Enter value: "; 
				while (!(std::cin >> item) || std::cin.get() != '\n')
				{
					std::cin.clear();
					std::cin.sync();std::cin.ignore(10000,'\n');
					std::cout << "::: Push (Back) -> Enter value: ";
				}

				if (!x.Push(item))
					std::cout << "::: Done!" << std::endl;
				break;

			case 'b':
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
		std::cout << "_______________________" << std::endl;
		if (returnBack)
			break;
	}
}