#include <iostream>
#include "CentralBank.h"
#include "ConcreteObserver.h"

using namespace std;

int main()
{
	CentralBank bank("BNB");
	
	bank.addCurrency("BGN", 1.00);
	bank.addCurrency("EUR", 1.98);
	bank.addCurrency("USD", 1.69);
	
	ConcreteObserver dsk("DSK");
	ConcreteObserver change("Change buro");
	ConcreteObserver trud("Newspaper Trud");

	bank.registerObserver(&dsk);
	bank.registerObserver(&change);
	bank.registerObserver(&trud);
	
	bank.setRate("USD", 1.96);
	cout << endl;

	bank.unregisterObserver(&dsk);
	bank.setRate("EUR", 2.03);
	cout << endl;
	
    return 0;
}

