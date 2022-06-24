#pragma once
#include "Star.h"

class Player {
  int id;
  size_t points;
  Star yourStar;

public:
  Player(int newId);

  void addPoints(const int add);

  virtual bool levelUp() = 0;

  void goUpOneStar();

  void setPoints(const size_t newPoints);

  size_t getPoints() const;
  int getId() const;
  Star getStar() const;

  virtual ~Player();
};