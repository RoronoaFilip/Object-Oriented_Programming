// Line 1-8 are included in all .cpp files to check for memory leaks
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "Rectangle.h"
#include "Circle.h"

Rectangle::Rectangle(double x1, double y1, double x2, double y2) : Shape(4) {
	Shape::setPoint(0, x1, y1);
	Shape::setPoint(1, x1, y2);
	Shape::setPoint(2, x2, y2);
	Shape::setPoint(3, x2, y1);
	height = 0;
	width = 0;
}

void Rectangle::setWidth(const double newWidth) { width = newWidth; }
void Rectangle::setHeight(const double newHeight) { height = newHeight; }
double Rectangle::getWidth() const { return width; }
double Rectangle::getHeight() const { return height; }

double Rectangle::getArea() const {
	Shape::Point p0 = getPointAtIndex(0);
	Shape::Point p1 = getPointAtIndex(1);
	Shape::Point p3 = getPointAtIndex(3);

	return p0.getDist(p1) * p0.getDist(p3);
}
double Rectangle::getPerimeter() const {
	Shape::Point p0 = getPointAtIndex(0);
	Shape::Point p1 = getPointAtIndex(1);
	Shape::Point p3 = getPointAtIndex(3);

	return 2 * (p0.getDist(p1) + p0.getDist(p3));
}
bool Rectangle::isPointIn(double x, double y) const {
	Shape::Point temp(x, y);
	return temp.x >= Shape::getPointAtIndex(0).x &&
		temp.y >= Shape::getPointAtIndex(0).y &&
		temp.x <= Shape::getPointAtIndex(2).x &&
		temp.y <= Shape::getPointAtIndex(2).y;
}
Shape* Rectangle::clone() const {
	Shape* temp = new Rectangle(*this);

	return temp;
}
void Rectangle::display() const {
	std::cout << "Rectangle: " << Shape::getPointAtIndex(0).x << ' '
		<< Shape::getPointAtIndex(0).y << ' ' << width << ' ' << height
		<< ' ';
	try {
		std::cout << Shape::getFill() << ' ';
	} catch (...) {
	}
	try {
		std::cout << Shape::getStroke() << ' ';
	} catch (...) {
	}
	try {
		std::cout << Shape::getStrokeWidth() << ' ';
	} catch (...) {
	}

	std::cout << std::endl;
}

void Rectangle::saveToFileStream(std::ostream& file) const {
	file << "<rect x=\"" << Shape::getPointAtIndex(0).x << "\" y=\"" << Shape::getPointAtIndex(0).y << "\" width=\"" << getWidth() << "\" height=\"" << getHeight() << "\"";
	if (getFill() != "~") {
		file << " fill=\"" << getFill() << "\"";
	}
	if (getStroke() != "~") {
		file << " stroke=\"" << getStroke() << "\"";
	}
	if (getStrokeWidth()) { //* If it is zero it doesnt get added
		file << " stroke-width=\"" << getStrokeWidth() << "\"";
	}
	file << "/>";
}

void Rectangle::translate() {
	Rectangle temp(Shape::getPointAtIndex(0).y, Shape::getPointAtIndex(0).x,
		Shape::getPointAtIndex(2).y, Shape::getPointAtIndex(2).x);

	temp.setHeight(getHeight());
	temp.setWidth(getWidth());
	temp.setFill(getFill());

	if (getStroke() != "none") {
		temp.setStroke(getStroke());
	}

	temp.setStrokeWidth(getStrokeWidth());

	*this = temp;
}

bool Rectangle::isWithinRectangle(const Shape& toCompare) const {
	Shape* ptr = const_cast<Shape*>(&toCompare);
	Rectangle* ptr2 = dynamic_cast<Rectangle*>(ptr);

	if (ptr2 == nullptr) {
		return false;
	}

	return ptr2->isPointIn(Shape::getPointAtIndex(0).x, Shape::getPointAtIndex(0).y) && ptr2->isPointIn(Shape::getPointAtIndex(2).x, Shape::getPointAtIndex(2).y);
}

bool Rectangle::isWithinCircle(const Shape& toCompare) const {
	Shape* ptr = const_cast<Shape*>(&toCompare);
	Circle* ptr2 = dynamic_cast<Circle*>(ptr);

	if (ptr2 == nullptr) {
		return false;
	}

	return  ptr2->isPointIn(Shape::getPointAtIndex(0).x, Shape::getPointAtIndex(0).y) && ptr2->isPointIn(Shape::getPointAtIndex(2).x, Shape::getPointAtIndex(2).y);
}
