/*
Find the prime factors of a given number.

Note: Prime factorization is a way of expressing a number as a product of its prime factors.
For example, if we take the number 30.
We know that 30 = 5 × 6, but 6 is not a prime number.
The number 6 can further be factorized as 2 × 3, where 2 and 3 are prime numbers

*/
#include <stdio.h>

// Function to print the prime factors of a given number.
void primeFactors(int num)
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

    primeFactors(num);

    return 0;
}

/*
The program iterates from 2 to the given number and checks if each number is a prime factor.
It divides the number by each prime factor until it is no longer divisible.
The prime factors are printed as they are found.

*/
