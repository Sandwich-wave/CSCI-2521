/**
 * @file Lab2_KameronBranson.cpp
 * @author Kameron Branson
 * @date 2026-09-13
 * @brief A program that accepts user input to calculate the perimeter of a rectangle.
 */

#include<iostream>
using namespace std;

int main()
{

	float length;
	float width;

	std::cout << "This application will caclulate the perimeter of a rectangle. \n";

	std::cout << "Please enter the length of the rectangle: ";
	std::cin >> length;

	std::cout << "Please enter the width of the rectangle: ";
	std::cin >> width;

	float perimeter = 2 * (length + width);

	std::cout << "The perimeter of the rectangle is: "
	<< perimeter;

	return 0;
}
