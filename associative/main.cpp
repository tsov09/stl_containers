#include <iostream>
#include "binary_tree.h"

void check_binary_tree_traversals();

int main() {
	check_binary_tree_traversals();
	return 0;
}

void check_binary_tree_traversals() {

	Node<int>* n1 = new Node<int>();
	Node<int>* n2 = new Node<int>();
	Node<int>* n3 = new Node<int>();
	Node<int>* n4 = new Node<int>();
	Node<int>* n5 = new Node<int>();
	Node<int>* n6 = new Node<int>();
	Node<int>* n7 = new Node<int>();


	n1->value = 15;
	n2->value = 71;
	n3->value = 62;
	n4->value = 81;
	n5->value = 26;
	n6->value = 41;
	n7->value = 96;

	Binary_Tree<int>* bin_tree = new Binary_Tree<int>();
	bin_tree->insert(n1);
	bin_tree->insert(n2);
	bin_tree->insert(n3);
	bin_tree->insert(n4);
	bin_tree->insert(n5);
	bin_tree->insert(n6);
	bin_tree->insert(n7);


	std::cout << "The tree:" << std::endl << "          " << n1->value << "        "
		<< std::endl << "    " << n2->value << "          " << n3->value << "    "
		<< std::endl << "" << n4->value << "      " << n5->value << "  " << n6->value << "      " << n7->value << "" << std::endl << std::endl;


	Node<int>* bin_tree_root = bin_tree->get_root();
	std::cout << "Inorder: " << std::endl;
	bin_tree->inorder(bin_tree_root);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Preorder: " << std::endl;
	bin_tree->preorder(bin_tree_root);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Postorder: " << std::endl;
	bin_tree->postorder(bin_tree_root);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Layer by layer: " << std::endl;
	bin_tree->layer_by_layer(bin_tree_root);
	std::cout << std::endl;
	std::cout << std::endl;
}