#include <iostream>
#include "account.h"

using namespace std;

// account constructor
Account::Account(double balance, int number)
{
    (*this).balance =  balance;
    this->number = number;
}

double Account::getBalance()
{
    return balance;
}

int Account::getNumber()
{
    return number;
}

void Account::deposit(double depositAmt)
{
    balance += depositAmt;
}

void Account::withdraw(double withdrawAmt)
{
    if (balance - withdrawAmt >= 0)
        balance -= withdrawAmt;
    else
        cout << "You cannot withdraw more than the available balance!" << endl;
}