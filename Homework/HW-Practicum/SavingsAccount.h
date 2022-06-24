#pragma once
#include "Account.h"

class SavingsAccount : public Account {
  double interestRate;

public:
  SavingsAccount();
  SavingsAccount(const FilipString &newUsername, const FilipString &newPassword,
                 const FilipString &newIban, const Customer &newOwner,
                 const double newInterestRate);

  void setRate(const double newInterestRate);

  const double getRate() const;

  Account *clone() const override;
  void deposit(const size_t toDeposit) override;
  bool withdraw(const size_t toWithdraw) override;
  void display() const override;
};