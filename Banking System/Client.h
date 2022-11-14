#pragma once

#include <string>
#include "Client.fwd.h"
#include "BankAccount.h"

class Client{
private:
    std::string name, address, phoneNumber;
    BankAccount *pBankAccount;
public:
    Client() = default;
    Client(const std::string &name,const std::string &address,const std::string &phoneNumber);
     ~Client();

    const std::string &getName() const;
    void setName(const std::string &name);

    const std::string &getAddress() const;
    void setAddress(const std::string &address);

    const std::string &getPhoneNumber() const;
    void setPhoneNumber(const std::string &phoneNumber);

    BankAccount *getBankAccount() const;
    void setBankAccount(BankAccount *bankAccount);
};