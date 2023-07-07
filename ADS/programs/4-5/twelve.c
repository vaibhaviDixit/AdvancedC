/*
Write a program to find the sum of all prime numbers within a given range [a, b].

Input: Enter the range [a, b]: 5 20
Output: Sum of prime numbers between 5 and 20 is: 72

*/

#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime.
bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

// Function to find the sum of prime numbers within a range.
int sumPrimes(int a, int b)
{
    int sum = 0;

    // Iterate through the range [a, b] and add the prime numbers to the sum.
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
            sum += i;
    }

    return sum;
}

int main()
{
    int a, b;
    printf("Enter the range [a, b]: ");
    scanf("%d %d", &a, &b);

    int sum = sumPrimes(a, b);
    printf("Sum of prime numbers between %d and %d is: %d\n", a, b, sum);

    return 0;
}

/*
This program finds the sum of all prime numbers within a given range [a, b].
It uses the isPrime function to check if a number is prime, and the sumPrimes function to iterate through the range
and add the prime numbers to the sum.
The program takes input from the user for the range [a, b], calls the sumPrimes function, and prints the sum as output.
*/
