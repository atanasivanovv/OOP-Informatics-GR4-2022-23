#pragma once
#include <iostream>
#include <cstring>

class Account {
    private:
    int x;
    int balance;
    char name[100];

    public:
    Account ();
    Account (int x, int balance, const char* randomName);
    int getBalance();
    void setBalance(int balance);
    bool compareMoneyWith(const Account& other);
    // bool compareMoneyWithSuperAccount(SuperAccount other);
};