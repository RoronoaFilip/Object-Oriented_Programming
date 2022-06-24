#pragma once
#include "Award.h"

class ComputerBoy : public Award {
public:
  ComputerBoy();
  ComputerBoy(const size_t newPoints);

  void visualize();
};