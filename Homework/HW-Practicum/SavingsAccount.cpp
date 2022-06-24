#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "SavingsAccount.h"

Account *SavingsAccount::clone() const {
  Account *temp = new SavingsAccount(*this);

  return temp;
}

SavingsAccount::SavingsAccount() { interestRate = 0; }
SavingsAccount::SavingsAccount(const FilipString &newUsername,
                               const FilipString &newPassword,
                               const FilipString &newIban,
                               const Customer &newOwner,
                               const double newInterestRate)

    : Account(newUsername, newPassword, newIban, newOwner) {
  setRate(newInterestRate);
}

void SavingsAccount::setRate(const double newInterestRate) {
  interestRate = newInterestRate;
}

const double SavingsAccount::getRate() const { return interestRate; }

void SavingsAccount::deposit(const size_t toDeposit) { balance += toDeposit; }
bool SavingsAccount::withdraw(const size_t toWithdraw) { return false; }
void SavingsAccount::display() const {
  std::tm *now = std::localtime(&t);

  std::cout << "Savings Account:" << std::endl
            << "Date Created: " << (now->tm_year + 1900) << '/'
            << (now->tm_mon + 1) << '/' << now->tm_mday << std::endl
            << "Owner: " << getOwner()->getName() << std::endl
            << "IBAN: " << getIban() << std::endl
            << "Balance: " << getBalance() << std::endl
            << std::endl;
}