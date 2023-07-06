/*
Given a positive floating-point number, find its square root using binary search.

Input: 16.0
Output: Square root of 16.00 is 4.00

*/

#include <stdio.h>

// Binary search function to find the square root of a number
double binarySearchSquareRoot(double num) {
    double low = 0, high = num;
    double precision = 0.00001;

    while (high - low > precision) {
        double mid = low + (high - low) / 2;
        double square = mid * mid;

        if (square == num) {
            return mid;
        } else if (square < num) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return low + (high - low) / 2;
}

int main() {
    double num = 16.0;

    double squareRoot = binarySearchSquareRoot(num);

    printf("Square root of %.2f is %.2f\n", num, squareRoot);

    return 0;
}

/*
This program demonstrates how binary search can be used to find the square root of a positive floating-point number.
The binarySearchSquareRoot function takes the number as input and performs binary search to find its square root.
It uses the low and high variables to represent the range of possible square root values.
The precision is set to control the level of accuracy. The function returns the calculated square root.
The main function initializes the number and calls the binarySearchSquareRoot function to find the square root.
It then prints the original number and its square root.
*/
