#pragma once

template <class T>
class Vector {
public:
	Vector();
	~Vector();
	Vector(const Vector<T>& obj);
	Vector(Vector<T>&& obj);
	Vector<T>& operator = (const Vector<T>& obj);
	Vector<T>& operator = (Vector<T>&& obj);
	T& operator[] (int i);
private:
	T* m_ptr;
	int m_size;
	int m_capacity;
public:
	int size();
	T gen_element(int x);
	void push_back(const T& item);
	void insert(int index, const T& item);
	void pop_back();
	void erase(int index);
	void clear();
	//void print();
	void swap(T&,T&);
	//void buble_sort();
};