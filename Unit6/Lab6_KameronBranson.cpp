/**
 * @file Lab6_KameronBranson.cpp
 * @author Kameron Branson
 * @date 2026-10-18
 * @brief Compares vectors and static arrays to process student scores
 */
#include<iostream>
#include <algorithm>
using namespace std;

/**
 * @brief Checks if user input is between 0 and 100.
 * @param userInput user input passed to check
 * @return True if input is in acceptable range. False if input is not in acceptable range.
 */
bool inputValidator(int userInput) {
    if (userInput >= 0 && userInput <= 100) {
        return true;
    } else {
        std::cout << "Please enter a valid score between 0 and 100." << std::endl;
        return false;
    }
}

/**
 * @brief arraySolution helper to determine average
 * @param arr The array holding integer scores
 * @param size The size of the array
 * @return The average score as a float
 */
float calculateAverage(const int arr[], int size)
{
    float cumulative = 0;

    for (int i = 0; i < size; i ++) {
        cumulative = cumulative + arr[i];
    }

    return (cumulative/size);
}

/**
 * @brief arraySolution helper to determine maximum int
 * @param arr The array holding integer scores
 * @param size The size of the array
 * @return The highest score as an int
 */
int findMax(const int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

/**
 * @brief arraySolution helper to determine minimum int
 * @param arr The array holding integer scores
 * @param size The size of the array
 * @return The lowest score as an int
 */
int findMin(const int arr[], int size)
{
    int min = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

/**
 * @brief Caculates statistics using fixed-size static array
 * @param None
 * @return None (void).
 */
void arraySolution()
{
    int scores[10] = {};
    int count = 0;
    float average = 0;
    int max = 0;
    int min = 0;

    std::cout << "Please enter up to 10 scores. " <<
        "Ensure the values are between 0 and 100 using whole numbers." << std::endl;

    for (int i = 0; i < 10; i++) {
        int currentValue = scores[i];
        std::cout << "Enter score #" << i + 1 << ": ";
        std::cin >> scores[i];

        bool validInput = inputValidator(scores[i]);

        if ( validInput== true) {
            if (currentValue != scores[i]) {count++;}
        } else {
            i--;
        }

    }

    average = calculateAverage(scores, count);
    max = findMax(scores, count);
    min = findMin(scores, count);

    std::cout << "The highest score is: " << max << std::endl;
    std::cout << "The lowest score is: " << min << std::endl;
    std::cout << "The average score is: " << average << std::endl;
}

/**
 * @brief Calculates the average of the scores
 * @param vec The vector containing integer scores
 * @return The average score as a float
 */
float calculateAverage(const std::vector<int>& vec)
{

}

/**
 *
 * @param vec The vector containing integer scores
 * @return The highest score as an int
 */
int findMax(const std::vector<int>& vec)
{

}

/**
 *
 * @param vec The vector containing integer scores
 * @return The lowest score as an int
 */
int findMin(const std::vector<int>& vec)
{

}


/**
 * @brief Calculates statistics using a dynamic vector.
 * @param None.
 * @return None (void).
 */
void vectorSolution()
{

}

/**
 * @brief
 * @param
 * @return 0 to indicate success
 */
int main()
{
	arraySolution();

	return 0;
}
