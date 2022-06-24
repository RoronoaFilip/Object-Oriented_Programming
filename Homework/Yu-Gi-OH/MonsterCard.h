#pragma once
#include <cstring>
#include <iostream>

#pragma warning(disable : 4996)

class MonsterCard {
	char* name;
	unsigned int attackPoints;
	unsigned int deffPoints;

	void free();

	void copyFrom(const MonsterCard& other);

	bool validatePoints(const int points) const;

public:
	//* Default Constructor
	MonsterCard();

	//* Constructor
	MonsterCard(const char* newName, const int newAttackPoints,
		const int newDeffPoints);

	//* Copy Constructor
	MonsterCard(const MonsterCard& other);

	//* Operator=
	MonsterCard& operator=(const MonsterCard& other);

	//* Destructor
	~MonsterCard();

	void print() const;

	//! Setters===================================
	void setName(const char* newName);
	void setAttackPoints(const int newAttackPoints);
	void setDeffPoints(const int newDeffPoints);

	//! Getters===================================
	const char* getName() const;
	unsigned int getAttackPoints() const;
	unsigned int getDeffPoints() const;
};