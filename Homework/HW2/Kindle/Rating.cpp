#include "Rating.h"

Rating::Rating() : name() {
	rate = -1;
}

Rating::Rating(const FilipString& newName, const int newRate) {
	setName(newName);
	setRate(newRate);
}

size_t Rating::setRate(const int newRate) {
	if (newRate >= 0 && newRate <= 10) {
		rate = newRate;
	} else {
		rate = -1;
	}
	
	return 1;
}

size_t Rating::setName(const FilipString& newName) {
	name = newName;

	return 1;
}

const int Rating::getRate() const {
	return rate;
}

const char* Rating::getName() const
{
	return name.getCharPointer();
}

bool Rating::operator==(const Rating& other) const {
	return name == other.name;
}

bool Rating::operator!=(const Rating& other) const
{
	return !(* this == other);
}

std::ostream& operator<<(std::ostream& stream, const Rating& other) {
	stream << other.name << " " << other.rate ;

	return stream;
}

std::istream& operator>>(std::istream& stream,  Rating& other) {
	char temp[100];
	stream >> temp;
	other.setName(temp);

	int rating;
	stream >> rating;
	other.setRate(rating);

	return stream;
}
