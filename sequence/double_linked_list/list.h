#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T value;
	Node* next = nullptr;
	Node* previous = nullptr;
};

template <typename T>
class List {
	Node<T>* head;
	Node<T>* end;
public:
	List();
	void add_front(Node<T>*);
	void pop_front();
	void push_back(Node<T>*);
	void pop_back();
	void insert(int, Node<T>*);
	void print();
	void print_from_end();
};
