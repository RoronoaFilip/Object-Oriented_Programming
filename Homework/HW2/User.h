#pragma once

#include "Book.h"
#include "FilipString.h"

class User {
  FilipString username;
  FilipString password;

  FilipString fileName;

  int *writenBooks;
  size_t capacityWriten;
  size_t sizeWriten;

  int *readBooks;
  size_t capacityRead;
  size_t sizeRead;

  void freeMemory();

  void copyFrom(const User &other);

  void resizeWriten();
  void resizeRead();

  int checkIfBookExists(const int index) const;

public:
  //* Default Constructor
  User();

  //* Constructor
  User(const FilipString &newUsername, const FilipString &newPassword);

  //* Constructor for File
  User(const char *filePath);

  //* Copy Constructor
  User(const User &other);

  //* Operator=
  User &operator=(const User &other);

   //* Move Constructor
   User(User &&other);

   //* Move Operator=
   User &operator=(User &&other);

  //* Destructor
  ~User();

  //* Operator==
  bool operator==(const User& other) const;

  //! ====================================

  //* Pass in a Book and start Reading
  size_t readBook(const Book &book);

  //* Add the read Book to the Attay of read Books
  size_t addReadBook(const int index);

  //* Write a new Book
  Book writeBook()const;

  //* Write a new Book
  void rewriteBook(Book& rewriteThis) const;

  //* Add the writed Book to the Array of writen Books
  size_t addWritenBook(const int index);

  //* Comment the passed in Book
  size_t comment(Book &commentBook) const;

  //* Read the Comments of the Book
  size_t readComments(const Book &readCommentsBook) const;

  //* Write User to File
  size_t writeUserToFile() const;

  //* Read User from File
  size_t readUserFromFile();

  //* Get the Name of the File
  const FilipString getFileName() const;

  //* Check if the Book is already Read
  size_t isRead(const int index) const;

  //* Check if the Book is Writen by Current User
  size_t isWriten(const int index) const;

  //* Make a Comment to a Book
  const FilipString makeComment() const;

  //* Return the Name of the User
  const FilipString getUsername()const;

  //* Input your Rating for the Book
  const int makeRating() const;
};