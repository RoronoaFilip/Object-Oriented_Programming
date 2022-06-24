#pragma once
#include "Award.h"

class Sylvester : public Award {
public:
  Sylvester();
  Sylvester(const size_t newPoints);

  void visualize();
};