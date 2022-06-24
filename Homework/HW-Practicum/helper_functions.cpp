#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "helper_functions.h"
#include "Bank.h"
#include "CustomerFactory.h"
#include "AccountFactory.h"
#include "FilipString.h"
#include <iostream>

void printMainMenu() {
	std::cout << std::endl
		<< "Menu: " << std::endl
		<< "1 - Edit" << std::endl
		<< "2 - List" << std::endl
		<< "3 - Action" << std::endl
		<< "4 - Display Info for the Bank" << std::endl
		<< "5 - Quit" << std::endl
		<< "h - Print Main Menu again" << std::endl;
}

void printEditMenu() {
	std::cout << std::endl
		<< "Edit Menu: " << std::endl
		<< "a - Add Customer" << std::endl
		<< "b - Delete Customer" << std::endl
		<< "c - Add Account" << std::endl
		<< "d - Delete Account" << std::endl;
}
void printListMenu() {
	std::cout << std::endl
		<< "Edit Menu: " << std::endl
		<< "a - List all Customers" << std::endl
		<< "b - List all Accounts" << std::endl
		<< "c - List Customer Accounts" << std::endl
		<< "d - List log" << std::endl;
}
void printActionMenu() {
	std::cout << std::endl
		<< "Edit Menu: " << std::endl
		<< "a - Deposit" << std::endl
		<< "b - Withdraw" << std::endl
		<< "c - Transfer" << std::endl;
}

void consoleInterface() {

	CustomerFactory custFact;
	AccountFactory accFact;

	Customer* currentCustomer = custFact.createCustomer();

	printMainMenu();
	Bank bank1("Reiffeisen Bank", "DDZ");
	bank1.addCustomer(*currentCustomer);
	while (true) {
		std::cout << "Enter your Choice: ";
		char symbol;
		std::cin >> symbol;
		std::cin.ignore();

		Account* ptr;
		size_t sum;
		FilipString ibanTemp;
		FilipString ibanTemp2;
		switch (symbol) {
		case '1':
			printEditMenu();
			std::cout << "Enter your Choice: ";
			char editSymbol;
			std::cin >> editSymbol;
			std::cin.ignore();


			Customer* temp;
			switch (editSymbol) {
			case 'a':
				temp = custFact.createCustomer();
				bank1.addCustomer(*temp);
				delete temp;
				continue;
				break;
			case 'b':
				temp = custFact.createCustomer();
				bank1.deleteCustomer(*temp);
				delete temp;
				continue;
				break;
			case 'c':
				ptr = accFact.createAccount(*currentCustomer);
				bank1.addAccount(*ptr);
				delete ptr;
				continue;
				break;
			case 'd':
				ptr = accFact.createAccount(*currentCustomer);
				bank1.deleteAccount(*ptr);
				delete ptr;
				continue;
				break;
			default:
				continue;
				break;
			}
			break;
		case '2':
			printListMenu();
			std::cout << "Enter your Choice: ";
			char listSymbol;
			std::cin >> listSymbol;
			std::cin.ignore();

			switch (listSymbol) {
			case 'a':
				bank1.listCustomers();
				continue;
				break;
			case 'b':
				bank1.listAccounts();
				continue;
				break;
			case 'c':
				temp = custFact.createCustomer();
				bank1.listCustomerAccounts(*temp);
				delete temp;
				continue;
				break;
			case 'd':
				bank1.listLogs();
				continue;
				break;
			default:
				continue;
				break;
			}
			break;
		case '3':
			printActionMenu();
			std::cout << "Enter your Choice: ";
			char actionSymbol;
			std::cin >> actionSymbol;
			std::cin.ignore();
			switch (actionSymbol) {
			case 'a':
				ptr = accFact.createAccount(*currentCustomer);
				std::cout << "Enter Sum: ";
				std::cin >> sum;
				bank1.deposit(ptr, sum);
				delete ptr;
				continue;
				break;
			case 'b':
				ptr = accFact.createAccount(*currentCustomer);
				std::cout << "Enter Sum: ";
				std::cin >> sum;
				bank1.withdraw(ptr, sum);
				delete ptr;
				continue;
				break;
			case 'c':
				std::cout << "Enter IBAN to withdraw from: ";
				std::cin >> ibanTemp;

				std::cout << "Enter IBAN to deposit to: ";
				std::cin >> ibanTemp2;

				std::cout << "Enter Sum: ";
				std::cin >> sum;

				bank1.transfer(sum, ibanTemp, ibanTemp2);

				continue;
				break;
			default:
				break;
			}
			break;
		case '4':
			bank1.display();
			continue;
			break;
		case 'h':
			printMainMenu();
			continue;
			break;
		default:
			break;
		}
		break;
	}

	delete currentCustomer;
}