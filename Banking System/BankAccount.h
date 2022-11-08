#pragma once

#include "Client.fwd.h"
#include <string>
static int bank_account_counter = 0;

class BankAccount {
private:
    const std::string TYPE = "basic";

protected:
    int id;
    double balance;
     Client *pClient;
public:
    BankAccount() = default;
    explicit BankAccount(double balance);
    // ~BankAccount();

    int getId() const;

    virtual const std::string &getType() const;

    double getBalance() const;
    void setBalance(double balance);

    Client *getClient() const;
    void setClient(Client *client);

    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
};