#pragma once
#include "FilipQueue.hpp"
#include "FilipVector.hpp"

template <typename T>
class kPriorityQueue {
  FilipVector<FilipQueue<T>> queue;
  size_t priority;

public:
  kPriorityQueue(const size_t newPriority);

  void push(const T &obj, const size_t withPriority);
  void pop();
  const T &peek() const;

  bool isEmpty() const;
};

template <typename T>
kPriorityQueue<T>::kPriorityQueue(const size_t newPriority) : priority(newPriority) {
  for (size_t i = 0; i <= priority; ++i) {
    queue.push_back(FilipQueue<T>());
  }
}

template <typename T>
void kPriorityQueue<T>::push(const T &obj, const size_t withPriority) {
  if (withPriority < 0 || withPriority > priority) {
    return;
  }

  queue[withPriority].push(obj);

  return;
}
template <typename T>
void kPriorityQueue<T>::pop() {
  for (size_t i = priority; i >= 0; --i) {
    if (!queue[i].isEmpty()) {
      return queue[i].pop();
    }
  }
}

template <typename T>
const T &kPriorityQueue<T>::peek() const {
  for (size_t i = priority; i >= 0; --i) {
    if (!queue[i].isEmpty()) {
      return queue[i].peek();
    }
  }
}

template <typename T>
bool kPriorityQueue<T>::isEmpty() const {
  for (size_t i = priority; i >= 0; --i) {
    if (!queue[i].isEmpty()) {
      return false;
    }
  }

  return true;
}