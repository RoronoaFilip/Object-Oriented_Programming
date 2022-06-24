#pragma once
#include "Employee.h"

class Worker : public Employee {
  size_t monthsWorked;

public:
  Worker(const FilipString &newName, const size_t newAge,
         const size_t newSalary, const size_t newMonthsWorked);
  ~Worker();

  Employee *clone() const override;
};