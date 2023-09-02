/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs.

Input : 4
Output : 7
Explanation:
Below are the seven ways
 1 step + 1 step + 1 step + 1 step
 1 step + 2 step + 1 step
 2 step + 1 step + 1 step
 1 step + 1 step + 2 step
 2 step + 2 step
 3 step + 1 step
 1 step + 3 step

Input : 3
Output : 4


*/

// C++ Program to find n-th stair using step size 1 or 2 or 3.
#include <bits/stdc++.h>
using namespace std;

class Test {
private:
	int findStepHelper(int n, vector<int>& dp)
	{
		// Base Case
		if (n == 0)
			return 1;
		else if (n < 0)
			return 0;
		// If subproblems are already calculated
		//then return it
		if (dp[n] != -1) {
			return dp[n];
		}

	// store the subproblems in the vector
		return dp[n] = findStepHelper(n - 3, dp)
					+ findStepHelper(n - 2, dp)
					+ findStepHelper(n - 1, dp);
	}

	// Returns count of ways to reach n-th stair using 1 or 2 or 3 steps.
public:
	int findStep(int n)
	{
		vector<int> dp(n + 1, -1);
		return findStepHelper(n, dp);
	}
};

int main()
{
	Test g;
	int n = 4;

	cout << g.findStep(n);
	return 0;
}

/*

Class Definition:

Test is a class that contains the implementation for calculating the number of ways to reach the nth stair using step sizes of 1, 2, or 3.
Private Function findStepHelper:

This private member function is used to recursively find the number of ways to reach the nth stair while considering step sizes of 1, 2, or 3.
It takes two parameters: n (the current stair number) and dp (a vector to store previously calculated subproblems).
The function uses dynamic programming and recursion to calculate the number of ways to reach the nth stair.
It first handles the base cases: if n is 0, there's only one way (no steps needed), and if n is negative, there are no ways.
If the value of dp[n] (the number of ways to reach the nth stair) is already calculated and stored, the function returns it.
Otherwise, it calculates the number of ways by summing the results of recursive calls to findStepHelper with step sizes of 1, 2, and 3. The results are stored in dp to avoid recomputation.
Public Function findStep:

This public member function initializes a vector dp with -1 values to store subproblem results.
It then calls the private findStepHelper function with the input parameter n and the dp vector.
The result of the helper function call is returned.
Main Function:

The main function creates an instance of the Test class named g.
An integer n is set to 4, representing the nth stair for which the number of ways is to be calculated.
The program then prints the result of the findStep function call on the instance g with input parameter n.

*/

