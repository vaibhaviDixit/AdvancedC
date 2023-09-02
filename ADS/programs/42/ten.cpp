/*
Travelling Salesman Problem (TSP):
Given a set of cities and the distance between every pair of cities, the problem is to find the shortest possible route that visits every city
exactly once and returns to the starting point. Note the difference between Hamiltonian Cycle and TSP. The Hamiltonian cycle problem is to find
if there exists a tour that visits every city exactly once. Here we know that Hamiltonian Tour exists (because the graph is complete) and in fact,
many such tours exist, the problem is to find a minimum weight Hamiltonian Cycle.

Input: { { 0, 0, 0, 0, 0 }, { 0, 0, 10, 15, 20 },{ 0, 10, 0, 25, 25 }, { 0, 15, 25, 0, 30 },{ 0, 20, 25, 30, 0 }}
Output: 80


*/


#include <iostream>

using namespace std;

// there are four nodes in example graph (graph is 1-based)
const int n = 4;
// give appropriate maximum to avoid overflow
const int MAX = 1000000;

// dist[i][j] represents shortest distance to go from i to j this matrix can be calculated for any given graph using all-pair shortest path algorithms
int dist[n + 1][n + 1] = {
	{ 0, 0, 0, 0, 0 }, { 0, 0, 10, 15, 20 },
	{ 0, 10, 0, 25, 25 }, { 0, 15, 25, 0, 30 },
	{ 0, 20, 25, 30, 0 },
};

// memoization for top down recursion
int memo[n + 1][1 << (n + 1)];

int fun(int i, int mask)
{
	// base case
	// if only ith bit and 1st bit is set in our mask, it implies we have visited all other nodes already
	if (mask == ((1 << i) | 3))
		return dist[1][i];
	// memoization
	if (memo[i][mask] != 0)
		return memo[i][mask];

	int res = MAX; // result of this sub-problem

	// we have to travel all nodes j in mask and end the path at ith node so for every node j in mask,
	// recursively calculate cost of travelling all nodes in mask except i and then travel back from node j to node i taking the shortest path take the minimum of all possible j nodes

	for (int j = 1; j <= n; j++)
		if ((mask & (1 << j)) && j != i && j != 1)
			res = std::min(res, fun(j, mask & (~(1 << i)))
									+ dist[j][i]);
	return memo[i][mask] = res;
}
// Driver program to test above logic
int main()
{
	int ans = MAX;
	for (int i = 1; i <= n; i++)
		// try to go from node 1 visiting all nodes in between to i then return from i taking the shortest route to 1
		ans = std::min(ans, fun(i, (1 << (n + 1)) - 1)
								+ dist[i][1]);

	printf("The cost of most efficient tour = %d", ans);

	return 0;
}

/*
Constants and Data: It defines constants for the number of nodes (n) and a maximum value (MAX) to avoid overflow.

Distance Matrix dist: A 2D array dist represents the distances between nodes. The value dist[i][j] is the distance from node i to node j.

Memoization Array memo: A 2D memoization array memo is used to store the results of subproblems. The value memo[i][mask] represents the minimum cost to visit all nodes in the mask and end at node i.

Function fun:

This function takes two parameters: i (current node) and mask (bitmask representing visited nodes).
The base case checks if the mask includes only the 1st and i-th bits set, which implies that all other nodes have been visited, and the tour can return to node 1. In this case, it returns the distance from node 1 to node i.
Memoization is used to store and reuse already calculated results to avoid redundant calculations.
The function initializes a variable res to a large value (MAX) to store the result of this subproblem.
For each node j in the mask, it calculates the cost of visiting all nodes in the mask except i, then traveling back from node j to node i taking the shortest path. It keeps track of the minimum value res.
Finally, it updates the memo array and returns the result res.
Main Function:

The main function initializes a variable ans to the maximum value (MAX).
It iterates over all nodes from 1 to n and calculates the cost of the most efficient tour by going from node 1 to all other nodes and returning to node 1.
The calculated cost is stored in the variable ans.

*/

