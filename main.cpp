#include <iostream>
#include <cstring>
#include "account.h"
#include "savingsAccount.h"
#include "checkingsAccount.h"
#include <limits>

using namespace std;
typedef Account** accPtr;
const int maxNumAccounts = 10;

void menu(int&);
void makeChoice(accPtr, int, int&);
void addAccount(accPtr &, int &);
void removeAccount(accPtr&, int &);
void displayAccounts(accPtr, int);

int main()
{
    accPtr accounts;
    int numAddedAccounts = 0;
    int choice;

    accounts = new Account*[maxNumAccounts];

    do
    {
        menu(choice);
        makeChoice(accounts, choice, numAddedAccounts);
    } while (choice != 4);


    return 0;
}

// This function prints out the selection menu for option selection
// It parameter includes the address of an int which will be used to hold the user input

void menu(int &choice)
{
    cout << "1. Add an account to the list" << endl
         << "2. Remove an existing account from the list" << endl
         << "3. Display the content of all accounts in the current list" << endl
         << "4. Exit the program" << endl << endl;

    cout << "Enter Choice: ";
    cin >> choice;
}

// This function selects an option based on the user input stored in the int variable, choice
// Its parameter list includes; a pointer to a list of account pointers, a choice as an int,
    // and the address to an int which will be used to count the number of accounts in the
    // list of account pointers
void makeChoice(accPtr accounts ,int choice, int &numAddedAccounts)
{
    cout << endl << "You selected Option " << choice << endl << endl;

    switch (choice)
    {
        case 1: addAccount(accounts, numAddedAccounts); break;

        case 2: removeAccount(accounts, numAddedAccounts); break;

        case 3:  displayAccounts(accounts, numAddedAccounts); break;
    }
}

// This function adds an account to the list of account pointers
// Its parameter list includes; a pointer to a list of account pointers, and the address to an 
// int which will be used to count the number of accounts in the list of account pointers
void addAccount(accPtr &accounts, int &numAddedAccounts)
{
    int accType = 0;
    int newNumber = 0;
    double newBalance = 0;
    float newInterest = 0;
    bool exists = false;

    cout << "What type of account would you like to create? " << endl
         << "1. Savings Account" << endl
         << "2. Checkings Account" << endl << endl;

    cout << "Enter Choice: ";
    cin >> accType;

    cout << "Enter account number: ";
    cin >> newNumber;

    cout << "Enter amount you wish to deposit: ";
    cin >> newBalance;

    cout << endl << "gets here ";

    if (numAddedAccounts > 0)
    {
        // this while loop makes sure that two accounts with the same account number cannot get made
        while (!exists)
        {
            // doing a linear search to see if a certain account number already exists
            for (int i=0; i < numAddedAccounts; i++)
            {
               if (accounts[i]->getNumber() == newNumber)
               {
                  exists = true;
               }
            }

            // if account exists, it promts the user to create a new account with another account number
            if (exists)
            {
               cout << "Account " << newNumber << " already exists" << endl;
               cout << "Enter account number: ";
               cin >> newNumber;
            }

        }

        // checking for the type of account that the user wants to create and then creating one
        if (accType == 1)
        {
            cout << "Enter your expected interest rate: ";
            cin >> newInterest;
            accounts[numAddedAccounts] = new savingsAccount(newBalance, newNumber, newInterest);
        }
        else if (accType == 2)
            accounts[numAddedAccounts] = new checkingsAccount(newBalance, newNumber);

        numAddedAccounts += 1;
    }
    else
    {
        if (accType == 1)
        {
            cout << "Enter your expected interest rate: ";
            cin >> newInterest;
            accounts[numAddedAccounts] = new savingsAccount(newBalance, newNumber, newInterest);
        }
        else if (accType == 2)
            accounts[numAddedAccounts] = new checkingsAccount(newBalance, newNumber);

        numAddedAccounts += 1;
    }

    cout << endl << "Account Added!!!" << endl << endl;
}

// This function removes an account from the list of account pointers
// Its parameter list includes; a pointer to a list of account pointers, and the address to an
// int which will be used to count the number of accounts in the list of account pointers
void removeAccount(accPtr &accounts, int &numAddedAccounts)
{
    int removeNumber;
    bool exists = false;
    
    // checks if there is at least one account in the array of accounts because you cannot delete
    // an account if there are no accounts.
    if (numAddedAccounts > 0)
    {
        cout << "Enter the account number for account to be removed: ";
        cin >> removeNumber;
        cin.ignore(200, '\n');

        // i is a counter which is used to go through the array of accounts to search for the
        // account with the account number to be deleted.
        int i = 0;
        while ( i < numAddedAccounts && !exists)
        {
            // if the account is found, it gets overrided by the next account, and the next gets
            // overrided, and so on until the end. Then the number of accounts gets reduced by 1
            if (accounts[i]->getNumber() == removeNumber)
            {
                // the overriding is done in this for loop
               for (i; i < numAddedAccounts; i++)
               {
                    accounts[i] = accounts[i + 1];
               }
               exists = true;
               delete accounts[numAddedAccounts];
               numAddedAccounts -= 1;
               cout << "Account Removed!!" << endl << endl;
            }
            i++;
        }

        // if the account is not found, exists will remain false and the code below the if statement
        // will run
        if (!exists)
        {
            cout << "Account " << removeNumber << " does not exist" << endl;
            cout << "Press Enter to continue... ";
            cin.ignore(200, '\n');
            cout << endl;
        }
    }
    // if there are no accounts, the statement below will be printed
    else
    {
        cout << endl << "There are " << numAddedAccounts 
             << " accounts. You have to add an account first!!!" << endl;
    }
}

// this function is used to loop throught the list of accounts and call the display function of each
// account object
void displayAccounts(accPtr accounts, int numAddedAccounts)
{
    if (numAddedAccounts > 0)
        for (int i=0; i < numAddedAccounts; i++)
        {
            cout << "****************** Account " << i+1 << " ********************" << endl;
            (*accounts[i]).display();
            cout << "*************************************************" << endl << endl;
        }
    else
        cout << endl << "There are " << numAddedAccounts 
             << " acounts. You have to add an account first!!!" << endl;
}
