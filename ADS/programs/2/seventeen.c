/*
Given an array of integers, write a C program to count the frequency of each element and print the results.

Input: {1, 2, 3, 4, 2, 3, 1, 2, 4, 4}
Output:
Element  Frequency
1       2
2       3
3       2
4       3

*/
#include <stdio.h>

#define MAX_SIZE 100

void countFrequency(int arr[], int size) {
    int freq[MAX_SIZE] = {0};
    int i;

    // Counting the frequency of each element
    for (i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    // Printing the frequencies
    printf("Element  Frequency\n");
    for (i = 0; i < MAX_SIZE; i++) {
        if (freq[i] != 0) {
            printf("%d\t%d\n", i, freq[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 3, 1, 2, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    countFrequency(arr, size);

    return 0;
}

/*
The countFrequency function takes an array and its size as input. It initializes a frequency array with zeros and
then counts the frequency of each element by incrementing the corresponding index in the frequency array.
Finally, the frequencies are printed.
This program demonstrates how to use a frequency array to count the occurrence of each element in an array.
*/
