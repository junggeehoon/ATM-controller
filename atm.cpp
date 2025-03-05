# include "atm.h"

ATM::ATM(BankSystem& bankSystem) : bank(bankSystem), validated(false) {}

bool ATM::insertCard(const string& cardNumber) {

    // If current card slot is empty, mark current card with card number.
    if (currentCard.empty()) {
        currentCard = cardNumber;
        return true;
    }

    return false;
}

bool ATM::enterPin(const string& pin) {

    // Make sure card has inserted.
    if (currentCard.empty()) {
        cout << "Please Insert card first.\n";
        return -1;
    }

    // Communicate with bank system to check valid pin.
    if (bank.checkPin(currentCard, pin)) {
        validated = true;
        return true;
    } else {
        cout << "Invalid pin number.\n";
        return false;
    }
    return false;
}

bool ATM::selectAccount(const string& accountNumber) {
     // Make sure card has inserted.
    if (currentCard.empty()) {
        cout << "Please Insert card first.\n";
        return -1;
    }
    // Communicate with bank system to get specific account with accountnumber.
    BankSystem::Account* account = bank.getAccount(currentCard, accountNumber);

    // Mark current account with associated accound number.
    if (account) {
        currentAccount = accountNumber;
    } else {
        cout << "Invalid account number.\n";
        return false;
    }

    return false;
}

int ATM::viewBalance() {
    if (currentCard.empty()) {
        cout << "Please Insert card first.\n";
        return -1;
    }

    if (currentAccount.empty()) {
        cout << "Please select account first.\n";
        return -1;
    }
    // Communicate with server for remaining balance.
    return bank.viewBalance(currentCard, currentAccount);
    return 0;
}

bool ATM::deposit(int amount) {
    if (currentCard.empty()) {
        cout << "Please Insert card first.\n";
        return -1;
    }

    if (currentAccount.empty()) {
        cout << "Please select account first.\n";
        return -1;
    }
    // Communicate with server to update balance.
    return bank.updateBalance(currentCard, currentAccount, amount);
}

bool ATM::withdraw(int amount) {
    return deposit(amount * -1);
}

void ATM::ejectCard() {
    currentCard.clear();
    currentAccount.clear();
    validated = false;
}