#pragma once
#include "Employee.h"

class Trainee : public Employee {
  size_t monthsLeft;

public:
public:
  Trainee(const FilipString &newName, const size_t newAge,
          const size_t newSalary, const size_t newMonthsLeft);
  ~Trainee();

  Employee *clone() const override;
};