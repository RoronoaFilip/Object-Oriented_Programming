#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "NormalAccount.h"
#include <iostream>

Account *NormalAccount::clone() const {
  Account *temp = new NormalAccount(*this);

  return temp;
}

NormalAccount::NormalAccount(const FilipString &newUsername,
                             const FilipString &newPassword,
                             const FilipString &newIban,
                             const Customer &newOwner)
    : Account(newUsername, newPassword, newIban, newOwner) {}

void NormalAccount::deposit(const size_t toDeposit) { balance += toDeposit; }
bool NormalAccount::withdraw(const size_t toWithdraw) {
  if (balance >= toWithdraw) {
    balance -= toWithdraw;
    return true;
  }

  return false;
}
void NormalAccount::display() const {
  std::tm *now = std::localtime(&t);

  std::cout << "Normal Account:" << std::endl
            << "Date Created: " << (now->tm_year + 1900) << '/'
            << (now->tm_mon + 1) << '/' << now->tm_mday << std::endl
            << "Owner: " << getOwner()->getName() << std::endl
            << "IBAN: " << getIban() << std::endl
            << "Balance: " << getBalance() << std::endl
            << std::endl;
}