
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "array.h"

void check_array() {
	std::cout << std::endl;

	Array<int> arr_i;
	std::cout << "Array of 10 elements: " << std::endl;
	arr_i.print();

	std::cout << std::endl;
	arr_i.push_back(1000);
	std::cout << "Array after call push_back(...): " << std::endl;
	arr_i.print();
	std::cout << std::endl;
	arr_i.pop_back();
	std::cout << "Array after call pop_back(): " << std::endl;
	arr_i.print();
	std::cout << std::endl;
}


int main() {
	srand(time(NULL));
	check_array();
	return 0;
}
