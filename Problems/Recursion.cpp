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


// A C++ program to find a local minima in an array
#include <stdio.h>
 
// A binary search based function that returns
// index of a local minima.
int localMinUtil(int arr[], int low, int high, int n)
{
    // Find index of middle element
    int mid = low + (high - low)/2;  /* (low + high)/2 */
 
    // Compare middle element with its neighbours
    // (if neighbours exist)
    if ((mid == 0 || arr[mid-1] > arr[mid]) &&
            (mid == n-1 || arr[mid+1] > arr[mid]))
        return mid;
 
    // If middle element is not minima and its left
    // neighbour is smaller than it, then left half
    // must have a local minima.
    else if (mid > 0 && arr[mid-1] < arr[mid])
        return localMinUtil(arr, low, (mid -1), n);
 
    // If middle element is not minima and its right
    // neighbour is smaller than it, then right half
    // must have a local minima.
    return localMinUtil(arr, (mid + 1), high, n);
}
 
// A wrapper over recursive function localMinUtil()
int localMin(int arr[], int n)
{
    return localMinUtil(arr, 0, n-1, n);
}

void callRecursiveFunctions(){
//    std::string result;
//    cout << "5 to binary: " << numTobinary(5, result) << endl;
//
//    cout << "10 - sum: " << summation(10) << endl;
//
//    // Binary Search
//    std::vector<int> input = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 10, 11};
//    cout << "Binary Search: - find 10 " << binarySearch(input, 10) << endl;
//
//    std::vector<int> inputMerge = {100, 10, 5, 16, 12, 14, 51, 6, 7, -1, 2};
//    cout << "Raw data:  ";
//    display(inputMerge);
//    mergeSort(inputMerge, 0, inputMerge.size()-1);
//    cout << "MergeSort: ";
//    display(inputMerge);
 
    int arr[] = {12, 15, 16, 14, 13, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Index of a local minima is %d\n",
                           localMin(arr, n));
    
}

//int main(){
//    callRecursiveFunctions();
//    return 0;
//}
