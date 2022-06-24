#include "ComputerBoy.h"
#include "Pacman.h"
#include "Penguin.h"
#include "Squidward.h"
#include "Sylvester.h"
#include <iostream>

int main() {
  ComputerBoy award1;
  award1.visualize();
  Penguin award2;
  award2.visualize();
  Sylvester award3;
  award3.visualize();
  Pacman award4;
  award4.visualize();
  Squidward award5;
  award5.visualize();

  return 0;
}