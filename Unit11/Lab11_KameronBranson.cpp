/**
 * @file Lab11_KameronBranson.cpp
 * @author Kameron Branson
 * @date 2026-11-27
 * @brief Demonstrates exception handling with STL vector to handle invalid index access safely.
 */
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
using namespace std;

/**
 * @brief Main function to run program.
 * @return 0 to indicate successful completion.
 */
int main()
{
    std::vector<std::string> cities =
        {"Columbus", "Cleveland", "Cincinnati", "Toledo", "Akron", "Dayton", "Youngstown"};
    string city;
    int userInput;

    cout << "Please enter an index to lookup a city: " << endl;
    cin >> userInput;

    try {
        city = cities.at(userInput);
        cout << "City at index " << userInput << " is " << city << endl;

    } catch (std::out_of_range& e) {
        string fl = "";

        if (userInput < 0) {
            fl = "first";
            city = cities.at(0);
        } else {
            fl = "last";
            city = cities.at(6);
        }

        cout << "Invalid index. Here's the " << fl << " city instead: " << city << endl;

    }

	return 0;
}
