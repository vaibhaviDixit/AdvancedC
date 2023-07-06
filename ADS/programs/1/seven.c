/*
Given an array of integers, find the length of the longest subarray that has a positive product.

Input: {2, -3, 4, -1, -2, 1, 5, -3}
Output: Length of the longest subarray with positive product: 8

Input: {2, -3, 4, -1, -2, 1, 5, 3}
Output: Length of the longest subarray with positive product: 4
*/

#include <stdio.h>

// Function to find the length of the longest subarray with a positive product
int longestSubarrayWithPositiveProduct(int arr[], int n) {
    int maxLength = 0; // Variable to store the length of the longest subarray
    int negativeCount = 0; // Variable to count the number of negative integers in the current subarray

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        // Reset the negative count if the current element is zero
        if (arr[i] == 0) {
            negativeCount = 0;
        }
        // Increment the negative count if the current element is negative
        else if (arr[i] < 0) {
            negativeCount++;
        }

        // Update the maximum length if the current subarray has a positive product
        if (negativeCount % 2 == 0) {
            int subarrayLength = i + 1; // Length of the current subarray
            if (subarrayLength > maxLength) {
                maxLength = subarrayLength;
            }
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {2, -3, 4, -1, -2, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int longestLength = longestSubarrayWithPositiveProduct(arr, n);
    printf("Length of the longest subarray with positive product: %d\n", longestLength);

    return 0;
}
/*
The program defines a function longestSubarrayWithPositiveProduct that takes an array arr and its size n as input. It returns an integer representing the length of the longest subarray with a positive product.

Inside the function, two variables are initialized: maxLength to store the length of the longest subarray and negativeCount to count the number of negative integers in the current subarray.

The program iterates through the array using a for loop. For each element in the array, it performs the following operations:

a. If the current element is zero, it means the current subarray will have a product of zero. Therefore, the negativeCount is reset to zero.

b. If the current element is negative, the negativeCount is incremented by one.

c. Next, the program checks if the current subarray has a positive product. It does this by checking if the negativeCount is an even number. If so, the subarray has an even count of negative integers, which cancels out the negatives and results in a positive product.

d. If the current subarray has a positive product, it calculates the length of the subarray (subarrayLength). If subarrayLength is greater than the current maxLength, the maxLength is updated with the new length.

Finally, the function returns the maxLength.

In the main function, an example array arr is defined, and the function longestSubarrayWithPositiveProduct is called with the array and its size. The resulting length of the longest subarray with a positive product is printed to the console.
*/
