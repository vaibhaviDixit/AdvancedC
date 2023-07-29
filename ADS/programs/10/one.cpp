/*
Given an array and an integer K, find the maximum sum of any contiguous subarray of size K.

Input: array = {1, 4, 2, 10, 2, 3, 1, 0, 20}
        k = 4
Output: Maximum sum of subarray of size 4: 24

*/

#include <iostream>
#include <vector>

using namespace std;

// Function to find the maximum sum of any contiguous subarray of size K
int maxSumSubarrayOfSizeK(vector<int>& nums, int k) {
    int maxSum = 0;      // Variable to store the maximum sum found so far
    int currentSum = 0;  // Variable to store the current sum of the subarray

    // Calculate the initial sum of the first subarray of size K
    for (int i = 0; i < k; i++) {
        currentSum += nums[i];
    }

    // Start sliding the window from index K and calculate the maximum sum
    for (int i = k; i < nums.size(); i++) {
        currentSum += nums[i] - nums[i - k];  // Add the current element and remove the element outside the window

        // Update the maximum sum if the current sum is greater
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {1, 4, 2, 10, 2, 3, 1, 0, 20};  // Input array
    int k = 4;  // Size of the subarray

    int result = maxSumSubarrayOfSizeK(nums, k);  // Call the function to find the maximum sum

    cout << "Maximum sum of subarray of size " << k << ": " << result << endl;

    return 0;
}

/*
The problem is to find the maximum sum of any contiguous subarray of size K in the given array. We can solve this efficiently using the sliding window technique.

The maxSumSubarrayOfSizeK function takes a vector of integers nums and an integer k as input and returns the maximum sum found. It initializes two variables maxSum and currentSum to store the maximum sum found so far and the current sum of the subarray of size K, respectively.

To find the initial sum of the first subarray of size K, we iterate through the first K elements of the input array and add their values to currentSum.

Next, we start sliding the window from index K and calculate the current sum by adding the current element and removing the element that is now outside the window (i.e., nums[i - k]). We update the maxSum if the current sum is greater.

Finally, we return the maxSum, which represents the maximum sum of any contiguous subarray of size K in the input array.


*/


