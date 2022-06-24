// Line 1-8 are included in all .cpp files to check for memory leaks
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "Shape.h"

const Shape::Point &Shape::getPointAtIndex(size_t index) const {
  if (index >= pointsCount)
    throw "Invalid point index!";

  return points[index];
}

Shape::Shape(const size_t pointsCount) : stroke(), fill(), strokeWidth() {
  for (size_t i = 0; i < pointsCount; ++i) {
    points.push_back(Point());
  }

  this->pointsCount = pointsCount;
}

bool Shape::operator==(const Shape& other) const {
    for (size_t i = 0; i < points.getSize(); ++i) {
        if (points[i] != other.points[i]) {
            return false;
        }
    }

    return pointsCount == pointsCount && fill.getData() == other.fill.getData() &&
        stroke.getData() == other.stroke.getData() &&
        strokeWidth.getData() == other.strokeWidth.getData();
}

bool Shape::operator!=(const Shape& other) const {
    for (size_t i = 0; i < points.getSize(); ++i) {
        if (points[i] == other.points[i]) {
            return false;
        }
    }

    return pointsCount != pointsCount && fill.getData() != other.fill.getData() &&
        stroke.getData() != other.stroke.getData() &&
        strokeWidth.getData() != other.strokeWidth.getData();
}

Shape::~Shape() {}

bool Shape::setPoint(const size_t index, double newX, double newY) {
  if (index >= 0 && index < pointsCount) {
    points[index].setX(newX);
    points[index].setY(newY);
    return true;
  }

  return false;
}

void Shape::setStroke(const FilipString &newStroke) {
  stroke.setData(newStroke);
}
void Shape::setStrokeWidth(const double newStrokeWidth) {
  strokeWidth.setData(newStrokeWidth);
}
void Shape::setFill(const FilipString &newFill) { fill.setData(newFill); }

const FilipString Shape::getStroke() const {
  try {
    return stroke.getData();
  } catch (...) {
  }

  return FilipString("~");
}
double Shape::getStrokeWidth() const {
  try {
    return strokeWidth.getData();
  } catch (...) {
    std::cout << "Optional is empty!" << std::endl;
  }

  return 0;
}

const FilipString Shape::getFill() const {
  try {
    return fill.getData();
  } catch (...) {
    std::cout << "Optional is empty!" << std::endl;
  }

  return FilipString("~");
}

const size_t Shape::getPointsCount() const {
    return pointsCount;
}
