/*
Given an array containing 0s and 1s, find the largest subarray with an equal number of 0s and 1s.

Input: {0, 1, 0, 1, 1, 0, 1, 0, 1}
Output: Largest subarray with equal number of 0s and 1s: 8

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMaxLength(vector<int>& nums) {
    int maxLength = 0;
    int count = 0; // Variable to keep track of the difference between 0s and 1s
    unordered_map<int, int> countMap; // Map to store the count and its corresponding index

    for (int i = 0; i < nums.size(); i++) {
        // If the element is 1, increment count; otherwise, decrement it
        count += nums[i] == 1 ? 1 : -1;

        // If count is 0, it means we have an equal number of 0s and 1s from index 0 to i.
        // So, update maxLength to (i+1) since (i+1) elements are balanced.
        if (count == 0)
            maxLength = max(maxLength, i + 1);
        else {
            // If count is not 0, check if we've seen this count before (in previous iterations).
            // If yes, it means the subarray between the previous index and the current index
            // has an equal number of 0s and 1s, so update maxLength accordingly.
            if (countMap.find(count) != countMap.end())
                maxLength = max(maxLength, i - countMap[count]);
            else
                countMap[count] = i; // If count is not in the map, add it along with its index.
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums = {0, 1, 0, 1, 1, 0, 1, 0, 1};
    int result = findMaxLength(nums);
    cout << "Largest subarray with equal number of 0s and 1s: " << result << endl;
    return 0;
}

/*
The problem is to find the largest subarray with an equal number of 0s and 1s in a given array. To solve this, we use the concept of a running count to keep track of the difference between the number of 0s and 1s encountered so far.

We traverse the array from left to right, and for each element:

If the element is 0, we decrement the count, and if it is 1, we increment the count.
If the count becomes 0 at any index, it means that the subarray from the beginning to that index has an equal number of 0s and 1s. We update the maxLength to include this subarray.
If the count is not 0, we check if we have seen this count before. If we have, it means that there is a subarray with an equal number of 0s and 1s between the previous index where we saw this count and the current index. We update the maxLength accordingly.
If the count is not in the map, we add it along with its index to the map. This is because, if we encounter the same count again later,
it will help us find a subarray with an equal number of 0s and 1s.

*/

