// Line 1-8 are included in all .cpp files to check for memory leaks
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "Circle.h"

const double PI = 3.14;
Circle::Circle(double x1, double y1, double r) : Shape(1) {
	Shape::setPoint(0, x1, y1);
	radius = r;
}
double Circle::getRadius() const { return radius; }
double Circle::getArea() const { return PI * radius * radius; }
double Circle::getPerimeter() const { return 2 * PI * radius; }
bool Circle::isPointIn(double x, double y) const {
	Shape::Point temp(x, y);
	Shape::Point p0 = getPointAtIndex(0);
	return temp.getDist(p0) <= radius;
}
Shape* Circle::clone() const {
	Shape* temp = new Circle(*this);

	return temp;
}
void Circle::display() const {
	std::cout << "Circle: " << Shape::getPointAtIndex(0).x << ' '
		<< Shape::getPointAtIndex(0).y << ' ' << getRadius() << ' ';
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

void Circle::saveToFileStream(std::ostream& file) const {
	file << "<circle cx=\"" << Shape::getPointAtIndex(0).x << "\" cy=\"" << Shape::getPointAtIndex(0).y << "\" r=\"" << radius << "\"";
	if (!getFill().isEmpty()) {
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

void Circle::translate() {
	Circle temp(Shape::getPointAtIndex(0).y, Shape::getPointAtIndex(0).x, radius);

	temp.setFill(getFill());

	if (getStroke() != "none") {
		temp.setStroke(getStroke());
	}

	temp.setStrokeWidth(getStrokeWidth());

	*this = temp;
}

bool Circle::isWithinRectangle(const Shape& toCompare) const {
	Point upper(Shape::getPointAtIndex(0).x, Shape::getPointAtIndex(0).y + radius);
	Point lower(Shape::getPointAtIndex(0).x, Shape::getPointAtIndex(0).y - radius);
	Point right(Shape::getPointAtIndex(0).x + radius, Shape::getPointAtIndex(0).y);
	Point left(Shape::getPointAtIndex(0).x - radius, Shape::getPointAtIndex(0).y);

	Shape* ptr = const_cast<Shape*>(&toCompare);
	Rectangle* ptr2 = dynamic_cast<Rectangle*>(ptr);

	if (ptr2 == nullptr) {
		return false;
	}

	return ptr2->isPointIn(upper.x, upper.y) && ptr2->isPointIn(lower.x, lower.y) && ptr2->isPointIn(right.x, right.y) && ptr2->isPointIn(left.x, left.y);
}

bool Circle::isWithinCircle(const Shape& toCompare) const {
	Point upper(Shape::getPointAtIndex(0).x, Shape::getPointAtIndex(0).y + radius);
	Point lower(Shape::getPointAtIndex(0).x, Shape::getPointAtIndex(0).y - radius);
	Point right(Shape::getPointAtIndex(0).x + radius, Shape::getPointAtIndex(0).y);
	Point left(Shape::getPointAtIndex(0).x - radius, Shape::getPointAtIndex(0).y);

	Shape* ptr = const_cast<Shape*>(&toCompare);
	Circle* ptr2 = dynamic_cast<Circle*>(ptr);

	if (ptr2 == nullptr) {
		return false;
	}

	return ptr2->isPointIn(upper.x, upper.y) && ptr2->isPointIn(lower.x, lower.y) && ptr2->isPointIn(right.x, right.y) && ptr2->isPointIn(left.x, left.y);
}
