/*
Given an array of integers, write a program to find the frequency of each prefix sum in the array.

Input:  {1, -1, 2, 3, -2, 4, -4}
Output:
Prefix Sum      Frequency
0               1
1               1
2               1
3               2
5               1
7               1

*/
#include <stdio.h>

void findFrequency(int arr[], int n) {
    int freq[1000] = {0}; // Frequency array with maximum size
    int prefixSum = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        freq[prefixSum]++;
    }

    printf("Prefix Sum\tFrequency\n");

    for (int i = 0; i < 1000; i++) {
        if (freq[i] != 0) {
            printf("%d\t\t%d\n", i, freq[i]);
        }
    }
}

int main() {
    int arr[] = {1, -1, 2, 3, -2, 4, -4};
    int n = sizeof(arr) / sizeof(arr[0]);

    findFrequency(arr, n);

    return 0;
}

/*
This program finds the frequency of each prefix sum in an array. It uses a frequency array, freq, to store the count of each prefix sum.
The array arr is iterated, and for each element, the prefix sum is computed and the frequency array is updated.
Finally, the frequency of each prefix sum is printed.
*/
