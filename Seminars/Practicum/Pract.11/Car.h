#pragma once
#include "CarAccumulator.h"
#include "CarTire.h"
#include "Engine.h"
#include "FilipString.h"
#include "FilipVector.hpp"
#include "FuelTank.h"
class Car {
  FuelTank fuelTank;
  Engine engine;
  FilipVector<CarTire> tires;
  CarAccumulator accumulator;
  double kilometersPassed;
  size_t weight;

public:
  Car();

  void drive(const double km);

  void setKM(const double newKM);
  const double getKM() const;

  void setWeight(const size_t newWeight);
  const size_t getWight() const;

  const double getFuelTank() const; //* getCurrentLiters
};