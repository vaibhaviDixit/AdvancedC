/*
Given an array of integers, find the most frequent element using a frequency array and print the result.

Input:  {1, 2, 3, 4, 2, 3, 1, 2, 4, 4}
Output: Most frequent element: 2

*/

#include <stdio.h>
#define MAX_SIZE 100

int findMostFrequent(int arr[], int size) {
    int freq[MAX_SIZE] = {0};
    int i, maxFreq = -1, mostFrequent;

    // Counting the frequency of each element
    for (i = 0; i < size; i++) {
        freq[arr[i]]++;
        if (freq[arr[i]] > maxFreq) {
            maxFreq = freq[arr[i]];
            mostFrequent = arr[i];
        }
    }

    return mostFrequent;
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 3, 1, 2, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int mostFrequent = findMostFrequent(arr, size);

    printf("Most frequent element: %d\n", mostFrequent);

    return 0;
}
/*
The findMostFrequent function takes an array and its size as input. It initializes a frequency array with zeros and counts
the frequency of each element by incrementing the corresponding index in the frequency array.
The function also keeps track of the element with the maximum frequency and returns it.
The main function calls findMostFrequent and prints the most frequent element.
This program demonstrates how to find the most frequent element in an array using a frequency array.
*/
