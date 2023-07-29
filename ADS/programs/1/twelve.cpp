/*
Given an array nums of n integers, find all unique triplets in the array that give the sum of zero.

Input: {-1, 0, 1, 2, -1, -4}
Output:
Unique triplets with sum 0:
-1 -1 2
-1 0 1

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    if (n < 3)
        return result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> triplets = threeSum(nums);

    cout << "Unique triplets with sum 0:\n";
    for (const vector<int>& triplet : triplets) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
This program finds all unique triplets in an array that give the sum of zero. It uses two pointers to find the sum of elements while
iterating through the sorted array. The first pointer i iterates through the array elements, and for each element, the program searches
for a pair of elements (second pointer left and right) that sum up to the negation of the current element (-nums[i]). If such a pair is found,
it's added to the result vector, and the pointers are adjusted to skip duplicates and continue searching for other pairs.
The solution has a time complexity of O(n^2) since the two-pointer technique processes each element and searches for pairs in a sorted array.

*/
