#pragma once
#include "FilipString.h"

class Employee {
  FilipString name;
  size_t age;
  size_t salary;

public:
  Employee(const FilipString &newName, const size_t newAge,
           const size_t newSalary);

  virtual ~Employee();

  void setName(const FilipString &newName);
  void setAge(const size_t newAge);
  void setSalary(const size_t newSalary);

  const char *getName() const;
  size_t getAge() const;
  size_t getSalary() const;

  virtual Employee *clone() const = 0;
};