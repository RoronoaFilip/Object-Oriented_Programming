#pragma once
#include <cstring>
#include <iostream>

#include "BetType.h"
class Player {
  char *name;
  char *password;
  int age;
  double money;

  void free();
  void copyFrom(const Player &other);
  //* Validate Password
  bool isPasswordValid(const char *newPassword) const;

public:
  //* Constructor
  Player(const char *newName, const char *newPassword, const int newAge,
         const double newMoney, const char *oldPassword = nullptr);

  //* Copy Constructor
  Player(const Player &other);

  //* Operator=
  Player &operator=(const Player &other);

  //* Destructor
  ~Player();

  //! Setters ================================================
  void setName(const char *newName);

  void setPassword(const char *newPassword, const char *oldPassword);

  void setAge(int newAge);

  void setMoney(double newMoney);

  //! Getters ===================================================
  const char *getName() const;

  // const char *getPassword() const;

  const int getAge() const;

  const double getMoney() const;

  //! Add money ===============================================
  void addThreeTimes(const double bet);
  void addOneFourth(const double bet);
  void addOneHalf(const double bet);
  void addDouble(const double bet);
  void addTimesOneHundred(const double bet);

  //! Make Bets ===============================================
  //* Get Bet Type
  BetType makeBetType() const;

  //* Make Bet
  double makeBet() const;
};