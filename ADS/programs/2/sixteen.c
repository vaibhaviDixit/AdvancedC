/*
Given an array of integers containing numbers from 1 to 1000, write a program to find and print the missing numbers from the array.

Input: {1, 2, 4, 6, 8}
Output: (All missing numbers from array in range 1 to 1000)
*/
#include <stdio.h>

void findMissingNumbers(int arr[], int n) {
    int freq[1001] = {0};  // Frequency array to mark numbers

    // Mark the numbers present in the array
    for (int i = 0; i < n; i++) {
        freq[arr[i]] = 1;
    }

    // Find and print the missing numbers
    printf("Missing numbers: ");
    for (int i = 1; i <= 1000; i++) {
        if (freq[i] == 0)
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    findMissingNumbers(arr, n);
    return 0;
}
/* This program finds and prints the missing numbers from a given array. It uses a frequency array of size 1001 to mark the numbers present in the array.
The program iterates through the array and marks the corresponding index in the frequency array. Then, it prints the numbers that are not marked.
*/


