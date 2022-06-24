/*
* Stack.h
*/

#ifndef STACK_H
#define STACK_H

int const MAX = 100;

class Stack
{
private:
	int arr[MAX];	// масив с елементите на стека
	int top;	    // индекс на последния елемент

	// проверка дали стекът е пълен
	bool full() const;

public:

	// създаване на празен стек
	Stack();

	// функции за достъп

	// проверка дали стек е празен
	bool empty() const;

	// намиране на елемента на върха на стека
	int peek() const;

	// мутатори

	// включване на елемент
	void push(int);

	// изключване на елемент
	int pop();

};

#endif /* STACK_H_ */