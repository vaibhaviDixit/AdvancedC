/*
Given two sorted arrays of integers, find the median using binary search.

Input: {1, 3, 5}
       {2, 4, 6}
Output: Median: 1.50

*/

#include <stdio.h>
#include <limits.h>
#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a

// Binary search function to find the median of two sorted arrays
double findMedianSortedArrays(int arr1[], int m, int arr2[], int n) {
    if (m > n) {
        return findMedianSortedArrays(arr2, n, arr1, m); // Ensure m <= n for binary search
    }

    int low = 0, high = m;
    int halfLen = (m + n + 1) / 2;

    while (low <= high) {
        int partition1 = low + (high - low) / 2;
        int partition2 = halfLen - partition1;

        int maxLeft1 = (partition1 == 0) ? INT_MIN : arr1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : arr1[partition1];

        int maxLeft2 = (partition2 == 0) ? INT_MIN : arr2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : arr2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            // Found the correct partition
            if ((m + n) % 2 == 0) {
                // Even number of elements
                return (double)(max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2;
            } else {
                // Odd number of elements
                return (double)max(maxLeft1, maxLeft2);
            }
        } else if (maxLeft1 > minRight2) {
            high = partition1 - 1; // Move to the left side
        } else {
            low = partition1 + 1; // Move to the right side
        }
    }

    return 0.0; // Median not found
}

int main() {
    int arr1[] = {1, 3, 5};
    int m = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6};
    int n = sizeof(arr2) / sizeof(arr2[0]);

    double median = findMedianSortedArrays(arr1, m, arr2,n);

    printf("Median: %.2f\n", median);

    return 0;
}

/*
This program uses binary search to find the median of two sorted arrays of integers.
The findMedianSortedArrays function takes the two arrays and their sizes as inputs.
It performs binary search on the smaller array to partition the arrays into two halves.
It then compares the elements at the partition points to determine if the partitions are correct.
If the partitions are correct, it calculates the median based on the number of elements and returns it.
If the partitions are not correct, it updates the search range accordingly. The function returns 0.0 if the median is not found.
The main function initializes the two arrays, their sizes, calls the findMedianSortedArrays function, and prints the median.
*/
