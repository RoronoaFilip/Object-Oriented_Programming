#pragma once

#include "FilipVector.hpp"
#include "Page.h"
#include "Rating.h"
#include <fstream>
#include <iostream>
class Book {
	FilipString name;
	FilipString author;

	FilipString fileName;

	FilipVector<Page> pages;

	FilipVector<FilipString> comments;
	FilipVector<FilipString> commentators;

	FilipVector<Rating> ratings;

	double avarageRate;

private:
	//* Print all Pages
	size_t printPages() const;

	int checkIfRatingExists(const Rating& other) const;

public:
	//* Default Constructor
	Book();

	//* Constructor
	Book(const FilipString newName, const FilipString newAuthor);

	Book(const char* filePath);

	//* Copy Constructor
	Book(const Book& other);

	//* Operator=
	Book& operator=(const Book& other);

	//* Move Constructor
	Book(Book&& other);

	//* Move Operator=
	Book& operator=(Book&& other);

	friend std::ostream& operator<<(std::ostream& stream, const Book& book);

	bool operator==(const Book& other) const;

	//!===============================

	//* Print the Book
	size_t print() const;

	//* Read the Book
	size_t read() const;

	//* Get File Name
	const FilipString getFileName() const;

	//* Read Pages from File
	size_t readBookFromFile(const char* filePath);

	//* Save the Book to File
	size_t saveBookToFile() const;

	//* Set the Name
	void setName(const FilipString& newName);
	void setName(FilipString&& newName);
	//* Set the Author
	void setAuthor(const FilipString& newAuthor);
	void setAuthor(FilipString&& newAuthor);


	//! Actions with Pages
	//* Add a new Page
	size_t addPage(const Page& newPage);

	//* Print a certain Page
	size_t printPage(const size_t pageNumber) const;

	//* Change an existing Page
	size_t changePage(const size_t pageNumber, const Page& editedPage);

	//! Actions with Comments
	//* Add a Comment
	size_t addComment(const FilipString& newComment, const FilipString& user);

	//* Print all the Comments along with the Commentators
	size_t printComments() const;

	//* Add Rate
	size_t addRating(const int rate, const FilipString& name);

	//* Calculate the avarage Rate
	size_t calculateAvarageRating();

	//* Get the avarage Rate
	const double getAvarageRate()const;

	//* Delete a Page of the Book
	size_t deletePage(const size_t pageIndex);
};