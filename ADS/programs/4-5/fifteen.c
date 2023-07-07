/*
Given a vector of integers, the program finds and prints the maximum sum of a subarray within the vector.

Input:  3 6 8 -3 2
Output: Maximum subarray sum: 17

*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a dynamic vector.
struct Vector {
    int size;       // Size of the vector
    int *elements;  // Pointer to the array of elements
};

// Function to create a vector of the given size.
struct Vector createVector(int size) {
    struct Vector v;
    v.size = size;
    v.elements = malloc(size * sizeof(int)); // Allocate memory for the elements
    return v;
}

// Function to free the memory allocated for the vector.
void destroyVector(struct Vector v) {
    free(v.elements); // Free the memory
}

// Function to find the maximum subarray sum in the vector.
int maxSubarraySum(struct Vector v) {
    int maxSum = v.elements[0];
    int currentSum = v.elements[0];

    for (int i = 1; i < v.size; i++) {
        currentSum = (currentSum + v.elements[i] > v.elements[i]) ? currentSum + v.elements[i] : v.elements[i];
        maxSum = (currentSum > maxSum) ? currentSum : maxSum;
    }

    return maxSum;
}

int main() {
    int size;
    printf("Enter the size of the vector: ");
    scanf("%d", &size);

    struct Vector v = createVector(size); // Create a vector of the given size

    printf("Enter the elements of the vector: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &v.elements[i]); // Read elements into the vector
    }

    int maxSum = maxSubarraySum(v); // Find the maximum subarray sum

    printf("Maximum subarray sum: %d\n", maxSum);

    destroyVector(v); // Free the memory allocated for the vector

    return 0;
}


/*
The program utilizes the Kadane's algorithm to efficiently solve the problem.
It begins by defining a struct Vector to represent the vector and includes functions to create and destroy vectors.
The maxSubarraySum function implements Kadane's algorithm to iterate over the elements of the vector and determine the
maximum sum of a subarray.

In the main function, the program prompts the user to input the size of the vector and the elements. It then calls the
maxSubarraySum function to obtain the maximum subarray sum and prints the result.

By combining Kadane's algorithm with a vector, this program efficiently solves the problem of finding the maximum subarray sum.
*/
