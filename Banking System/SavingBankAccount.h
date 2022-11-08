#pragma once

#include "BankAccount.h"

class SavingBankAccount : public BankAccount {
private:
    double minimumBalance = 1000;
    const std::string TYPE = "saving";

public:
    SavingBankAccount() = default;
    SavingBankAccount(double balance, double minimumBalance=1000);

    bool deposit(double amount) override;
    bool withdraw(double amount) override;

    double getMinimumBalance() const;
    const std::string &getType() const;

    void setMinimumBalance(double minimumBalance);
};