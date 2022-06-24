#pragma once
#include "Order.h"
#include "Restaurant.h"

class FoodPanda {
  Order *orders;
  Restaurant *restaurants;

  size_t restaurantsCount;
  size_t ordersCount;

  size_t ordersCapacity;
  size_t restaurantsCapacity;

  void free();
  void copyFrom(const FoodPanda &other);
  void resizeOrders();
  void resizeRestaurants();

  size_t doesRestaurantExist(const Restaurant &other) const;
  size_t doesOrderExist(const Order &other) const;

public:
  FoodPanda();
  FoodPanda(const size_t newOrdersCount);

  FoodPanda(const FoodPanda &other);
  FoodPanda &operator=(const FoodPanda &other);

  FoodPanda(FoodPanda &&other);
  FoodPanda &operator=(FoodPanda &&other);

  ~FoodPanda();

  void addRestaurant(const Restaurant &newRestaurant);
  void addOrder(const Order &newOrder);

  size_t makeOrder();
};
