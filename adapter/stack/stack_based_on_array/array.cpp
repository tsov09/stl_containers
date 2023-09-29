#include <iostream>

#include "array.h"

template class Array<int>;
template class Array<float>;
template class Array<double>;


template <typename T>
Array<T>::Array() {
	this->size = 10;
	this->ptr = new T[this->size];
	this->fill_array();
}

template <typename T>
Array<T>::Array(int size) {
	this->size = size;
	this->ptr = new T[this->size];
	this->fill_array();
}

template <typename T>
Array<T>::~Array() {
	delete[] this->ptr;
}

template <typename T>
Array<T>::Array(const Array<T>& obj) {
	this->size = obj.size;
	this->ptr = new T[this->size];
	for (int i = 0; i < this->size; i++) {
		this->ptr[i] = obj.ptr[i];
	}
}

template <typename T>
Array<T>::Array(Array<T>&& obj) {
	std::cout << "Array move con-tor" << std::endl;
	this->size = obj.size;
	this->ptr = obj.ptr;
	obj.ptr = nullptr;
	obj.size = 0;
}

template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& obj) {
	if (this != &obj) {
		delete[] this->ptr;
		this->ptr = nullptr;
		this->size = obj.size;
		this->ptr = new T[this->size];
		for (int i = 0; i < this->size; i++) {
			this->ptr[i] = obj.ptr[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>& Array<T>::operator = (Array<T>&& obj) {
	std::cout << "Array op. move assign." << std::endl;
	if (this != &obj) {
		delete[] this->ptr;
		this->ptr = nullptr;
		this->size = obj.size;
		this->ptr = obj.ptr;
		obj.ptr = nullptr;
		obj.size = 0;
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[] (int i) {
	if (i >= this->size || i < 0) {
		std::cout << "The number is out of range" << std::endl << std::endl;
		exit(0);
	}
	else {
		return this->ptr[i];
	}
}

template <typename T>
void Array<T>::fill_array() {
	for (int i = 0; i < this->size; i++) {
		this->ptr[i] = rand() % 100 + 10;
	}
}

template <typename T>
T Array<T>::gen_element(int x) {
	if (x >= this->size || x < 0) {
		std::cout << "The number is out of range" << std::endl << std::endl;
		exit(0);
	}
	else {
		return this->ptr[x];
	}
}

template <typename T>
void Array<T>::push_back(T item) {
	this->size++;
	T* temp_ptr = this->ptr;
	this->ptr = new T[this->size];
	for (int i = 0; i < this->size - 1; i++) {
		this->ptr[i] = temp_ptr[i];
	}
	this->ptr[this->size - 1] = item;
	delete[] temp_ptr;
	temp_ptr = nullptr;
}

template <typename T>
void Array<T>::pop_back() {
	this->size--;
	T* temp_ptr = this->ptr;
	this->ptr = new T[this->size];
	for (int i = 0; i < this->size; i++) {
		this->ptr[i] = temp_ptr[i];
	}
	//this->ptr[this->size - 1] = item;
	delete[] temp_ptr;
	temp_ptr = nullptr;
}

template <typename T>
int Array<T>::length() {
	return this->size;
}

template <typename T>
void Array<T>::print() {
	std::cout << "{ ";
	for (int i = 0; i < this->size - 1; i++) {
		std::cout << this->ptr[i] << ", ";
	}
	std::cout << this->ptr[this->size - 1] << " }";

}
