#include "bank_system.h"
#include <iostream>

void runTests() {
    BankSystem bank;

    cout << "Test1: Correct pin number.\n";
    cout << (bank.checkPin("1234", "1111") ? "Success\n\n" : "Fail\n\n");

    cout << "Test2: Incorrect pin number.\n";
    cout << (bank.checkPin("1234", "1112") ? "Fail\n\n" : "Success\n\n");

    cout << "Test3: Get account.\n";
    cout << (bank.getAccount("1234", "a1") ? "Success\n\n" : "Fail\n\n");

    cout << "Test4: View balance.\n";
    cout << (bank.viewBalance("1234", "a1") ? "Success\n\n" : "Fail\n\n");

    cout << "Test4: Update balance.\n";
    cout << (bank.updateBalance("1234", "a1", 100) ? "Success\n\n" : "Fail\n\n");

    cout << "Test5: Invalid update balance request.\n";
    cout << (bank.updateBalance("1234", "a1", -1000) ? "Fail\n\n" : "Success\n\n");

}

int main() {
    runTests();
    return 0;
}