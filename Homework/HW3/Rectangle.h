#pragma once

#include "FilipString.h"
#include "Shape.h"

class Rectangle : public Shape {
  double width;
  double height;

public:
  Rectangle() = delete;
  Rectangle(double x1, double y1, double x2, double y2);

  void setWidth(const double newWidth);
  void setHeight(const double newHeight);
  double getWidth() const;
  double getHeight() const;

  virtual double getArea() const override;
  virtual double getPerimeter() const override;
  virtual bool isPointIn(double x, double y) const override;
  virtual Shape *clone() const override;
  virtual void display() const override final;
  virtual void saveToFileStream(std::ostream& file) const override final;
  void translate() override;
  bool isWithinRectangle(const Shape& toCompare) const override;
  bool isWithinCircle(const Shape& toCompare) const override;
};