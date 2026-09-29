/**
 * @file Lab4_KameronBranson.cpp
 * @author Kameron Branson
 * @date 2026-09-28
 * @brief A program that validates user input to then generate a multiplication tables
 */

#include<iostream>
#include<string>

using namespace std;

int main()
{
	int maxDigit = 0;

	std::cout << "Please enter the maximum digit for the multiplication table.\n"
		<< "The digit must be greater than 4 and less than 10" << std::endl;

	while (maxDigit >= 10 || maxDigit <= 4) {
		std::cout << "Max Digit: ";
		std::cin >> maxDigit;

		if (maxDigit >= 10 || maxDigit <= 4) {
			std::cout << "Error: The max digit must be greater than 4 and less than 10. Please try again." << std::endl;
		}
		else {
			for (int i = 1; i <= maxDigit; i++) {

				for (int j = 1; j <= maxDigit; j++) {
					std::cout << i * j << "\t";
				}

				std::cout << std::endl;

			}
		}
	}

	return 0;
}
