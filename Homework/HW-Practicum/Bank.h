#pragma once
#include "Account.h"
#include "AccountsCollection.h"
#include "Customer.h"
#include "FilipString.h"
#include "FilipVector.hpp"

class Bank {
  FilipString name;
  FilipString address;

  FilipVector<Customer> customers;

  //* The Accounts must be dynamic
  AccountsCollection accounts;
  //* Otherwise an error will occur when deleting with freeMemory()

  FilipVector<FilipString> logs;

  Account *findAccountBasedOnIban(const FilipString &iban) const;

public:
  Bank();
  Bank(const FilipString &newName, const FilipString &newAddress);
  ~Bank();

  void setName(const FilipString &newName);
  void setAddress(const FilipString &newAddress);

  const char *getName() const;
  const char *getAddress() const;

  bool addCustomer(const Customer &newCustomer);
  bool deleteCustomer(const Customer &toDelete);

  bool addAccount(const Account &newAccount);
  bool deleteAccount(const Account &toDelete);

  void listCustomers() const;
  void listAccounts() const;
  void listCustomerAccounts(const Customer &toList) const;
  void listLogs() const;

  bool exportLogs() const;
  bool transfer(const size_t sum, const FilipString &fromIBAN,
                const FilipString &toIBAN);

  bool withdraw(Account *from, const size_t sum);
  bool deposit(Account *to, const size_t sum);

  void display() const;
};