/*
Write a program to count the number of prime numbers within a given range [a, b].

Input: Enter the range [a, b]: 7 21
Output: Number of prime numbers between 7 and 21 is: 5

Input: Enter the range [a, b]: 1 25
Output: Number of prime numbers between 1 and 25 is: 9

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

// Function to count prime numbers within a range.
int countPrimes(int a, int b)
{
    int count = 0;

    // Iterate through the range [a, b] and count the prime numbers.
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
            count++;
    }

    return count;
}

int main()
{
    int a, b;
    printf("Enter the range [a, b]: ");
    scanf("%d %d", &a, &b);

    int count = countPrimes(a, b);
    printf("Number of prime numbers between %d and %d is: %d\n", a, b, count);

    return 0;
}

/*
This program counts the number of prime numbers within a given range [a, b].
It uses the isPrime function to check if a number is prime, and the countPrimes function to iterate through the range
and count the prime numbers.
The program takes input from the user for the range [a, b], calls the countPrimes function, and prints the count as output.
*/
