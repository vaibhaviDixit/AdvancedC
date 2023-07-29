/*
Given an array of integers, write a C program to compute the prefix sum array and print the results.

Input: {1,2,3,4,5}
Output: Prefix Sum Array: 1 3 6 10 15

*/

#include <stdio.h>

#define MAX_SIZE 100

void prefixSum(int arr[], int prefix[], int size) {
    int i;

    prefix[0] = arr[0];

    // Calculating the prefix sum
    for (i = 1; i < size; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
}

int main() {
    int arr[] = {2,5,7,3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int prefix[MAX_SIZE];

    prefixSum(arr, prefix, size);

    printf("Prefix Sum Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", prefix[i]);
    }

    return 0;
}


/*
The prefixSum function takes an array, an empty prefix array, and the size of the array as input. It calculates the prefix sum by
adding the current element with the previous element in the array and stores the results in the prefix array. Finally, the prefix sum
array is printed.
This program demonstrates how to compute the prefix sum array, where each element represents the sum of all the elements before it in
the original array.
*/
