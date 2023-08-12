/*
Given an array containing only 0s, 1s, and 2s, sort the array in ascending order using the Dutch National Flag Algorithm.
The algorithm should rearrange the elements in the array so that all 0s come before 1s, and all 1s come before 2s.

Input: [0, 1, 2, 0, 1, 2, 1, 0]
Output: [0, 0, 0, 1, 1, 1, 2, 2]

*/

#include <iostream>
using namespace std;

// Dutch National Flag Algorithm
// This function takes an array 'arr' and its size 'n' as input.
// It sorts the array in-place in ascending order, where the elements are colors represented as integers (0, 1, or 2).
// The algorithm rearranges the elements so that all 0s come before 1s, and all 1s come before 2s.
void sortColors(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;
    int temp;

    // The algorithm uses three pointers: 'low', 'mid', and 'high'.
    // 'low' points to the boundary between 0s and 1s.
    // 'mid' points to the boundary between 1s and unprocessed elements.
    // 'high' points to the boundary between unprocessed elements and 2s.

    while (mid <= high) {
        switch (arr[mid]) {
            case 0: {
                // If the element at 'mid' is 0, swap it with the element at 'low'.
                // Move 'low' and 'mid' one step forward.
                temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                low++;
                mid++;
                break;
            }
            case 1: {
                // If the element at 'mid' is 1, move 'mid' one step forward.
                mid++;
                break;
            }
            case 2: {
                // If the element at 'mid' is 2, swap it with the element at 'high'.
                // Move 'high' one step backward.
                temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                high--;
                break;
            }
        }
    }
}

int main() {
    // Sample array of colors represented as integers (0, 1, or 2)
    int arr[] = {0, 1, 2, 1, 2, 0};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    // Call the sortColors function to sort the array in-place
    sortColors(arr, n);

    // Print the sorted array
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

/*
The program demonstrates the Dutch National Flag Algorithm for sorting an array of colors represented as integers (0, 1, or 2).
The algorithm rearranges the elements in the array so that all 0s come before 1s, and all 1s come before 2s, effectively sorting the array in ascending order.
The sortColors function takes an array arr and its size n as input and sorts the array in-place using the Dutch National Flag Algorithm.

*/


