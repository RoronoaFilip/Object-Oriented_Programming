#include "AccountsCollection.h"

void AccountsCollection::freeMemory() {
  //* The Stuff the Pointers are pointing to get deleted
  //* The Vector deletes the Array of Pointers
  for (size_t i = 0; i < accounts.getSize(); ++i) {
    delete accounts[i];
  }
}

void AccountsCollection::copyFrom(const AccountsCollection &other) {
  accounts.resize(other.accounts.getSize());

  for (size_t i = 0; i < other.accounts.getSize(); ++i) {
    accounts[i] = other.accounts[i]->clone();
  }
}
AccountsCollection::AccountsCollection(const AccountsCollection &other) {
  copyFrom(other);
}
AccountsCollection &
AccountsCollection::operator=(const AccountsCollection &other) {
  if (this != &other) {
    freeMemory();
    copyFrom(other);
  }

  return *this;
}
AccountsCollection::~AccountsCollection() { freeMemory(); }

bool AccountsCollection::addAccount(const Account &newAccount) {
  accounts.push_back(newAccount.clone());

  return true;
}
bool AccountsCollection::deleteAccount(const Account &toDelete) {
  accounts.remove((Account *const)&toDelete);

  return true;
}

size_t AccountsCollection::getSize() const { return accounts.getSize(); }

Account *AccountsCollection::operator[](const size_t index) {
  if (index >= accounts.getSize()) {
    return nullptr;
  }

  return accounts[index];
}
Account *AccountsCollection::operator[](const size_t index) const {
  if (index >= accounts.getSize()) {
    return nullptr;
  }

  return accounts[index];
}
//* Remove the Element on the Position
//! Return 0 if good, 1 if invalid Position, 2 if Empty
size_t AccountsCollection::remove(const size_t position) {
  return accounts.remove(position);
}