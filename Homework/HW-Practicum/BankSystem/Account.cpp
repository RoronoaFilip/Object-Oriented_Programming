#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "Account.h"

Account::Account() : username(), password(), iban(), owner() {
  t = std::time(0);
  balance = 0;
}
Account::Account(const FilipString &newUsername, const FilipString &newPassword,
                 const FilipString &newIban, const Customer &newOwner) {
  t = std::time(0);
  setUsername(newUsername);
  setPassword(newPassword);
  setIban(newIban);
  balance = 0;

  setOwner(newOwner);
}

//* Virtual Destructor
Account::~Account() {}

void Account::setUsername(const FilipString &newUsername) {
  username = newUsername;
}
void Account::setPassword(const FilipString &newPassword) {
  password = newPassword;
}
void Account::setIban(const FilipString &newIban) { iban = newIban; }
void Account::setOwner(const Customer &newOwner) { owner = &newOwner; }

const char *Account::getUsername() const { return username.getCharPointer(); }
const char *Account::getPassword() const { return password.getCharPointer(); }
const char *Account::getIban() const { return iban.getCharPointer(); }
int Account::getBalance() const { return balance; }
const Customer *Account::getOwner() const { return owner; }