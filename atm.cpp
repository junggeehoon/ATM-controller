# include "atm.h"

ATM::ATM(BankSystem& bankSystem) : bank(bankSystem), validated(false) {}

bool ATM::insertCard(const string& cardNumber) {

    // If current card slot is empty, insert card.
    if (currentCard.empty()) {
        currentCard = cardNumber;
        return true;
    }

    return false;
}

bool ATM::enterPin(const string& pin) {
    if (!currentCard.empty() && bank.checkPin(currentCard, pin)) {
        validated = true;
        return true;
    } else {
        cout << "Invalid pin number.\n";
        return false;
    }
    return false;
}

bool ATM::selectAccount(const string& accountNumber) {
    if (currentCard.empty()) {
        cout << "Please Insert card first.\n";
        return -1;
    }

    BankSystem::Account* account = bank.getAccount(currentCard, accountNumber);

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