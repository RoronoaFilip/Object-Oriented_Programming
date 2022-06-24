/*
* LinkedStack.cpp
*/

#include "LinkedStack.h"

#include <iostream>
using namespace std;

LinkedStack::LinkedStack() {
	top = NULL;
}

void LinkedStack::deleteStack() {
	while (!empty()) {
		pop();
	}
}

LinkedStack::~LinkedStack() {
	deleteStack();
}

void LinkedStack::copyStack(LinkedStack const& s) {
	if (s.top != NULL)
	{
		StackElement *toCopy = s.top, *newElement = NULL, *prevElement = NULL;
		newElement = new StackElement;
		newElement->data = toCopy->data;
		newElement->next = NULL;
		top = newElement;
		prevElement = top;
		toCopy = toCopy->next;
		while (toCopy != NULL) {
			newElement = new StackElement;
			newElement->data = toCopy->data;
			newElement->next = NULL;
			prevElement->next = newElement;
			prevElement = newElement;
			toCopy = toCopy->next;
		}
	}
	else
		top = NULL;
}

LinkedStack::LinkedStack(LinkedStack const& s) {
	copyStack(s);
}
LinkedStack& LinkedStack::operator=(LinkedStack const & s) {
	if (this != &s)
	{
		deleteStack();
		copyStack(s);
	}
	return *this;
}
bool LinkedStack::empty() const {
	return top == NULL;
}

int LinkedStack::peek() const {
	if (empty()) {
		cout << "Грешка: опит за поглеждане в празен стек!\n";
		return 0;
	}

	return top->data;
}

void LinkedStack::push(int x) {
	StackElement* p = new StackElement;
	p->data = x;
	p->next = top;
	top = p;
}

int LinkedStack::pop() {
	if (empty()) {
		cout << "Грешка: опит за изключване от празен стек!\n";
		return 0;
	}
	// top != NULL

	StackElement* p = top;
	top = top->next;
	int x = p->data;
	delete p;
	return x;
}
