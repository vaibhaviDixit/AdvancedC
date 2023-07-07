/*
 Find the count of factors and the largest prime factor of a given number.

Input:
Enter a number: 17
Output:
Number of factors: 2
Largest prime factor: 17

Input:
Enter a number: 12
Output:
Number of factors: 6
Largest prime factor: 3

*/

#include <stdio.h>
#include <stdbool.h>

// Function to find the count of factors of a given number.
int countFactors(int num)
{
    int count = 0;
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            // If both factors are the same, count only one.
            if (num / i == i)
                count++;
            else
                count += 2;
        }
    }
    return count;
}

// Function to find the largest prime factor of a given number.
int largestPrimeFactor(int num)
{
    int largest_prime = -1;
    for (int i = 2; i * i <= num; i++)
    {
        while (num % i == 0)
        {
            largest_prime = i;
            num /= i;
        }
    }
    if (num > 1)
        largest_prime = num;
    return largest_prime;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int factor_count = countFactors(num);
    int largest_prime = largestPrimeFactor(num);

    printf("Number of factors: %d\n", factor_count);
    printf("Largest prime factor: %d\n", largest_prime);

    return 0;
}

/*
The program uses two functions, countFactors and largestPrimeFactor, to find the count of factors and the largest
prime factor of the given number, respectively. The countFactors function iterates from 1 to the square root of the number
and counts the factors by checking if the number is divisible. The largestPrimeFactor function iterates from 2 to the
square root of the number and finds the largest prime factor by dividing the number by prime factors until no further division is possible.
The count of factors and the largest prime factor are printed as the result.
*/
