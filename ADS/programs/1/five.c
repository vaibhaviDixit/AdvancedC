/*
Given an array of 0s and 1s and an integer M, find the maximum number of
consecutive 1s that can be obtained by flipping at most M 0s.

Input:  {1, 0, 0, 1, 1, 0, 1, 0, 1, 1}
        m=2
Output: Maximum number of consecutive 1s after flipping 2 zeroes: 7

*/

#include <stdio.h>

int maxConsecutiveOnes(int arr[], int n, int m) {
    int windowStart = 0;  // Start index of the sliding window
    int maxOnesCount = 0;  // Maximum number of consecutive ones
    int zerosCount = 0;  // Number of zeroes in the current window

    for (int windowEnd = 0; windowEnd < n; windowEnd++) {
        if (arr[windowEnd] == 0)
            zerosCount++;  // Increment zerosCount if encountering a zero

        while (zerosCount > m) {  // Shrink the window until zerosCount becomes <= m
            if (arr[windowStart] == 0)
                zerosCount--;  // Decrement zerosCount if the element at windowStart is zero
            windowStart++;  // Move the window start ahead
        }

        maxOnesCount = (windowEnd - windowStart + 1) > maxOnesCount ? (windowEnd - windowStart + 1) : maxOnesCount;
        // Update the maximum number of consecutive ones if the current count is larger
    }

    return maxOnesCount;  // Return the maximum number of consecutive ones after flipping m zeroes
}

int main() {
    int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1};
    int m = 2;  // Maximum number of zeroes to flip
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    int maxOnesCount = maxConsecutiveOnes(arr, n, m);
    printf("Maximum number of consecutive 1s after flipping %d zeroes: %d\n", m, maxOnesCount);

    return 0;
}


/*
We maintain a window start index, a maximum ones count, and a count of zeros.
If the current element is 0, we increment the zeros count.
If the count of zeros becomes greater than M, we move the window start index and decrement the zeros count.
We update the maximum ones count at each step.
*/
