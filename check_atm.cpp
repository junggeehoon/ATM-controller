#include "atm.h"
#include "bank_system.h"
#include <iostream>

void runTests() {
    BankSystem bank;
    ATM atm(bank);

    cout << "Test1: Insert Card\n";
    cout << (atm.insertCard("1234") ? "Success\n\n" : "Fail\n\n");

    // cout << "Test2: Incorrect pin number\n";
    // cout << (bank.checkPin("1234", "1112") ? "Fail\n\n" : "Success\n\n");

}

int main() {
    runTests();
    return 0;
}