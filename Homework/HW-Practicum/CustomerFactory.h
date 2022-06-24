#pragma once
#include "Customer.h"

class CustomerFactory {
public:
	Customer* createCustomer();
};