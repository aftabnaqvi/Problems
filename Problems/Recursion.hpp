//
//  Recursion.hpp
//  Problems
//
//  Created by Syed Naqvi on 3/17/23.
//

#ifndef Recursion_hpp
#define Recursion_hpp

#include <iostream>
#include <vector>

std::string numTobinary(int number, std::string& result);

int summation(int number);

int binarySearch(const std::vector<int>& input, int left, int right, int targetNumber);

void mergeSort(std::vector<int>& input, int start, int end);

#endif /* Recursion_hpp */
