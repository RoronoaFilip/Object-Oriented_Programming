/*
* Point.cpp
*/

#include <iostream>
#include <cmath>
using namespace std;

#include "Point.h"

Point::Point(double x, double y)
{
	radius = sqrt(x*x + y*y);
	theta = atan2(y,x);
}

double Point::getX() const
{
	return radius * cos(theta);
}

double Point::getY() const
{
	return radius * sin(theta);
}

void Point::setX(double x)
{
	double y = getY();
	radius = sqrt(x * x + y * y);
	theta = atan2(y, x);
}

void Point::setY(double y)
{
	double x = getX();
	radius = sqrt(x * x + y * y);
	theta = atan2(y, x);
}

void Point::print() const
{
	cout << '(' << getX() << ", " << getY() << ')';
}

double Point::distance(Point p) const
{
	return sqrt((getX() - p.getX())* (getX() - p.getX()) + (getY() - p.getY())* (getY() - p.getY()));
}

void Point::offset(double offsetX, double offsetY)
{
	double x = getX();
	double y = getY();
	setX(x + offsetX);
	setY(y + offsetY);
}

