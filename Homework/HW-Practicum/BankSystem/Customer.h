#pragma once
#include "FilipString.h"

class Customer {
  FilipString name;
  FilipString address;
  size_t id;

public:
  Customer() = default;
  Customer(const FilipString &newName, const FilipString &newAddress,
           const size_t newId);

  void setName(const FilipString &newName);
  void setAddress(const FilipString &newAddress);
  void setId(const size_t newId);

  const char *getName() const;
  const char *getAddress() const;
  size_t getId() const;

  void display() const;

  bool operator==(const Customer &other);
};