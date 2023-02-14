#pragma once
#include "ShapesCollection.h"
#include "SvgParser.h"
#include <cmath>

class SvgShapes {
	ShapesCollection shapes;
	mutable FilipString fileName; // Mutable for saveFile() Function

	Rectangle parseLineToRect(const char* line) const;
	Circle parseLineToCircle(const char* line) const;
	Line parseLineToLine(const char* line) const;

public:
	SvgShapes() = default;

	void addRectangle(const Rectangle& add);
	void addCircle(const Circle& add);
	void addLine(const Line& add);

	bool erase(const size_t index);
	void printAllPointIn(double x, double y) const;

	void displayShapes() const;
	void printAreas() const;
	void printPerimeters() const;
	void translate(const int index = -1);
	void printWithinCircle(const Circle& shape) const;
	void printWithinRectangle(const Rectangle& shape) const;

	bool readFile(const char* filePath);
	bool saveFile(const char* filePath = nullptr) const;
};