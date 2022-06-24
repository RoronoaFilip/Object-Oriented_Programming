#pragma once
#include "MagicCardType.h"
#include <cstring>
#include <iostream>

#pragma warning(disable : 4996)

const char BUFF[] = "buff";
const char TRAP[] = "trap";
const char SPELL[] = "spell";
const char UNKNOWN[] = "unknown";

class MagicCard {
	char* name;
	char* effect;
	MagicCardType cardType;

	void free();

	void copyFrom(const MagicCard& other);

	MagicCardType getCardType(const char* type) const;

public:
	//* Default Constructor
	MagicCard();

	//* Constructor
	MagicCard(const char* newName, const char* newEffect,
		const char* newType);

	//* Copy Constructor
	MagicCard(const MagicCard& other);

	//* Operator=
	MagicCard& operator=(const MagicCard& other);

	//* Destructor
	~MagicCard();

	void print() const;

	//! Setters===================================
	void setName(const char* newName);
	void setEffect(const char* newEffect);
	void setCardType(const char* type);

	//! Getters===================================
	const char* getName() const;
	const char* getEffect() const;
	const char* getCardType() const;
	const MagicCardType getEnumCardType() const;
};