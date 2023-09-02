/*
In share trading, a buyer buys shares and sells on a future date. Given the stock price of n days, the trader is allowed to make at most k transactions,
where a new transaction can only start after the previous transaction is complete, find out the maximum profit that a share trader could have made.

Input:
Price = [10, 22, 5, 75, 65, 80]
K = 2
Output:  87
--Trader earns 87 as sum of 12 and 75 Buy at price 10, sell at 22, buy at 5 and sell at 80

Input:
Price = [12, 14, 17, 10, 14, 13, 12, 15]
K = 3
Output:  12

*/



// C++ program to find out maximum profit by buying and selling a share atmost k times given stock price of n days
#include <bits/stdc++.h>
using namespace std;

int B;
vector<int> A;
int dp[501][201][2];
int solve(int j, int i, int b)
{
    // if the result has already been calculated return that result
    if (dp[i][j][b] != -1)
        return dp[i][j][b];
    // if i has reached the end of the array return 0
    if (i == B)
        return 0;
    // if we have exhausted the number of transaction return 0
    if (j == 0)
        return 0;
    int res;
    // if we are to buy stocks
    if (b == 1)
        res = max(-A[i] + solve(j, i + 1, 0), solve(j, i + 1, 1));
    // if we are to sell stock and complete one transaction
    else
        res = max(A[i] + solve(j - 1, i + 1, 1), solve(j, i + 1, 0));
    // return the result
    return dp[i][j][b] = res;
}
int maxProfit(int K, int N, int C[])
{
    A = vector<int>(N, 0);
    // Copying C to global A
    for (int i = 0; i < N; i++)
        A[i] = C[i];
    // Initializing DP with -1
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= K; j++)
        {
            dp[i][j][1] = -1;
            dp[i][j][0] = -1;
        }
    // Copying n to global B
    B = N;
    return solve(K, 0, 1);
}

int main()
{
    // TEST 1
    int k1 = 3;
    int price1[] = {12, 14, 17, 10, 14, 13, 12, 15};
    int n1 = sizeof(price1) / sizeof(price1[0]);
    cout << "Maximum profit is: "
         << maxProfit(k1, n1, price1) << endl;
    // TEST 2
    int k2 = 2;
    int price2[] = {10, 22, 5, 75, 65, 80};
    int n2 = sizeof(price2) / sizeof(price2[0]);

    cout << "Maximum profit is: "
         << maxProfit(k2, n2, price2);
    return 0;
}

/*
The maxProfit function takes three arguments: 'K' (the maximum number of transactions allowed), 'N' (the number of days for which stock prices are given), and 'C[]' (an array containing the stock prices for each day).

The program sets up a global vector A to store the stock prices and initializes a 3D dynamic programming array dp of size N+1 x K+1 x 2. The three dimensions represent the current day 'i', the remaining number of transactions 'j', and whether we hold a stock or not ('b' - 1 for holding, 0 for not holding).

The solve function is a recursive function that calculates the maximum profit based on the current day, remaining transactions, and stock holding status.

The dp array is used to memoize the results, so if a subproblem has been solved before, its result is stored in dp and returned directly.

Inside the solve function, it checks several conditions:

If we have reached the end of the array ('i == B'), return 0.
If we have exhausted the number of transactions ('j == 0'), return 0.
If we are holding a stock ('b == 1'), calculate the maximum profit by either selling the stock on the current day or not selling and moving to the next day.
If we are not holding a stock ('b == 0'), calculate the maximum profit by either buying a stock on the current day or not buying and moving to the next day.
The program sets the result in dp[i][j][b] and returns it.

In the main function, there are two test cases:

Test 1: 'k1' is set to 3, 'price1' contains the stock prices, and 'n1' is the number of elements in 'price1'. It calculates and prints the maximum profit.
Test 2: Similar to Test 1 but with different values.

*/
