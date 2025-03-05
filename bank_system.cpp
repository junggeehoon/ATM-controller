#include "bank_system.h"

BankSystem:: BankSystem() {

    card["1234"] = "1111";
    card["5678"] = "2222";

    userAccounts["1234"] = {{"a1", 10}, {"a2", 20}};
    userAccounts["5678"] = {{"a3", 100}};
}

bool BankSystem::checkPin(const string& cardNumber, const string& enteredPin) {

    // If card exists, and entered pin matches with card pin number, return true.
    return card.count(cardNumber) && card[cardNumber] == enteredPin;
}

// Return all the account with card number.
vector<BankSystem::Account>* BankSystem::getAccounts(const string& cardNumber) {
    
    // If user acount exists, return pointer to user account.
    if (userAccounts.count(cardNumber)) {
        return &userAccounts[cardNumber];
    }

    return nullptr;
}

// Return specific account with card number and account number.
BankSystem::Account* BankSystem::getAccount(const string& cardNumber, const string& accountNumber) {
    vector<Account>* accounts = getAccounts(cardNumber);

    if (accounts) {
        for (auto& account: *accounts) {
            if (account.accountNumber == accountNumber) {
                return &account;
            }
        }
    }

    return nullptr;
}

bool BankSystem::updateBalance(const string& cardNumber, const string& accountNumber, int amount) {
    Account* account = getAccount(cardNumber, accountNumber);

    if (account) {
        account -> balance += amount;
        return true;
    }

    return false;
}

int BankSystem::viewBalance(const string& cardNumber, const string& accountNumber) {
    Account* account = getAccount(cardNumber, accountNumber);

    return account ? account -> balance : -1;
}