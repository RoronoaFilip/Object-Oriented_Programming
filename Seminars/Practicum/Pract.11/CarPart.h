#pragma once
#include "FilipString.h"
class CarPart {
  FilipString id;
  FilipString manufacturer;
  FilipString info;

public:
  CarPart();
  CarPart(const FilipString &newId, const FilipString &newManufacturer,
          const FilipString &newInfo);

  const char *getId() const;
  const char *getManufacturer() const;
  const char *getInfo() const;

  void setId(const FilipString &newId);
  void setManufacturer(const FilipString &newManufacturer);
  void setInfo(const FilipString &newInfo);
};