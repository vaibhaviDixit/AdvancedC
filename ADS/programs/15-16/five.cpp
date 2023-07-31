/*
 Implement a recursive binary search algorithm to find a target element in a sorted array.

 Input: Enter the size of the sorted array: 7
        Enter the sorted array elements: 4 6 12 16 19 21 56
        Enter the target element to search: 12
 Output: Element 12 found at index 2

*/

#include <iostream>

// Recursive binary search function
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearch(arr, mid + 1, high, target);
    else
        return binarySearch(arr, low, mid - 1, target);
}

int main() {
    int n, target;
    std::cout << "Enter the size of the sorted array: ";
    std::cin >> n;
    int* arr = new int[n];
    std::cout << "Enter the sorted array elements: ";
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];
    std::cout << "Enter the target element to search: ";
    std::cin >> target;
    int index = binarySearch(arr, 0, n - 1, target);
    if (index != -1)
        std::cout << "Element " << target << " found at index " << index << std::endl;
    else
        std::cout << "Element not found in the array." << std::endl;
    delete[] arr;
    return 0;
}

/*
int binarySearch(int arr[], int low, int high, int target): This is the recursive function definition for performing binary search. The function takes four parameters:

arr: A pointer to the sorted integer array to be searched.
low: The starting index of the search range.
high: The ending index of the search range.
target: The element to be searched in the array.
The function returns an integer representing the index where the target element is found. If the target is not present in the array, it returns -1.

if (low > high) return -1;: This is the base case of the recursion. If the low index becomes greater than the high index, it means that the target element is not present in the current search range. In this case, the function returns -1 to indicate that the element was not found.

int mid = low + (high - low) / 2;: This calculates the index of the middle element in the current search range.

if (arr[mid] == target) return mid;: This checks if the middle element is equal to the target element. If so, it means the target element has been found, and the function returns the index mid.

else if (arr[mid] < target) return binarySearch(arr, mid + 1, high, target);: If the middle element is less than the target element, it means the target element lies in the right half of the array. The function then calls itself recursively with the updated search range, i.e., from mid + 1 to high.

else return binarySearch(arr, low, mid - 1, target);: If the middle element is greater than the target element, it means the target element lies in the left half of the array. The function calls itself recursively with the updated search range, i.e., from low to mid - 1.

*/

