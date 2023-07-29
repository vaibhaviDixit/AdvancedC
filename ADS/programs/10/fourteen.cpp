/*

You are given an array of integers. Your task is to find the minimum subarray that needs to be sorted in-place to make the whole array
sorted.

Input:  Enter the number of elements in the array: 7
        Enter the elements of the array: 2 6 4 8 10 9 15
Output: Minimum subarray to sort: 6 4 8 10 9

*/

#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the minimum subarray that needs to be sorted in-place.
// Parameters:
//   arr: The input array to be sorted.
//   leftIndex: Reference to store the starting index of the minimum subarray.
//   rightIndex: Reference to store the ending index of the minimum subarray.
void findMinimumSubarrayToSort(std::vector<int>& arr, int& leftIndex, int& rightIndex) {
    int n = arr.size();

    // Step 1: Find the first element that is greater than its next element from the beginning.
    for (leftIndex = 0; leftIndex < n - 1; leftIndex++) {
        if (arr[leftIndex] > arr[leftIndex + 1]) {
            break;
        }
    }

    // If the array is already sorted, return.
    if (leftIndex == n - 1) {
        rightIndex = leftIndex;
        return;
    }

    // Step 2: Find the first element that is smaller than its previous element from the end.
    for (rightIndex = n - 1; rightIndex > 0; rightIndex--) {
        if (arr[rightIndex] < arr[rightIndex - 1]) {
            break;
        }
    }

    // Step 3: Find the minimum and maximum elements in the subarray.
    int minElement = arr[leftIndex];
    int maxElement = arr[leftIndex];
    for (int i = leftIndex + 1; i <= rightIndex; i++) {
        minElement = std::min(minElement, arr[i]);
        maxElement = std::max(maxElement, arr[i]);
    }

    // Step 4: Extend the subarray if there are elements greater than minElement on its left side.
    for (int i = 0; i < leftIndex; i++) {
        if (arr[i] > minElement) {
            leftIndex = i;
            break;
        }
    }

    // Step 5: Extend the subarray if there are elements smaller than maxElement on its right side.
    for (int i = n - 1; i > rightIndex; i--) {
        if (arr[i] < maxElement) {
            rightIndex = i;
            break;
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int leftIndex, rightIndex;
    findMinimumSubarrayToSort(arr, leftIndex, rightIndex);

    if (leftIndex <= rightIndex) {
        std::cout << "Minimum subarray to sort: ";
        for (int i = leftIndex; i <= rightIndex; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "The array is already sorted." << std::endl;
    }

    return 0;
}

/*
The given C++ program finds the minimum subarray that needs to be sorted in-place to make the whole array sorted.
The algorithm used in this program involves finding two indices: leftIndex and rightIndex, which represent the starting and ending
indices of the minimum subarray.

*/



