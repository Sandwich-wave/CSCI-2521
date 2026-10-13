/**
 * @file Lab5_KameronBranson.cpp
 * @author Kameron Branson
 * @date 2026-10-12
 * @brief A modular program that displays multiplication tables with functions
 */
#include<iostream>
using namespace std;

/**
 * @brief Outputs error due to invalid user input.
 * @param None.
 * @return None(void).
*/
void printInputValidationError() {
    std::cout << "Error: The max digit must be greater than 4 and less than 10. Please try again." << std::endl;
}

/**
 * @brief Validates user input against acceptable range of >4 and <10.
 * @param input - User provided int for evaluation.
 * @return true if user input is in range (>4 && <10); false if input is not in range.
*/
bool isMaxDigitInputValid(int input) {
    if (input > 4 && input < 10) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Prompts user for input.
 * @param None.
 * @return An int passing validation checks.
*/
int getMaxDigitInput() {
    int userInput = 0;

    std::cout << "Please enter the maximum digit for the multiplication table.\n"
        << "The digit must be greater than 4 and less than 10" << std::endl;

    do {
        std::cout << "Max Digit: ";
        std::cin >> userInput;

        if (isMaxDigitInputValid(userInput) == true) {
            return userInput;
        } else {
            printInputValidationError();
        }

    } while (true);

}

/**
 * @brief Prints the multiplication table with formatting.
 * @param maxDigit - The highest digit included in the table.
 * @return None(void).
*/
void printMultiplicationTable(int maxDigit) {
    for (int i = 1; i <= maxDigit; i++) {

        for (int j = 1; j <= maxDigit; j++) {
            std::cout << i * j << "\t";
        }

        std::cout << std::endl;
    }
}

/**
 * @brief Entry point of program
 * @param None
 * @return 0 to indicate success
 */
int main()
{
	printMultiplicationTable(getMaxDigitInput());

	return 0;
}
