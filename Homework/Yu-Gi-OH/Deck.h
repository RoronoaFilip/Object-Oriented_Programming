#pragma once
#include "MagicCard.h"
#include "MonsterCard.h"
#include <iostream>

const int DECKSIZE = 40;
const int MONSTERCARDSIZE = 20;
const int MAGICCARDSIZE = 20;

class Deck {
  MonsterCard monsterCards[20];
  MagicCard magicCards[20];

  int currentMonsterCardsSize;
  int currentMagicCardsSize;

  int currentMonsterCardsIndex;
  int currentMagicCardsIndex;

  void copyFrom(const Deck &other);

public:
  //* Default Constructor
  Deck();

  //* Copy Constructor
  Deck(const Deck &other);

  //* Operator=
  Deck &operator=(const Deck &other);

  void print() const;

  //* Get Counts of Cards
  int getMonsterCardsCount() const;
  int getMagicCardsCount() const;

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