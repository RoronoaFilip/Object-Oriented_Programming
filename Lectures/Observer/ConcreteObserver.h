#pragma once
#include "Observer.h"
#include <string>

class ConcreteObserver : public Observer
{
public:
	ConcreteObserver();
	ConcreteObserver(std::string name);
	~ConcreteObserver();
	virtual void update(const Currency& updatedCurrency);
private:
	std::string mName;
};

