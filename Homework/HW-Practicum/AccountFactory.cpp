#include "AccountFactory.h"


Account* AccountFactory::createAccount(const Customer& owner) {
	std::cout << "Enter Account Type: ";
	FilipString type;
	std::cin >> type;

	std::cout << "Enter Username: ";
	FilipString username;
	std::cin >> username;

	std::cout << "Enter Password: ";
	FilipString password;
	std::cin >> password;

	std::cout << "Enter IBAN: ";
	FilipString IBAN;
	std::cin >> IBAN;

	if (type == "Normal Account") {
		Account* temp = new NormalAccount(username, password, IBAN, owner);

		return temp;
	} else if (type == "Savings Account") {
		std::cout << "Enter Interest Rate: ";
		size_t interestRate;
		std::cin >> interestRate;

		Account* temp =
			new SavingsAccount(username, password, IBAN, owner, interestRate);

		return temp;
	} else if (type == "Privilege Account") {
		std::cout << "Enter Overdraft: ";
		size_t overdraft;
		std::cin >> overdraft;

		Account* temp =
			new PrivilegeAccount(username, password, IBAN, owner, overdraft);

		return temp;
	}

	return nullptr;
}