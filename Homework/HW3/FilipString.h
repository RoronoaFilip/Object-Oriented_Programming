//* My Implementation of String

#pragma once
#include <cstring>
#include <iostream>

class FilipString {
  char *data;
  size_t size;

  //* Copy Function for dynamic Memory
  void copyFrom(const FilipString &other);

  //* Delete all of the dynamic Memory
  void freeMemory();

  //* Copy Array
  //! Note: start and end are not Indexes
  char *copyString(const size_t newArrSize, const size_t start,
                   const size_t end) const;

public:
  //! ==========================================================
  //! Constructor, Destructor, (Move)Operator=, Copy/Move Constructor

  //* Default Constructor
  FilipString();

  //* Constructor to set the String
  FilipString(const char *newString);

  //* Copy Constructor
  FilipString(const FilipString &other);

  //* Operator=
  FilipString &operator=(const FilipString &other);

  //* Move Constructor
  FilipString(FilipString &&other);

  //* Move operator=
  FilipString &operator=(FilipString &&other);

  //* Destructor
  ~FilipString();

  //! ===========================================================
  //* Operators
  FilipString &operator+=(const FilipString &other);
  bool operator==(const FilipString &other) const;
  bool operator!=(const FilipString &other) const;
  bool operator<(const FilipString &other) const;
  bool operator<=(const FilipString &other) const;
  bool operator>(const FilipString &other) const;
  bool operator>=(const FilipString &other) const;
  friend std::istream &operator>>(std::istream &stream, FilipString &myString);
  friend std::ostream &operator<<(std::ostream &stream,
                                  const FilipString &myString);

  //! Care For Exceptions
  char operator[](const size_t index);
  //! Care For Exceptions
  const char operator[](const size_t index) const;

  //! ===========================================================

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
  //! NOTE: start and end are not INDEXES
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

FilipString operator+(const FilipString &lhs, const FilipString &rhs);