#include "SavingsAccount.h"

#include "../../../../../../../Program Files/JetBrains/CLion 2026.2.2/bin/mingw/lib/gcc/x86_64-w64-mingw32/15.2.0/include/c++/iosfwd"

SavingsAccount::SavingsAccount() : interest(1)
{
}

SavingsAccount::SavingsAccount(const string& accNum, double initialBalance, float interest, const Customer& customer)
    : Account(accNum, initialBalance, customer)
{    
    this->interest = interest;
}

void SavingsAccount::closeOfBusiness()
{
    double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
    double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

    double previousBalance = balance;
    double interestToApply = previousBalance <= 0 ? 0 : interest;
    double newBalance = (previousBalance + totalDeposits - totalWithdrawals) * (1 + interestToApply);

    printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

    balance = newBalance;

    deposits.clear();
    withdrawals.clear();
}

void SavingsAccount::printAccountInfo() const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: $" << balance << endl;
    cout << "Interest Rate: " << interest * 100 << "%" << endl;
    owner.printCustomerInfo();
}

void SavingsAccount::Save() const
{
    std::ofstream outFS;
    outFS.open("account_summary.txt");

    outFS << "Account Number: " << accountNumber << endl;
    outFS << "Current Balance: $" << balance << endl;
    outFS << "Interest Rate: " << interest * 100 << "%" << endl;

    outFS.close();
}
