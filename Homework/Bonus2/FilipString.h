#pragma once
#include <cstring>
#include <iostream>
class FilipString {
  char *string;
  size_t size;

  //* Copy Function for dynamic Memory
  void copyFrom(const FilipString &other);

  //* Delete all of the dynamic Memory
  void free();

  //* Copy Array
  //! Note: start and end are not Indexes
  char *copyString(const size_t newArrSize, const size_t start, const size_t end) const;

public:
  //! ==========================================================
  //! Constructor, Destructor, Operator=, Copy Constructor

  //* Default Constructor
  FilipString();

  //* Constructor to set the String
  FilipString(const char *newString);

  //* Copy Constructor - create a new Object of type FilipString
  FilipString(const FilipString &other);

  //* Operator= - Modify an EXISTING Object of type FilipString
  FilipString &operator=(const FilipString &other);

  //* Destructor - delete[] dynamic Memory
  ~FilipString();

  //! ===========================================================
  //* Operators
  bool operator==(const FilipString &other) const;
  bool operator!=(const FilipString &other) const;
  bool operator<(const FilipString &other) const;
  bool operator>(const FilipString &other) const;
  friend std::istream &operator>>(std::istream &stream, FilipString &myString);
  friend std::ostream &operator<<(std::ostream &stream, FilipString &myString);
  char operator[](const size_t index);
  const char operator[](const size_t index) const;

  //* Print the String
  void print() const;

  //! Getters and Setters ===============================================
  //* Get the Size of the String
  int getSize() const;

  //* Set a new String
  void setString(const FilipString &other);

  //* Get a const Pointer to the String
  const char *getCharPointer() const;

  //* Get a const Pointer to the String
  //! A NEW POINTER
  const char *getCharPointerNew() const;

  //! Other Functions ================================================

  //* Get a Substring from the String - a new char Array
  //! Note: start and end are not Indexes
  const char *substring(const size_t start, const size_t end) const;

  //* Check if String is empty
  bool isEmpty() const;

  //* Swap constents with Other
  void swap(FilipString &other);

  //* Concatenate 2 Strings
  void concatenate(const FilipString &other);

  //* Add a String to the End
  void push_back(const FilipString &other);

  //* Add a Symbol to the End
  void push_back(const char add);

  //* Remove a Symbol from the End
  void pop_back();

  //* Clear and Reset the String
  void clear();
};