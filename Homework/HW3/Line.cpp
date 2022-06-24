// Line 1-8 are included in all .cpp files to check for memory leaks
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"

Line::Line(double x1, double y1, double x2, double y2, double newStrokeWidth)
	: Shape(2) {
	Shape::setPoint(0, x1, y1);
	Shape::setPoint(1, x2, y2);

	//* In Line strokeWidth is not Optional
	Shape::setStrokeWidth(newStrokeWidth);
}

double Line::getArea() const {
	Shape::Point p0 = getPointAtIndex(0);
	Shape::Point p1 = getPointAtIndex(1);

	return p0.getDist(p1);
}

double Line::getPerimeter() const {
	Shape::Point p0 = getPointAtIndex(0);
	Shape::Point p1 = getPointAtIndex(1);

	return p0.getDist(p1);
}
bool Line::isPointIn(double x, double y) const {
	Shape::Point temp(x, y);
	Shape::Point p0 = getPointAtIndex(0);
	Shape::Point p1 = getPointAtIndex(1);

	return p0.getDist(temp) + temp.getDist(p1) == p0.getDist(p1);
}
Shape* Line::clone() const {
	Shape* temp = new Line(*this);

	return temp;
}
void Line::display() const {
	std::cout << "Line: " << Shape::getPointAtIndex(0).x << ' '
		<< Shape::getPointAtIndex(0).y << ' ' << Shape::getPointAtIndex(1).x
		<< ' ' << Shape::getPointAtIndex(1).y << ' ';

	try {
		std::cout << Shape::getStroke() << ' ';
	} catch (...) {
	}  try {
		std::cout << Shape::getStrokeWidth() << ' ';
	} catch (...) {
	}
	std::cout << std::endl;
}

void Line::saveToFileStream(std::ostream& file) const {
	file << "<line x1=\"" << Shape::getPointAtIndex(0).x << "\" y1=\"" << Shape::getPointAtIndex(0).y << "\" x2=\"" << Shape::getPointAtIndex(1).x << "\" y2=\"" << Shape::getPointAtIndex(1).y << "\"";

	if (getStroke() != "~") {
		file << " stroke=\"" << getStroke() << "\"";
	}
	if (getStrokeWidth()) { //* If it is zero it doesnt get added
		file << " stroke-width=\"" << getStrokeWidth() << "\"";
	}
	file << "/>";
}

void Line::translate() {
	Line temp(Shape::getPointAtIndex(0).y, Shape::getPointAtIndex(0).x,
		Shape::getPointAtIndex(1).y, Shape::getPointAtIndex(1).x, getStrokeWidth());

	temp.setStroke(getStroke());

	*this = temp;
}

bool Line::isWithinRectangle(const Shape& toCompare) const {
	Shape* ptr = const_cast<Shape*>(&toCompare);
	Rectangle* ptr2 = dynamic_cast<Rectangle*>(ptr);

	if (ptr2 == nullptr) {
		return false;
	}

	return ptr2->isPointIn(Shape::getPointAtIndex(0).x, Shape::getPointAtIndex(0).y) && ptr2->isPointIn(Shape::getPointAtIndex(1).x, Shape::getPointAtIndex(1).y);
}

bool Line::isWithinCircle(const Shape& toCompare) const {
	Shape* ptr = const_cast<Shape*>(&toCompare);
	Circle* ptr2 = dynamic_cast<Circle*>(ptr);

	if (ptr2 == nullptr) {
		return false;
	}

	return  ptr2->isPointIn(Shape::getPointAtIndex(0).x, Shape::getPointAtIndex(0).y) && ptr2->isPointIn(Shape::getPointAtIndex(1).x, Shape::getPointAtIndex(1).y);
}
