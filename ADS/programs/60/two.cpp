/*
A Hamiltonian path, is a path in an undirected graph that visits each vertex exactly once.
Given an undirected graph, the task is to check if a Hamiltonian path is present in it or not.
N (the number of vertices), M (Number of edges)

Input:
N = 4, M = 4
Edges[][]= { {1,2}, {2,3}, {3,4}, {2,4} }
Output:
1

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to recursively check for Hamiltonian Path
    bool checkHamiltonian(int node, int currVis, int n, int m, vector<int>& vis, vector<int> adj[]) {
        // Base case: If all nodes are visited, a Hamiltonian Path is found
        if (currVis == n)
            return true;

        vis[node] = 1; // Mark the current node as visited
        for (auto nodes : adj[node]) {
            if (!vis[nodes]) {
                if (checkHamiltonian(nodes, currVis + 1, n, m, vis, adj))
                    return true;
            }
        }

        vis[node] = 0; // Backtrack: Mark the current node as unvisited
        return false;
    }

    // Function to check for Hamiltonian Path in the graph
    bool check(int N, int M, vector<vector<int>> Edges) {
        vector<int> adj[N + 1]; // Adjacency list for the graph

        // Creating the adjacency list from the given edges
        for (auto vec : Edges) {
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Since the graph is undirected
        }

        // For each node in the graph, check if there's a Hamiltonian Path
        for (int i = 1; i <= N; i++) {
            vector<int> vis(N + 1, 0); // Initialize the visited array
            if (checkHamiltonian(i, 1, N, M, vis, adj))
                return true; // If Hamiltonian Path exists, return true
        }

        return false; // If no Hamiltonian Path is found, return false
    }
};

int main()
{
    int N, M, X, Y;
    cin >> N >> M; // Input: Number of nodes (N) and edges (M)
    vector<vector<int>> Edges; // Stores the edges of the graph

    // Input the edges from the user
    for (int i = 0; i < M; i++) {
        cin >> X >> Y;
        Edges.push_back({ X, Y });
    }

    Solution obj; // Create an instance of the Solution class
    if (obj.check(N, M, Edges)) {
        cout << "1" << endl; // Output: If Hamiltonian Path exists, print 1
    }
    else {
        cout << "0" << endl; // Output: If no Hamiltonian Path, print 0
    }

    return 0;
}


/*
This C++ program is designed to determine whether there exists a Hamiltonian Path in an undirected graph, which visits every
vertex exactly once. The program uses a backtracking approach to explore different paths in the graph while keeping track of
visited vertices. It also checks whether a given graph contains a Hamiltonian Path.

*/
