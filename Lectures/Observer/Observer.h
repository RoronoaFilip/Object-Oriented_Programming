#pragma once
#include "Currency.h"

class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void update(const Currency& updatedCurrency) = 0;
};

