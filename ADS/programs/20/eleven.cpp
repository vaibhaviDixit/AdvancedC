/*
Given an array of integers and a positive integer k, find if it's possible to divide the array into k non-empty subsets with equal sums.

Input:  nums = [4,3,2,3,5,2,1], k = 4
Output: It is possible to divide the array into 4 subsets with equal sums.

Input: nums = [1,2,3,4], k = 3
Output: It is NOT possible to divide the array into 3 subsets with equal sums.

*/

#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's possible to divide the array into k subsets with equal sums
// start: current index to consider for the element
// k: number of subsets to divide the array into
// targetSum: target sum for each subset
// currentSum: current sum of elements in the current subset
// selected: a boolean vector to keep track of whether an element is selected for the subset or not
bool canPartitionKSubsetsHelper(vector<int>& nums, int start, int k, int targetSum, int currentSum, vector<bool>& selected) {
    // Base case: If k becomes 1, that means all subsets have been formed, so return true
    if (k == 1) {
        return true;
    }

    // If the current sum equals the target sum, start forming the next subset
    if (currentSum == targetSum) {
        return canPartitionKSubsetsHelper(nums, 0, k - 1, targetSum, 0, selected);
    }

    // Start from the 'start' index and try all possible elements
    for (int i = start; i < nums.size(); ++i) {
        if (!selected[i]) {
            selected[i] = true;
            if (canPartitionKSubsetsHelper(nums, i + 1, k, targetSum, currentSum + nums[i], selected)) {
                return true;
            }
            selected[i] = false;
        }
    }

    return false;
}

// Function to check if it's possible to divide the array into k subsets with equal sums
bool canPartitionKSubsets(vector<int>& nums, int k) {
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    // If the total sum is not divisible by k, it's impossible to divide the array into k subsets with equal sums
    if (totalSum % k != 0) {
        return false;
    }

    int targetSum = totalSum / k;
    int currentSum = 0;
    vector<bool> selected(nums.size(), false);

    // Call the helper function to check if it's possible to divide the array into k subsets with equal sums
    return canPartitionKSubsetsHelper(nums, 0, k, targetSum, currentSum, selected);
}

int main() {
    vector<int> nums = {4,3,2,3,5,2,1};
    int k = 4;

    // Call the canPartitionKSubsets function to check if it's possible to divide the array into k subsets with equal sums
    if (canPartitionKSubsets(nums, k)) {
        cout << "It is possible to divide the array into " << k << " subsets with equal sums." << endl;
    } else {
        cout << "It is NOT possible to divide the array into " << k << " subsets with equal sums." << endl;
    }

    return 0;
}

/*
The given C++ program uses a recursive approach to determine if it's possible to divide an array of integers into k non-empty subsets with equal sums. The main function canPartitionKSubsets calculates the total sum of the array elements and checks if it's divisible by k. If it's not divisible, it's impossible to divide the array into k subsets with equal sums, and the function returns false.

If the total sum is divisible by k, the program calculates the target sum for each subset (which is the total sum divided by k). It initializes a boolean vector selected to keep track of whether an element is selected for a subset or not.

The program then calls the helper function canPartitionKSubsetsHelper, which performs a recursive search for each possible combination of elements to form k subsets with equal sums. It tries all possible elements, and if it finds a valid combination for k subsets, it returns true.

The main function then checks the result from the helper function and prints whether it's possible or not to divide the array into k subsets with equal sums.

*/



