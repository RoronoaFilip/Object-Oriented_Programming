#pragma once
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
#include "Shape.h"

class ShapesCollection {
	Shape** shapes;
	size_t size;
	size_t capacity;

	void freeMemory();
	void copyFrom(const ShapesCollection& other);
	void resize();

	void addShape(const Shape* other);

public:
	ShapesCollection();
	ShapesCollection(const ShapesCollection& other);
	ShapesCollection& operator=(const ShapesCollection& other);
	~ShapesCollection();

	Shape*& operator[](const size_t index);
	Shape*& operator[](const size_t index)const;
	
	void addRectangle(const Rectangle& other);
	void addCircle(const Circle& other);
	void addLine(const Line& other);

	bool erase(const size_t index);
	void allPointIn(double x, double y) const;

	void displayAll() const;
	void printAreasAll() const;
	void printPerimetersAll()const;
	void translateAll();
	void printAllWithinCircle(const Circle& shape) const;
	void printAllWithinRectangle(const Rectangle& shape) const;

	void saveAllToFileStream(std::ostream& file) const;

	size_t getSize() const;
};