#pragma once

#include "Client.h"
#include "BankAccount.h"
#include "SavingBankAccount.h"

#include <iostream>
#include <string>
#include <vector>

class BankApplication {
private:
    std::vector<Client*> clients;
public:
    BankApplication();

    void bankSystem();
    bool displayMenu();
    bool addClient();
};