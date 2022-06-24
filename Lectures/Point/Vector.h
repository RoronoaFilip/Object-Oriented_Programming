/*
* Vector.h
*/

#include "Point.h"

#ifndef VECTOR_H
#define VECTOR_H
class Vector
{
private:
	Point start;
	Point end;
public:
	// конструктури
	Vector(Point, Point);
	
	// функции за достъп
	Point getStart() const
	{
		return start;
	}
	Point getEnd() const
	{
		return end;
	}
	void print() const;
	double length() const;

	// мутатори
	void setStart(Point a) 
	{
		start = a;
	}
	void setEnd(Point b)
	{
		end = b;
	}
	void offset(double, double);
};

#endif // VECTOR_H