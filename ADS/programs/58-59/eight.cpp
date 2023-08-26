/*
Given a directed and strongly connected graph with non-negative edge weights. We define the mean weight of a cycle as the summation of all the edge
weights of the cycle divided by the no. of edges. Our task is to find the minimum mean weight among all the directed cycles of the graph.

Input: [(0, 1, 1),(0, 2, 10),(1, 2, 3),(2, 3, 2),(3, 1, 0),(3, 0, 8)]

Output: 1.66667

*/

// C++ program to find minimum average weight of a cycle in connected and directed graph.

#include<bits/stdc++.h>
using namespace std;

const int V = 4;

// a struct to represent edges
struct edge
{
	int from, weight;
};

// vector to store edges
vector <edge> edges[V];

void addedge(int u,int v,int w)
{
	edges[v].push_back({u, w});
}

// calculates the shortest path
void shortestpath(int dp[][V])
{
	// initializing all distances as -1
	for (int i=0; i<=V; i++)
		for (int j=0; j<V; j++)
			dp[i][j] = -1;

	// shortest distance from first vertex
	// to in itself consisting of 0 edges
	dp[0][0] = 0;

	// filling up the dp table
	for (int i=1; i<=V; i++)
	{
		for (int j=0; j<V; j++)
		{
			for (int k=0; k<edges[j].size(); k++)
			{
				if (dp[i-1][edges[j][k].from] != -1)
				{
					int curr_wt = dp[i-1][edges[j][k].from] +
								edges[j][k].weight;
					if (dp[i][j] == -1)
						dp[i][j] = curr_wt;
					else
					dp[i][j] = min(dp[i][j], curr_wt);
				}
			}
		}
	}
}

// Returns minimum value of average weight of a
// cycle in graph.
double minAvgWeight()
{
	int dp[V+1][V];
	shortestpath(dp);

	// array to store the avg values
	double avg[V];
	for (int i=0; i<V; i++)
		avg[i] = -1;

	// Compute average values for all vertices using
	// weights of shortest paths store in dp.
	for (int i=0; i<V; i++)
	{
		if (dp[V][i] != -1)
		{
			for (int j=0; j<V; j++)
				if (dp[j][i] != -1)
					avg[i] = max(avg[i],
				((double)dp[V][i]-dp[j][i])/(V-j));
		}
	}

	// Find minimum value in avg[]
	double result = avg[0];
	for (int i=0; i<V; i++)
		if (avg[i] != -1 && avg[i] < result)
			result = avg[i];

	return result;
}

int main()
{
	addedge(0, 1, 1);
	addedge(0, 2, 10);
	addedge(1, 2, 3);
	addedge(2, 3, 2);
	addedge(3, 1, 0);
	addedge(3, 0, 8);

	cout << minAvgWeight();

	return 0;
}

/*
The program defines the number of vertices V in the graph as a constant.

The edge struct represents an edge with attributes from (source vertex) and weight (weight of the edge).

The edges vector array stores the edges of the graph. Each element of the array is a vector that contains the edges for a specific vertex.

The addedge function is used to add an edge to the edges array with the given source vertex u, destination vertex v, and weight w.

The shortestpath function calculates the shortest paths using dynamic programming.

The dp array stores the shortest distances from vertex j to vertex i using i edges.
It initializes the dp table with -1.
The shortest distance from the first vertex to itself with 0 edges is set to 0.
The function iterates through each vertex and edge, calculating the shortest path using the previous values in the dp table.
The calculated shortest distance is stored in the dp table.
The minAvgWeight function calculates the minimum average weight of a cycle in the graph.

It calls the shortestpath function to calculate the dp table.
It initializes the avg array to store average values for each vertex.
For each vertex, it computes the average weight using the shortest paths stored in the dp table.
The result variable stores the minimum average weight found among all vertices.
The main function initializes the graph by adding edges to the edges vector.

The example graph in this program has 4 vertices.
The addedge function is used to add the directed edges along with their weights.
The minAvgWeight function is called to calculate and print the minimum average weight of a cycle in the graph.

*/


