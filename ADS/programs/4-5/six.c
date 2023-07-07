/*
 Find the largest prime number in an array of integers.

 Input: 3 4 66 23 12
 Output: The largest prime number in the array is: 23

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

// Function to find the largest prime number in the given array.
int largestPrimeNumber(int arr[], int n, bool prime[])
{
    int largest_prime = -1;
    for (int i = 0; i < n; i++)
    {
        if (prime[arr[i]] && arr[i] > largest_prime)
            largest_prime = arr[i];
    }
    return largest_prime;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Generate prime numbers up to the maximum number in the array.
    int max_num = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_num)
            max_num = arr[i];
    }
    bool prime[max_num + 1];
    sieveOfEratosthenes(max_num, prime);

    int largest_prime = largestPrimeNumber(arr, n, prime);
    printf("The largest prime number in the array is: %d\n", largest_prime);

    return 0;
}


/*
The program generates all prime numbers up to the maximum number in the array using the Sieve of Eratosthenes algorithm.
It stores the prime numbers in a boolean array. Then, it finds the largest prime number in the array by iterating through
the array and checking if each number is prime using the pre-generated prime numbers.
The largest prime number found is printed as the result.
*/
