#pragma once
template <typename T>
struct Node {
	T value;
	Node* next = nullptr;
};

template <typename T>
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