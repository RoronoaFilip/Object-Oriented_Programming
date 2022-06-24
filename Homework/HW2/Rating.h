#pragma once
#include "FilipString.h"


class Rating {
	FilipString name;

	int rate;


public:
	Rating();
	Rating(const FilipString& newName, const int newRate);

	size_t setRate(const int newRate);
	size_t setName(const FilipString& newName);

	const int getRate() const;
	const char* getName() const;

	bool operator==(const Rating& other) const;
	bool operator!=(const Rating& other) const;

	friend std::ostream& operator<<(std::ostream& stream, const Rating& other);
	friend std::istream& operator>>(std::istream& stream, Rating& other);
};

