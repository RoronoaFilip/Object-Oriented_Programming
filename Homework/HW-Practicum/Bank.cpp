#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "Bank.h"
#include <fstream>
#include <iostream>

Account *Bank::findAccountBasedOnIban(const FilipString &iban) const {
  for (size_t i = 0; i < accounts.getSize(); ++i) {
    if (FilipString(accounts[i]->getIban()) == iban) {
      return accounts[i];
    }
  }

  return nullptr;
}

Bank::Bank() : name(), address(), customers(), accounts(), logs() {}
Bank::Bank(const FilipString &newName, const FilipString &newAddress)
    : customers(), accounts(), logs() {
  setName(newName);
  setAddress(newAddress);
}

Bank::~Bank() { exportLogs(); }

void Bank::setName(const FilipString &newName) { name = newName; }
void Bank::setAddress(const FilipString &newAddress) { address = newAddress; }

const char *Bank::getName() const { return name.getCharPointer(); }
const char *Bank::getAddress() const { return address.getCharPointer(); }

bool Bank::addCustomer(const Customer &newCustomer) {
  customers.push_back(newCustomer);

  logs.push_back(FilipString("Added Customer ") +
                 FilipString(newCustomer.getName()));

  return true;
}

bool Bank::deleteCustomer(const Customer &toDelete) {
  for (size_t i = 0; i < customers.getSize(); ++i) {
    if (FilipString(customers[i].getName()) ==
        FilipString(toDelete.getName())) {
      customers.remove(i);
      logs.push_back(FilipString("Deleted Customer ") +
                     FilipString(toDelete.getName()));

      return true;
    }
  }

  return false;
}

bool Bank::addAccount(const Account &newAccount) {
  accounts.addAccount(newAccount);

  logs.push_back(FilipString("Added Account ") +
                 FilipString(newAccount.getIban()));

  return true;
}
bool Bank::deleteAccount(const Account &toDelete) {
  for (size_t i = 0; i < accounts.getSize(); ++i) {
    if (FilipString(accounts[i]->getIban()) ==
        FilipString(toDelete.getIban())) {
      delete accounts[i];
      accounts.remove(i);
      logs.push_back(FilipString("Deleted Account ") +
                     FilipString(toDelete.getIban()));

      return true;
    }
  }

  return false;
}

void Bank::listCustomers() const {
  for (size_t i = 0; i < customers.getSize(); ++i) {
    customers[i].display();
    std::cout << std::endl;
  }
}
void Bank::listAccounts() const {
  for (size_t i = 0; i < accounts.getSize(); ++i) {
    accounts[i]->display();
    std::cout << std::endl;
  }
}
void Bank::listCustomerAccounts(const Customer &toList) const {
  for (size_t i = 0; i < accounts.getSize(); ++i) {
    Customer temp(*accounts[i]->getOwner());
    if (temp == toList) {
      accounts[i]->display();
      std::cout << std::endl;
    }
  }
}
void Bank::listLogs() const {
  for (size_t i = 0; i < logs.getSize(); ++i) {
    std::cout << logs[i] << std::endl;
  }
}

bool Bank::exportLogs() const {
  std::ofstream file("logs.txt", std::ios::trunc);

  if (!file.is_open()) {
    std::cout << "Error opening File in read form!" << std::endl;
    return false;
  }

  for (size_t i = 0; i < logs.getSize(); ++i) {
    file << logs[i] << std::endl;
  }

  try {
    file.close();
  } catch (...) {
    std::cout << "Error closing File!" << std::endl;
  }

  return true;
}
bool Bank::transfer(const size_t sum, const FilipString &fromIBAN,
                    const FilipString &toIBAN) {
  Account *account1 = findAccountBasedOnIban(fromIBAN);
  Account *account2 = findAccountBasedOnIban(toIBAN);

  if (account1->withdraw(sum)) {

    account2->deposit(sum);

    logs.push_back(FilipString("Transfer from ") + fromIBAN +
                   FilipString(" to ") + toIBAN);

    return true;
  }

  return false;
}

void Bank::display() const {
  std::cout << "Bank Name: " << name << std::endl
            << "Address: " << address << std::endl
            << std::endl;

  for (size_t i = 0; i < customers.getSize(); ++i) {
    customers[i].display();

    std::cout << std::endl;

    listCustomerAccounts(customers[i]);
  }
}

bool Bank::withdraw(Account *from, const size_t sum) {
  for (size_t i = 0; i < accounts.getSize(); ++i) {
    if (FilipString(accounts[i]->getIban()) == FilipString(from->getIban())) {
      return accounts[i]->withdraw(sum);
    }
  }

  logs.push_back("Withdraw from " + FilipString(from->getIban()));

  return false;
}
bool Bank::deposit(Account *to, const size_t sum) {
  for (size_t i = 0; i < accounts.getSize(); ++i) {
    if (FilipString(accounts[i]->getIban()) == FilipString(to->getIban())) {
      accounts[i]->deposit(sum);
      return true;
    }
  }

  logs.push_back("Deposit to " + FilipString(to->getIban()));

  return false;
}