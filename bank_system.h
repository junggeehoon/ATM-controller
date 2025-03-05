#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class BankSystem {

public:
    struct Account {
        string accountNumber;
        int balance;
    };

    BankSystem();
    bool checkPin(const string& cardNumber, const string& pin);
    vector<Account>* getAccounts(const string& cardNumber);
    bool updateBalance(const string& cardNumber, const string& accountNumber, int amount);

private:
    unordered_map<string, string> card; // Card number, Pin
    unordered_map<string, vector<Account> > userAccounts; // Account Number, Account

};

#endif