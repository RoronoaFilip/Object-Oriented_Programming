/*
* Point.h
*/

#ifndef POINT_H
#define POINT_H

#define PI 3.14159265

class Point
{
private:
	double radius, theta;

public:
	// конструктори
	Point()
	{
		radius = theta = 0;
	};
	Point(double, double);

	// функции за достъп
	double getX() const;
	double getY() const;
	void print() const;
	double distance(Point) const;
	
	// мутатори
	void setX(double x);
	void setY(double y);

	// отместване на точката
	void offset(double, double);

};

#endif // POINT_H