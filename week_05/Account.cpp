#include "Account.h"

Account::Account () {
    this->x = 0;
    this->balance = 0;
}

Account::Account (int x, int balance, const char* randomName) {
    this->x = x;
    this->balance = balance;
    strcpy_s(this->name, randomName);
}

int Account::getBalance() {
    return balance;
}

void Account::setBalance(int balance) {
    if (balance < 0) {
        std::cout << "NEW BALANCE CAN'T BE < 0";
        return;
    }
    this->balance = balance;
}

bool Account::compareMoneyWith(const Account& other) {
    // this is invalid because of const -> 
    // GOOD PRACTISE WHEN NOT WANTING TO MODIFY
    // other.setBalance(50000); // = 50000;
    return this->balance == other.balance;
}

// bool compareMoneyWithSuperAccount(SuperAccount other) {
//     return this->balance == other.getBalance();
// }