#ifndef CLASS_ACCOUNT_
#define CLASS_ACCOUNT_

class Account
{
    protected:
        double balance;            // account balance
        int number;                // account number

    public:
        Account(double, int);

        double getBalance();
        int getNumber();
        void deposit(double);
        void withdraw(double);
        virtual void display() = 0;
};

#endif