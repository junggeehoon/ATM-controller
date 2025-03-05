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

vector<BankSystem::Account>* BankSystem::getAccounts(const string& cardNumber) {
    
    // If user acount exists, return pointer to user account.
    if (userAccounts.count(cardNumber)) {
        return &userAccounts[cardNumber];
    }

    return nullptr;
}

bool BankSystem::updateBalance(const string& cardNumber, const string& accountNumber, int amount) {
    // Check whether user account exists in userAccounts map.
    if (userAccounts.count(cardNumber)) {
        // If exists, iterate through all accounts to find account that has same accountNumber.
        for (auto& account: userAccounts[cardNumber]) {
            // If account exists, update balance.
            if (account.accountNumber == accountNumber) {
                account.balance += amount;
                return true;
            }
        }
    }

    return false;
}