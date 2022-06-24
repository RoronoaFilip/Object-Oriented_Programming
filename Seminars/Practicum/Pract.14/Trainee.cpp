#include "Trainee.h"
Trainee::Trainee(const FilipString &newName, const size_t newAge,
                 const size_t newSalary, const size_t newMonthsLeft)
    : Employee(newName, newAge, newSalary), monthsLeft(newMonthsLeft) {}
Trainee::~Trainee() {}

Employee *Trainee::clone() const { return new Trainee(*this); }