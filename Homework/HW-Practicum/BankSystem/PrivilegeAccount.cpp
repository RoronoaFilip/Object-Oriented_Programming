#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "PrivilegeAccount.h"

Account *PrivilegeAccount::clone() const {
  Account *temp = new PrivilegeAccount(*this);

  return temp;
}

PrivilegeAccount::PrivilegeAccount() { overdraft = 100; }
PrivilegeAccount::PrivilegeAccount(const FilipString &newUsername,
                                   const FilipString &newPassword,
                                   const FilipString &newIban,
                                   const Customer &newOwner,
                                   const size_t newOverdraft)
    : Account(newUsername, newPassword, newIban, newOwner) {
  setOverdraft(newOverdraft);
}

void PrivilegeAccount::setOverdraft(const size_t newOverdraft) {
  overdraft = newOverdraft;
}
const size_t PrivilegeAccount::getOverdraft() const { return overdraft; }

void PrivilegeAccount::deposit(const size_t toDeposit) { balance += toDeposit; }
bool PrivilegeAccount::withdraw(const size_t toWithdraw) {
  if (balance + overdraft >= toWithdraw) {
    balance -= toWithdraw;
    return true;
  }

  return false;
}
void PrivilegeAccount::display() const {
  std::tm *now = std::localtime(&t);

  std::cout << "Privilege Account:" << std::endl
            << "Date Created: " << (now->tm_year + 1900) << '/'
            << (now->tm_mon + 1) << '/' << now->tm_mday << std::endl
            << "Owner: " << getOwner()->getName() << std::endl
            << "IBAN: " << getIban() << std::endl
            << "Balance: " << getBalance() << std::endl
            << std::endl;
}