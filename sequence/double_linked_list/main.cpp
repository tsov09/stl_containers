#include <iostream>
#include "list.h"
using namespace std;

void check_double_linked_list() {
	Node<int>* n_1 = new Node<int>;
	n_1->value = 7;

	Node<int>* n_2 = new Node<int>;
	n_2->value = 11;
	Node<int>* n_3 = new Node<int>;
	n_3->value = 18;
	Node<int>* n_4 = new Node<int>;
	n_4->value = 89;

	List<int>* list = new List<int>;
	list->push_back(n_1);
	list->push_back(n_2);
	list->push_back(n_4);
	list->push_back(n_3);
	cout << "push_back(...) 7, 11, 89, 18: ";
	list->print();
	cout << endl;
	cout << "pop_back(): ";
	list->pop_back();
	list->print();
	cout << endl;
	list->add_front(n_3);
	cout << "add_front() 18: ";
	list->print();
	cout << endl;
	list->pop_front();
	cout << "pop_front(): ";
	list->print();
	cout << endl;
	list->insert(2, n_3);
	cout << "insert(2, ) 18: ";
	list->print();
	cout << endl;
	cout << "print_from_end(): ";
	list->print_from_end();
	cout << endl;
	delete n_1, n_2, n_3, n_4, list;
}

int main() {
	check_double_linked_list();

	return 0;
}