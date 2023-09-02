/*
Given a set of non-negative integers and a value sum, the task is to check if there is a subset of the given set whose sum is equal to the given sum.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True
Explanation: There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False

*/

// A Dynamic Programming solution for subset sum problem
#include <bits/stdc++.h>
using namespace std;

// Returns true if there is a subset of set[] with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
	// The value of subset[i][j] will be true if there is a subset of set[0..j-1] with sum equal to i
	bool subset[n + 1][sum + 1];

	// If sum is 0, then answer is true
	for (int i = 0; i <= n; i++)
		subset[i][0] = true;

	// If sum is not 0 and set is empty, then answer is false
	for (int i = 1; i <= sum; i++)
		subset[0][i] = false;

	// Fill the subset table in bottom up manner
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			if (j >= set[i - 1])
				subset[i][j]
					= subset[i - 1][j]
					|| subset[i - 1][j - set[i - 1]];
		}
	}

	return subset[n][sum];
}


int main()
{
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		cout << "Found a subset with given sum";
	else
		cout << "No subset with given sum";
	return 0;
}

/*
The isSubsetSum Function: This function determines whether there is a subset of the given set with a sum equal to the provided target sum. It takes three parameters: an array of integers set[] representing the set of elements, an integer n representing the number of elements in the set, and an integer sum representing the target sum.

2D Subset Table: A 2D boolean array subset is created of size (n + 1) x (sum + 1). The element subset[i][j] will be true if there is a subset of the first i elements with a sum equal to j.

Base Cases: Two loops are used to initialize the base cases:

The loop for (int i = 0; i <= n; i++) initializes the first column of the subset table. If the sum is 0, then there is always an empty subset that results in a sum of 0.
The loop for (int i = 1; i <= sum; i++) initializes the first row of the subset table. If the set is empty, it's not possible to achieve any positive sum.
Filling the Subset Table: Two nested loops iterate over the set elements and the target sum, respectively. For each element i and sum j, the following steps are performed:

If the current element set[i - 1] is greater than the current sum j, then the value at subset[i][j] is copied from the previous row, indicating that the current element cannot be used.
If the current element set[i - 1] is less than or equal to the current sum j, then the value at subset[i][j] is updated based on two cases: either by excluding the current element or by including the current element. The logic subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]] captures this inclusion/exclusion logic.

*/


