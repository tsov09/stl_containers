#include <iostream>
#include "list.h"

template class List<int>;
template class List<float>;
template class List<double>;


template <typename T>
List<T>::List() : head(nullptr), end(nullptr) {};

template <typename T>
void List<T>::add_front(Node<T>* item) {
	item->next = head;
	head->previous = item;
	head = item;
}

template <typename T>
void List<T>::pop_front() {
	head = head->next;
	head->previous = nullptr;
}

template <typename T>
void List<T>::push_back(Node<T>* item) {
	if (head == nullptr) {
		head = item;
		return;
	}
	Node<T>* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	item->previous = temp;
	temp->next = item;
	end = item;
}

template <typename T>
void List<T>::pop_back() {
	if (head == nullptr) {
		cout << "List is empty." << endl;
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
		end = temp;
	}
}

template <typename T>
void List<T>::insert(int position, Node<T>* item) {
	Node<T>* temp = head;
	if (position == 0) {
		head->previous = item;
		head = item;
		head->next = temp;
		head->previous = nullptr;
	}
	else if (position > 0) {
		for (int i = 0; i < position - 1; i++) {
			if (temp->next == nullptr) {
				cout << "Number is out of range" << endl;
				return;
			}
			temp = temp->next;
		}
		if (temp->next != nullptr) {
			temp->next->previous = item;
		}
		else {
			end = item;
		}
		item->next = temp->next;
		temp->next = item;
		item->previous = temp;

	}
	else {
		cout << "The number must be positive." << endl;
	}
}

template <typename T>
void List<T>::print() {
	if (head == nullptr) {
		cout << "List is empty." << endl;
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

template <typename T>
void List<T>::print_from_end() {
	if (head == nullptr) {
		cout << "List is empty." << endl;
		return;
	}
	else if (end == nullptr) {
		cout << "{ " << head->value << " }";
	}
	else {
		Node<T>* temp = end;
		cout << "{ ";
		while (temp->previous != nullptr) {
			cout << temp->value << ", ";
			temp = temp->previous;
		}
		cout << temp->value << " }";
	}
}