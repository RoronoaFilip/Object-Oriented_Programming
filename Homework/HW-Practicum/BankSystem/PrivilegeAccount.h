#pragma once
#include "Account.h"

class PrivilegeAccount : public Account {
  size_t overdraft;

public:
  PrivilegeAccount();
  PrivilegeAccount(const FilipString &newUsername,
                   const FilipString &newPassword, const FilipString &newIban,
                   const Customer &newOwner, const size_t newOverdraft);

  void setOverdraft(const size_t newOverdraft);
  const size_t getOverdraft() const;

  Account *clone() const override;
  void deposit(const size_t toDeposit) override;
  bool withdraw(const size_t toWithdraw) override;
  void display() const override;
};