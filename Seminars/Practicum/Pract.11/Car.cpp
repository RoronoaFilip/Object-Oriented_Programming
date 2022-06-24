#include "Car.h"

void Car::drive(const double km) {
  kilometersPassed += km;

  fuelTank.use(km * (log(engine.getHp()) / log(3.6) / 100 + log(weight) / log(8) / 100));
}