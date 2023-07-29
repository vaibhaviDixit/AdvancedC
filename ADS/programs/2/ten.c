/*
Given an array of integers, calculate the sum of elements in a given range using the prefix sum array and print the result.

Input: {1, 2, 3, 4, 5}
       range= 1-3
Output: Sum of elements from index 1 to 3: 9

*/

#include <stdio.h>
#define MAX_SIZE 100

int rangeSum(int prefix[], int left, int right) {
    if (left == 0) {
        return prefix[right];
    } else {
        return prefix[right] - prefix[left - 1];
    }
}

int main() {
    int arr[] = {-3,6,-7,8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int prefix[MAX_SIZE];

    prefix[0] = arr[0];

    // Calculating the prefix sum
    for (int i = 1; i < size; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int left = 0;  // Range start index
    int right = 2; // Range end index

    int sum = rangeSum(prefix, left, right);
    printf("Sum of elements from index %d to %d: %d\n", left, right, sum);

    return 0;
}

/*
The rangeSum function takes a prefix sum array, the left index of the range, and the right index of the range as input.
It calculates the sum of elements within the given range by subtracting the prefix sum at the left index from the prefix sum
at the right index. The result is then returned. The main function computes the prefix sum array and calls rangeSum to find the
sum of elements within a specific range.
This program demonstrates how to compute the sum of elements within a given range in an array using the prefix sum array.
*/
