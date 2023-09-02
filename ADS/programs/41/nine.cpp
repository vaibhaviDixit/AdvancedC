/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. Since the answer can be large return it modulo 10^9 + 7.

Input : n = 2 k = 4
Output : 16
Explanation: We have 4 colors and 2 posts.
Ways when both posts have same color : 4
Ways when both posts have diff color :4(choices for 1st post) * 3(choices for 2nd post) = 12

Input : n = 3 k = 2
Output : 6

*/

// C++ program for Painting Fence Algorithm optimised version

#include <bits/stdc++.h>
using namespace std;

// Returns count of ways to color k posts
long countWays(int n, int k)
{
	long dp[n + 1];
	memset(dp, 0, sizeof(dp));
	long long mod = 1000000007;

	dp[1] = k;
	dp[2] = k * k;

	for (int i = 3; i <= n; i++) {
		dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
	}

	return dp[n];
}

int main()
{
	int n = 3, k = 2;
	cout << countWays(n, k) << endl;
	return 0;
}

/*
The countWays Function: This function calculates the count of ways to color n fence posts using k colors, ensuring that no more than two adjacent posts have the same color. It takes two integer parameters: n (the number of fence posts) and k (the number of available colors).

Array dp: A long array dp of size n + 1 is declared to store the count of valid coloring arrangements for different numbers of fence posts. Each element dp[i] represents the count of ways to color i fence posts.

Modulus for Large Numbers: The variable mod is assigned the value 1000000007. This value is used to take the modulus of intermediate results to prevent integer overflow in cases where the numbers become large.

Base Cases: The initial values of dp[1] and dp[2] are set to k and k * k respectively. These values represent the valid coloring arrangements for 1 and 2 fence posts.

Dynamic Programming Loop: A loop iterates from 3 to n, representing the number of fence posts. For each value of i, the following formula is used to calculate the count of valid coloring arrangements:

dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
The (k - 1) factor accounts for the restriction that no more than two adjacent posts can have the same color.

*/
