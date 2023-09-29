#include <iostream>
#include<string>
#include "forward_list.h"
using namespace std;


void checking_forward_list();
void check_bubble_sort();

int main() {
	checking_forward_list();

	return 0;
}




void checking_forward_list() {
	Node<int>* n_1 = new Node<int>;
	n_1->value = 7;

	Node<int>* n_2 = new Node<int>;
	n_2->value = 11;
	Node<int>* n_3 = new Node<int>;
	n_3->value = 18;
	Node<int>* n_4 = new Node<int>;
	n_4->value = 89;

	Forward_List<int>* list = new Forward_List<int>;
	list->push_back(n_1);
	list->push_back(n_2);
	list->push_back(n_3);
	list->push_back(n_4);
	cout << "Forward list after push_back(...) 4 times: ";
	list->print();
	cout << endl;

	list->pop_back();
	cout << "Forward list after single pop_back(): ";
	list->print();
	cout << endl;


	list->insert(2, n_4);
	cout << "Forward list after insert(2, ...): ";
	list->print();
	cout << endl;

	list->reverse();
	cout << "Forward list after reverse(): ";
	list->print();
	cout << endl;

	list->pop_front();
	cout << "Forward list after single pop_front(): ";
	list->print();
	cout << endl;


	list->buble_sort();
	cout << "Sorted forward: ";
	list->print();
	cout << endl;

	int n = 3;
	Node<int>* val = list->find_n_th_from_end(n);
	if (val) {
		cout << n << "-th from the end element's value is " << val->value << "." << endl;
	}
	cout << endl;



	cout << "Checking if ";
	list->print();
	cout << " forward list is cycled." << endl;

	if (list->is_cycled()) {
		cout << "Forward list is cycled." << endl;
	}
	else {
		cout << "Forward list isn't cycled." << endl;
	}
	cout << endl;

	cout << "End: " << list->last() << endl;

	list->push_back(n_2);
	cout << "Checking if forward list is cycled after push_back(...) element which already exists in list." << endl;

	if (list->is_cycled()) {
		cout << "Forward list is cycled." << endl;
	}
	else {
		cout << "Forward list isn't cycled." << endl;
	}

	delete n_1, n_2, n_3, n_4, list;

}

void check_bubble_sort() {
	Node<int>* n_1 = new Node<int>;
	n_1->value = 7;
	Node<int>* n_2 = new Node<int>;
	n_2->value = 11;
	Node<int>* n_3 = new Node<int>;
	n_3->value = 18;
	Node<int>* n_4 = new Node<int>;
	n_4->value = 89;
	Node<int>* n_5 = new Node<int>;
	n_5->value = 12;

	Forward_List<int>* list = new Forward_List<int>;
	list->push_back(n_1);
	list->push_back(n_2);
	list->push_back(n_4);
	list->push_back(n_5);
	list->push_back(n_3);
	list->print();
	cout << endl;
	list->buble_sort();
	list->print();
}