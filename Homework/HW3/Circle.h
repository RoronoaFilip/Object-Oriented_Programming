#pragma once

#include "FilipString.h"
#include "Shape.h"
#include "Rectangle.h"

class Circle : public Shape {
	double radius;

public:
	Circle() = delete;
	Circle(double x1, double y1, double r);

	double getRadius() const;

	virtual double getArea() const override;
	virtual double getPerimeter() const override;
	virtual bool isPointIn(double x, double y) const override;
	virtual Shape* clone() const override;
	virtual void display() const override;
	virtual void saveToFileStream(std::ostream& file) const override;
	void translate() override;
	bool isWithinRectangle(const Shape& toCompare) const override;
	bool isWithinCircle(const Shape& toCompare) const override;
};