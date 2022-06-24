#pragma once
#include "Award.h"

class Squidward : public Award {
public:
  Squidward();
  Squidward(const size_t newPoints);

  void visualize();
};