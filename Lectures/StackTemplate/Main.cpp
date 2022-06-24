/*
* Main.cpp
*/

#include "Stack.h"

#include <iostream>
using namespace std;

void main()
{
	Stack<int> st;


	for (int i = 0; i < 1000; i++) {
		st.push(i);
	}

	Stack<int> st1 = st;
	Stack<int> st2;
	st2 = st1;

	while (!st2.empty())
	{
		cout << st2.pop() << ' ';
	}
	cout << endl;

	Stack<double> st3;
	st3.push(1.5);
	st3.push(2.5);
	st3.push(3.5);

	while (!st3.empty())
	{
		cout << st3.pop() << ' ';
	}
	cout << endl;
}
