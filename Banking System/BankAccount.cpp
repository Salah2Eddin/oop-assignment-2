#include "BankAccount.h"
#include "Client.h"
#include <iostream>


BankAccount::BankAccount(double balance) {
    this->id = ++bank_account_counter;
    this->balance = balance;
    this->pClient = new Client;
}

int BankAccount::getId() const {
    return id;
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::setBalance(double balance) {
    BankAccount::balance = balance;
}

Client *BankAccount::getClient() const {
    return pClient;
}

void BankAccount::setClient(Client *client) {
    delete BankAccount::pClient;
    BankAccount::pClient = client;
}

bool BankAccount::deposit(double amount) {
    if (amount > 0) {
        this->balance += amount;
        return true;
    }
    return false;
}

bool BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= this->balance) {
        this->balance -= amount;
        return true;
    }
    return false;
}

const std::string &BankAccount::getType() const {
    return TYPE;
}

/*
BankAccount::~BankAccount() {
    std::cout << "Deconstructed BankAccount with id: " << id << std::endl;
}*/
