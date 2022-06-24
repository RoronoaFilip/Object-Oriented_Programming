#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#pragma once
//* My Implementation of Vector that works with any kind of Data

#include <iostream>

template <typename T> class FilipVector {
  T *data;

  size_t size;
  size_t capacity;

  //* Delete[] dynamic memory
  void freeMemory();

  //* Copy from other
  void copyFrom(const FilipVector<T> &other);

  //* Resize the data
  void resize();

  //* Calculate the new Capacity
  size_t calculateCapacity(const size_t newCapacity);

public:
  //! ====================================
  //* Default Constructor
  FilipVector();

  //* Copy Constructor
  FilipVector(const FilipVector<T> &other);

  //* Operator=
  FilipVector<T> &operator=(const FilipVector<T> &other);

  //* Move Constructor
  FilipVector(FilipVector<T> &&other);

  //* Move Operator=
  FilipVector<T> &operator=(FilipVector<T> &&other);

  //* Destructor
  ~FilipVector();
  //! ====================================

  //! Operators
  FilipVector<T> &operator+=(const T &other);

  //! Can Throw if Invalid Index
  T &operator[](const size_t index);

  //! Can Throw if Invalid Index
  const T &operator[](const size_t index) const;

  //! ====================================

  //! Other Functions

  //* Clear the Contents
  void clear();

  //* Add a Vector
  void push_back(const T &add);
  //* Add a Vector with Move Semantics
  void push_back(T &&add);

  //* Remove the last Element
  //! Return 0 if good, 2 if Empty
  size_t pop_back();

  //* Insert an Element on the Position
  //! Return 0 if good, 1 if invalid Position
  size_t insert(const T &add, const size_t position);

  //* Insert an Element on the Position with Move Semantics
  //! Return 0 if good, 1 if invalid Position
  size_t insert(T &&add, const size_t position);

  //* Remove the Element on the Position
  //! Return 0 if good, 1 if invalid Position, 2 if Empty
  size_t remove(const size_t position);

  size_t remove(const T &toRemove);

  //* Check if Vector is empty
  const size_t isEmpty() const;

  //* Returns the capacity
  const size_t max_size() const;

  //* Get the Size
  const size_t getSize() const;

  //* Public Resize
  void resize(const size_t newCapacity);

  //* Swap the Contents with another Vector
  void swap(FilipVector<T> &other);
};

//* Delete[] dynamic memory
template <typename T> void FilipVector<T>::freeMemory() { delete[] data; }

//* Copy from other
template <typename T> void FilipVector<T>::copyFrom(const FilipVector &other) {
  size = other.size;
  capacity = other.capacity;

  data = new T[capacity];
  for (size_t i = 0; i < size; ++i) {
    data[i] = other.data[i];
  }
}

//* Resize the data
template <typename T> void FilipVector<T>::resize() {
  capacity *= 2;

  T *temp = new T[capacity];

  for (size_t i = 0; i < size; ++i) {
    temp[i] = data[i];
  }

  delete[] data;
  data = temp;
}

//! ====================================
//* Default Constructor
template <typename T> FilipVector<T>::FilipVector() : size(0), capacity(8) {
  data = new T[capacity];
}

//* Copy Constructor
template <typename T> FilipVector<T>::FilipVector(const FilipVector<T> &other) {
  copyFrom(other);
}

//* Operator=
template <typename T>
FilipVector<T> &FilipVector<T>::operator=(const FilipVector<T> &other) {
  if (this != &other) {
    freeMemory();
    copyFrom(other);
  }

  return *this;
}

//* Move Constructor
template <typename T>
FilipVector<T>::FilipVector(FilipVector<T> &&other)
    : data(other.data), size(other.size), capacity(other.capacity) {}

//* Move Operator=
template <typename T>
FilipVector<T> &FilipVector<T>::operator=(FilipVector<T> &&other) {
  if (this != &other) {
    freeMemory();
    size = other.size;
    capacity = other.capacity;

    data = other.data;
  }

  return *this;
}

