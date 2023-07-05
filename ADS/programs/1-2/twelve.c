/*
Given an array arr[] consisting of N of integers, the task is to find the minimum positive value S that needs to be
added such that the prefix sum at each index of the given array after adding S is always positive.

Input: {-3, 2, -3, 4, 2}
Output: 5
*/

#include <stdio.h>
#include <stdlib.h>

// Function to find minimum startValue
// for positive prefix sum at each index
int minStartValue(int* nums, int size) {
    // Store the minimum prefix sum
    int minValue = 0;

    // Stores prefix sum at each index
    int sum = 0;

    // Traverse over the array
    for (int i = 0; i < size; i++) {
        int n = nums[i];

        // Update the prefix sum
        sum += n;

        // Update the minValue
        if (sum < minValue) {
            minValue = sum;
        }
    }

    int startValue = 1 - minValue;

    // Return the positive start value
    return startValue;
}

int main() {
    int nums[] = { -3, 2, -3, 4, 2 };
    int size = sizeof(nums) / sizeof(nums[0]);

    // Function Call
    int result = minStartValue(nums, size);
    printf("Minimum start value for positive prefix sum: %d\n", result);

    return 0;
}


/*
This C program finds the minimum start value for a positive prefix sum at each index in an array.
The algorithm calculates the prefix sum at each index and keeps track of the minimum prefix sum encountered so far.
Then, it subtracts the minimum prefix sum from 1 to obtain the positive start value.

The minStartValue function takes two parameters: nums, a pointer to an array of integers, and size, the size of the array.
It returns the minimum start value.

In the main function, an example array nums is defined, and the size of the array is calculated.
The minStartValue function is called with nums and size as arguments, and the result is printed.
*/
