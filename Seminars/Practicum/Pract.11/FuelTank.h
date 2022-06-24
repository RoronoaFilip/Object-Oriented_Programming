#pragma once
#include "FilipString.h"

class FuelTank {
  double maxCapacity;
  double currentLiters;

public:
  FuelTank();
  FuelTank(const double newMaxCapacity);
  FuelTank(const double newMaxCapacity, const double newCurrentLiters);

  void setMaxCapacity(const double newMaxCapacity);
  void setCurrentLiters(const double newCurrentLiters);

  void use(const double use);
  void fill(const double fill);
};