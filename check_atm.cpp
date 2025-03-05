#include "atm.h"
#include "bank_system.h"
#include <iostream>

void runTests() {
    BankSystem bank;
    ATM atm(bank);

    cout << "Test1: Insert Card\n";
    cout << (atm.insertCard("1234") ? "Success\n\n" : "Fail\n\n");

    cout << "Test2: Enter incorrect pin number\n";
    cout << (atm.enterPin("1112") ? "Fail\n\n" : "Success\n\n");

    cout << "Test3: Enter correct pin number\n";
    cout << (atm.enterPin("1111") ? "Success\n\n" : "Fail\n\n");
    
    cout << "Test4: Select invalid account\n";
    cout << (atm.selectAccount("c1") ? "Fail\n\n" : "Success\n\n");

    cout << "Test 5: Select valid account \n";
    cout << (atm.selectAccount("a1") ? "Fail\n\n" : "Success\n\n");

    cout << "Test 6: View balance, expected 10 \n";
    cout << "Balance: " << atm.viewBalance() << endl << endl;

    cout << "Test 7: Deposit 90\n";
    cout << (atm.deposit(90) ? "Success\n\n" : "Fail\n\n");

    cout << "Test 8: View balance, expected 100 \n";
    cout << "Balance: " << atm.viewBalance() << endl << endl;

    cout << "Test 9: Withdraw 100\n";
    cout << (atm.withdraw(100) ? "Success\n\n" : "Fail\n\n");

    cout << "Test 10: View balance, expected 0 \n";
    cout << "Balance: " << atm.viewBalance() << endl << endl;

    cout << "Test 11: Withdraw greater than remaining balance. \n";
    cout << (atm.withdraw(100) ? "Fail\n\n" : "Success\n\n");

    cout << "Test 12: Eject card\n";
    atm.ejectCard();
    cout << "Successfully ejected card.\n";

}

int main() {
    runTests();
    return 0;
}