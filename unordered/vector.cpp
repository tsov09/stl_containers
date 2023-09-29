#include <iostream>
#include<string>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>

#include "vector.h"
#include "forward_list.h"


template class Vector<int>;
template class Vector<double>;
template class Vector<float>;
template class Vector<Forward_List<int>>;
template class Vector<Forward_List<double>>;
template class Vector<Forward_List<float>>;



template <typename T>
Vector<T>::Vector() : m_size(0), m_capacity(0) {};
template <typename T>
Vector<T>::~Vector() {
	delete[] m_ptr;
}
template <typename T>
Vector<T>::Vector(const Vector<T>& obj) {
	m_size = obj.m_size;
	m_ptr = new T[m_size];
	for (int i = 0; i < m_size; i++) {
		m_ptr[i] = obj.m_ptr[i];
	}
}
template <typename T>
Vector<T>::Vector(Vector<T>&& obj) {
	std::cout << "Vector move con-tor" << std::endl;
	m_size = obj.m_size;
	m_ptr = obj.m_ptr;
	obj.m_ptr = nullptr;
	obj.m_size = 0;
}
template <typename T>
Vector<T>& Vector<T>::operator = (const Vector<T>& obj) {
	if (this != &obj) {
		delete[] m_ptr;
		m_ptr = nullptr;
		m_size = obj.m_size;
		m_ptr = new T[m_size];
		for (int i = 0; i < m_size; i++) {
			m_ptr[i] = obj.m_ptr[i];
		}
	}
	return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator = (Vector<T>&& obj) {
	std::cout << "Vector op. move assign." << std::endl;
	if (this != &obj) {
		delete[] m_ptr;
		m_ptr = nullptr;
		m_size = obj.m_size;
		m_ptr = obj.m_ptr;
		obj.m_ptr = nullptr;
		obj.m_size = 0;
	}
	return *this;
}
template <typename T>
T& Vector<T>::operator[] (int i) {
	if (i >= m_size || i < 0) {
		std::cout << "The number is out of range" << std::endl << std::endl;
		exit(0);
	}
	else {
		return m_ptr[i];
	}
}
template <typename T>
int Vector<T>::size() {
	return m_size;
}
template <typename T>
T Vector<T>::gen_element(int x) {
	if (x >= m_size || x < 0) {
		std::cout << "The index is out of range" << std::endl << std::endl;
		exit(0);
	}
	else {
		return m_ptr[x];
	}
}
template <typename T>
void Vector<T>::push_back(const T& item) {
	m_size++;
	if (m_size - 1 == m_capacity) {
		m_capacity = m_size * 2;
		T* temp = m_ptr;
		m_ptr = new T[m_capacity];
		for (int i = 0; i < m_size - 1; i++) {
			m_ptr[i] = temp[i];
		}
		delete[] temp;
		temp = nullptr;

	}
	m_ptr[m_size - 1] = item;
}
template <typename T>
void Vector<T>::insert(int index, const T& item) {
	if (index == m_size) {
		push_back(item);
	}
	else if (index < m_size&& index >= 0) {
		m_size++;
		if (m_size - 1 == m_capacity) {
			m_capacity = m_size * 2;
			T* temp = m_ptr;
			m_ptr = new T[m_capacity];
			for (int i = 0; i < index; i++) {
				m_ptr[i] = temp[i];
			}
			for (int i = m_size - 1; i > index; i--) {
				m_ptr[i] = temp[i - 1];
			}
			m_ptr[index] = item;
			delete[] temp;
			temp = nullptr;

		}
		else {
			for (int i = m_size - 1; i > index; i--) {
				m_ptr[i] = m_ptr[i - 1];
			}
			m_ptr[index] = item;
		}
	}
	else {
		std::cout << "Invalid index for insert: " << index << "." << std::endl;
	}
}
template <typename T>
void Vector<T>::pop_back() {
	if (m_size > 0) {
		m_size--;
	}
	else {
		std::cout << "The vector is empty." << std::endl;
	}
}
template <typename T>
void Vector<T>::erase(int index) {
	if (index == m_size - 1) {
		m_size--;
	}
	else if (index < m_size - 1 && index >= 0) {
		for (int i = index; i < m_size; i++) {
			m_ptr[i] = m_ptr[i + 1];
		}
		m_size--;

	}
	else {
		std::cout << "Invalid index for erase: " << index << "." << std::endl;
	}
}
template <typename T>
void Vector<T>::clear() {
	m_size = 0;
}
//template <typename T>
//void Vector<T>::print() {
//	if (m_size > 0) {
//		std::cout << "{ ";
//		for (int i = 0; i < m_size - 1; i++) {
//			std::cout << m_ptr[i] << ", ";
//		}
//		std::cout << m_ptr[m_size - 1] << " }";
//	}
//	else {
//		std::cout << "The vector is empty." << std::endl;
//	}
//}
template <typename T>
void Vector<T>::swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
//template <typename T>
//void Vector<T>::buble_sort() {
//	bool sorted = true;
//	for (int g = 0; g < m_size - 1; g++) {
//		for (int i = 0; i < m_size - 1;) {
//			if (m_ptr[i] > m_ptr[i + 1]) {
//				swap(m_ptr[i], m_ptr[i + 1]);
//				sorted = false;
//			}
//			else {
//				i++;
//			}
//		}
//		if (sorted) {
//			break;
//		}
//		sorted = true;
//	}
//}