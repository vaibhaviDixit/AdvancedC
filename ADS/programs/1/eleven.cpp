/*
 Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

 Input: nums = {1, 1, 2, 2, 3, 4, 4, 4, 5, 6}
 Output: New length of the array: 6
         Updated array: 1 2 3 4 5 6

*/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
        return 0;

    int unique_count = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[unique_count] = nums[i];
            unique_count++;
        }
    }

    return unique_count;
}

int main() {
    vector<int> nums = {1, 7,8,8,9,10,11,11};

    int new_length = removeDuplicates(nums);

    cout << "New length of the array: " << new_length << endl;
    cout << "Updated array: ";
    for (int i = 0; i < new_length; i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}

/*
This program removes duplicates from a sorted array in-place and returns the new length of the array with unique elements.
It uses two pointers, i and unique_count. The unique_count keeps track of the index where the next unique element should be placed.
The loop iterates through the array, and if the current element is different from the previous element, it is considered a new unique element,
and it's placed at the index unique_count. The unique_count is then incremented to point to the next position where the next unique element
should be placed. The solution has a time complexity of O(n) as each element is visited once.

*/

