#ifndef VECTOR_HEADER
#define VECTOR_HEADER

#include <iostream>

class vector {
private:
  int *data;
  size_t size;
  size_t capacity;

  void free();
  void copyFrom(const vector &);
  void resize(); // x2 memory
  void swap(int &a, int &b);

public:
  vector();
  vector(const int *newData);
  vector(const vector &);

  vector &operator=(const vector &);

  size_t getSize() const;
  void push_back(int);
  void pop_back();
  void clear();
  void reverse();
  void selectionSort();
  size_t findItem(const int item);

  int &operator[](size_t);
  const int operator[](size_t) const;

  ~vector();
};
std::istream &operator>>(std::istream &stream, const vector &myVector);
std::ostream &operator<<(std::ostream stream, const vector &myVector);

#endif
