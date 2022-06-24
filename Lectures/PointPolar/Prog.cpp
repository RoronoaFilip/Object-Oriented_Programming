/*
* Prog.cpp
*/

#include <iostream>
using namespace std;

#include "Point.h"
#include "Vector.h"

int main()
{
	Point p; // извиква се конструктора по подразбиране
	p.setX(1.0);
	p.setY(-2.0);
	p.print(); cout << endl;

	Point q(2, 3);
	q.print(); cout << endl;

	cout << "Distance " << p.distance(q) << endl;

	Vector v(Point(0, 0), Point(2, 2));
	v.print();
	cout << endl;

	v.offset(2, 2);
	v.print();
	cout << endl;

	cout << "Length: " << v.length() << endl;

}