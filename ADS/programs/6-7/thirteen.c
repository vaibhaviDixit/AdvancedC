/*
Given an array of non-negative integers, find the largest number that can be formed by concatenating the elements of the array.
The result should be a string representation of the largest number.

Input: Given array: [3, 30, 34, 5, 9]
Output: Largest number formed from the array: 9534330

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator function to compare two strings and determine their order
// This function takes two const void pointers 'a' and 'b' as input.
// It converts them to char pointers and concatenates them in different orders to compare their lexicographical order.
// The function returns the result of the comparison.
int compare(const void* a, const void* b) {
    char* ab = (char*)malloc(strlen(*(char**)a) + strlen(*(char**)b) + 1);
    char* ba = (char*)malloc(strlen(*(char**)a) + strlen(*(char**)b) + 1);

    strcpy(ab, *(char**)a);
    strcat(ab, *(char**)b);
    strcpy(ba, *(char**)b);
    strcat(ba, *(char**)a);

    int result = strcmp(ba, ab);

    free(ab);
    free(ba);

    return result;
}

// Largest Number Algorithm
// This function takes an array 'arr' and its size 'n' as input.
// It finds the largest number that can be formed by concatenating the array elements.
// The function sorts the array of strings using the compare function and then concatenates them to form the result.
void largestNumber(int arr[], int n) {
    char* str_arr[n];
    int count_zeros = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            count_zeros++;
        str_arr[i] = (char*)malloc(12 * sizeof(char)); // Assumption: Maximum number of digits is 11
        sprintf(str_arr[i], "%d", arr[i]);
    }

    // Sort the strings to form the largest number
    qsort(str_arr, n, sizeof(str_arr[0]), compare);

    // Concatenate the strings to form the result
    printf("Largest number formed from the array: ");
    if (count_zeros == n)
        printf("0"); // All elements in the array are zeros
    else {
        for (int i = 0; i < n; i++)
            printf("%s", str_arr[i]);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++)
        free(str_arr[i]);
}

int main() {
    // Sample array of integers
    int arr[] = {3, 30, 34, 5, 9};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the given array
    printf("Given array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Call the largestNumber function to find the largest number formed from the array
    largestNumber(arr, n);

    return 0;
}


/*
The program implements the Largest Number Algorithm to find the largest number that can be formed by concatenating the elements of a given array of integers.
The algorithm converts each integer in the array to a string and stores them in a string array.
It then sorts the string array using the custom compare function, which determines the lexicographical order based on different concatenations of two strings.
After sorting, the function concatenates the strings to form the largest number and prints the result.

*/
