#include "BankApplication.h"

bool BankApplication::displayMenu() {
    std::cout << "1. Create a New Account \n"
                 "2. List Clients and Accounts \n"
                 "3. Withdraw Money \n"
                 "4. Deposit Money \n"
                 "5. Exit \n"
                 "Please Enter Choice: ";

    int choice = -1;
    std::cin >> choice;
    std::cout << "\n";

    switch (choice) {
        case 1: {
            addClient();
            auto cur = clients.back();
            printf("Client %s has been added with account ID FCAI-%d and Starting Balance %.3f L.E.\n", cur->getName().c_str(),
                   cur->getBankAccount()->getId(), cur->getBankAccount()->getBalance());
            break;
        }
        case 2: {
            for (auto client: clients) {
                printf("-------------------------- %s --------------------------\n"
                       "Address: %s Phone: %s\n"
                       "Account ID: FCAI-%d (%s) \n"
                       "Balance: %.3f\n\n", client->getName().c_str(), client->getAddress().c_str(),
                       client->getPhoneNumber().c_str(), client->getBankAccount()->getId(),
                       client->getBankAccount()->getType().c_str(), client->getBankAccount()->getBalance());
            }
            std::cout << "----------------------------------------------------\n";
            break;
        }
        case 3: {
            std::cout << "Enter Account ID: ";
            int id;
            std::cin >> id;
            auto client = clients[id - 1];
            std::cout << "Enter Amount: ";
            double amount;
            std::cin >> amount;
            if (client->getBankAccount()->withdraw(amount)) {
                std::cout << "Withdrawn Successfully \n";
            } else {
                std::cout << "Withdrawn Failed \n";
            }
            break;
        }
        case 4: {
            std::cout << "Enter Account ID: ";
            int id;
            std::cin >> id;
            auto client = clients[id - 1];
            std::cout << "Enter Amount: ";
            double amount;
            std::cin >> amount;
            if (client->getBankAccount()->deposit(amount)) {
                std::cout << "Deposit Successfully \n";
            } else {
                std::cout << "Deposit Failed \n";
            }
            break;
        }
        case 5: {
            return false;
        }
        default: {
            std::cout << "Invalid Choice" << std::endl;
            break;
        }
    }
    return true;
}

bool BankApplication::addClient() {
    std::string name, address, phoneNumber;
    std::cout << "Enter Client Name: ";
    std::getline(std::cin >> std::ws, name);
    std::cout << "Enter Client Address: ";
    std::getline(std::cin >> std::ws, address);
    std::cout << "Enter Client Phone Number: ";
    std::cin >> phoneNumber;

    int choice = -1;
    std::cout << "Enter Account Type: \n"
                 "1. Saving Account \n"
                 "2. Current Account \n"
                 "Please Enter Choice: ";
    std::cin >> choice;
    switch (choice) {
        case 1: {
            double balance = 0;
            std::cout << "Enter Balance: ";
            std::cin >> balance;

            auto *pClient = new Client(name, address, phoneNumber);
            auto *pBankAccount = new SavingBankAccount(balance);
            pClient->setBankAccount(pBankAccount);
            pBankAccount->setClient(pClient);
            clients.push_back(pClient);
            break;
        }
        case 2: {
            double balance = 0;
            std::cout << "Enter Balance: ";
            std::cin >> balance;

            auto *pClient = new Client(name, address, phoneNumber);
            auto *pBankAccount = new BankAccount(balance);
            pClient->setBankAccount(pBankAccount);
            pBankAccount->setClient(pClient);
            clients.push_back(pClient);
            break;
        }
        default: {
            std::cout << "Invalid Choice" << std::endl;
            return false;
            break;
        }
    }
    return true;
}

BankApplication::BankApplication() {
    clients = std::vector<Client *>();
}

void BankApplication::bankSystem() {
    std::cout << "Welcome to FCAI Banking Application\n";

    bool loop = true;
    while (loop) {
        loop = displayMenu();
        std::cout << "\n";
    }
}
