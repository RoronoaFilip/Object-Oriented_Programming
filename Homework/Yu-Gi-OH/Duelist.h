#pragma once
#include "Deck.h"

class Duelist {
  char *name;
  Deck deck;

  void free();

  void copyFrom(const Duelist &other);

public:
  Duelist();

  Duelist(const char *newName);

  Duelist(const Duelist &other);
  Duelist &operator=(const Duelist &other);

  void print() const;

  //* Get Counts of Cards
  int getMonsterCardsCount() const;
  int getMagicCardsCount() const;

  void setName(const char *newName);

  //! Add=====================================
  //* Add a Monster Card
  bool addMonsterCard(const MonsterCard &newCard);

  //* Add a Magic Card
  bool addMagicCard(const MagicCard &newCard);

  //! Change=================================
  //* Change Monster Card
  bool changeMonsterCard(const MonsterCard &newCard, const int index);

  //* Change Magic Card
  bool changeMagicCard(const MagicCard &newCard, const int index);
};