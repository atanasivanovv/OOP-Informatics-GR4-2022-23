#include <iostream>
#include <cstring>
#include "Account.h"
struct MyStruct {
    int x;
    private: int balance;
};
class SuperAccount {
    private:
    int balance;

    public: 
    int getBalance() {
        return balance;
    }

    void setBalance(int balance) {
        if (balance < 0) {
            std::cout << "NEW BALANCE CAN'T BE < 0";
            return;
        }
        this->balance = balance;
    }
};

int main() {
    Account account;
    account.setBalance(500);
    account.setBalance(600);

    Account account2 = Account(5, 10, "Ivo");
    std::cout << account2.getBalance();

    account.compareMoneyWith(account2);
};