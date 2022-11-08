#include "SavingBankAccount.h"
#include <stdexcept>
#include <iostream>

SavingBankAccount::SavingBankAccount(double balance, double minimumBalance) : BankAccount(balance) {
    try {
        if (balance < minimumBalance) {
            throw std::invalid_argument("Balance is less than minimum balance");
        }
        this->minimumBalance = minimumBalance;
    }
    catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
}

double SavingBankAccount::getMinimumBalance() const {
    return minimumBalance;
}

void SavingBankAccount::setMinimumBalance(double minimumBalance) {
    SavingBankAccount::minimumBalance = minimumBalance;
}

bool SavingBankAccount::deposit(double amount) {
    if (amount >= 100) {
        return BankAccount::deposit(amount);
    }
    return false;
}

bool SavingBankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= this->balance && this->balance - amount >= this->minimumBalance) {
        return BankAccount::withdraw(amount);
    }
    return false;
}

const std::string &SavingBankAccount::getType() const {
    return TYPE;
}
