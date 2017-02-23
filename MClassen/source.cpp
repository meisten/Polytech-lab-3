#include "cinemascope.h"

int main() {

	while (1) {
		std::cout << "Choose the list-type: \n";
		std::cout << "1 - Deque \n";
		std::cout << "2 - Stack \n";
		std::cout << "3 - Queue \n";
		std::cout << "0 - EXIT \n";
		std::cout << ">>> ";
		char command = _getch();
		std::cout << command << std::endl;

		if (command == '0')
			return 0;
		else if (command == '1') {
			std::cout << "# DEQUE" << std::endl;
			list::deque x;
			Scope::deque(x);
		}
		else if (command == '2') {
			std::cout << "# STACK" << std::endl;
			list::stack x;
			Scope::stack(x);
		}
		else if (command == '3') {
			std::cout << "# QUEUE" << std::endl;
			list::queue x;
			Scope::queue(x);
		}
		else
			std::cout << "# Traceback (OPERATION): wrong command \n";
		
	}
	system("pause");
	return 0;
}