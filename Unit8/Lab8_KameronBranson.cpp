/**
 * @file Lab8_KameronBranson.cpp
 * @author Kameron Branson
 * @date 2026-11-02
 * @brief Demonstration of stack vs heap memory and pointer use and reference
 */
#include<iostream>
using namespace std;

/**
 * @brief Entry point for the memeory demonstraition
 * @return 0 to indicate success.
 */
int main()
{

    int stackInt = 1;
    int *heapInt = new int;
    int *ptrToStack = &stackInt;
    int &refToStack = stackInt;

    std::cout << "Value of \"stackInt\" is: " << stackInt <<
        ", and its memory address is: " << &stackInt << "\n\n";

    std::cout << "Value stored at \"heapInt\" is: " << *heapInt <<
        ", and its memory address is: " << &heapInt << "\n\n";

    std::cout << "Value pointed to by \"ptrToStack\" is: " << *ptrToStack <<
        ", and the address \"ptrToStack\" holds is: " << ptrToStack << "\n\n";

    std::cout << "Value referred to by \"refToStack\" is: " << refToStack <<
        ", and its memory address is: " << &refToStack << "\n\n";


    delete heapInt;
    heapInt = nullptr;

	return 0;
}
