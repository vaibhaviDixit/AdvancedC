/*
Given a set of cities and distances between every pair of cities, the problem is to find the shortest possible route that visits every city exactly
once and returns to the starting point.

Input: { { 0, 10, 15, 20 },{ 10, 0, 35, 25 },{ 15, 35, 0, 30 },{ 20, 25, 30, 0 }}
Output: 80

*/

// CPP program to implement traveling salesman problem using naive approach.
#include <bits/stdc++.h>
using namespace std;
#define V 4

// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][V], int s)
{
	// store all vertex apart from source vertex
	vector<int> vertex;
	for (int i = 0; i < V; i++)
		if (i != s)
			vertex.push_back(i);

	// store minimum weight Hamiltonian Cycle.
	int min_path = INT_MAX;
	do {

		// store current Path weight(cost)
		int current_pathweight = 0;

		// compute current path weight
		int k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}
		current_pathweight += graph[k][s];

		// update minimum
		min_path = min(min_path, current_pathweight);

	} while (
		next_permutation(vertex.begin(), vertex.end()));

	return min_path;
}

int main()
{
	// matrix representation of graph
	int graph[][V] = { { 0, 10, 15, 20 },
					{ 10, 0, 35, 25 },
					{ 15, 35, 0, 30 },
					{ 20, 25, 30, 0 } };
	int s = 0;
	cout << travllingSalesmanProblem(graph, s) << endl;
	return 0;
}

/*
The constant V is defined to specify the number of vertices (cities) in the graph.

The travllingSalesmanProblem function takes the graph representation and the source vertex s as inputs and returns the length of the minimum Hamiltonian cycle (shortest route).

The function starts by creating a vector vertex that stores all the cities except the source city.

Using a brute-force approach, the function then iterates through all permutations of the vertex vector to find the minimum path weight (cost) of visiting the cities in a specific order and returning to the source city.

Inside the permutation loop:

The current path weight current_pathweight is initialized to 0.
A loop iterates through the vertex vector and calculates the total cost of the current path.
The minimum of min_path and current_pathweight is updated to store the minimum path weight encountered so far.
The main function:

Initializes the graph as a 2D array graph that represents the distance between cities.
Specifies the source vertex s.
Calls the travllingSalesmanProblem function to find the length of the shortest Hamiltonian cycle.
Prints the result.

*/




