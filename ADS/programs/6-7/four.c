/*
Implement the Quick Sort algorithm to sort an array of integers in ascending order.

Input: Unsorted array: 64 34 25 12 22 11 90
Output: Sorted array: 11 12 22 25 34 64 90

*/

#include <stdio.h>

// Partition Function
// This function takes an array 'arr' and its lower and higher indices 'low' and 'high'.
// It selects the last element (arr[high]) as the pivot and arranges the elements such that all elements
// smaller than the pivot are on the left side, and all elements greater than the pivot are on the right side.
// It returns the index of the pivot element after partitioning.
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Select the pivot element as the last element (arr[high])
    int i = low - 1; // Initialize the index of the smaller element

    // Iterate through the array and move elements smaller than the pivot to the left side
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap elements to move smaller elements to the left side
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap the pivot element to its correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return the index of the pivot element after partitioning
}

// Quick Sort Algorithm
// This function takes an array 'arr' and its lower and higher indices 'low' and 'high'.
// It recursively applies the Quick Sort algorithm to sort the array in ascending order.
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the index of the pivot element
        int pi = partition(arr, low, high);

        // Recursively apply Quick Sort to the left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Sample unsorted array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Call the Quick Sort function to sort the array
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
The program demonstrates the Quick Sort algorithm, which is a widely used divide-and-conquer sorting technique.
The partition function is responsible for selecting a pivot element (in this case, the last element) and arranging the array elements such that all elements smaller than the pivot are on the left side, and all elements greater than the pivot are on the right side. It returns the index of the pivot element after partitioning.
The quickSort function takes an array arr and its lower and higher indices low and high as input. It recursively applies the partition function to divide the array into smaller subarrays and then sorts them using the same process.
The main function initializes an array with some sample unsorted values and calculates the size of the array.
It then prints the unsorted array, calls the quickSort function to sort the array, and finally prints the sorted array.
The printf function is used to display the elements of the array on the console.
*/
