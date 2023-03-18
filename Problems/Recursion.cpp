//
//  Recursion.cpp
//  Problems
//
//  Created by Syed Naqvi on 3/17/23.
//

#include "Recursion.hpp"

using namespace std;

std::string numTobinary(int number, std::string& result)
{
    if (number == 0)
        return result;
    result = std::to_string(number%2) + result;
    return numTobinary(number/2, result);
}

int summation(int number)
{
    if(number == 1){
        return number;
    }
    
    int result = number + summation(number-1);
    return result;
}

// Binaray Seach
int binarySearch(const std::vector<int>& input, int left, int right, int targetNumber)
{
    if (left > right) {
        return -1;
    }
    
    int mid = (left + right) / 2;
    
    if (input[mid] == targetNumber) {
        return mid;
    }
    
    // move to right
    if (targetNumber > input[mid]) {
        return binarySearch(input, mid+1, right, targetNumber);
    }
    
    // move to left.
    return binarySearch(input, left, mid, targetNumber);;
}

int binarySearch(const std::vector<int>& input, int targetNumber)
{
    return binarySearch(input, 0, input.size()-1, targetNumber);
}


void callRecursiveFunctions(){
    std::string result;
    cout << "5 to binary: " << numTobinary(5, result) << endl;
    
    cout << "10 - sum: " << summation(10) << endl;
    
    // Binary Search
    std::vector<int> input = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 10, 11};
    
    cout << "Binary Search: - find 10 " << binarySearch(input, 10) << endl;
}

int main(){
    
    callRecursiveFunctions();
    
    return 0;
}
