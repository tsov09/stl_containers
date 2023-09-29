#pragma once

template <class T>

class Node {
	public:
	T value;
	Node* next = nullptr;
};

template <class T>
class Forward_List {
	Node<T>* head;

public:
	Forward_List();
	void add_front(Node<T>*);
	void pop_front();
	void push_back(Node<T>*);
	void pop_back();
	void insert(int, Node<T>*);
	void reverse();
	Node<T>* find_n_th_from_end(int);
	bool is_cycled();
	T last();
	T first();
	void buble_sort();
	void print();
};
