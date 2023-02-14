#pragma once
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"

class ShapeFactory {
public:
	Rectangle* createRectangleFromConsole() const;
	Circle* createCircleFromConsole() const;
	Line* createLineFromConsole() const;
};