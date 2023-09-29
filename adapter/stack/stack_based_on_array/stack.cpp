#include <iostream>

#include "array.h"
#include "stack.h"

template class Stack<int>;
template class Stack<float>;
template class Stack<double>;

template <typename T>
void Stack<T>::push(T item) {
	this->push_back(item);
}

template <typename T>
void Stack<T>::pop() {
	this->pop_back();
}

template <typename T>
T Stack<T>::top() {
	return this->gen_element(this->length() - 1);
}