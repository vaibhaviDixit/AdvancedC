/*
Given an array of integers, write a C program to count the frequency of even and odd elements separately and print the results.

Input: {1, 2, 3, 4, 2, 3, 1, 2, 4, 4}
Output:
Even Element  Frequency
2               3
4               3
Odd Element  Frequency
1               2
3               2

*/
#include <stdio.h>

#define MAX_SIZE 100

void countEvenOdd(int arr[], int size) {
    int evenFreq[MAX_SIZE] = {0};
    int oddFreq[MAX_SIZE] = {0};
    int i;

    // Counting the frequency of even and odd elements
    for (i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenFreq[arr[i]]++;
        } else {
            oddFreq[arr[i]]++;
        }
    }

    // Printing the frequencies of even elements
    printf("Even Element  Frequency\n");
    for (i = 0; i < MAX_SIZE; i += 2) {
        if (evenFreq[i] != 0) {
            printf("%d\t\t%d\n", i, evenFreq[i]);
        }
    }

    // Printing the frequencies of odd elements
    printf("Odd Element  Frequency\n");
    for (i = 1; i < MAX_SIZE; i += 2) {
        if (oddFreq[i] != 0) {
            printf("%d\t\t%d\n", i, oddFreq[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 3, 1, 2, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    countEvenOdd(arr, size);

    return 0;
}

/*
The countEvenOdd function takes an array and its size as input.
It initializes two frequency arrays, evenFreq and oddFreq, with zeros and then counts the frequency of even and odd elements
separately by incrementing the corresponding index in the respective frequency arrays. Finally, the frequencies of even and odd
elements are printed.

This program demonstrates how to use two separate frequency arrays to count the occurrence of even and odd elements in an array.

*/
