#pragma once
#include "FilipString.h"
#include <fstream>
#include <iostream>

class Page {
	FilipString data;
	size_t size;

public:
	//* Default Constructor
	Page();

	//* Constructor
	Page(const FilipString& newData);

	//* Copy Constructor
	Page(const Page& other);

	//* Operator=
	Page& operator=(const Page& other);

	//* Move Constructor
	Page(Page&& other);

	//* Move Operator=
	Page& operator=(Page&& other);

	//*Operator<<
	friend std::ostream& operator<<(std::ostream& stream, const Page& page);

	//* Set Page
	void setPage(const FilipString& newData);
	//* Set Page
	void setPage(FilipString&& newData);
};