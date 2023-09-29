#pragma once
#include "forward_list.h"

template <typename T>
class Queue : private Forward_List<T> {
public:
	void enqueue(Node<T>*);
	void pop();
	T front();
	T back();
};