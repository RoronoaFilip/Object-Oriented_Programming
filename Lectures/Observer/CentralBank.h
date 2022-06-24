#pragma once
#include "Observer.h"
#include <string>
#include <vector>

class CentralBank
{
public:
	CentralBank();
	CentralBank(std::string name);
	~CentralBank();
	void addCurrency(std::string currency, double rate);
	void deleteCurrency(std::string currency);
	void setRate(std::string currency, double rate);
	void registerObserver(Observer* observer);
	void unregisterObserver(Observer* observer);
	void notify(const Currency& updatedCurrency) const;
private:
	std::string mName;
	std::vector<Currency> mCurrencies;
	std::vector<Observer*> mObservers;
};

