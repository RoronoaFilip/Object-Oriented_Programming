#pragma once
#include "Customer.h"
#include "FilipString.h"
#include <ctime>
#pragma warning(                                                               \
    disable : 4996) //* Pragma for the ctime Conversion to the Current date in
                    //* the Display Functions of the Children Classes

class Account {
  FilipString username;
  FilipString password;
  FilipString iban;

  const Customer *owner;

protected:
  std::time_t t;
  int balance;

public:
  Account();
  Account(const FilipString &newUsername, const FilipString &newPassword,
          const FilipString &newIban, const Customer &newOwner);

  virtual ~Account();

  void setUsername(const FilipString &newUsername);
  void setPassword(const FilipString &newPassword);
  void setIban(const FilipString &newIban);
  void setOwner(const Customer &newOwner);

  virtual Account *clone() const = 0;
  virtual void deposit(const size_t toDeposit) = 0;
  virtual bool withdraw(const size_t toWithdraw) = 0;
  virtual void display() const = 0;

  const char *getUsername() const;

  //* Maybe getPassword should get removed I don't use it anywhere though
  const char *getPassword() const;
  const char *getIban() const;
  virtual int getBalance() const;
  const Customer *getOwner() const;
};