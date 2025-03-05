#include "bank_system.h"
#include <iostream>

void runTests() {
    BankSystem bank;

    cout << "Test1: Correct pin number\n";
    cout << (bank.checkPin("1234", "1111") ? "Success\n\n" : "Fail\n\n");

    cout << "Test2: Incorrect pin number\n";
    cout << (bank.checkPin("1234", "1112") ? "Fail\n\n" : "Success\n\n");

}

int main() {
    runTests();
    return 0;
}