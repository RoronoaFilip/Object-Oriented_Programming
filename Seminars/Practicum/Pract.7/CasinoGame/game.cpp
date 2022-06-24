#include <cstring>
#include <iostream>

#include "Casino.h"
#include "Player.h"

int main() {
  Casino game1;

  Player player1("Name1", "1234", 23, 100);

  game1.play(player1);

  return 0;
}