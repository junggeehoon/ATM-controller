#ifndef ATM_H
#define ATM_H

#include "bank_system.h"

class ATM {

public:
    ATM(BankSystem& BankSystem);
    bool insertCard(const string& cardNumber);
    bool enterPin(const string& pin);
    bool selectAccount(const string& accountNumber);
    int viewBalance();
    bool deposit(int amoount);
    bool withdraw(int amount);
    void ejectCard();

private: 
    BankSystem& bank;
    string currentCard;
    string currentAccount;
    bool validated;
};

#endif