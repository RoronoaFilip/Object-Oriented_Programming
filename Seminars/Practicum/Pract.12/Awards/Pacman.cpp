#include "Pacman.h"
#include <fstream>
#include <iostream>

Pacman::Pacman() : Award(50, "pacman.txt") {}
Pacman::Pacman(const size_t newPoints) : Award(newPoints, "pacman.txt") {}

void Pacman::visualize() {
  std::ifstream file(getFileName());

  try {
    if (!file.is_open()) {
      std::cout << "Error opening File in read form!" << std::endl;
      return;
    }

    while (!file.eof()) {
      char temp[1024];
      file.getline(temp, 1024);
      std::cout << temp << std::endl;

      file.peek();
    }
  } catch (...) {
    std::cout << "Error while working with File!" << std::endl;
  }

  try {
    file.close();
  } catch (...) {
    std::cout << "File couldn't be closed!" << std::endl;
  }
}