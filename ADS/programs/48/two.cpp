/*
There are 100 different types of caps each having a unique id from 1 to 100. Also, there are ‘n’ persons each having a collection of a variable number of
caps. One day all of these persons decide to go in a party wearing a cap but to look unique they decided that none of them will wear the same type of cap.
So, count the total number of arrangements or ways such that none of them is wearing the same type of cap.
Constraints: 1 <= n <= 10

The first line contains the value of n, next n lines contain collections
of all the n persons.
Input:
3
5 100 1     // Collection of the first person.
2           // Collection of the second person.
5 100       // Collection of the third person.

Output: 4

*/

// C++ program to find number of ways to wear hats
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

// capList[i]'th vector contains the list of persons having a cap with id i id is between 1 to 100 so we declared an array of 101 vectors as indexing
// starts from 0.
vector<int> capList[101];

// dp[2^10][101] .. in dp[i][j], i denotes the mask i.e., it tells that how many and which persons are wearing cap. j denotes the first j caps
// used. So, dp[i][j] tells the number ways we assign j caps to mask i such that none of them wears the same cap
int dp[1025][101];

// This is used for base case, it has all the N bits set so, it tells whether all N persons are wearing a cap.
int allmask;

// Mask is the set of persons, i is cap-id (OR the number of caps processed starting from first cap).
long long int countWaysUtil(int mask, int i)
{
	// If all persons are wearing a cap so we are done and this is one way so return 1
	if (mask == allmask) return 1;

	// If not everyone is wearing a cap and also there are no more caps left to process, so there is no way, thus return 0;
	if (i > 100) return 0;

	// If we already have solved this subproblem, return the answer.
	if (dp[mask][i] != -1) return dp[mask][i];

	// Ways, when we don't include this cap in our arrangement or solution set.
	long long int ways = countWaysUtil(mask, i+1);

	// size is the total number of persons having cap with id i.
	int size = capList[i].size();

	// So, assign one by one ith cap to all the possible persons and recur for remaining caps.
	for (int j = 0; j < size; j++)
	{
		// if person capList[i][j] is already wearing a cap so continue as we cannot assign him this cap
		if (mask & (1 << capList[i][j])) continue;

		// Else assign him this cap and recur for remaining caps with new updated mask vector
		else ways += countWaysUtil(mask | (1 << capList[i][j]), i+1);
		ways %= MOD;
	}

	// Save the result and return it.
	return dp[mask][i] = ways;
}

// Reads n lines from standard input for current test case
void countWays(int n)
{
	//----------- READ INPUT --------------------------
	string temp, str;
	int x;
	getline(cin, str); // to get rid of newline character
	for (int i=0; i<n; i++)
	{
		getline(cin, str);
		stringstream ss(str);

		// while there are words in the streamobject ss
		while (ss >> temp)
		{
			stringstream s;
			s << temp;
			s >> x;

			// add the ith person in the list of cap if with id x
			capList[x].push_back(i);
		}
	}
	//----------------------------------------------------

	// All mask is used to check whether all persons
	// are included or not, set all n bits as 1
	allmask = (1 << n) - 1;

	// Initialize all entries in dp as -1
	memset(dp, -1, sizeof dp);

	// Call recursive function count ways
	cout << countWaysUtil(0, 1) << endl;
}

int main()
{
	int n; // number of persons in every test case
	cin >> n;
	countWays(n);
	return 0;
}

/*
It uses a vector of vectors capList, where capList[i] contains the list of persons having a cap with id i. The program assumes that cap ids are between 1 and 100, so it creates an array of 101 vectors.

The 2D array dp of size [1025][101] is used for dynamic programming. In dp[i][j], i represents a mask indicating which persons are wearing caps, and j represents the number of caps processed so far.

The variable allmask is used to check if all persons are wearing caps. It is initialized with all bits set to 1 ((1 << n) - 1) to represent all persons wearing caps.

The function countWaysUtil is a recursive function that calculates the number of ways people can wear caps while considering the constraints. It takes two parameters: mask (a bitmask representing the persons wearing caps) and i (the index of the current cap being considered).

The base cases are as follows:

If mask equals allmask, it means all persons are wearing caps, so there is only one way to assign caps. The function returns 1 in this case.
If i exceeds 100 (the maximum cap id), it means there are no more caps to process, so there is no valid way to assign caps. The function returns 0 in this case.
The program uses memoization to avoid redundant calculations. If dp[mask][i] is not equal to -1, it means the result for this subproblem has already been calculated, so the function returns the cached result.

The ways variable is initialized with the result of recursively calling countWaysUtil with the same mask and the next cap (i+1).

It then iterates over all persons who can wear the current cap (stored in capList[i]). If a person is not already wearing a cap (checked using bitwise operations), it assigns the cap to that person and recursively calls countWaysUtil with the updated mask and the next cap (i+1).

The result ways is updated and kept modulo MOD to prevent integer overflow.

Finally, the result is stored in dp[mask][i] for memoization and returned.

The countWays function reads input data for the current test case and initializes the data structures.

*/


