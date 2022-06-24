#include "ShapeFactory.h"


Rectangle* ShapeFactory::createRectangleFromConsole() const {
	double x = 0, y = 0, strokeWidth = 0, height = 0, width = 0;
	FilipString stroke, fill;

	std::cout << "Enter x: ";
	std::cin >> x;
	std::cout << "Enter y: ";
	std::cin >> y;
	std::cout << "Enter width: ";
	std::cin >> width;
	std::cout << "Enter height: ";
	std::cin >> height; std::cin.ignore();
	std::cout << "Enter fill: ";
	std::cin >> fill;
	std::cout << "Enter stroke: ";
	std::cin >> stroke;
	std::cout << "Enter strokeWidth: ";
	std::cin >> strokeWidth;

	Rectangle* temp = new Rectangle(x, y, x + width, y + height);
	temp->setHeight(height);
	temp->setWidth(width);
	temp->setFill(fill);

	if (stroke != "none") {
		temp->setStroke(stroke);
	}

	temp->setStrokeWidth(strokeWidth);

	return temp;
}

Circle* ShapeFactory::createCircleFromConsole() const {
	double x = 0, y = 0, strokeWidth = 0, radius = 0;
	FilipString stroke, fill;

	std::cout << "Enter x: ";
	std::cin >> x;
	std::cout << "Enter y: ";
	std::cin >> y;
	std::cout << "Enter radius: ";
	std::cin >> radius; std::cin.ignore();
	std::cout << "Enter fill: ";
	std::cin >> fill;
	std::cout << "Enter stroke: ";
	std::cin >> stroke;
	std::cout << "Enter strokeWidth: ";
	std::cin >> strokeWidth;

	Circle *temp = new Circle(x, y, radius);

	temp->setFill(fill);

	if (stroke != "none") {
		temp->setStroke(stroke);
	}

	temp->setStrokeWidth(strokeWidth);

	return temp;
}

Line* ShapeFactory::createLineFromConsole() const {
	double x1 = 0, y1 = 0, strokeWidth = 0, x2 = 0, y2 = 0;

	std::cout << "Enter x1: ";
	std::cin >> x1;
	std::cout << "Enter y2: ";
	std::cin >> y2;
	std::cout << "Enter x2: ";
	std::cin >> x2;
	std::cout << "Enter strokeWidth: ";
	std::cin >> strokeWidth;

	Line *temp = new Line(x1, y1, x2, y2, strokeWidth);

	return temp;
}