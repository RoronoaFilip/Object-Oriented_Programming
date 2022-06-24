/*
* Point.h
*/

#ifndef POINT_H
#define POINT_H

class Point
{
private:
	double x, y;

public:
	// конструктори
	Point()
	{
		x = y = 0;
	};
	Point(double, double);

	// функции за достъп
	double getX() const {
		return x;
	}
	double getY() const
	{
		return y;
	}
	void print() const;
	double distance(Point) const;
	
	// мутатори
	void setX(double x)
	{
		this->x = x;
	}
	void setY(double y)
	{
		this->y = y;
	}
	// отместване на точката
	void offset(double, double);

};

#endif // POINT_H