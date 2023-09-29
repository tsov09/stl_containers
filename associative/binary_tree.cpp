#include <iostream>
#include "binary_tree.h"

template class Binary_Tree<int>;
template class Binary_Tree<double>;
template class Binary_Tree<float>;

template <typename T>
Binary_Tree<T>::Binary_Tree() : m_root(nullptr) {};

template <typename T>
void Binary_Tree<T>::set_root(Node<T>* r) {
	m_root = r;
}

template <typename T>
Node<T>* Binary_Tree<T>::get_root() {
	return m_root;
}

template <typename T>
void Binary_Tree<T>::inorder(Node<T>* root) {
	if (root->left) {
		inorder(root->left);
	}
	std::cout << root->value << " ";
	if (root->right) {
		inorder(root->right);
	}
}

template <typename T>
void Binary_Tree<T>::preorder(Node<T>* root) {
	std::cout << root->value << " ";
	if (root->left) {
		preorder(root->left);
	}
	if (root->right) {
		preorder(root->right);
	}
}

template <typename T>
void Binary_Tree<T>::postorder(Node<T>* root) {
	if (root->left) {
		postorder(root->left);
	}
	if (root->right) {
		postorder(root->right);
	}
	std::cout << root->value << " ";
}

template <typename T>
void Binary_Tree<T>::layer_by_layer(Node<T>* root) {
	if (root == m_root) {
		std::cout << root->value << " ";
	}
	if (root->left) {
		std::cout << root->left->value << " ";
	}
	if (root->right) {
		std::cout << root->right->value << " ";
	}
	else {
		return;
	}
	layer_by_layer(root->left);
	layer_by_layer(root->right);
}

template <typename T>
void Binary_Tree<T>::insert(Node<T>* item) {
	if (!m_root) {
		m_root = item;
	}
	else {
		recursion_insert(m_root, item);
	}
}

template <typename T>
void Binary_Tree<T>::recursion_insert(Node<T>* root, Node<T>* item) {
	if (!root->left) {
		root->left = item;
		return;
	}
	else if (!root->right) {
		root->right = item;
		return;
	}
	else if (root->left) {
		recursion_insert(root->left, item);
	}
	else {
		recursion_insert(root->right, item);
	}
}
