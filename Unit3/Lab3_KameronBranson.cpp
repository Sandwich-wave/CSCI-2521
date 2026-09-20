/**
 * @file Lab3_KameronBranson.cpp
 * @author Kameron Branson
 * @date 2026-09-20
 * @brief TUI based area caculator for rectangles and circles
 */
#include<iostream>
#include<string>

using namespace std;

int main()
{
	const float PI = 3.14159;
	float radius =0;
	float area = 0;
	float length = 0;
	float width = 0;
	int menu = 0;
	string areaOfWhat = "";

	std::cout<<"Menu\n" <<
		"1. Calculate the Area of a Rectangle\n" <<
		"2. Calculate the Area of a Circle\n" <<
		"3. Quit (Hit any other key + enter to quit)\n" <<
		"Please make a menu selection: ";

	std::cin>>menu;

	if (menu == 1 || menu == 2)
	{
		switch(menu)
		{
		case 1:
			std::cout<<"Please enter the length of the rectangle: ";
			std::cin>>length;
			std::cout<<"Please enter the width of the rectangle: ";
			std::cin>>width;
			area = length * width;
			areaOfWhat = "rectangle";
			break;

		case 2:
			std::cout<<"Please enter the radius of the circle: ";
			std::cin>>radius;
			area = PI * (radius * radius);
			areaOfWhat = "circle";
			break;
		}

		std::cout<<"The area of the " << areaOfWhat << " is: " << area;

	}


	return 0;
}
