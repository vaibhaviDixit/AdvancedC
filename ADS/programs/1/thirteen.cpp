/*
Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Input: nums = {3, 2, 2, 3, 1, 4, 3, 5};
       val = 3
Output:
New length of the array after removing 3: 5
Updated array: 2 2 1 4 5


*/

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    if (n == 0)
        return 0;

    int new_length = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] != val) {
            nums[new_length] = nums[i];
            new_length++;
        }
    }

    return new_length;
}

int main() {
    vector<int> nums = {3, 2, 2, 3, 1, 4, 3, 5};
    int val = 2;

    int new_length = removeElement(nums, val);

    cout << "New length of the array after removing " << val << ": " << new_length << endl;
    cout << "Updated array: ";
    for (int i = 0; i < new_length; i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}

/*
This program removes all occurrences of a given value from an array in-place and returns the new length of the array.
It uses two pointers, i and new_length. The new_length keeps track of the index where the next non-target element should be placed.
The loop iterates through the array, and if the current element is not equal to the target value, it is considered as part of the updated
array, and it's placed at the index new_length. The new_length is then incremented to point to the next position where the next non-target
element should be placed. The solution has a time complexity of O(n) as each element is visited once.

*/
