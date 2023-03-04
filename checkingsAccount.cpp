#include "account.h"
#include "checkingsAccount.h"
#include <iostream>

using namespace std;

checkingsAccount::checkingsAccount(double balance, int number)
    :Account(balance, number)
{
}

void checkingsAccount::display()
{
    cout << "The account balance is: $" << getBalance() << endl;
    cout << "The accound number is: " << getNumber() << endl;
}