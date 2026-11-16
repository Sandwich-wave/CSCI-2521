/**
 * @file Source.cpp
 * @author Kameron Branson
 * @date 2026-11-16
 * @brief A partial banking application simulating SavingsAccount and Customer object interactions
 */
#include<iostream>
#include "Account.h"

/**
 * @class SavingsAccount
 * @brief inherits Account to add interest related transaction
 */
class SavingsAccount: public Account
{
public:
    /**
     * @brief Creates account and sets interest rate
     * @param accNum The account number
     * @param initBal The initial balance
     * @param cust The customer object associated to this account
     */
    SavingsAccount(const string& accNum, double initBal, const Customer& cust)
    : Account(accNum, initBal, cust), dailyInterestRate(0.05)
    {
    }

    /**
     * @brief Iterates deposits and withdrawals and updates balance
     */
    void closeOfBusiness() override
    {
        double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
        double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

        double previousBalance = balance;
        double newBalance = previousBalance + totalDeposits - totalWithdrawals;

        newBalance = newBalance + (newBalance * dailyInterestRate);
        printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

        balance = newBalance;

        deposits.clear();
        withdrawals.clear();

    }
    /**
     * @brief Prints a quick information summary about the account
     */
    void printAccountInfo() const override
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "Interest Rate: " << (100 * dailyInterestRate) << "%" << endl;
        owner.printCustomerInfo();
    }

private:
    double dailyInterestRate;
};

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
    Account* savingsAccount = new SavingsAccount("5423678409", 100.00, customer);
    savingsAccount->printAccountInfo();

    int menuChoice = getMenuOption();
    while (menuChoice != QUIT)
    {
        double amount = 0.0;
        switch (menuChoice)
        {
        case DEPOSIT:
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;
            if (isAmountValid(amount) == true) {
                savingsAccount->deposit(amount);
            } else {
                printInvalidMenuChoiceMessage();
            }
            break;

            case WITHDRAWAL:
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amount;
            if (isAmountValid(amount) == true) {
                savingsAccount->withdraw(amount);
            } else {
                printInvalidMenuChoiceMessage();
            }
            break;

        case CLOSE_OF_BUSINESS:
            savingsAccount->closeOfBusiness();
            break;
        }

        menuChoice = getMenuOption();
    }
    delete savingsAccount;
    savingsAccount = nullptr;
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