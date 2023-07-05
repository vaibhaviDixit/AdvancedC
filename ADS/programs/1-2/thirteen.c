/*
Given an array of integers, count the number of unique elements using a frequency array and print the result.

Input: {1, 2, 3, 4, 2, 3, 1, 2, 4, 7, 4}
Output: 1

Input: {1, 2, 3, 4, 2, 3, 1, 2, 4, 4}
Output: 0

*/
#include <stdio.h>
#define MAX_SIZE 100

int countUnique(int arr[], int size) {
    int freq[MAX_SIZE] = {0};
    int i, uniqueCount = 0;

    // Counting the frequency of each element
    for (i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    // Counting the number of unique elements
    for (i = 0; i < MAX_SIZE; i++) {
        if (freq[i] == 1) {
            uniqueCount++;
        }
    }

    return uniqueCount;
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 3, 1, 2, 4,7, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int uniqueCount = countUnique(arr, size);

    printf("Number of unique elements: %d\n", uniqueCount);

    return 0;
}

/*
The countUnique function takes an array and its size as input. It initializes a frequency array with zeros and counts
the frequency of each element by incrementing the corresponding index in the frequency array.
Then, it counts the number of unique elements by checking for a frequency of 1. The main function calls countUnique and
prints the number of unique elements.
This program demonstrates how to count the number of unique elements in an array using a frequency array.
*/
