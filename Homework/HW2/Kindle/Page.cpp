#include <cstdlib>
#include "Page.h"

//* Default Constructor
Page::Page() : data() {
	size = 0;
}

//* Constructor
Page::Page(const FilipString& newPage) {
	setPage(newPage);
}

//* Copy Constructor
Page::Page(const Page& other) : data(other.data), size(other.size) {}

//* Operator=
Page& Page::operator=(const Page& other) {
	if (this != &other) {
		data = other.data;
		size = other.size;
	}

	return *this;
}

//* Move Constructor
Page::Page(Page&& other) : data(other.data), size(other.size) {
}

Page& Page::operator=(Page&& other) {
	if (this != &other) {
		data = other.data;
		size = other.size;
	}

	return *this;
}

//*Operators
std::ostream& operator<<(std::ostream& stream, const Page& page) {
	stream << page.data;

	return stream;
}

//* Set Page
void Page::setPage(const FilipString& newData) {
	size = newData.getSize();
	data = newData;
}
//* Set Page
void Page::setPage(FilipString&& newData) {
	size = newData.getSize();
	data = newData;
}
