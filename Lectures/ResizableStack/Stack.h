/*
* Stack.h
*/

#ifndef STACK_H
#define STACK_H

int const MAX = 100;

class Stack
{
private:
	int *arr;	    // динамичен масив с елементите на стека
	int top;	    // индекс на последния елемент
	int size;

	// проверка дали стекът е пълен
	bool full() const;
	void grow();

public:

	// конструктор
	Stack();
	// конструктор за копиране
	Stack(Stack const&);

	// Дестуктор
	~Stack();

	// Оператор =
	Stack& operator=(Stack const &);

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