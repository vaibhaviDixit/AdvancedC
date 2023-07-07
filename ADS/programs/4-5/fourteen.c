/*
Given a vector v, the program calculates and prints its magnitude (length).

Input: X=3 Y=4
Output: Magnitude of the Vector: 5.00

*/

#include <stdio.h>
#include <math.h>

// Structure to represent a 2D vector.
struct Vector {
    int x; // x-component of the vector
    int y; // y-component of the vector
};

// Function to calculate the magnitude of a vector.
double getVectorMagnitude(struct Vector v)
{
    return sqrt((v.x * v.x) + (v.y * v.y));
}

int main()
{
    struct Vector v = {3, 4}; // Create a vector with x = 3 and y = 4

    double magnitude = getVectorMagnitude(v); // Calculate the magnitude of the vector

    printf("Magnitude of the Vector: %.2f\n", magnitude); // Print the magnitude

    return 0;
}

/*
This program defines a struct Vector and includes a function getVectorMagnitude to calculate the magnitude of a vector.
The main function initializes the vector v with the given values and calls getVectorMagnitude to obtain the magnitude.
The program then displays the magnitude of the vector with two decimal places.
*/
