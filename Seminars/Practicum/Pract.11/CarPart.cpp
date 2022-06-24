#include "CarPart.h"

CarPart::CarPart() {}
CarPart::CarPart(const FilipString &newId, const FilipString &newManufacturer,
                 const FilipString &newInfo) : id(newId), manufacturer(newManufacturer),
                                               info(newInfo) {}

const char *CarPart::getId() const {
  return id.getCharPointer();
}
const char *CarPart::getManufacturer() const {
  return manufacturer.getCharPointer();
}
const char *CarPart::getInfo() const {
  return info.getCharPointer();
}

void CarPart::setId(const FilipString &newId) {
  id = newId;
}
void CarPart::setManufacturer(const FilipString &newManufacturer) {
  manufacturer = newManufacturer;
}
void CarPart::setInfo(const FilipString &newInfo) {
  info = newInfo;
}