/*
You are given an array of integers nums and an integer K.
Your task is to find the length of the shortest subarray in the given array such that the sum of its elements is at least K.
If there is no such subarray with a sum of at least K, return -1.

Input: nums = {1, 2, 3, 1, 2, 5}
       K = 8
Output: Length of the shortest subarray with sum at least 8 is: 3

*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Function to find the length of the shortest subarray with a sum of at least K
int shortestSubarrayWithSumK(vector<int>& nums, int K) {
    int n = nums.size();
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    deque<int> dq; // Stores the index of the elements in the prefixSum array
    int minLength = n + 1;

    for (int i = 0; i <= n; ++i) {
        // Keep the deque sorted in non-decreasing order of prefixSum values.
        // By doing this, we can efficiently find the shortest subarray with sum >= K.
        while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= K) {
            minLength = min(minLength, i - dq.front());
            dq.pop_front();
        }

        // Remove elements that are larger than the current prefixSum value to maintain a sorted deque.
        while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    return minLength <= n ? minLength : -1;
}

int main() {
    // Example usage of the function
    vector<int> nums = {1, 2, 3, 1, 2, 5};
    int K = 8;
    int result = shortestSubarrayWithSumK(nums, K);

    if (result != -1) {
        cout << "Length of the shortest subarray with sum at least " << K << " is: " << result << endl;
    } else {
        cout << "No subarray with sum at least " << K << " found." << endl;
    }

    return 0;
}

/*
The given program aims to find the length of the shortest subarray in an array nums with a sum of at least K.
The function shortestSubarrayWithSumK takes the input array nums and integer K as parameters and returns the length of the shortest
subarray with a sum of at least K. If no such subarray exists, the function returns -1.

*/

