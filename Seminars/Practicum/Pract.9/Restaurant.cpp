#include "Restaurant.h"
#include <iostream>

void Restaurant::free() {
  delete[] products;
}
void Restaurant::copyFrom(const Restaurant &other) {
  name = other.name;
  productsCount = other.productsCount;
  capacity = other.capacity;

  products = new FilipString[capacity];
  for (size_t i = 0; i < productsCount; ++i) {
    products[i] = other.products[i];
  }
}
void Restaurant::resize() {
  capacity *= 2;
  FilipString *temp = new FilipString[capacity];

  for (size_t i = 0; i < productsCount; ++i) {
    temp[i] = products[i];
  }

  delete[] products;
  products = temp;
}

size_t Restaurant::doesProductExist(const FilipString &other) const {
  for (size_t i = 0; i < productsCount; ++i) {
    if (products[i] == other) {
      return i + 1;
    }
  }

  return 0;
}

Restaurant::Restaurant() : products(nullptr), capacity(32), productsCount(0) {}

Restaurant::Restaurant(const FilipString *newProducts, size_t size)
    : products(nullptr), capacity(32), productsCount(0) {
  setProducts(newProducts, size);
}
Restaurant::Restaurant(const FilipString &newName)
    : products(nullptr), capacity(32), productsCount(0) {
  name = newName;
}

Restaurant::Restaurant(const Restaurant &other) {
  copyFrom(other);
}

Restaurant &Restaurant::operator=(const Restaurant &other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }

  return *this;
}
Restaurant::Restaurant(Restaurant &&other) {
  name = other.name;

  products = other.products;
  other.products = nullptr;

  productsCount = other.productsCount;
  capacity = other.capacity;
}
Restaurant &Restaurant::operator=(Restaurant &&other) {
  if (this != &other) {
    name = other.name;

    products = other.products;
    other.products = nullptr;

    productsCount = other.productsCount;
    capacity = other.capacity;
  }

  return *this;
}

Restaurant::~Restaurant() {
  free();
}

bool Restaurant::operator==(const Restaurant &other) const {
  if (productsCount != other.productsCount) {
    throw false;
  }

  for (size_t i = 0; i < productsCount; ++i) {
    if (products[i] != other.products[i]) {
      throw false;
    }
  }

  return name == other.name;
}

void Restaurant::setProducts(const FilipString *newProducts, size_t size) {
  delete[] products;

  for (size_t i = 0; i < size; ++i) {
    products[productsCount++] = newProducts[i];
  }
}

void Restaurant::addProduct(const FilipString &other) {
  if (!doesProductExist(other)) {
    return;
  }

  if (productsCount == capacity) {
    resize();
  }

  products[productsCount++] = other;
}