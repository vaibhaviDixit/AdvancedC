/*
You are given a list of N coins of different denominations. You can pay an amount equivalent to any 1 coin and can acquire that coin. In addition,
once you have paid for a coin, we can choose at most K more coins and can acquire those for free. The task is to find the minimum amount required to
acquire all the N coins for a given value of K.


Input : coin[] = {100, 20, 50, 10, 2, 5},
        k = 3
Output : 7

Input : coin[] = {1, 2, 5, 10, 20, 50},
        k = 3
Output : 3

*/


// C++ program to acquire all n coins
#include<bits/stdc++.h>
using namespace std;

// function to calculate min cost
int minCost(int coin[], int n, int k)
{
	// sort the coins value
	sort(coin, coin + n);

	// calculate no. of coins needed
	int coins_needed = ceil(1.0 * n /
							(k + 1));

	// calculate sum of all selected coins
	int ans = 0;
	for (int i = 0; i <= coins_needed - 1;
									i++)
		ans += coin[i];

	return ans;
}

int main()
{
	int coin[] = {8, 5, 3, 10,2, 1, 15, 25};
	int n = sizeof(coin) / sizeof(coin[0]);
	int k = 3;
	cout << minCost(coin, n, k);
	return 0;
}

/*
The program defines the minCost function, which calculates the minimum cost to acquire all n coins with certain restrictions. It takes the following parameters:

coin[]: An array representing the values of n coins.
n: The number of coins.
k: A parameter that limits the number of coins that can be chosen consecutively without choosing any other coin in between.
Inside the function:

The coin[] array is sorted in non-decreasing order.

The number of coins needed to acquire all n coins is calculated using the formula:

coins_needed = ceil(1.0 * n / (k + 1))
This formula calculates how many groups of k+1 consecutive coins are needed to acquire all the coins.

An integer variable ans is initialized to 0. This variable will store the minimum cost.

A loop iterates over the first coins_needed coins in the sorted array.

Inside the loop, the values of the selected coins are added to ans.
Finally, the function returns the value of ans, which represents the minimum cost to acquire all n coins.

In the main function:

An array coin[] is defined, representing the values of the coins.
The number of coins n is calculated using sizeof(coin) / sizeof(coin[0]).
The parameter k is set to 3, which means that no more than 3 consecutive coins can be chosen without choosing any other coin in between.
The minCost function is called with the coin[] array, n, and k as arguments.
The program prints the result to the console.

*/
