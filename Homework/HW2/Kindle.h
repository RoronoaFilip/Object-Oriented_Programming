#pragma once
#include "Book.h"
#include "User.h"

class Kindle {
  FilipString name;
  FilipString fileName;

  FilipVector<Book> books;

  FilipVector<User> users;

private:

  int checkIfUserExists(const User& other)const;
  int checkIfBookExists(const Book& other)const;
  size_t printMenu()const;
  
  size_t checkUsername(const FilipString& username)const;


public:
  //* Default Constructor
  Kindle();

  //* Constructor
  Kindle(const FilipString &newName);

  //* Copy Constructor
  Kindle(const Kindle &other);

  //* Operator=
  Kindle &operator=(const Kindle &other);

  //* Move Constructor
  Kindle(Kindle &&other);

  //* Move Operator=
  Kindle &operator=(Kindle &&other);

  //* Destructor
  ~Kindle();

  //* Add Book
  size_t addBook(const Book &newBook);

  //* Add User - register
  User registerUserFromConsole();

  //* Login as an existing User
  int loginAsExistingUser(User& currentUser);

  //* Login to the Kindle
  size_t login();

  //* Write the Kindle to File
  size_t writeKindleToFile() const;

  //* Read Books from File
  size_t readKindleFromFile();

  //* Get Book to Read
  Book getBookToRead() const;

  //* Get Book to Comment
  int getBookToRate() const;

  //* Get Book to Rewrite
  int getBookToRewrite() const;
};
