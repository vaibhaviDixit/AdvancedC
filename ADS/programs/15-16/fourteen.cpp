/*
Write a recursive function to count the occurrences of a given number in an integer array.

Input:  Enter the size of the array: 7
        Enter the array elements: 3 1 5 2 1 6 1
        Enter the number to count occurrences: 1
Output: Number of occurrences: 3

*/

#include <iostream>

// Recursive function to count occurrences of a number in an array
int countOccurrences(int arr[], int n, int target) {
    // Base case: If the size of the array is 0, there are no elements to check,
    // so the count of occurrences is 0.
    if (n == 0)
        return 0;

    // Recursive step: Call the function with the array size reduced by 1 (n - 1)
    // to check the rest of the elements.
    int count = countOccurrences(arr, n - 1, target);

    // Check if the last element of the array (arr[n - 1]) is equal to the target number.
    // If yes, increment the count by 1, as this is an occurrence of the target number.
    if (arr[n - 1] == target)
        count++;

    // Return the final count of occurrences.
    return count;
}

int main() {
    int n, target;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    // Dynamically allocate memory for the array based on the user-provided size.
    int* arr = new int[n];

    std::cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    std::cout << "Enter the number to count occurrences: ";
    std::cin >> target;

    // Call the countOccurrences function with the array, its size, and the target number.
    int occurrences = countOccurrences(arr, n, target);

    // Output the number of occurrences of the target number in the array.
    std::cout << "Number of occurrences: " << occurrences << std::endl;

    // Free the dynamically allocated memory to avoid memory leaks.
    delete[] arr;

    return 0;
}

/*
int countOccurrences(int arr[], int n, int target): This is the recursive function definition to count the occurrences of a given number (target) in an array. The function takes three parameters:

arr: An integer array representing the input array.
n: An integer representing the size of the array.
target: An integer representing the number whose occurrences need to be counted.
The function returns an integer representing the count of occurrences of the target number in the array.
if (n == 0) return 0;: This is the base case of the recursion. If the size of the array n is 0, it means there are no elements to check, so the count of occurrences is 0.

int count = countOccurrences(arr, n - 1, target);: This line represents the recursive step. The function calls itself with the array size reduced by 1 (n - 1) to check the rest of the elements in the array. The result of this recursive call, which is the count of occurrences for the remaining elements, is stored in the variable count.

if (arr[n - 1] == target) count++;: This line checks if the last element of the array (arr[n - 1]) is equal to the target number. If yes, it means this element is an occurrence of the target number, so the count is incremented by 1.

return count;: This line returns the final count of occurrences after considering the current element and the recursive count of occurrences for the remaining elements.

*/


