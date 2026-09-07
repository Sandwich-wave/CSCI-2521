/**
* @file Lab1_KameronBranson.cpp
 * @author Kameron Branson
 * @date 2026-09-07
 * @brief Simple program that asks for first and last name then outputs welcome message.
 */

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string firstName;
    string lastName;

    std::cout<<"Please enter your first name: ";
    std::cin >> firstName;
    std::cout<<"Please enter your last name: ";
    std::cin >> lastName;

    std::cout<<"Welcome to C++ Progamming, " << firstName << " " << lastName;

    return 0;
}