#include "Deck.h"

void Deck::copyFrom(const Deck &other) {
  for (int i = 0; i < other.getMonsterCardsCount(); ++i) {
    monsterCards[i] = other.monsterCards[i];
  }

  for (int i = 0; i < other.getMagicCardsCount(); ++i) {
      magicCards[i] = other.magicCards[i];
  }

  currentMagicCardsIndex = other.currentMagicCardsIndex;
  currentMagicCardsSize = other.currentMagicCardsSize;
  currentMonsterCardsIndex = other.currentMonsterCardsIndex;
  currentMonsterCardsSize = other.currentMonsterCardsSize;
}

//* Default Constructor
Deck::Deck() : currentMagicCardsIndex(0), currentMagicCardsSize(0),
               currentMonsterCardsIndex(0), currentMonsterCardsSize(0) {}

//* Copy Constructor
Deck::Deck(const Deck &other) {
  copyFrom(other);
}

//* Operator=
Deck &Deck::operator=(const Deck &other) {

  if (this != &other) {
    copyFrom(other);
  }

  return *this;
}

void Deck::print() const {
  std::cout << "Magic Cards:" << std::endl;
  for (int i = 0; i < currentMagicCardsIndex; ++i) {
    magicCards[i].print();
  }
  std::cout << "Monster Cards:" << std::endl;
  for (int i = 0; i < currentMonsterCardsIndex; ++i) {
    monsterCards[i].print();
  }
}

//* Get Counts of Cards
int Deck::getMonsterCardsCount() const {
  return currentMonsterCardsSize;
}
int Deck::getMagicCardsCount() const {
  return currentMagicCardsSize;
}

//! Add=====================================
//* Add a Monster Card
bool Deck::addMonsterCard(const MonsterCard &newCard) {
  if (currentMonsterCardsSize >= MONSTERCARDSIZE) {
    return false;
  }

  monsterCards[currentMonsterCardsIndex++] = newCard;
  ++currentMonsterCardsSize;

  return true;
}

//* Add a Magic Card
bool Deck::addMagicCard(const MagicCard &newCard) {
  if (currentMagicCardsSize >= MAGICCARDSIZE) {
    return false;
  }

  magicCards[currentMagicCardsIndex++] = newCard;
  ++currentMagicCardsSize;

  return true;
}

//! Change=================================
//* Change Monster Card
bool Deck::changeMonsterCard(const MonsterCard &newCard,
                             const int index) {
  if (index + 1 >= MONSTERCARDSIZE) {
    return false;
  }

  monsterCards[index] = newCard;

  return true;
}

//* Change Magic Card
bool Deck::changeMagicCard(const MagicCard &newCard,
                           const int index) {
  if (index + 1 >= MAGICCARDSIZE) {
    return false;
  }

  magicCards[index] = newCard;

  return true;
}