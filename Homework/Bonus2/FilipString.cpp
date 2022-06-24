#include "FilipString.h"
#include <cstring>
#include <iostream>

#pragma warning(disable : 4996)

//* Copy Function for dynamic Memory
void FilipString::copyFrom(const FilipString &other) {
  string = new char[strlen(other.string) + 1];

  strcpy(string, other.string);

  size = other.size;
}

//* Delete all of the dynamic Memory
void FilipString::free() { delete[] string; }

//* Copy Array
//! Note: start and end are not Indexes
char *FilipString::copyString(const size_t newArrSize, const size_t start,
                              const size_t end) const {

  char *newArr = new char[newArrSize];
  size_t newArrIndex = 0;
  for (size_t i = start - 1; i < end; ++i) {
    newArr[newArrIndex++] = string[i];
  }

  newArr[newArrSize] = '\0';

  return newArr;
}

//! public:

//! ==========================================================
//! Constructor, Destructor, Operator=, Copy Constructor

//* Default Constructor
FilipString::FilipString() {
  string = new char[1];
  string[0] = '\0';
  size = 0;
}

//* Constructor to set the String
FilipString::FilipString(const char *newString) {
  size = strlen(newString);
  string = new char[size + 1];
  strcpy(string, newString);
}

//* Copy Constructor - create a new Object of type FilipString
FilipString::FilipString(const FilipString &other) { copyFrom(other); }

//* Operator= - Modify an EXISTING Object of type FilipString
FilipString &FilipString::operator=(const FilipString &other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }
  return *this;
}

//*Destructor - delete[] dynamic Memory
FilipString::~FilipString() { free(); }

//! ===========================================================

void FilipString::print() const { std::cout << string << std::endl; }

//! Getters and Setters ===============================================

//* Get the Size of the String
int FilipString::getSize() const { return size; }

//* Get a const Pointer to the String
const char *FilipString::getCharPointer() const { return string; }

//* Get a const Pointer to the String
//! A NEW POINTER
const char *FilipString::getCharPointerNew() const {
  char *temp = new char[size];

  strcpy(temp, string);

  return temp;
}

//* Set a new String
void FilipString::setString(const FilipString &other) {
  if (this == &other || strcmp(string, other.string) == 0) {
    return;
  }

  free();
  size = strlen(other.string);
  string = new char[size + 1];
  strcpy(string, other.string);
}

//! Other Functions ================================================

//* Get a Substring from the String - a new char Array
//! Note: start and end are not Indexes
const char *FilipString::substring(const size_t start, const size_t end) const {
  size_t newStringSize = end - start + 2;
  char *newString = new char[newStringSize];

  size_t newStringIndex = 0;

  for (size_t i = start - 1; i < end; ++i) {
    newString[newStringIndex++] = string[i];
  }

  newString[newStringIndex] = '\0';

  return newString;
}

//* Check if String is empty
bool FilipString::isEmpty() const { return (size == 0); }

//* Swap constents with Other
void FilipString::swap(FilipString &other) {
  FilipString temp = *this;
  *this = other;
  other = temp;
}

//* Concatenate 2 Strings
void FilipString::concatenate(const FilipString &other) {
  char *temp = new char[getSize() + other.getSize() + 1];
  strcpy(temp, string);
  strcat(temp, other.string);

  delete[] string;
  string = temp;
  size += other.getSize();
}

//* Add a String to the End
void FilipString::push_back(const FilipString &other) { concatenate(other); }

//* Add a Symbol to the End
void FilipString::push_back(const char other) {
  char *temp = new char[size + 1];
  temp = string;
  temp[size++] = other;

  free();
  string = temp;
}

//* Remove a Symbol from the End
void FilipString::pop_back() {
  if (size - 1 <= 0) {
    string[0] = '\0';
    return;
  }

  --size;

  char *temp = new char[size];

  int tempIndex = 0;
  for (int i = 0; i < size; ++i) {
    temp[tempIndex++] = string[i];
  }

  temp[tempIndex] = '\0';

  free();
  string = temp;
}

//* Clear and Reset the String
void FilipString::clear() {
  if (size != 0) {
    free();
    copyFrom("");
  }

  return;
}

//* Operator==
bool FilipString::operator==(const FilipString &other) const {
  return (strcmp(string, other.string) == 0);
}

//* Operator!=
bool FilipString::operator!=(const FilipString &other) const {
  return !(string == other.string);
}

//* Operator<
bool FilipString::operator<(const FilipString &other) const {
  return strcmp(string, other.string) == -1;
}

//* Operator<
bool FilipString::operator>(const FilipString &other) const {
  return strcmp(string, other.string) == 1;
}

//* Operator>>
std::istream &operator>>(std::istream &stream, FilipString &myString) {
  char input[1024];
  stream >> input;
  myString.push_back(input);

  return stream;
}

//* Operator<<
std::ostream &operator<<(std::ostream &stream, FilipString &myString) {
  stream << myString.string;

  return stream;
}

//* Operator[]
char FilipString::operator[](const size_t index) {
  if (index >= size) {
    return '~';
  }

  return string[index];
}
//* Operator[]
const char FilipString::operator[](const size_t index) const {
  if (index >= size) {
    return '~';
  }

  return string[index];
}
