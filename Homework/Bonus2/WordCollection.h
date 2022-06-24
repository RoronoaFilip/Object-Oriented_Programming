#include "FilipString.h"
#include <iostream>
class WordCollection {
private:
  FilipString *words;
  size_t capacity; //* The current Capacity (dynamic size)
  size_t size;     //* The current Index

  void copyFrom(const WordCollection &other);

  void free();

  //* Resize the String once it reaches the size
  void resize();

  //* Check if the Word Exist
  size_t doesWordExist(const FilipString &other) const;

  //* Selection Sort
  void selectionSort();

  //* Rearange Blank Strings at the End and
  void fill();

public:
  //* Default Constructor
  WordCollection();

  //* Copy Constructor
  WordCollection(const WordCollection &other);

  //* Operator=
  WordCollection &operator=(const WordCollection &other);

  //* Destructor
  ~WordCollection();

  //* Operators
  WordCollection &operator+=(const WordCollection &other);
  WordCollection &operator-=(const WordCollection &other);
  WordCollection &operator*=(const FilipString &other);
  WordCollection &operator/=(const FilipString &othe);
  bool operator[](const FilipString &other);
  const bool operator[](const FilipString &other) const;

  //* Stream Operators
  friend std::ostream &operator<<(std::ostream &stream, const WordCollection &myCollection);
  friend WordCollection &operator>>(WordCollection &myCollection, const FilipString &other);
  friend WordCollection &operator>>(const FilipString &other, WordCollection &myCollection);
  friend std::istream &operator>>(std::istream &stream, WordCollection &myCollection);

  //* Setters
  void addWord(const FilipString &other);

  //* Getters
  size_t getSize() const;

  //* Print
  void print() const;
};

//* Other Operators
WordCollection operator+(const WordCollection &lhs, const WordCollection &rhs);
WordCollection operator-(const WordCollection &lhs, const WordCollection &rhs);