//* Destructor
template <typename T> FilipVector<T>::~FilipVector() { freeMemory(); }
//! ====================================

//! Operators
template <typename T>
FilipVector<T> &FilipVector<T>::operator+=(const T &other) {
  push_back(other);

  return *this;
}

template <typename T> T &FilipVector<T>::operator[](const size_t index) {
  if (index < 0 || index >= size) {
    throw "Invalid Index";
  }

  return data[index];
}

template <typename T>
const T &FilipVector<T>::operator[](const size_t index) const {
  if (index < 0 || index >= size) {
    throw "Invalid Index";
  }

  return data[index];
}

//! ====================================

//* Clear the Contents
template <typename T> void FilipVector<T>::clear() {
  freeMemory();
  capacity = 8;
  T *temp = new T[capacity];
  data = temp;
  size = 0;
}

//* Add an Element
template <typename T> void FilipVector<T>::push_back(const T &add) {
  if (size >= capacity) {
    resize();
  }

  data[size++] = add;

  return;
}
//* Add an Element with Move Semantics
template <typename T> void FilipVector<T>::push_back(T &&add) {
  if (size >= capacity) {
    resize();
  }

  data[size++] = add;

  return;
}

//* Remove the last Element
//! Return 0 if good, 2 if Empty
template <typename T> size_t FilipVector<T>::pop_back() {
  if (isEmpty()) {
    return 2;
  }

  --size;

  return 0;
}

//* Insert an Element on the Position
//! Return 0 if good, 1 if invalid Position
template <typename T>
size_t FilipVector<T>::insert(const T &add, const size_t position) {
  if (position < 0 || position > size) {
    return 1;
  }
  if (size + 1 > capacity) {
    resize(size + 1);
  }

  for (size_t i = size; i > position; i--) {
    data[i] = data[i - 1];
  }

  data[position] = add;
  size++;

  return 0;
}

//* Insert an Element on the Position with Move Semantics
//! Return 0 if good, 1 if invalid Position
template <typename T>
size_t FilipVector<T>::insert(T &&add, const size_t position) {
  if (position < 0 || position > size) {
    return 1;
  }
  if (size >= capacity) {
    resize(size + 1);
  }

  for (size_t i = size; i > position; i--) {
    data[i] = data[i - 1];
  }

  data[position] = add;
  size++;

  return 0;
}

//* Remove the Element on the Position
//! Return 0 if good, 1 if invalid Position, 2 if Empty
template <typename T> size_t FilipVector<T>::remove(const size_t position) {
  if (position < 0 || position >= size) {
    return 1;
  }

  if (isEmpty()) {
    return 2;
  }

  for (size_t i = position; i < size - 1; i++) {
    data[i] = data[i + 1];
  }

  size--;

  //* pop_back();

  return 0;
}
template <typename T> size_t FilipVector<T>::remove(const T &toRemove) {
  for (size_t i = 0; i < size; ++i) {
    if (data[i] == toRemove) {
      remove(i);
      return 1;
    }
  }

  return 0;
}

//* Check if Vector is empty
template <typename T> const size_t FilipVector<T>::isEmpty() const {
  return size == 0;
}

//* Returns the capacity
template <typename T> const size_t FilipVector<T>::max_size() const {
  return capacity;
}

//* Get the Size
template <typename T> const size_t FilipVector<T>::getSize() const {
  return size;
}

template <typename T>
size_t FilipVector<T>::calculateCapacity(const size_t newCapacity) {
  size_t result = 8;

  while (result < newCapacity) {
    result *= 2;
  }

  return result;
}

//* Public Resize
template <typename T> void FilipVector<T>::resize(const size_t newCapacity) {
  capacity = calculateCapacity(newCapacity);

  T *temp = new T[capacity];

  for (size_t i = 0; i < size; ++i) {
    temp[i] = data[i];
  }

  delete[] data;
  data = temp;

  size = newCapacity;
}

//* Swap the Contents with another Vector
template <typename T> void FilipVector<T>::swap(FilipVector<T> &other) {
  FilipVector<T> tempVector(*this);
  *this = other;
  other = tempVector;
}