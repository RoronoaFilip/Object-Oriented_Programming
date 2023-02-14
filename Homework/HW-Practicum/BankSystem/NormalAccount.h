#pragma once
#include "Account.h"

class NormalAccount : public Account {

public:
  NormalAccount() = default;
  NormalAccount(const FilipString &newUsername, const FilipString &newPassword,
                const FilipString &newIban, const Customer &newOwner);

  Account *clone() const override;
  void deposit(const size_t toDeposit) override;
  bool withdraw(const size_t toWithdraw) override;
  void display() const override;
};