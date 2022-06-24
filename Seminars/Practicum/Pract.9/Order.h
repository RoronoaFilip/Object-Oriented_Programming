#pragma once
#include "FilipString.h"

class Order {
  FilipString restName;
  FilipString *order;

  size_t orderSize;
  size_t capacity;

private:
  void free();
  void copyFrom(const Order &other);
  void resize();

public:
  Order();
  Order(const FilipString toRestaurant);
  Order(const FilipString toRestaurant,
        const FilipString *newOrder, const size_t newOrderSize);

  Order(const Order &other);
  Order &operator=(const Order &other);

  ~Order();

  bool operator==(const Order &other) const;

  void addProductToOrder(const FilipString &newProduct);
};