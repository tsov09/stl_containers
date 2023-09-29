#include "queue.h"

template class Queue<int>;
template class Queue<double>;
template class Queue<float>;

template <typename T>
void Queue<T>::enqueue(Node<T>* item) {
	this->add_front(item);
}
template <typename T>
void Queue<T>::pop() {
	this->pop_back();
}
template <typename T>
T Queue<T>::front() {
	return this->first();
}
template <typename T>
T Queue<T>::back() {
	return this->last();
}