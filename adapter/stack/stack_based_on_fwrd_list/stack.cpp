#include <iostream>
#include<string>
#include "forward_list.h"
#include "stack.h"
using namespace std;

template class Stack<int>;
template class Stack<double>;
template class Stack<float>;

using namespace std;


template <typename T>
void Stack<T>::push(Node<T>* item) {
	this->push_back(item);
}
template <typename T>
void Stack<T>::pop() {
	this->pop_back();
}
template <typename T>
T Stack<T>::top() {
	return this->last();
}