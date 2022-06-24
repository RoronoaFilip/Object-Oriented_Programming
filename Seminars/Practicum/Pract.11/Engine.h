#pragma once
#include "CarPart.h"

class Engine : public CarPart {
  size_t hp;

public:
  Engine();
  Engine(const int newHp);

  void setHp(const int newHp);
  const int getHp() const;

  friend std::ostream &operator<<(std::ostream &stream, Engine &engine);
};