/*
Find the prime factors of a given number using pre-generated prime numbers.

Input: Enter a number: 27
Output: Prime factors of 27 are: 3 3 3

Input: Enter a number: 12
Output: Prime factors of 12 are: 2 2 3
*/

#include <stdio.h>
#include <stdbool.h>

// Function to generate all prime numbers up to a given limit using the Sieve of Eratosthenes.
void sieveOfEratosthenes(int limit, bool prime[])
{
    // Initialize all entries of the boolean array as true.
    for (int i = 0; i <= limit; i++)
        prime[i] = true;

    for (int p = 2; p * p <= limit; p++)
    {
        // If prime[p] is not changed, then it is a prime number.
        if (prime[p] == true)
        {
            // Update all multiples of p as false.
            for (int i = p * p; i <= limit; i += p)
                prime[i] = false;
        }
    }
}

// Function to print the prime factors of a given number using the pre-generated prime numbers.
void primeFactors(int num, bool prime[])
{
    printf("Prime factors of %d are: ", num);
    for (int i = 2; i <= num; i++)
    {
        while (num % i == 0)
        {
            printf("%d ", i);
            num /= i;
        }
    }
    printf("\n");
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Generate prime numbers up to the given number.
    bool prime[num + 1];
    sieveOfEratosthenes(num, prime);

    // Find the prime factors of the given number using the pre-generated prime numbers.
    primeFactors(num, prime);

    return 0;
}

/*
The program first generates all prime numbers up to the given number using the Sieve of Eratosthenes algorithm.
It stores the prime numbers in a boolean array. Then, it finds the prime factors of the given number by iterating from 2
to the number and dividing the number by each prime factor until it is no longer divisible.
The prime factors are printed as they are found.
*/
