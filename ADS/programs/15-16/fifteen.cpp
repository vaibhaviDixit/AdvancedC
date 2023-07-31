/*
Implement the Merge Sort algorithm using recursion.

Input:  Enter the size of the array: 5
        Enter the array elements: 8 4 12 42 7
Output: Sorted array: 4 7 8 12 42

*/

#include <iostream>
#include <vector>

// Merge two sorted subarrays and combine them into a single sorted array
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    // Create temporary vectors to hold the left and right subarrays
    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    // Copy data from the original array to the temporary left and right subarrays
    for (int i = 0; i < n1; ++i)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArray[j] = arr[mid + 1 + j];

    int i = 0; // Initial index of the left subarray
    int j = 0; // Initial index of the right subarray
    int k = left; // Initial index of the merged subarray

    // Merge the two subarrays back into the original array in sorted order
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            ++i;
        } else {
            arr[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements, if any, from the left subarray
    while (i < n1) {
        arr[k] = leftArray[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements, if any, from the right subarray
    while (j < n2) {
        arr[k] = rightArray[j];
        ++j;
        ++k;
    }
}

// Recursive function to sort an array using Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Calculate the middle index

        // Recursive call to sort the left and right halves of the array
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}

/*
void merge(std::vector<int>& arr, int left, int mid, int right): This function merges two sorted subarrays within the original array. It takes the vector arr, along with indices left, mid, and right, which define the two subarrays to be merged.

int mergeSort(std::vector<int>& arr, int left, int right): This is the main recursive function that implements the Merge Sort algorithm. It takes the vector arr and indices left and right, representing the range of the array that needs to be sorted.

if (left < right): This is the base case of the recursion. If the left index is less than the right index, it means there are more than one element in the current range to sort.

int mid = left + (right - left) / 2;: This line calculates the middle index mid to divide the array into two halves for sorting.

mergeSort(arr, left, mid); and mergeSort(arr, mid + 1, right);: These lines are recursive calls to mergeSort for sorting the left and right halves of the array.

merge(arr, left, mid, right);: This line merges the sorted left and right subarrays back into the original array to obtain the fully sorted array.

*/

