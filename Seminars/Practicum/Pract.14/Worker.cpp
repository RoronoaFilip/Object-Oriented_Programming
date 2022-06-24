#include "Worker.h"
Worker::Worker(const FilipString &newName, const size_t newAge,
               const size_t newSalary, const size_t newMonthsWorked)
    : Employee(newName, newAge, newSalary), monthsWorked(newMonthsWorked) {}
Worker::~Worker() {}

Employee *Worker::clone() const { return new Worker(*this); }