/*
Given a set of n elements, find number of ways of partitioning it.(Bell Numbers)

Input:  n = 2
Output: Number of ways = 2

Input:  n = 3
Output: Number of ways = 5

*/

// A C++ program to find n'th Bell number
#include<iostream>
using namespace std;

int bellNumber(int n)
{
    int bell[n+1][n+1];
    bell[0][0] = 1;
    for (int i=1; i<=n; i++)
    {
        // Explicitly fill for j = 0
        bell[i][0] = bell[i-1][i-1];

        // Fill for remaining values of j
        for (int j=1; j<=i; j++)
            bell[i][j] = bell[i-1][j-1] + bell[i][j-1];
    }
    return bell[n][0];
}

int main()
{
    for (int n=0; n<=5; n++)
        cout << "Bell Number " << n << " is "
             << bellNumber(n) << endl;
    return 0;
}

/*
The bellNumber Function: This function calculates the nth Bell number using a dynamic programming approach. It takes an integer parameter n representing the index of the desired Bell number in the sequence.

Bell Number Matrix: An array bell of size (n+1) x (n+1) is created to store the Bell numbers. bell[i][j] will store the Bell number for the partition of i elements into j subsets.

Base Case: The value bell[0][0] is set to 1 as the base case. It represents the number of ways to partition an empty set into an empty subset.

Filling the Matrix: A nested loop structure is used to fill in the bell matrix. The outer loop iterates from 1 to n, representing the number of elements in the set. The inner loop iterates from 0 to i, representing the number of subsets to partition the set into.

For each i, the value of bell[i][0] is set to the value of the previous row's last element (bell[i-1][i-1]).
For the remaining values of j, bell[i][j] is calculated as the sum of the element above it (bell[i-1][j-1]) and the element to the left of it (bell[i][j-1]). This represents adding the last element of the previous partition and the element that results from partitioning the current element into a new subset.
Output in main Function: The main function contains a loop that iterates from 0 to 5 (for the first 6 Bell numbers). Inside the loop, the bellNumber function is called with the loop variable n as an argument. The calculated Bell number is printed using cout.

Printing Result: The loop prints the calculated Bell numbers for n values 0 to 5.

*/
