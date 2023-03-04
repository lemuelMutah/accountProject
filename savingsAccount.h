#ifndef CLASS_SAVINGS_ACCOUNT_
#define CLASS_SAVINGS_ACCOUNT_

#include "account.h"

class savingsAccount : public Account
{
    private:
        float rate;

    public:
        savingsAccount(double, int, float);
        void display();
};

#endif