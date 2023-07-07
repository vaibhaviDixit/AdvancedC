/*
Given an integer N, the program finds and prints the Nth prime number using the Sieve of Eratosthenes algorithm.

Input: Enter the value of N: 17
output: The 17th prime number is: 59

Input: Enter the value of N: 1
Output: The 1th prime number is: 2

*/

#include <stdio.h>
#include <stdbool.h>

// Function to find the nth prime number.
int nthPrime(int n)
{
    int count = 0;
    int num = 2;

    while (count < n)
    {
        bool isPrime = true;

        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            count++;

        num++;
    }

    return num - 1;
}

int main()
{
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    int nthPrimeNumber = nthPrime(n);

    printf("The %dth prime number is: %d\n", n, nthPrimeNumber);

    return 0;
}


/*
The program defines a function nthPrime that takes an integer n as input and returns the Nth prime number.
It uses a counter and a while loop to iterate until the count reaches N. For each number, it checks if it is prime by dividing
it by all numbers from 2 to the square root of the number. If a divisor is found, it is marked as not prime, and if no divisor
is found, the number is considered prime.
The program increments the count and the number until the count reaches N, and then returns the number as the Nth prime.
*/
