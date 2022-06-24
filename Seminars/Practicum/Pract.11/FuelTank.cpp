#include "FuelTank.h"

FuelTank::FuelTank() {}
FuelTank::FuelTank(const double newMaxCapacity) {
  setMaxCapacity(newMaxCapacity);
}
FuelTank::FuelTank(const double newMaxCapacity, const double newCurrentLiters) {
  setMaxCapacity(newMaxCapacity);
  setCurrentLiters(newCurrentLiters);
}

void FuelTank::setMaxCapacity(const double newMaxCapacity) {
  if (newMaxCapacity > 0) {
    maxCapacity = newMaxCapacity;
  } else {
    maxCapacity = 0;
  }
}
void FuelTank::setCurrentLiters(const double newCurrentLiters) {
  if (newCurrentLiters > 0) {
    currentLiters = newCurrentLiters;
  } else {
    currentLiters = 0;
  }
}

void FuelTank::use(const double use) {
  if (use > currentLiters) {
    throw "Not Enough Fuel!";
  }

  currentLiters -= use;
}
void FuelTank::fill(const double fill) {
  if (currentLiters + fill > maxCapacity) {
    currentLiters = maxCapacity;
    return;
  }

  currentLiters += fill;
}