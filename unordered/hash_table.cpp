#include "forward_list.h"
#include "vector.h"
#include "hash_table.h"
#include <iostream>

template class Hash_Table<int>;
template class Hash_Table<double>;
template class Hash_Table<float>;

template <typename T>
Hash_Table<T>::Hash_Table() {
	std::cout << "Default c-tor" << std::endl;
	m_size = 0;
};

template <typename T>
void Hash_Table<T>::insert(T value) {
	int index = hash_function(value);
	Node<T>* node = new Node<T>();
	node->value = value;

	if (m_size > index) {
		m_table[index].add_front(node);
	}
	else {
		Forward_List<T> fwd_list;
		fwd_list.add_front(node);
		m_table.push_back(fwd_list);
		m_size++;
	}
};

template <typename T>
int Hash_Table<T>::hash_function(T key) {
	return (key / 7);
}

template <typename T>
void Hash_Table<T>::print() {
	for (int i = 0; i < m_table.size(); i++) {
		m_table[i].print();
		std::cout << std::endl;
	}
};