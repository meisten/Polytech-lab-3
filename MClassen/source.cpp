#include "cinemascope.h"

int main(int argc, char** argv) {

	while (1) {
		std::cout << "Choose the list-type: \n";
		std::cout << "1 - Deque \n";
		std::cout << "2 - Stack \n";
		std::cout << "3 - Queue \n";
		std::cout << "esc - EXIT \n";
		std::cout << ">>> ";
		char command = _getch();
		std::cout << command << std::endl;

		if (command == 27)
			return 0;
		else if (command == '1') {
			system("cls");
			list::deque x;
			Scope::deque(x);
		}
		else if (command == '2') {
			system("cls");
			list::stack x;
			Scope::stack(x);
		}
		else if (command == '3') {
			system("cls");
			list::queue x;
			Scope::queue(x);
		}
		else
			std::cout << "# Traceback (OPERATION): wrong command \n";
		
	}
	return 0;
}