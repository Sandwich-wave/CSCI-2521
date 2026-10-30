/**
 * @file Source.cpp
 * @author Kameron Branson
 * @date 2026-10-29
 * @brief A partial banking application simulating Account and Customer object interactions
 */
#include<iostream>
#include "Account.h"

void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;

/**
 * @brief Entry point for the banking applicaiton
 * @return 0 to indicate success
 */
int main()
{
    // just use dummy data for now for the customer and the account
    // we care about interacting with account object for this lab
    Customer customer("0123456789", "customer@cscc.edu");
    Account account("5423678409", 100.00, customer);
    account.printAccountInfo();

    int menuChoice = getMenuOption();
    while (menuChoice != QUIT)
    {
        int amount = 0;
        switch (menuChoice)
        {
        case DEPOSIT:
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;
            if (isAmountValid(amount) == true) {
                account.deposit(amount);
            } else {
                printInvalidMenuChoiceMessage();
            }
            break;

            case WITHDRAWAL:
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amount;
            if (isAmountValid(amount) == true) {
                account.withdraw(amount);
            } else {
                printInvalidMenuChoiceMessage();
            }
            break;

        case CLOSE_OF_BUSINESS:
            /*
            TODO: Add the code that interacts with the account object to perform
            the close of business account balancing.
            */
            break;
        }

        menuChoice = getMenuOption();
    }
}

void printMenu()
{
    cout << "\nCSCC Bank and Trust" << endl;
    cout << "Select an option:" << endl;
    cout << DEPOSIT << ". Make a deposit" << endl;
    cout << WITHDRAWAL << ". Make a withdrawal" << endl;
    cout << CLOSE_OF_BUSINESS << ". Close of Business" << endl;
    cout << QUIT << ". Quit" << endl;
}

int getMenuOption()
{
    int choice = 0;

    do
    {
        printMenu();
        cin >> choice;

        if (!isMenuChoiceValid(choice))
        {
            printInvalidMenuChoiceMessage();
        }
    } while (!isMenuChoiceValid(choice));

    return choice;
}

bool isMenuChoiceValid(int choice)
{
    return choice >= DEPOSIT and choice <= QUIT;
}

bool isAmountValid(double amount)
{
    return amount > 0;
}

void printInvalidMenuChoiceMessage()
{
    cout << "Invalid option selected. Please try again." << endl;
}