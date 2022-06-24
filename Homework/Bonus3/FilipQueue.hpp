#pragma once
#include <exception>
#include <iostream>
template <typename T>
class FilipQueue {
  T *data;
  size_t capacity;
  size_t size;

  size_t get;
  size_t put;

  void resize();

  void copyFrom(const FilipQueue<T> &other);
  void free();

public:
  FilipQueue();

  FilipQueue(const FilipQueue<T> &other);
  FilipQueue<T> &operator=(const FilipQueue<T> &other);

  void push(const T &obj);
  void push(T &&obj); //* Move semantics
  void pop();

  const T &peek() const;
  bool isEmpty() const;

  ~FilipQueue();
};

template <typename T>
void FilipQueue<T>::resize() {
  T *resizedData = new T[capacity * 2];
  for (size_t i = 0; i < size; i++) {
    resizedData[i] = data[get];
    (++get) %= capacity;
  }
  capacity *= 2;
  delete[] data;
  data = resizedData;
  get = 0;
  put = size;
}

template <typename T>
void FilipQueue<T>::copyFrom(const FilipQueue<T> &other) {
  data = new T[other.capacity];
  for (int i = 0; i < other.capacity; i++) {
    data[i] = other.data[i];
  }

  get = other.get;
  put = other.put;

  size = other.size;
  capacity = other.capacity;
}

template <typename T>
void FilipQueue<T>::free() {
  delete[] data;
}

template <typename T>
FilipQueue<T>::FilipQueue() {
  capacity = 4;
  data = new T[capacity];
  size = 0;
  get = put = 0;
}

template <typename T>
FilipQueue<T>::FilipQueue(const FilipQueue<T> &other) {
  copyFrom(other);
}

template <typename T>
FilipQueue<T> &FilipQueue<T>::operator=(const FilipQueue<T> &other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }
  return *this;
}

template <typename T>
FilipQueue<T>::~FilipQueue() {
  free();
}

template <typename T>
void FilipQueue<T>::push(const T &obj) {
  if (size == capacity) {
    resize();
  }

  data[put] = obj; // operator=
  (++put) %= capacity;
  size++;
}

template <typename T>
void FilipQueue<T>::push(T &&obj) {
  if (size == capacity) {
    resize();
  }

  data[put] = obj; // move operator =
  (++put) %= capacity;
  size++;
}

template <typename T>
bool FilipQueue<T>::isEmpty() const {
  return size == 0;
}

template <typename T>
const T &FilipQueue<T>::peek() const {
  if (isEmpty()) {
    throw std::logic_error("Empty queue!");
  }

  return data[get];
}

template <typename T>
void FilipQueue<T>::pop() {
  if (isEmpty()) {
    throw std::logic_error("Empty queue!");
  }
  (++get) %= capacity;
  size--;
}