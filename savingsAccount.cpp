#include "account.h"
#include "savingsAccount.h"
#include <iostream>

using namespace std;

savingsAccount::savingsAccount(double balance, int number, float rate)
    :Account(balance, number)
{
    this->rate = rate;
}

void savingsAccount::display()
{
    cout << "The account balance is: $" << getBalance() << endl;
    cout << "The accound number is: " << getNumber() << endl;
    cout << "The Annual Interest Rate is: " << rate << "%" << endl;
}