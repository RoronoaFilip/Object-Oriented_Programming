#include "Duelist.h"

void Duelist::free() {
	delete[] name;
}

void Duelist::copyFrom(const Duelist& other) {
	int nameLen = strlen(other.name);

	name = new char[nameLen + 1];

	strcpy(name, other.name);

	deck = other.deck;
}

Duelist::Duelist() : name(nullptr), deck() {}

Duelist::Duelist(const char* newName) : name(nullptr) {
	setName(newName);
}

Duelist::Duelist(const Duelist& other) {
	copyFrom(other);
}

Duelist& Duelist::operator=(const Duelist& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

void Duelist::print() const {
	std::cout << "Duelist Name: " << name << std::endl;
	deck.print();
}

//* Get Counts of Cards
int Duelist::getMonsterCardsCount() const {
	return deck.getMonsterCardsCount();
}
int Duelist::getMagicCardsCount() const {
	return deck.getMagicCardsCount();
}

void Duelist::setName(const char* newName) {
	if (name == newName) {
		return;
	}

	delete[] name;

	int nameLen = strlen(newName);

	name = new char[nameLen + 1];

	strcpy(name, newName);
}

//! Add=====================================
//* Add a Monster Card
bool Duelist::addMonsterCard(const MonsterCard& newCard) {
	return deck.addMonsterCard(newCard);
}

//* Add a Magic Card
bool Duelist::addMagicCard(const MagicCard& newCard) {
	return deck.addMagicCard(newCard);
}

//! Change=================================
//* Change Monster Card
bool Duelist::changeMonsterCard(const MonsterCard& newCard, const int index) {
	return deck.changeMonsterCard(newCard, index);
}

//* Change Magic Card
bool Duelist::changeMagicCard(const MagicCard& newCard, const int index) {
	return deck.changeMagicCard(newCard, index);
}