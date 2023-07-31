/*
Write a recursive function to find the sum of elements in an integer array.

Input:  Enter the size of the array: 5
        Enter the array elements: 4 2 7 8 3
Output: Sum of array elements: 24

*/

#include <iostream>

// Recursive function to calculate sum of array elements
int sumOfArray(int arr[], int n) {
    // Base case: If the size of the array is 0, return 0 as there are no elements to add.
    if (n == 0)
        return 0;

    // Recursive step: Return the last element (arr[n-1]) and add it to the sum of array elements
    // obtained by calling the function with the array size reduced by 1 (n - 1).
    return arr[n - 1] + sumOfArray(arr, n - 1);
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    // Dynamically allocate memory for the array based on the user-provided size.
    int* arr = new int[n];

    std::cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    // Call the sumOfArray function with the array and its size.
    int sum = sumOfArray(arr, n);

    // Output the sum of array elements.
    std::cout << "Sum of array elements: " << sum << std::endl;

    // Free the dynamically allocated memory to avoid memory leaks.
    delete[] arr;

    return 0;
}

/*
int sumOfArray(int arr[], int n): This is the recursive function definition to calculate the sum of elements in an array. The function takes an integer array arr and an integer n (representing the size of the array) as its parameters and returns an integer representing the sum of elements in the array.

if (n == 0) return 0;: This is the base case of the recursion. If the size of the array n is 0, it means there are no elements to add, so the function returns 0.

return arr[n - 1] + sumOfArray(arr, n - 1);: This line represents the recursive step. The function returns the last element of the array (obtained using arr[n - 1]) and adds it to the sum of array elements obtained by calling the sumOfArray function with the array size reduced by 1 (obtained using n - 1). This step effectively adds all elements of the array one by one, starting from the last element and moving towards the first element.

*/


