#include "MagicCard.h"

void MagicCard::free() {
	delete[] name;
	delete[] effect;
}

void MagicCard::copyFrom(const MagicCard& other) {
	int nameLen = strlen(other.name);
	int effectLen = strlen(other.effect);

	name = new char[nameLen + 1];
	effect = new char[effectLen + 1];

	strcpy(name, other.name);
	strcpy(effect, other.effect);

	cardType = other.cardType;
}

MagicCardType MagicCard::getCardType(const char* type) const {
	if (strcmp(type, SPELL)) {
		return MagicCardType::spell;
	}
	else if (strcmp(type, BUFF)) {
		return MagicCardType::buff;
	}
	else if (strcmp(type, TRAP)) {
		return MagicCardType::trap;
	}

	return MagicCardType::unknown;
}

//! public:
//* Default Constructor
MagicCard::MagicCard() : name(nullptr), effect(nullptr),
cardType(MagicCardType::unknown) {}

//* Constructor
MagicCard::MagicCard(const char* newName, const char* newEffect,
	const char* newType) : name(nullptr), effect(nullptr), cardType(MagicCardType::unknown) {
	setName(newName);
	setEffect(newEffect);
	setCardType(newType);
}

//* Copy Constructor
MagicCard::MagicCard(const MagicCard& other) {
	copyFrom(other);
}

//* Operator=
MagicCard& MagicCard ::operator=(const MagicCard& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

//* Destructor
MagicCard::~MagicCard() {
	free();
}

void MagicCard::print() const {
	const char* type = getCardType();

	std::cout << "Magic Card Name: " << name << std::endl
		<< "Magic Card Effect: " << effect << std::endl
		<< "Magic Card Type: " << type << std::endl
		<< std::endl;
}

//! Setters===================================
void MagicCard::setName(const char* newName) {
	if (name == newName) {
		return;
	}

	delete[] name;
	int nameSize = strlen(newName);
	name = new char[nameSize + 1];

	strcpy(name, newName);
}
void MagicCard::setEffect(const char* newEffect) {
	if (effect == newEffect) {
		return;
	}

	delete[] effect;
	int effectSize = strlen(newEffect);
	effect = new char[effectSize + 1];

	strcpy(effect, newEffect);
}

void MagicCard::setCardType(const char* type) {
	MagicCardType theRealType = getCardType(type);

	cardType = theRealType;
}

//! Getters===================================
const char* MagicCard::getName() const {
	return name;
}
const char* MagicCard::getEffect() const {
	return effect;
}
const char* MagicCard::getCardType() const {
	switch (cardType) {
	case MagicCardType::buff:
		return BUFF;
		break;
	case MagicCardType::spell:
		return SPELL;
		break;
	case MagicCardType::trap:
		return TRAP;
		break;

	default:
		return UNKNOWN;
		break;
	}
}
const MagicCardType MagicCard::getEnumCardType() const {
	return cardType;
}