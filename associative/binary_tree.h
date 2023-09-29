#pragma once
#include <iostream>
template <class T>
struct Node {
	Node* left = nullptr;
	Node* right = nullptr;
	T value;
};

template <class T>
class Binary_Tree {
	Node<T>* m_root;
public:
	Binary_Tree();
	void set_root(Node<T>*);
	Node<T>* get_root();
	void inorder(Node<T>*);
	void preorder(Node<T>*);
	void postorder(Node<T>*);
	void layer_by_layer(Node<T>*);
	void insert(Node<T>*);
private:
	void recursion_insert(Node<T>* root, Node<T>*);
};
