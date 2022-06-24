// Line 1-8 are included in all .cpp files to check for memory leaks
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "ShapesCollection.h"

void ShapesCollection::freeMemory() {
	for (size_t i = 0; i < size; ++i) {
		delete shapes[i];
	}

	delete[] shapes;
}
void ShapesCollection::copyFrom(const ShapesCollection& other) {
	size = other.size;
	capacity = other.capacity;

	shapes = new Shape * [capacity];
	for (size_t i = 0; i < size; ++i) {
		shapes[i] = other.shapes[i]->clone();
	}
}
void ShapesCollection::resize() {
	capacity *= 2;
	Shape** temp = new Shape * [capacity];
	for (size_t i = 0; i < size; ++i) {
		temp[i] = shapes[i];
	}

	delete[] shapes;
	shapes = temp;
}

ShapesCollection::ShapesCollection() : size(0), capacity(8) {
	shapes = new Shape * [capacity];
}
ShapesCollection::ShapesCollection(const ShapesCollection& other) {
	copyFrom(other);
}
ShapesCollection& ShapesCollection::operator=(const ShapesCollection& other) {
	if (this != &other) {
		freeMemory();
		copyFrom(other);
	}
	return *this;
}
ShapesCollection::~ShapesCollection() { freeMemory(); }

void ShapesCollection::addShape(const Shape* other) {
	if (size == capacity) {
		resize();
	}
	shapes[size++] = other->clone();
}
void ShapesCollection::addRectangle(const Rectangle& other) {
	addShape(&other);
}
void ShapesCollection::addCircle(const Circle& other) { addShape(&other); }
void ShapesCollection::addLine(const Line& other) { addShape(&other); }

bool ShapesCollection::erase(const size_t index) {
	if (index >= size || index < 0) {
		return false;
	}

	delete shapes[index];

	for (size_t j = index; j < size - 1; ++j) {
		shapes[j] = shapes[j + 1];
	}
	--size;

	return true;
}

void ShapesCollection::allPointIn(double x, double y) const {
	for (size_t i = 0; i < size; ++i) {
		if (shapes[i]->isPointIn(x, y)) {
			shapes[i]->display();
		}
	}
}

Shape*& ShapesCollection::operator[](const size_t index) {
	if (index >= size || size < 0) {
		throw "Out of range!";
	}

	return shapes[index];
}
Shape*& ShapesCollection::operator[](const size_t index) const {
	if (index >= size || size < 0) {
		throw "Out of range!";
	}

	return shapes[index];
}
void ShapesCollection::saveAllToFileStream(std::ostream& file) const {
	for (size_t i = 0; i < size; ++i) {
		shapes[i]->saveToFileStream(file);
		file << '\n';
	}
}
size_t ShapesCollection::getSize() const {
	return size;
}
void ShapesCollection::displayAll() const {
	for (size_t i = 0; i < size; ++i) {
		std::cout << i + 1 << ".";
		shapes[i]->display();
	}
}

void ShapesCollection::printAreasAll() const {
	for (size_t i = 0; i < size; ++i) {
		std::cout << i + 1 << ".";
		std::cout << shapes[i]->getArea() << std::endl;
	}
}

void ShapesCollection::printPerimetersAll() const {
	for (size_t i = 0; i < size; ++i) {
		std::cout << i + 1 << ".";
		std::cout << shapes[i]->getPerimeter() << std::endl;
	}
}

void ShapesCollection::translateAll() {
	for (size_t i = 0; i < size; ++i) {
		shapes[i]->translate();
	}
}

void ShapesCollection::printAllWithinCircle(const Circle& shape) const {
	for (size_t i = 0; i < size; ++i) {
		if (shapes[i]->isWithinCircle(shape)) {
			shapes[i]->display();
		}
	}
}

void ShapesCollection::printAllWithinRectangle(const Rectangle& shape) const {
	for (size_t i = 0; i < size; ++i) {
		if (shapes[i]->isWithinRectangle(shape)) {
			shapes[i]->display();
		}
	}
}
