#include "Employee.h"

Employee::Employee(const FilipString &newName, const size_t newAge,
                   const size_t newSalary)
    : name(newName), age(newAge), salary(newSalary) {}

Employee::~Employee() {}

void Employee::setName(const FilipString &newName) { name = newName; }
void Employee::setAge(const size_t newAge) { age = newAge; }
void Employee::setSalary(const size_t newSalary) { salary = newSalary; }

const char *Employee::getName() const { return name.getCharPointer(); }
size_t Employee::getAge() const { return age; }
size_t Employee::getSalary() const { return salary; }