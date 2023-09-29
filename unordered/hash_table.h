#pragma once

#include "forward_list.h"
#include "vector.h"

template <class T>
class Hash_Table {
public:
	int m_size;
	Vector<Forward_List<T>> m_table;
	Hash_Table();
	int hash_function(T key);
	void insert(T value);
	void print();
};


