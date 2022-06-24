#include "WordCollection.h"

void WordCollection::copyFrom(const WordCollection &other) {
  size = other.size;
  capacity = other.capacity;

  words = new FilipString[capacity];

  for (size_t i = 0; i < size; ++i) {
    words[i] = other.words[i];
  }
}

void WordCollection::free() {
  delete[] words;
}

//* Resize the String once it reaches the size
void WordCollection::resize() {
  FilipString *newArr = new FilipString[capacity * 2];

  for (size_t i = 0; i < size; ++i) {
    newArr[i] = words[i];
  }

  capacity *= 2;

  delete[] words;
  words = newArr;
}

//* Check if the Word Exist
size_t WordCollection::doesWordExist(const FilipString &other) const {
  //! Used to make the Additions to the Collection work like a Union
  //* Any duplicate words will be skipped

  for (size_t i = 0; i < size; ++i) {
    if (words[i] == other) {
      return i + 1;
    }
  }

  return 0;
}

//* Selection Sort
void WordCollection::selectionSort() {
  for (size_t i = 0; i < size - 1; i++) {
    // findMin
    int minElementIndex = i;
    for (size_t j = i + 1; j < size; j++) {
      if (strcmp(words[j].getCharPointer(), words[minElementIndex].getCharPointer()) == -1)
        minElementIndex = j;
    }
    if (minElementIndex != i)
      words[i].swap(words[minElementIndex]);
  }
}

//* Fill the Blank String
void WordCollection::fill() {
  size_t size2 = size;
  for (size_t i = 0; i < size2 - 1; ++i) {
    if (words[i] == "") {
      for (size_t j = size2 - 1; j > i; --j) {
        if (words[j] != "") {
          words[i].swap(words[j]);
          --size;
          break;
        }
      }
    }
  }
}

//* Default Constructor
WordCollection::WordCollection() {
  capacity = 64;
  words = new FilipString[capacity];
  size = 0;
}

//* Copy Constructor
WordCollection::WordCollection(const WordCollection &other) {
  copyFrom(other);
}

//* Operator=
WordCollection &WordCollection::operator=(const WordCollection &other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }

  return *this;
}

//* Destructor
WordCollection::~WordCollection() {
  free();
}

//* Operator+=
WordCollection &WordCollection::operator+=(const WordCollection &other) {
  if (this == &other) {
    return *this;
  }

  for (size_t i = 0; i < other.size; ++i) {
    if (size == capacity) {
      resize();
    }

    if (!doesWordExist(other.words[i])) {
      words[size++] = other.words[i];
    }
  }

  return *this;
}

//* Operator-=
WordCollection &WordCollection::operator-=(const WordCollection &other) {
  for (size_t i = 0; i < other.size; ++i) {
    for (size_t j = 0; j < size; ++j) {
      if (other.words[i] == words[j]) {
        words[j] = "";
        continue;
      }
    }
  }

  fill();

  return *this;
}
//* Operator*=
WordCollection &WordCollection::operator*=(const FilipString &other) {
  if (!doesWordExist(other)) {
    if (size == capacity) {
      resize();
    }
    words[size++] = other;
  }

  return *this;
}

//* Operator/=
WordCollection &WordCollection::operator/=(const FilipString &other) {

  size_t index = size - 1;
  if (doesWordExist(other)) {
    size_t i = 0;
    for (; i < size; ++i) {
      if (words[i] == other) {
        words[i] = "";
        words[i].swap(words[index--]);
        --size;
      }
    }
  }

  return *this;
}

//* Operator[]
bool WordCollection::operator[](const FilipString &other) {
  return doesWordExist(other);
}
const bool WordCollection::operator[](const FilipString &other) const {
  return doesWordExist(other);
}

//* Setters
void WordCollection::addWord(const FilipString &other) {
  *this *= other;
}

//* Getters
size_t WordCollection::getSize() const {
  return size;
}

//* Pring
void WordCollection::print() const {
  for (size_t i = 0; i < size; ++i) {
    words[i].print();
  }
}

//! =====================================================
//* Operator+
WordCollection operator+(const WordCollection &lhs, const WordCollection &rhs) {
  WordCollection result(lhs);
  result += rhs;

  return result;
}

//* Operator-
WordCollection operator-(const WordCollection &lhs, const WordCollection &rhs) {
  WordCollection result(lhs);
  result -= rhs;

  return result;
}

//* Stream Opeartors
std::ostream &operator<<(std::ostream &stream, const WordCollection &myCollection) {
  WordCollection temp = myCollection; //* Copy the Collection so that we can sort it without messing up the current one
  temp.selectionSort();

  for (size_t i = 0; i < temp.size; ++i) {
    if (temp.words[i] != "")
      stream << temp.words[i] << ' ';
  }

  return stream;
}
std::istream &operator>>(std::istream &stream, WordCollection &myCollection) {
  FilipString temp;

  stream >> temp;
  if (!myCollection.doesWordExist(temp)) {
    myCollection *= temp;
  }

  if (myCollection.size >= myCollection.capacity) {
    myCollection.resize();
  }

  return stream;
}

WordCollection &operator>>(WordCollection &myCollection, const FilipString &other) {
  myCollection *= other;

  return myCollection;
}

WordCollection &operator>>(const FilipString &other, WordCollection &myCollection) {
  myCollection >> other;

  return myCollection;
}