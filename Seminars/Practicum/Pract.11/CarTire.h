#pragma once
#include "CarPart.h"
#include "FilipString.h"
#include <iostream>

const int minWidth = 156;
const int maxWidth = 365;
const int minProfile = 30;
const int maxProfile = 80;
const int minDiameter = 13;
const int maxDiameter = 21;

class CarTire : public CarPart {
  size_t width;
  size_t profile;
  size_t diameter;

public:
  CarTire();
  CarTire(const int newWidth, const int newProfile, const int newDiameter);

  void setWidth(const int newWidth);
  void setProfile(const int newProfile);
  void setDiameter(const int newDiameter);

  const int getWidth() const;
  const int getProfile() const;
  const int getDiameter() const;

  friend std::ostream &operator<<(std::ostream &stream, CarTire &tire);
};