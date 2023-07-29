/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to the target.

Input: nums = {2, 7, 11, 15}
       target = 9
Output: Indices of two numbers that add up to target: 0, 1


Input: nums = {12, 8, 4, 6}
       target = 14
Output: Indices of two numbers that add up to target: 1, 3

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_index_map;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (num_index_map.find(complement) != num_index_map.end()) {
            return {num_index_map[complement], i};
        }
        num_index_map[nums[i]] = i;
    }

    return {};
}

int main() {
    vector<int> nums = {12, 8, 4, 6};
    int target = 14;

    vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        cout << "Indices of two numbers that add up to target: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No such pair exists.\n";
    }

    return 0;
}

/*
This program finds a pair of numbers in an array whose sum equals a given target value.
It uses a hash map to store the numbers' indices as they are iterated through.
 While iterating, it checks if the complement (target - current number) is already present in the map.
 If so, it means the pair is found, and their indices are returned. Otherwise, the current number and its index are added to the map.
The solution has a time complexity of O(n) since each element is processed once in the array.
*/
