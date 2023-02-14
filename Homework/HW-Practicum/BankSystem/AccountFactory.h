#pragma once
#include "NormalAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"

class AccountFactory {
public:
	Account* createAccount(const Customer& owner);

};