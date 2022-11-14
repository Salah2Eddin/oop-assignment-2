#include "Client.h"
#include <iostream>

Client::Client(const std::string &name, const std::string &address, const std::string &phoneNumber) {
    this->name = name;
    this->address = address;
    this->phoneNumber = phoneNumber;

    this->pBankAccount = new BankAccount();
}

const std::string &Client::getName() const {
    return name;
}

void Client::setName(const std::string &name) {
    Client::name = name;
}

const std::string &Client::getAddress() const {
    return address;
}

void Client::setAddress(const std::string &address) {
    Client::address = address;
}

const std::string &Client::getPhoneNumber() const {
    return phoneNumber;
}

void Client::setPhoneNumber(const std::string &phoneNumber) {
    Client::phoneNumber = phoneNumber;
}

BankAccount *Client::getBankAccount() const {
    return pBankAccount;
}

void Client::setBankAccount(BankAccount *bankAccount) {
    delete Client::pBankAccount;
    Client::pBankAccount = bankAccount;
}


Client::~Client() {
    delete pBankAccount;
}
