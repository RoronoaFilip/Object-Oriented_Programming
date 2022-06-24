#include "CustomerFactory.h"

Customer* CustomerFactory::createCustomer() {
	std::cout << "Enter Name: ";
	FilipString name;
	std::cin >> name;

	std::cout << "Enter Address: ";
	FilipString address;
	std::cin >> address;

	std::cout << "Enter ID: ";
	size_t id;
	std::cin >> id;

	return new Customer(name, address, id);
}