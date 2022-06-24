#pragma once
#include <cmath>
#include <iostream>

#include "BetType.h"
#include "Player.h"

class Casino {
  int currentNumber;

  //* My Abs Function
  int myAbs(int n) const;

  //* Check if the Number is a Degree of 2
  bool isNumDegreeOfTwo(int n) const;

  //* Is the number a Prime Number
  bool isPrime(int num) const;

  //* Check if number is even
  bool isEven(const int n) const;

  //* Check in Guess is correct
  bool checkGuess(Player &currentPlayer, const BetType betType, const double bet) const;

  //* Get new Random Number
  void nextRound();

  //* Game Menu
  void printMenu() const;

public:
  Casino();

  //* Get the Current Number
  const int getCurrentNumber() const;

  //* Play
  void play(Player &currentPlayer);
};