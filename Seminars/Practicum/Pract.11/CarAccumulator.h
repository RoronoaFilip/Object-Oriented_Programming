#pragma once
#include "CarPart.h"
#include "FilipString.h"

class CarAccumulator : public CarPart {
  size_t capacity;
  FilipString batteryId;

public:
  CarAccumulator();
  CarAccumulator(const int newCapacity, const FilipString &newId);

  const char *getId() const;
  const size_t getCapacity() const;

  void setBatteryId(const FilipString &newId);
  void setCapacity(const int newCapacity);

  friend std::ostream &operator<<(std::ostream &stream, CarAccumulator &accumulator);
};
