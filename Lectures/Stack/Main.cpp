/*
* Main.cpp
*/

#include "Stack.h"

#include <iostream>
using namespace std;

void main()
{
	// Прочитане на цяло положително число
	cout << "Number: ";
	int n;
	cin >> n;

	Stack st;

	int x = n;
	while (x)
	{
		st.push(x % 2);
		x /= 2;
	}

	// Извеждане на двоичното число
	while (!st.empty()) 
	{
		cout << st.pop();
	}
	cout << endl;
}
