#pragma once
#include "forward_list.h"
template <typename T>
class Stack : private Forward_List<T> {
public:
	void push(Node<T>*);
	void pop();
	T top();
};