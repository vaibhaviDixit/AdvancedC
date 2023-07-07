/*
Generate all prime numbers up to a given limit.
Note: A prime number is a number that has exactly two factors, 1 and the number itself.

Input: Enter the limit to generate prime numbers: 27
Output: Prime numbers up to 27 are: 2 3 5 7 11 13 17 19 23

*/

#include <stdio.h>
#include <stdbool.h>

// Function to generate all prime numbers up to a given limit using the Sieve of Eratosthenes.
void sieveOfEratosthenes(int limit)
{
    bool prime[limit + 1];
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

    printf("Prime numbers up to %d are: ", limit);
    for (int p = 2; p <= limit; p++)
    {
        if (prime[p])
            printf("%d ", p);
    }
    printf("\n");
}

int main()
{
    int limit;
    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);

    sieveOfEratosthenes(limit);

    return 0;
}
/*
The program uses the Sieve of Eratosthenes algorithm to generate all prime numbers up to the given limit.
It initializes a boolean array prime[] with all entries as true. It iterates from 2 to the square root of the limit and
updates the multiples of each prime number as false in the prime[] array.
Finally, it prints all the numbers that are marked as prime.
*/
