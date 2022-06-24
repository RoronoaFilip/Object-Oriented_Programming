/*
* Stack.cpp
*/

#include "Stack.h"

#include <iostream>
using namespace std;

Stack::Stack()
{
	top = -1; // Празен стек
}

bool Stack::empty() const 
{
	return top == -1;
}

int Stack::peek() const 
{
	if (empty()) {
		cout << "Грешка: опит за поглеждане в празен стек!\n";
		return 0;
	}

	return arr[top];
}

void Stack::push(int x) {
	if (full()) {
		cout << "Грешка: опит за включване в пълен стек!\n";
	}
	else
		arr[++top] = x;
}

bool Stack::full() const {
	return top == MAX - 1;
}

int Stack::pop() {
	if (empty()) {
		cout << "Грешка: опит за изключване от празен стек!\n";
		return 0;
	}
	return arr[top--];
}
