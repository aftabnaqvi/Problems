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


void megre(std::vector<int>& input, int start, int mid, int end)
{
    int temp[end-start+1];
    int start1 = start; // i
    int mid1 = mid+1; // j
    int index = 0; // k
    
    while(start1<=mid && mid1<=end){
        if(input[start1] <= input[mid1])
            temp[index++] = input[start1++];
        else
            temp[index++] = input[mid1++];
    }
    
    while(start1<=mid){
        temp[index++] = input[start1++];
    }
    
    while(mid1<=end){
        temp[index++] = input[mid1++];
    }
    
    for(int i=start; i<=end; ++i){
//        cout << temp[i-start] << " ";
        input[i] = temp[i-start];
    }
//    cout << "\n";
    
}

void mergeSort(std::vector<int>& input, int start, int end)
{
    if(start >= end) {
//        cout << "base case - returning" <<endl;
        return;
    }
    
    int mid = (start + end)/2;
    mergeSort(input, start, mid);
    mergeSort(input, mid+1, end);
    megre(input, start, mid, end);
}

void display(const std::vector<int> input)
{
    for(auto n : input){
        cout << n << ", ";
    }
    cout <<"\n";
}

void callRecursiveFunctions(){
    std::string result;
    cout << "5 to binary: " << numTobinary(5, result) << endl;
    
    cout << "10 - sum: " << summation(10) << endl;
    
    // Binary Search
    std::vector<int> input = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 10, 11};
    cout << "Binary Search: - find 10 " << binarySearch(input, 10) << endl;
    
    std::vector<int> inputMerge = {100, 10, 5, 16, 12, 14, 51, 6, 7, -1, 2};
    cout << "Raw data:  ";
    display(inputMerge);
    mergeSort(inputMerge, 0, inputMerge.size()-1);
    cout << "MergeSort: ";
    display(inputMerge);
    
    
}

int main(){
    
    callRecursiveFunctions();
    
    return 0;
}
