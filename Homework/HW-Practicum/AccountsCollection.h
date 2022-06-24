#pragma once

#include "Customer.h"
#include "FilipString.h"
#include "FilipVector.hpp"
#include "NormalAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"

class AccountsCollection {
  FilipVector<Account *> accounts;

  void freeMemory(); //!!!!!
  void copyFrom(const AccountsCollection &other);

public:
  AccountsCollection() = default;

  AccountsCollection(const AccountsCollection &other);
  AccountsCollection &operator=(const AccountsCollection &other);

  ~AccountsCollection();

  bool addAccount(const Account &newAccount);
  bool deleteAccount(const Account &toDelete);

  size_t getSize() const;

  Account *operator[](const size_t index);
  Account *operator[](const size_t index) const;

  //* Remove the Element on the Position
  //! Return 0 if good, 1 if invalid Position, 2 if Empty
  size_t remove(const size_t position);
};