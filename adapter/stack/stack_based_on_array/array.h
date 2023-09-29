#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>


template <class T>
class Array {
public:
	Array();
	Array(int);
	~Array();
	Array(const Array<T>&);
	Array(Array<T>&&);
	Array<T>& operator = (const Array<T>&);
	Array<T>& operator = (Array<T>&&);
	T& operator[] (int);
private:
	T* ptr;
	int size;
	void fill_array();
public:
	T gen_element(int);
	void push_back(T);
	void pop_back();
	int length();
	void print();
};