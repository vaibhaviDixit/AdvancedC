/*
Implement the Radix Sort algorithm to sort an array of integers in ascending order.

Input: Unsorted array: 170 45 75 90 802 24 2 66
Output: Sorted array: 2 24 45 66 75 90 170 802

*/

#include <stdio.h>

// Find the maximum element in the array
// This function takes an array 'arr' and its size 'n' as input.
// It finds and returns the maximum element in the array.
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Counting Sort for Radix Sort
// This function takes an array 'arr', its size 'n', and an 'exp' value as input.
// It sorts the array based on the 'exp' value, which represents the current digit position for the radix sort.
void countingSortRadix(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0}; // Count array to store the count of each element based on the current digit

    // Store the count of each element in count array
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Modify the count array to store the actual position of each element in output array
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr, so that arr now contains the sorted integers based on the current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort Algorithm
// This function takes an array 'arr' and its size 'n' as input.
// It applies the Radix Sort algorithm to sort the array in ascending order.
void radixSort(int arr[], int n) {
    int max = findMax(arr, n); // Find the maximum element in the array

    // Apply Counting Sort for each digit position from least significant to most significant
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortRadix(arr, n, exp);
}

int main() {
    // Sample unsorted array
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Call the Radix Sort function to sort the array
    radixSort(arr, n);

    // Print the sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
The program demonstrates the Radix Sort algorithm, which is a non-comparative sorting technique used to sort integers with the help of a stable sorting algorithm (here, Counting Sort is used as the stable sorting subroutine).
The findMax function takes an array arr and its size n as input and finds the maximum element in the array. This information is needed to determine the maximum number of digits in the largest element for the radix sort.
The countingSortRadix function takes an array arr, its size n, and an exp value as input. It sorts the array based on the exp value, which represents the current digit position for the radix sort. It utilizes Counting Sort to sort the elements based on the current digit.
The radixSort function takes an array arr and its size n as input. It applies the Radix Sort algorithm to sort the array in ascending order. The sorting is performed for each digit position, starting from the least significant digit to the most significant digit.
The main function initializes an array with some sample unsorted values and calculates the size of the array.
It then prints the unsorted array, calls the radixSort function to sort the array, and finally prints the sorted array.
The printf function is used to display the elements of the array on the console.

*/





