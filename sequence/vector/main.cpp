
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
#include <string>

#include "vector.h"

void print_unrdered_set(std::unordered_set<int> set_i) {
	for (int item : set_i) {
		std::cout << item << " ";
	}
}

int main() {

	srand(time(NULL));
	Vector<int> vector;
	vector.push_back(47);
	vector.push_back(10);
	vector.push_back(46);
	vector.push_back(45);
	vector.push_back(12);
	vector.push_back(17);
	vector.push_back(57);
	vector.push_back(-1);
	std::cout << std::endl;


	std::cout << "Vector after push_back(...) 8 times: " << std::endl;
	vector.print();
	std::cout << std::endl;
	std::cout << std::endl;


	vector.merge_sort();
	std::cout << "Vector after merge_sort(): " << std::endl;
	vector.print();
	std::cout << std::endl;
	std::cout << std::endl;



	std::cout << "Trying to get 20-th element in vector: " << std::endl;
	try {
		std::cout << vector.at(20) << std::endl;
	}
	catch (...) {
		std::cout << "The index is out of range." << std::endl << std::endl;
	}
	return 0;
}


