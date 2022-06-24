#include "ConcreteObserver.h"
#include <iostream>


ConcreteObserver::ConcreteObserver()
{
	mName = "";
}

ConcreteObserver::ConcreteObserver(std::string name)
{
	mName = name;
}


ConcreteObserver::~ConcreteObserver()
{
}

void ConcreteObserver::update(const Currency& updatedCurrency)
{
	std::cout << "Update " << mName << ": "
		<< updatedCurrency.currency << " " << updatedCurrency.rate << std::endl;
	// TO DO update members ...
}