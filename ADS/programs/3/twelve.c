/*
Given a 2D array of integers, find a peak element using binary search.

Input: {{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}}
Output: Peak element: 16
*/

#include <stdio.h>

#define ROWS 4
#define COLS 4

// Binary search function to find a peak element in a 2D array
int binarySearch2DPeak(int arr[][COLS], int row, int col) {
    int low = 0, high = row - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int maxIndex = 0;

        // Find the maximum element in the middle column
        for (int i = 0; i < row; i++) {
            if (arr[i][mid] > arr[maxIndex][mid]) {
                maxIndex = i;
            }
        }

        // Check if the max element is a peak
        if ((mid == 0 || arr[maxIndex][mid] >= arr[maxIndex][mid - 1]) &&
            (mid == col - 1 || arr[maxIndex][mid] >= arr[maxIndex][mid + 1])) {
            return arr[maxIndex][mid];
        } else if (mid > 0 && arr[maxIndex][mid - 1] > arr[maxIndex][mid]) {
            high = mid - 1; // Search on the left side
        } else {
            low = mid + 1; // Search on the right side
        }
    }

    return -1; // Peak element not found
}

int main() {
    int arr[ROWS][COLS] = {{1, 2, 3, 4},
                           {5, 6, 7, 8},
                          {9, 10, 11, 12},
                          {13, 14, 15, 16}};

    int peakElement = binarySearch2DPeak(arr, ROWS, COLS);

    if (peakElement != -1) {
        printf("Peak element: %d\n", peakElement);
    } else {
        printf("Peak element not found\n");
    }

    return 0;
}
/*

This program uses binary search to find a peak element in a 2D array of integers.
The binarySearch2DPeak function takes the 2D array, the number of rows, and the number of columns as inputs.
It performs binary search on the columns to find a peak element. For each column, it finds the maximum element and checks if it is a peak by
comparing it with its adjacent elements. If a peak element is found, it returns the element. If the maximum element is not a peak, it updates
the search range accordingly. The function returns -1 if a peak element is not found.
The main function initializes the 2D array, calls the binarySearch2DPeak function, and prints the peak element if found.
*/
