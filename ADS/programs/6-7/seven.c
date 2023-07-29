/*
 Implement the Pigeonhole Sort algorithm to sort an array of integers in ascending order.

 Input: Unsorted array: 9 6 3 5 3 4 8
 Output: Sorted array: 3 3 4 5 6 8 9

*/


#include <stdio.h>

// Pigeonhole Sort Algorithm
// This function takes an array 'arr' and its size 'n' as input.
// It sorts the array in ascending order using the Pigeonhole Sort algorithm.
void pigeonholeSort(int arr[], int n) {
    int min = arr[0], max = arr[0];

    // Find the minimum and maximum elements in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int range = max - min + 1; // Calculate the range of elements in the array
    int pigeonhole[range]; // Create a pigeonhole array of size equal to the range

    // Initialize pigeonhole array with zeros
    for (int i = 0; i < range; i++)
        pigeonhole[i] = 0;

    // Fill pigeonhole array with the count of each element
    for (int i = 0; i < n; i++)
        pigeonhole[arr[i] - min]++;

    // Fill the original array with sorted elements
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (pigeonhole[i] > 0) {
            arr[index] = i + min;
            pigeonhole[i]--;
            index++;
        }
    }
}

int main() {
    // Sample unsorted array
    int arr[] = {9, 6, 3, 5, 3, 4, 8};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Call the Pigeonhole Sort function to sort the array
    pigeonholeSort(arr, n);

    // Print the sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
The program demonstrates the Pigeonhole Sort algorithm, which is a non-comparative sorting technique based on the principle of pigeonhole or counting sort.
The pigeonholeSort function takes an array arr and its size n as input and sorts the array in ascending order using the Pigeonhole Sort algorithm.
The algorithm first finds the minimum and maximum elements in the array to determine the range of elements in the pigeonhole array.
It creates a pigeonhole array of size equal to the range and initializes all elements to zero.
Then, it fills the pigeonhole array with the count of each element present in the original array. The count is achieved by incrementing the corresponding pigeonhole index based on the difference of the current element and the minimum element.
Finally, it reconstructs the original array by placing the sorted elements back into the array based on the pigeonhole count.
The main function initializes an array with some sample unsorted values and calculates the size of the array.
It then prints the unsorted array, calls the pigeonholeSort function to sort the array, and finally prints the sorted array.
The printf function is used to display the elements of the array on the console.

*/
