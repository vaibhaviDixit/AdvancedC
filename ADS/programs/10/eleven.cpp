/*
Given an array and an integer K, find the subarray of exactly K elements with the maximum average.

Input: nums = {1, 12, -5, -6, 50, 3}
       int K = 4
Output: Subarray with maximum average: 12 -5 -6 50

*/

#include <iostream>
#include <vector>

std::vector<int> findMaxAverageSubarray(const std::vector<int>& nums, int K) {
    int n = nums.size();

    // Check if the input array is valid
    if (n < K || K <= 0) {
        std::cout << "Invalid input: The array is smaller than K or K is non-positive." << std::endl;
        return {};
    }

    int sum = 0;
    int maxSum = 0;
    int startIndex = 0;

    // Calculate the sum of the first K elements to initialize maxSum
    for (int i = 0; i < K; ++i) {
        sum += nums[i];
    }
    maxSum = sum;

    // Find the maximum sum of subarrays with exactly K elements
    for (int i = K; i < n; ++i) {
        sum += nums[i] - nums[i - K]; // Moving window technique
        if (sum > maxSum) {
            maxSum = sum;
            startIndex = i - K + 1;
        }
    }

    // Create the result subarray with K elements that has the maximum average
    std::vector<int> result;
    for (int i = startIndex; i < startIndex + K; ++i) {
        result.push_back(nums[i]);
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 12, -5, -6, 50, 3};
    int K = 4;

    std::vector<int> maxAverageSubarray = findMaxAverageSubarray(nums, K);

    // Print the subarray with maximum average
    std::cout << "Subarray with maximum average: ";
    for (int num : maxAverageSubarray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
This program finds the subarray of exactly K elements with the maximum average from a given array using a sliding window technique.
The function findMaxAverageSubarray takes the input array nums and the integer K as parameters and returns the subarray with the maximum average.

*/
