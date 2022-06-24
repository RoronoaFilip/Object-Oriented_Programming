#pragma once
#include "Player.h"

class Guest : public Player {
  size_t timeLeft;

public:
  Guest(const int newId);

  bool play(int timePlayed);

  bool levelUp();
};