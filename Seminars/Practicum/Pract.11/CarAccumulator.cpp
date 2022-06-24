#include "CarAccumulator.h"

CarAccumulator::CarAccumulator() {}
CarAccumulator::CarAccumulator(const int newCapacity, const FilipString &newId) : batteryId(newId) {
  setCapacity(newCapacity);
}

const char *CarAccumulator::getId() const {
  return batteryId.getCharPointer();
}
const size_t CarAccumulator::getCapacity() const {
  return capacity;
}

void CarAccumulator::setBatteryId(const FilipString &newId) {
  batteryId = newId;
}
void CarAccumulator::setCapacity(const int newCapacity) {
  if (newCapacity < 0) {
    capacity = 0;
  } else {
    capacity = newCapacity;
  }
}

std::ostream &operator<<(std::ostream &stream, CarAccumulator &accumulator) {
  stream << "Capacity: " << accumulator.capacity << " Battery Id: " << accumulator.batteryId << '\n';

  return stream;
}
