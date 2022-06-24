#pragma once

#include "FilipString.h"
#include "FilipVector.hpp"
#include "Optional.hpp"
#include <cmath>

class Shape {

public:
	struct Point {
		double x;
		double y;

		Point() : x(0), y(0) {}
		Point(double x, double y) : x(x), y(y) {}

		inline void setX(const double newX) { x = newX; }
		inline void setY(const double newY) { y = newY; }

		inline double getDist(const Point& other) const {
			double dx = x - other.x;
			double dy = y - other.y;

			return sqrt(dx * dx + dy * dy);
		}

		inline bool operator==(const Point& other) const {
			return x == other.x && y == other.y;
		}
		inline bool operator!=(const Point& other) const {
			return x != other.x && y != other.y;
		}
	};

	//! Can throw if invalid Index
	const Point& getPointAtIndex(size_t index) const;

private:
	FilipVector<Point> points;
	size_t pointsCount;

	Optional<FilipString> fill;
	Optional<FilipString> stroke;
	Optional<double> strokeWidth;

public:
	Shape() = delete;
	Shape(const size_t pointsCount);

	bool operator==(const Shape& other) const;
	bool operator!=(const Shape& other) const;

	virtual ~Shape();

	bool setPoint(const size_t index, double newX, double newY);

	void setStroke(const FilipString& newStroke);
	void setStrokeWidth(const double newStrokeWidth);
	void setFill(const FilipString& newFill);

	const FilipString getStroke() const;
	double getStrokeWidth() const;
	const FilipString getFill() const;
	const size_t getPointsCount() const;

	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual bool isPointIn(double x, double y) const = 0;
	virtual Shape* clone() const = 0;
	virtual void display() const = 0;
	virtual void saveToFileStream(std::ostream& file) const = 0;
	virtual void translate() = 0;
	virtual bool isWithinRectangle(const Shape& toCompare) const = 0;
	virtual bool isWithinCircle(const Shape& toCompare) const = 0;
};