#include "MonsterCard.h"

void MonsterCard::free() {
  delete[] name;
}

void MonsterCard::copyFrom(const MonsterCard &other) {
  int nameLen = strlen(other.name);

  name = new char[nameLen + 1];

  strcpy(name, other.name);

  attackPoints = other.attackPoints;
  deffPoints = other.deffPoints;
}

bool MonsterCard::validatePoints(const int points) const {
  return (points >= 0);
}

//! public:

//* Default Constructor
MonsterCard::MonsterCard() : name(nullptr), attackPoints(0), deffPoints(0) {}

//* Constructor
MonsterCard::MonsterCard(const char *newName, const int newAttackPoints,
                         const int newDeffPoints) : name(nullptr) {
  setName(newName);
  setAttackPoints(newAttackPoints);
  setDeffPoints(newDeffPoints);
}

//* Copy Constructor
MonsterCard::MonsterCard(const MonsterCard &other) : name(nullptr) {
  copyFrom(other);
}

//* Operator=
MonsterCard &MonsterCard::operator=(const MonsterCard &other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }

  return *this;
}

//* Destructor
MonsterCard::~MonsterCard() {
  free();
}

void MonsterCard::print() const {

  std::cout << "Monster Card Name: " << name << std::endl
            << "Monster Card Attacl Points: " << attackPoints << std::endl
            << "Monster Card Defense Points: " << deffPoints << std::endl
            << std::endl;
}

//! Setters===================================
void MonsterCard::setName(const char *newName) {
  if (name == newName) {
    return;
  }

  delete[] name;
  int nameSize = strlen(newName);
  name = new char[nameSize + 1];

  strcpy(name, newName);
}

void MonsterCard::setAttackPoints(const int newAttackPoints) {
  if (validatePoints(newAttackPoints)) {
    attackPoints = newAttackPoints;
  } else {
    attackPoints = 0;
  }
}

void MonsterCard::setDeffPoints(const int newDeffPoints) {
  if (validatePoints(newDeffPoints)) {
    deffPoints = newDeffPoints;
  } else {
    deffPoints = 0;
  }
}

//! Getters===================================
const char *MonsterCard::getName() const {
  return name;
}
unsigned int MonsterCard::getAttackPoints() const {
  return attackPoints;
}
unsigned int MonsterCard::getDeffPoints() const {
  return deffPoints;
}