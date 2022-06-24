#pragma once
#include "Award.h"

class Penguin : public Award {
public:
  Penguin();
  Penguin(const size_t newPoints);

  void visualize();
};