#include "FoodPanda.h"

void FoodPanda::free() {
  delete[] orders;
  delete[] restaurants;
}
void FoodPanda::copyFrom(const FoodPanda &other) {
  restaurantsCount = other.restaurantsCount;
  ordersCount = other.ordersCount;

  ordersCapacity = other.ordersCapacity;
  restaurantsCapacity = other.restaurantsCapacity;

  orders = new Order[ordersCapacity];
  restaurants = new Restaurant[restaurantsCapacity];

  for (size_t i = 0; i < ordersCount; ++i) {
    orders[i] = other.orders[i];
  }
  for (size_t i = 0; i < restaurantsCount; ++i) {
    restaurants[i] = other.restaurants[i];
  }
}
void FoodPanda::resizeOrders() {
  ordersCapacity *= 2;
  Order *temp = new Order[ordersCapacity];

  for (int i = 0; i < ordersCount; ++i) {
    temp[i] = orders[i];
  }

  delete[] orders;
  orders = temp;
}
void FoodPanda::resizeRestaurants() {
  restaurantsCapacity *= 2;
  Restaurant *temp = new Restaurant[restaurantsCapacity];

  for (int i = 0; i < restaurantsCount; ++i) {
    temp[i] = restaurants[i];
  }

  delete[] restaurants;
  restaurants = temp;
}

size_t FoodPanda::doesRestaurantExist(const Restaurant &other) const {
  for (size_t i = 0; i < restaurantsCount; ++i) {
    if (restaurants[i] == other) {
      return i + 1;
    }
  }

  return false;
}

size_t FoodPanda::doesOrderExist(const Order &other) const {
  for (size_t i = 0; i < ordersCount; ++i) {
    if (orders[i] == other) {
      return i + 1;
    }
  }

  return false;
}

FoodPanda::FoodPanda()
    : restaurants(nullptr), orders(nullptr),
      restaurantsCapacity(32), ordersCapacity(32),
      restaurantsCount(0), ordersCount(0) {}

FoodPanda::FoodPanda(const size_t newOrdersCount)
    : restaurants(nullptr), orders(nullptr),
      restaurantsCapacity(32), ordersCapacity(32),
      restaurantsCount(0), ordersCount(newOrdersCount) {}

FoodPanda::FoodPanda(const FoodPanda &other) {
  copyFrom(other);
}
FoodPanda &FoodPanda::operator=(const FoodPanda &other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }

  return *this;
}

FoodPanda::FoodPanda(FoodPanda &&other) {
  restaurantsCount = other.restaurantsCount;
  ordersCount = other.ordersCount;

  ordersCapacity = other.ordersCapacity;
  restaurantsCapacity = other.restaurantsCapacity;

  restaurants = other.restaurants;
  orders = other.orders;
}
FoodPanda &FoodPanda::operator=(FoodPanda &&other) {
  if (this != &other) {
    restaurantsCount = other.restaurantsCount;
    ordersCount = other.ordersCount;

    ordersCapacity = other.ordersCapacity;
    restaurantsCapacity = other.restaurantsCapacity;

    restaurants = other.restaurants;
    orders = other.orders;
  }

  return *this;
}

FoodPanda::~FoodPanda() {
  free();
}

void FoodPanda::addRestaurant(const Restaurant &newRestaurant) {
  if (restaurantsCount == restaurantsCapacity) {
    resizeRestaurants();
  }

  if (doesRestaurantExist(newRestaurant)) {
    return;
  }

  restaurants[restaurantsCount++] = newRestaurant;
}

void FoodPanda::addOrder(const Order &newOrder) {
  if (ordersCount == ordersCapacity) {
    resizeRestaurants();
  }

  orders[ordersCount++] = newOrder;
}

size_t FoodPanda::makeOrder() {
  bool isAllGood = true;

  Restaurant restaurant1("Raffy");
  restaurant1.addProduct("Burger");
  restaurant1.addProduct("Pizza");

  Restaurant restaurant2("McDonalds");
  restaurant1.addProduct("Bokluk");
  restaurant1.addProduct("Trash");

  addRestaurant(restaurant1);
  addRestaurant(restaurant2);

  while (true) {
    size_t OrderTime = 1; //* Minute

    FilipString restaurantName;
    std::cout << "Enter a Restaurant name: ";
    std::cin >> restaurantName;

    if (restaurantName == "exit") {
      return 0;
    }

    Restaurant restaurant(restaurantName);

    if (!doesRestaurantExist(restaurant)) {
      std::cout << "Restaurant doesn't exist! Please try again!" << std::endl;
    }

    size_t numberOfProducts;
    std::cin >> numberOfProducts;

    std::cout << "Enter Products you want:" << std::endl;

    Order newOrder(restaurantName);
    size_t currentProduct = 0;

    while (currentProduct != numberOfProducts) {
      FilipString product;
      std::cin >> product;
      try {
        restaurant.doesProductExist(product);
      } catch (bool b) {
        if (b) {
          std::cout << "Product added!" << std::endl;
        } else {
          std::cout << "This Restaurant doesn't offer this product! Please try again!" << std::endl
                    << std::endl;
          isAllGood = false;
          break;
        }
      }

      newOrder.addProductToOrder(product);
      ++currentProduct;
    }

    if (!isAllGood) {
      continue;
    } else {
      return numberOfProducts * 15;
    }
  }

  return 0;
}