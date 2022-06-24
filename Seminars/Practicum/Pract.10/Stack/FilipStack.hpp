#include <iostream>

template <typename T>
class FilipStack {
  T *data;

  int put;
  int capacity;

  int get;

private:
  void free();
  void copyFrom(const FilipStack<T> &other);
  void resize();

public:
  FilipStack();

  FilipStack(const FilipStack<T> &other);
  FilipStack &operator=(const FilipStack<T> &other);
  FilipStack(FilipStack<T> &&other);
  FilipStack &operator=(FilipStack<T> &&other);

  ~FilipStack();

  void push(const T &other);
  void pop();
  bool isEmpty() const;
  T &top();
  const T &top() const;
};

template <typename T>
void FilipStack<T>::free() {
  delete[] data;
}
template <typename T>
void FilipStack<T>::copyFrom(const FilipStack &other) {
  capacity = other.capacity;

  data = new T[capacity];
  for (size_t i = 0; i < put; ++i) {
    data[i] = other.data[i];
  }

  get = other.get;
  put = other.put;
}
template <typename T>
void FilipStack<T>::resize() {
  capacity *= 2;

  T *temp = new T[capacity];
  for (size_t i = 0; i < put; ++i) {
    temp[i] = data[i];
  }
}

template <typename T>
FilipStack<T>::FilipStack() {
  put = 0;
  get = 0;

  capacity = 4;
  data = new T[capacity];
}

template <typename T>
FilipStack<T>::FilipStack(const FilipStack<T> &other) {
  copyFrom(other);
}
template <typename T>
FilipStack<T> &FilipStack<T>::operator=(const FilipStack<T> &other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }

  return &this;
}

template <typename T>
FilipStack<T>::FilipStack(FilipStack<T> &&other) : data(other.data), put(other.put),
                                                   get(other.get), capacity(other.capacity) {}
template <typename T>
FilipStack<T> &FilipStack<T>::operator=(FilipStack<T> &&other) {
  if (this != &other) {
    free();
    capacity = other.capacity;

    data = other.data;

    get = other.get;
    put = other.put;
  }

  return &this;
}

template <typename T>
FilipStack<T>::~FilipStack() {
  free();
}

template <typename T>
void FilipStack<T>::push(const T &other) {
  if (put >= capacity) {
    resize();
  }

  get = put;
  data[put++] = other;
}

template <typename T>
void FilipStack<T>::pop() {
  if (put == 0) {
    return;
  }

  --get;
  --put;
}

template <typename T>
bool FilipStack<T>::isEmpty() const {
  return put == 0;
}

template <typename T>
const T &FilipStack<T>::top() const {
  return data[get];
}
template <typename T>
T &FilipStack<T>::top() {
  return data[get];
}