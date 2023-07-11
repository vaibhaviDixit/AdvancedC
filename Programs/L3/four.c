/*
Program to calculate the sum and average of the elements in an array using structures:

Input: Enter the number of elements (max 100): 5
Enter the elements:
34
2
55
44
31

Output:
Sum: 166
Average: 33.20

*/

#include <stdio.h>

// Structure to represent an array
struct Array {
    int elements[100]; // Array to store elements
    int size; // Size of the array
};

// Structure to represent the result of sum and average calculation
struct Result {
    int sum; // Sum of array elements
    float average; // Average of array elements
};

// Function to calculate the sum and average of array elements
struct Result calculateSumAndAverage(struct Array arr) {
    struct Result result;
    result.sum = 0;

    // Calculating the sum of array elements
    for (int i = 0; i < arr.size; i++)
        result.sum += arr.elements[i];

    // Calculating the average of array elements
    result.average = (float)result.sum / arr.size;

    return result;
}

int main() {
    struct Array arr;
    printf("Enter the number of elements (max 100): ");
    scanf("%d", &arr.size);

    printf("Enter the elements:\n");
    for (int i = 0; i < arr.size; i++)
        scanf("%d", &arr.elements[i]);

    // Calling the function to calculate sum and average
    struct Result result = calculateSumAndAverage(arr);
    printf("Sum: %d\n", result.sum);
    printf("Average: %.2f\n", result.average);

    return 0;
}
/*
This program calculates the sum and average of elements in an array.
The struct Array represents the array and its size.
The struct Result represents the result of sum and average calculation.
The calculateSumAndAverage function takes an Array as input and returns a Result structure containing the sum and average of the array elements.
The main function prompts the user to enter the size and elements of the array, then calls the calculateSumAndAverage function.
The sum and average are then displayed to the user.
*/
