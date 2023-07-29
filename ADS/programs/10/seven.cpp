/*
Given an array containing 0s and 1s, find the longest subarray of 1s after replacing at most 'k' 0s.

Input: arr={1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1}
Output: The longest subarray of 1s after replacing at most 2 0s: 8

*/

#include <iostream>
#include <vector>

using namespace std;

int longestSubarrayWithOnes(vector<int>& nums, int k) {
    int left = 0;           // Left pointer of the sliding window
    int maxLen = 0;         // Length of the longest subarray of 1s
    int zeroCount = 0;      // Count of 0s in the current window

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) {
            zeroCount++;
        }

        // Shrink the window from the left to keep at most 'k' 0s in the subarray
        while (zeroCount > k) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }

        // Update the maximum length of the subarray of 1s
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1};
    int k = 2;
    int result = longestSubarrayWithOnes(nums, k);
    cout << "The longest subarray of 1s after replacing at most " << k << " 0s: " << result << endl;
    return 0;
}

/*
The given problem can be solved using the sliding window technique. The idea is to maintain a window of consecutive 1s and track the number of 0s within that window. We need to find the longest window such that the number of 0s is at most 'k'.

Initialize the left pointer (representing the start of the window), maxLen (representing the maximum length of the subarray of 1s), and zeroCount (representing the count of 0s within the current window) to 0.

Iterate through the array using the right pointer (representing the end of the window).

If the current element is 0, increment the zeroCount.

Check if the zeroCount is greater than 'k'. If so, it means we have more than 'k' 0s in the current window, and we need to shrink the window from the left to maintain at most 'k' 0s. For this, increment the left pointer and reduce the zeroCount if the element at the left pointer is 0.

Update the maxLen by taking the maximum of the current maxLen and the length of the current window (right - left + 1).

Repeat steps 3 to 5 until the right pointer reaches the end of the array.

Return the maxLen, which represents the length of the longest subarray of 1s after replacing at most 'k' 0s.

*/

