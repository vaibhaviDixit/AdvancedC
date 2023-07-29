/*
Given an array of integers, find the longest subarray with at most two distinct integers.

Input: arr = {1, 2, 1, 2, 3, 3, 1, 2}
Output: Length of the longest subarray with at most two distinct integers: 4

*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestSubarrayWithTwoDistinct(vector<int>& nums) {
    int maxLength = 0;
    int left = 0;
    unordered_map<int, int> frequencyMap;

    for (int right = 0; right < nums.size(); right++) {
        frequencyMap[nums[right]]++;

        // Shrink the window until we have at most two distinct integers
        while (frequencyMap.size() > 2) {
            frequencyMap[nums[left]]--;
            if (frequencyMap[nums[left]] == 0)
                frequencyMap.erase(nums[left]);
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    vector<int> nums = {1, 2, 1, 2, 3, 3, 1, 2};
    int result = longestSubarrayWithTwoDistinct(nums);
    cout << "Length of the longest subarray with at most two distinct integers: " << result << endl;
    return 0;
}

/*
We are given an array of integers nums, and our task is to find the longest subarray with at most two distinct integers.
We will use the sliding window technique to solve this problem efficiently. The idea is to maintain a window [left, right] that contains at most two distinct integers.
We will use an unordered map frequencyMap to keep track of the frequency of each integer in the current window.
We initialize two pointers left and right to the beginning of the array (left = 0) and start expanding the window to the right.
At each step, we increment the frequency of the integer at right in the frequencyMap.
If the size of the frequencyMap becomes greater than 2, we need to shrink the window. We do this by moving the left pointer to the right until the size of the frequencyMap becomes 2 again.
We update the maxLength with the maximum length of the subarray found so far.
We repeat steps 5 to 7 until the right pointer reaches the end of the array.
Finally, the maxLength will contain the length of the longest subarray with at most two distinct integers, and we return it as the result.

*/
