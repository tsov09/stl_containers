#include <iostream>
#include<string>
#include "forward_list.h"
#include "stack.h"
using namespace std;

template class Forward_List<int>;
template class Forward_List<double>;
template class Forward_List<float>;

using namespace std;

template <typename T>
Forward_List<T>::Forward_List() : head(nullptr) {};

template <typename T>
void Forward_List<T>::add_front(Node<T>* item) {
	item->next = head;
	head = item;
}
template <typename T>
void Forward_List<T>::pop_front() {
	head = head->next;
}
template <typename T>
void Forward_List<T>::push_back(Node<T>* item) {
	if (head == nullptr) {
		head = item;
		return;
	}
	Node<T>* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = item;
}
template <typename T>
void Forward_List<T>::pop_back() {
	if (head == nullptr) {
		cout << "Forward list is empty." << endl;
		return;
	}
	else if (head->next == nullptr) {
		head = nullptr;
		return;
	}
	else {
		Node<T>* temp = head;
		while (temp->next->next != nullptr) {
			temp = temp->next;
		}
		temp->next = nullptr;
	}
}
template <typename T>
void Forward_List<T>::insert(int position, Node<T>* item) {
	Node<T>* temp = head;
	if (position == 0) {
		head = item;
		head->next = temp;
	}
	else if (position > 0) {
		for (int i = 0; i < position - 1; i++) {
			if (temp->next == nullptr) {
				cout << "The number is out of range." << endl;
				return;
			}
			temp = temp->next;
		}

		item->next = temp->next;
		temp->next = item;
	}
	else {
		cout << "The number can't be negative." << endl;
	}
}
template <typename T>
void Forward_List<T>::reverse() {
	if (head == nullptr || head->next == nullptr) {
		return;
	}
	Node<T>* temp = head;
	Node<T>* temp_next = head->next;
	Node<T>* tmp;
	while (temp_next != nullptr) {
		tmp = temp_next->next;
		temp_next->next = temp;
		temp = temp_next;
		temp_next = tmp;
	}
	head->next = nullptr;
	head = temp;
}
template <typename T>
Node<T>* Forward_List<T>::find_n_th_from_end(int n) {
	if (n < 1) {
		cout << "The number must be greather than 0." << endl;
		return nullptr;
	}
	int step = 1;
	Node<T>* temp = head;
	Node<T>* n_th = head;
	while (temp->next != nullptr) {
		temp = temp->next;
		step++;
		if (step > n) {
			n_th = n_th->next;
		}
	}
	if (n <= step) {
		return n_th;
	}
	else {
		cout << "The number is greather than forward list's size" << endl;
		return nullptr;
	}
}
template <typename T>
bool Forward_List<T>::is_cycled() {
	if (head == nullptr || head->next == nullptr) {
		return false;
	}

	Node<T>* temp = head;
	Node<T>* temp_next = head;
	while (temp_next->next != nullptr) {
		temp = temp->next;
		temp_next = temp_next->next->next;
		if (temp_next->next == temp || temp_next == temp) {
			return true;
		}
	}
	return false;
}
template <typename T>
T Forward_List<T>::last() {
	Node<T>* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	return temp->value;
}
template <typename T>
T Forward_List<T>::first() {
	return head->value;
}
template <typename T>
void Forward_List<T>::buble_sort() {
	bool sorted = true;
	Node<T>* temp_1 = head;
	while (true) {
		if (head->value > head->next->value) {
			temp_1 = temp_1->next;
			head->next = temp_1->next;
			temp_1->next = head;
			head = temp_1;
			//sorted = false;
		}
		temp_1 = head;
		while (temp_1->next->next != nullptr) {
			if (temp_1->next->value > temp_1->next->next->value) {
				sorted = false;
				Node<T>* temp_3 = temp_1->next->next;
				temp_1->next->next = temp_3->next;
				temp_3->next = temp_1->next;
				temp_1->next = temp_3;
			}
			temp_1 = temp_1->next;
		}
		if (sorted) {
			break;
		}
		temp_1 = head;
		sorted = true;
	}

}
template <typename T>
void Forward_List<T>::print() {
	if (head == nullptr) {
		cout << "Forward list is empty." << endl;
		return;
	}
	Node<T>* temp = head;
	cout << "{ ";
	while (temp->next != nullptr) {
		cout << temp->value << ", ";
		temp = temp->next;
	}
	cout << temp->value << " }";
}