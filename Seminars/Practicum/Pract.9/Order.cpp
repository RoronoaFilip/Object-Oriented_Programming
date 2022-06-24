#include "Order.h"

void Order::free() {
  delete[] order;
}
void Order::copyFrom(const Order &other) {
  orderSize = other.orderSize;
  capacity = other.capacity;

  order = new FilipString[capacity];

  for (size_t i = 0; i < orderSize; ++i) {
    order[i] = other.order[i];
  }
}
void Order::resize() {
  capacity *= 2;
  FilipString *temp = new FilipString[capacity];
  for (size_t i = 0; i < orderSize; ++i) {
    temp[i] = order[i];
  }
}

Order::Order() : order(nullptr), orderSize(0), capacity(32) {}

Order::Order(const FilipString toRestaurant)
    : order(nullptr), orderSize(0), capacity(32) {
  restName = toRestaurant;
}
Order::Order(const FilipString toRestaurant,
             const FilipString *newOrder, const size_t newOrderSize)
    : order(nullptr), orderSize(0), capacity(32) {
  restName = toRestaurant;
  orderSize = newOrderSize;

  for (size_t i = 0; i < orderSize; ++i) {
    order[i] = newOrder[i];
  }
}

Order::Order(const Order &other) {
  copyFrom(other);
}
Order &Order::operator=(const Order &other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }

  return *this;
}

Order::~Order() {
  free();
}

bool Order::operator==(const Order &other) const {
  if (orderSize != other.orderSize) {
    return false;
  }

  for (size_t i = 0; i < orderSize; ++i) {
    if (order[i] != other.order[i]) {
      return false;
    }
  }

  return restName == other.restName;
}

void Order::addProductToOrder(const FilipString &newProduct) {
  if (orderSize == capacity) {
    resize();
  }

  order[orderSize++] = newProduct;
}