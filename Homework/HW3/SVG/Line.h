#pragma once

#include "FilipString.h"
#include "Shape.h"

class Line : public Shape {

public:
	Line() = delete;
	Line(double x1, double y1, double x2, double y2, double newStrokeWidth);

	//! Returns Lenght
	virtual double getArea() const override;

	//! Returns Lenght
	virtual double getPerimeter() const override;

	virtual bool isPointIn(double x, double y) const override;
	virtual Shape* clone() const override;
	virtual void display() const override;
	virtual void saveToFileStream(std::ostream& file) const override;
	void translate() override;
	bool isWithinRectangle(const Shape& toCompare) const override;
	bool isWithinCircle(const Shape& toCompare) const override;
};