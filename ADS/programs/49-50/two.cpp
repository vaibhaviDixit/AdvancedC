/*
Given a range [low, high], print all primes in this range. For example, if the given range is [10, 20], then output is 11, 13, 17, 19.
Use Segmented Sieve

Input: low=2 high=100
Output:
Primes in range 2 to 100 are
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97

*/

#include <bits/stdc++.h>
using namespace std;
// fillPrime function fills primes from 2 to sqrt of high in chprime(vector) array
void fillPrimes(vector<int>& prime, int high)
{
    bool ck[high + 1];
    memset(ck, true, sizeof(ck));
    ck[1] = false;
    ck[0] = false;
    for (int i = 2; (i * i) <= high; i++)
    {
        if (ck[i] == true)
        {
            for (int j = i * i; j <= sqrt(high); j = j + i)
            {
                ck[j] = false;
            }
        }
    }
    for (int i = 2; i * i <= high; i++)
    {
        if (ck[i] == true)
        {
            prime.push_back(i);
        }
    }
}
// in segmented sieve we check for prime from range [low, high]
void segmentedSieve(int low, int high)
{
    if (low<2 and high>=2)
    {
        low = 2;
    }//for handling corner case when low = 1 and we all know 1 is not prime no.
    bool prime[high - low + 1];
//here prime[0] indicates whether low is prime or not similarly prime[1] indicates whether low+1 is prime or not
    memset(prime, true, sizeof(prime));

    vector<int> chprime;
    fillPrimes(chprime, high);
    //chprimes has primes in range [2,sqrt(n)]
    // we take primes from 2 to sqrt[n] because the multiples of all primes below high are marked by these
// primes in range 2 to sqrt[n] for eg: for number 7 its multiples i.e 14 is marked by 2, 21 is marked by 3,
// 28 is marked by 4, 35 is marked by 5, 42 is marked 6, so 49 will be first marked by 7 so all number before 49
// are marked by primes in range [2,sqrt(49)]
    for (int i : chprime)
    {
        int lower = (low / i);
        //here lower means the first multiple of prime which is in range [low,high]
        //for eg: 3's first multiple in range [28,40] is 30
        if (lower <= 1)
        {
            lower = i + i;
        }
        else if (low % i)
        {
            lower = (lower * i) + i;
        }
        else
        {
            lower = (lower * i);
        }
        for (int j = lower; j <= high; j = j + i)
        {
            prime[j - low] = false;
        }
    }

    for (int i = low; i <= high; i++)
    {
        if (prime[i - low] == true)
        {
            cout << (i) << " ";
        }
    }
}
int main()
{
    // low should be greater than or equal to 2
    int low = 2;
    // low here is the lower limit
    int high = 100;
    /* high here is the upper limit
    in segmented sieve we calculate primes in range [low,high]
    here we initially we find primes in range [2,sqrt(high)] to mark all their multiples as not prime
    then we mark all their(primes) multiples in range [low,high] as false
    this is a modified sieve of eratosthenes , in standard sieve of eratosthenes we find prime from 1 to n(given number)
    in segmented sieve we only find primes in a given interval
    */
    cout<<"Primes in range "<<low<<" to "<< high<<" are\n";
    segmentedSieve(low, high);
}

/*
It defines a function called fillPrimes that calculates and stores prime numbers from 2 to the square root of the specified upper limit high. It uses the traditional sieve of Eratosthenes algorithm to find prime numbers within this range. The prime numbers are stored in the vector prime.

Inside the fillPrimes function:

It creates a boolean array named ck of size high + 1 to mark whether a number is prime or not. All entries in this array are initially set to true.
It explicitly sets ck[0] and ck[1] to false because 0 and 1 are not prime numbers.
It iterates through numbers from 2 to the square root of high. For each prime number i, it marks its multiples as false in the ck array.
It stores all prime numbers found in the prime vector.
The segmentedSieve function takes two parameters: low and high, representing the lower and upper bounds of the range within which prime numbers are to be found.

Inside the segmentedSieve function:

It includes a conditional statement to handle the case when low is less than 2, setting it to 2 because 1 is not a prime number.
It initializes a boolean array named prime to mark whether each number in the range [low, high] is prime or not. Here, prime[i - low] represents whether the number i is prime or not.

It defines a vector called chprime to store all prime numbers from 2 to the square root of high by calling the fillPrimes function.

For each prime number i in the chprime vector, it calculates the first multiple of i within the range [low, high]. This step ensures that multiples of each prime within the range [low, high] are correctly marked as non-prime. The multiples are marked as false in the prime array.

Finally, it iterates through the range [low, high] and prints all numbers that are marked as prime (prime[i - low] == true).

In the main function:

It initializes the lower limit low to 2 (because primes start from 2).
It sets the upper limit high to the desired value, e.g., 100.
It prints a message indicating that it will find prime numbers in the range [low, high].
It calls the segmentedSieve function with the values of low and high.

*/
