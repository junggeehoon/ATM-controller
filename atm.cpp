# include "atm.h"

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
    }
    return false;
}

bool ATM::selectAccount(const string& accountNumber) {
    if (!validated) return false;

    auto* accounts = bank.getAccounts(currentCard);

    if (accounts) {
        for (const auto& account: *accounts) {
            if (account.accountNumber == accountNumber) {
                currentAccount  = accountNumber;
                return true;
            }
        }
    }

    return false;
}

int ATM::viewBalance() {
    if (currentCard.empty()) {
        cout << "Please Insert card first.";
        return -1;
    }

    if (currentAccount.empty()) {
        cout << "Please select account first.";
        return -1;
    }
}

bool ATM::deposit(int amount) {
    
}

bool ATM::withdraw(int amount) {

}

void ATM::ejectCard() {
    currentCard.clear();
    currentAccount.clear();
    validated = false;
}