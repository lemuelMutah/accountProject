#ifndef CLASS_CHECKINGS_ACCOUNT_
#define CLASS_CHECKINGS_ACCOUNT_

#include "account.h"

class checkingsAccount : public Account
{
    public:
        checkingsAccount(double, int);
        void display();
};

#endif