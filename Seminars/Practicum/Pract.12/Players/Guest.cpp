#include "Guest.h"

Guest::Guest(const int newId) : Player(newId) { timeLeft = 100; }

bool Guest::play(int timePlayed) {
  timeLeft -= timePlayed;
  return timeLeft > 0;
}

bool Guest::levelUp() { return false; }