/**
 * @file Exercise1_KameronBranson.cpp
 * @author Kameron Branson
 * @date 2026-10-18
 * @brief Program validates UPC-A barcodes performing the UPC-A check digit algorithm.
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

/**
 * @brief Takes upc vector and checks if the upc is valid
 * @param upc vector reference to upc
 * @return true if UPC code is valid. false if UCP code is not valid
 */
bool isValidUpc(std::vector<int>& upc) {
    int odd = 0;
    int even = 0;
    int caculatedCheckDigit;

    for (int i = 0; i < 12; i = i + 2) {
        odd = odd + upc[i];
    }

    for (int i = 1; i < 10; i = i + 2) {
        even = even + upc[i];
    }

    caculatedCheckDigit = (((((odd * 3) + (even))%10) - 10 )) * -1;

    if ( caculatedCheckDigit== upc[11]) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Converts validated string to vector reference passed
 * @param upc reference to empty vector to be filled with UPC code
 * @param userSequence string of user input characters to be converted to vector
 * @return None.
 */
void vectorConversion(std::vector<int>& upc, string& userSequence) {
    long userInput = std::stol(userSequence);
    for (int i = 0; i < 12; i++) {
        upc.insert(upc.begin(),(userInput % 10));
        userInput = userInput/10;
    }
}

/**
 * @brief Checks user input could be valid UPC length
 * @param userInputSequence user input string checked
 * @return true if user input is in 12 characters. false if not.
 */
bool isUserInputValid(const string& userInputSequence) {
    if (userInputSequence.size() == 12) {return true;}
    else {return false;}
}

/**
 * @brief Requests user input UPC code.
 * @param None.
 * @return user defined int to be validated.
 */
string requestUserInput() {
    std::string userInput;
    std::cout << "Please enter 12 digit UPC-A code sequence: ";
    std::cin >> userInput;
    return userInput;

}

/**
 * @brief Where main logic is run.
 * @param None.
 * @return 0 to indicate success
 */
int main()
{
    while (true) {
        int menu = 0;
        std::cout << "\t UPC Code Validator" << std::endl << "Enter 1 to start. Input anything else to quit: ";
        std::cin >> menu;

        if (menu == 1) {
            string userInput = requestUserInput();
            bool isValid = isUserInputValid(userInput);

            if (isValid) {
                std::vector<int> upc;
                vectorConversion(upc, userInput);

                if (isValidUpc(upc)) {
                    std::cout << "You have provided a valid UPC-A code!" << std::endl << std::endl;
                } else {
                    std::cout << "The code provided is not a valid UPC-A code!" << std::endl << std::endl;
                }
            }

            // 829676019311

        } else {
            break;
        }
    }




	return 0;
}
