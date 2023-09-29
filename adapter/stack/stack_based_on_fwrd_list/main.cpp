#include <iostream>
#include<string>
#include "forward_list.h"
#include "stack.h"

using namespace std;

void check_stack();

int main() {
	check_stack();
	return 0;
}

void check_stack() {
	Node<int>* node = new Node<int>();
	node->value = 27;

	Node<int>* n_1 = new Node<int>;
	n_1->value = 64;

	Node<int>* n_2 = new Node<int>;
	n_2->value = 158;

	Stack<int>* stack = new Stack<int>();

	cout << "Stack:" << endl;
	stack->push(node);
	cout << "Top after push(...) 27: " << stack->top() << endl;
	stack->push(n_1);
	cout << "Top after push(...) 64: " << stack->top() << endl;
	stack->pop();
	cout << "Top after pop(): " << stack->top() << endl;
}