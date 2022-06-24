#include "CarTire.h"

CarTire::CarTire() {}
CarTire::CarTire(const int newWidth, const int newProfile, const int newDiameter) {
  setWidth(newWidth);
  setProfile(newProfile);
  setDiameter(newDiameter);
}

void CarTire::setWidth(const int newWidth) {
  if (newWidth >= minWidth && newWidth <= maxWidth) {
    width = newWidth;

    return;
  }

  width = 0;
}
void CarTire::setProfile(const int newProfile) {
  if (newProfile >= minProfile && newProfile <= maxProfile) {
    profile = newProfile;

    return;
  }

  profile = 0;
}
void CarTire::setDiameter(const int newDiameter) {
  if (newDiameter >= minDiameter && newDiameter <= maxDiameter) {
    diameter = newDiameter;

    return;
  }

  diameter = 0;
}

const int CarTire::getWidth() const {
  return width;
}
const int CarTire::getProfile() const {
  return profile;
}
const int CarTire::getDiameter() const {
  return diameter;
}

std::ostream &operator<<(std::ostream &stream, CarTire &tire) {
  stream << "Width: " << tire.width << " Profile: "
         << tire.profile << " Diameter: " << tire.diameter << '\n';

  return stream;
}