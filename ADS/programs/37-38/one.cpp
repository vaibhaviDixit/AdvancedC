/*
You have given an unsorted integer array the task is to find a pair of elements in array with the given sum in it.
Make use of hashing to solve this problem.

Input: nums = [8, 7, 2, 5, 3, 1]
       target = 10
Output:
(8, 2) or (7, 3)

*/

#include <iostream>
#include <unordered_map>
using namespace std;

// Function to find a pair in an array with a given sum using hashing
void findPair(int nums[], int n, int target)
{
    // create an empty map
    unordered_map<int, int> map;

    // do for each element
    for (int i = 0; i < n; i++)
    {
        // check if pair (nums[i], target - nums[i]) exists

        // if the difference is seen before, print the pair
        if (map.find(target - nums[i]) != map.end())
        {
            cout << "(" << nums[map[target - nums[i]]] << ", "
                 << nums[i] << ")\n";
            return;
        }

        // store index of the current element in the map
        map[nums[i]] = i;
    }

    // we reach here if the pair is not found
    cout << "Pair not found";
}

int main()
{
    int nums[] = { 8, 7, 2, 5, 3, 1 };
    int target = 10;

    int n = sizeof(nums)/sizeof(nums[0]);

    findPair(nums, n, target);

    return 0;
}

/*
This program demonstrates the use of hashing to find a pair of elements in an array that sum up to a given target value. The problem can be solved in linear time complexity using an unordered map (hash map).

The findPair function takes an array nums, its length n, and the target sum target as inputs. It uses an unordered map to store the values encountered while traversing the array. The map stores the values as keys and their corresponding indices as values.

The main loop iterates through each element of the array. For each element nums[i], it checks if the difference (target - nums[i]) is present in the map. If it is, then a pair (nums[i], target - nums[i]) with the desired sum has been found, and the indices of the elements are retrieved from the map to print the pair.

If the difference is not present in the map, the current element is added to the map along with its index.

Finally, if no pair is found after processing all elements, the program prints "Pair not found".

This approach leverages the constant time lookup property of hashing to efficiently find a pair with the desired sum in the array.

*/


