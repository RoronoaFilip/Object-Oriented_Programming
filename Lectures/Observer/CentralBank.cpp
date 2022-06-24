#include "CentralBank.h"
#include "Observer.h"


CentralBank::CentralBank()
{
	mName = "";
}


CentralBank::~CentralBank()
{
}

CentralBank::CentralBank(std::string name)
{
	mName = name;
}

void CentralBank::addCurrency(std::string currency, double rate)
{
	Currency newCurrency;
	newCurrency.currency = currency;
	newCurrency.rate = rate;
	mCurrencies.push_back(newCurrency);
}

void CentralBank::deleteCurrency(std::string currency)
{
	for (std::vector<Currency>::iterator it = mCurrencies.begin(); 
		it != mCurrencies.end(); ++it)
	{
		if (it->currency == currency)
		{
			mCurrencies.erase(it);
			break;
		}
	}
}

void CentralBank::setRate(std::string currency, double rate)
{
	for (std::vector<Currency>::iterator it = mCurrencies.begin();
		it != mCurrencies.end(); ++it)
	{
		if (it->currency == currency)
		{
			it->rate = rate;
			notify(*it);
			break;
		}
	}
}

void CentralBank::registerObserver(Observer* observer)
{
	mObservers.push_back(observer);
}

void CentralBank::unregisterObserver(Observer* observer)
{
	for (std::vector<Observer*>::iterator it = mObservers.begin();
		it != mObservers.end(); ++it)
	{
		if (*it == observer)
		{
			mObservers.erase(it);
			break;
		}
	}
}

void CentralBank::notify(const Currency& updatedCurrency) const
{
	for (std::vector<Observer*>::const_iterator it = mObservers.cbegin();
		it != mObservers.cend(); ++it)
	{
		(*it)->update(updatedCurrency);
	}
}