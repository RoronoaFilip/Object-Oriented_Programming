#pragma once
#include "FilipString.h"
#include "Order.h"
#include <cstring>

class Restaurant {
  FilipString name;
  FilipString *products;

  size_t productsCount;
  size_t capacity;

  void free();
  void copyFrom(const Restaurant &other);
  void resize();

public:
  Restaurant();
  Restaurant(const FilipString *newProducts, size_t size);
  Restaurant(const FilipString &newName);

  Restaurant(const Restaurant &other);
  Restaurant &operator=(const Restaurant &other);

  Restaurant(Restaurant &&other);
  Restaurant &operator=(Restaurant &&other);

  ~Restaurant();

  bool operator==(const Restaurant &other) const;

  void setProducts(const FilipString *newProducts, size_t size);

  size_t doesProductExist(const FilipString &other) const;
  void addProduct(const FilipString &other);
};