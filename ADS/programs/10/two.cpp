/*
Given an array and an integer K, find the length of the longest subarray that contains at most K distinct elements.

Input: array = {1, 2, 1, 2, 3}
       int k = 2
Output: Length of the longest subarray with at most 2 distinct elements: 4

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestSubarrayWithKDistinct(vector<int>& nums, int k) {
    int maxLength = 0;                  // To store the maximum length of the subarray
    int left = 0;                       // Left pointer of the sliding window
    unordered_map<int, int> frequencyMap; // Hash map to track the frequency of elements

    for (int right = 0; right < nums.size(); right++) {
        frequencyMap[nums[right]]++;   // Add the current element to the frequency map

        // If the number of distinct elements in the current window exceeds K
        while (frequencyMap.size() > k) {
            frequencyMap[nums[left]]--; // Remove the leftmost element from the window
            if (frequencyMap[nums[left]] == 0)
                frequencyMap.erase(nums[left]); // Remove from the map if frequency becomes 0
            left++; // Move the left pointer to reduce the window size
        }

        // Update the maxLength with the current window size
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    vector<int> nums = {1, 2, 1, 2, 3}; // Sample input array
    int k = 2;                          // Maximum number of distinct elements allowed

    int result = longestSubarrayWithKDistinct(nums, k);

    cout << "Length of the longest subarray with at most " << k << " distinct elements: " << result << endl;
    return 0;
}

/*
The program uses the sliding window technique to find the length of the longest subarray that contains at most K distinct elements. The algorithm follows these steps:

Initialize maxLength to store the maximum length of the subarray and left to 0, which represents the left pointer of the sliding window.

Create an unordered map frequencyMap to track the frequency of elements in the current window. The key of the map represents the element in the array, and the value represents its frequency.

Traverse the array using the right pointer and perform the following steps for each element:

Add the current element to the frequencyMap and increment its frequency.

If the number of distinct elements in the current window exceeds K, move the left pointer towards the right, removing elements from the window until the number of distinct elements becomes K.

Update maxLength with the maximum of its current value and the size of the current window (right - left + 1).

Once the traversal is complete, the maxLength will contain the length of the longest subarray with at most K distinct elements.

Print the maxLength as the final result.

The sliding window approach ensures that we maintain a valid subarray with at most K distinct elements while efficiently finding the maximum length. The time complexity of this algorithm is O(n), where n is the size of the input array nums.

*/

