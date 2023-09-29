#pragma once
#include "array.h"
template <typename T>
class Stack : private Array<T> {
public:
	void push(T);
	void pop();
	T top();
};