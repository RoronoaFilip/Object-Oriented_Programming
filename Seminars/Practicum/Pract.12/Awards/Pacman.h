#pragma once
#include "Award.h"

class Pacman : public Award {
public:
  Pacman();
  Pacman(const size_t newPoints);

  void visualize();
};