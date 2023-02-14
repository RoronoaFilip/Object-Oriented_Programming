#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "Customer.h"

Customer::Customer(const FilipString &newName, const FilipString &newAddress,
                   const size_t newId) {
  setName(newName);
  setAddress(newAddress);
  setId(newId);
}

void Customer::setName(const FilipString &newName) { name = newName; }
void Customer::setAddress(const FilipString &newAddress) {
  address = newAddress;
}
void Customer::setId(const size_t newId) { id = newId; }

const char *Customer::getName() const { return name.getCharPointer(); }
const char *Customer::getAddress() const { return address.getCharPointer(); }
size_t Customer::getId() const { return id; }

void Customer::display() const {
  std::cout << "Customer:" << std::endl
            << "Name: " << name << std::endl
            << "Address: " << address << std::endl
            << "Id: " << id << std::endl;
}

bool Customer::operator==(const Customer &other) {
  return name == other.name && address == other.address && id == other.id;
}