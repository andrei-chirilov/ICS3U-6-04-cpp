// Copyright (c) 2019 Andrei Chirilov All rights reserved.
//
// Created by: Andrei Chirilov
// Created on: December 2019
// This program get's the average of all the numbers in a 2d list

#include <iostream>
#include <ctime>


template <int rows, int columns>
float calculate(float(&arrayNumbers)[rows][columns]) {
    // This function averages the random numbers from 1-50 in the 2D list

    // Variables
    float sum = 0;
    float divisor = 0;
    float averagedNum;

    // Process
    for (size_t rowNum = 0; rowNum < rows; ++rowNum) {
        for (size_t columnNum = 0; columnNum < columns; ++columnNum) {
            sum = sum + arrayNumbers[rowNum][columnNum];
            divisor += 1;
        }
    }


    averagedNum = sum/divisor;
    return averagedNum;
}


int main() {
    // This function generates random numbers from 1-50 in a 2D list
    // Then find average

    // Random number seed
    unsigned int seed = time(NULL);

    // Variables
    float randomNumber;
    const int rows = 2;
    const int columns = 2;
    float numberArray[rows][columns];
    float average;
    // No input because it needs to know beforehand
    // Process
    for (int rowNum = 0; rowNum < rows; rowNum++) {
        std::cout << "Row " << rowNum + 1 << ": " << std::endl;
        for (int columnNum = 0; columnNum < columns; columnNum++) {
            randomNumber = rand_r(&seed) % 50;
            numberArray[rowNum][columnNum] = randomNumber;
            std::cout << "Column " << columnNum + 1 << ": " << randomNumber
                      << std::endl;
        }
        std::cout << "" << std::endl;
    }

    average = calculate(numberArray);

    // Output
    std::cout << "The averages of the numbers is: " << average
              << std::endl;
}
