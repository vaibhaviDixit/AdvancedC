/*
 C++ code to find out minimum cost path to connect all the cities

Input : {{0, 1, 1, 100, 0, 0},
         {1, 0, 1, 0, 0, 0},
         {1, 1, 0, 0, 0, 0},
         {100, 0, 0, 0, 2, 2},
         {0, 0, 0, 2, 0, 2},
         {0, 0, 0, 2, 2, 0}};
Output : 106

Input : {{0, 1, 2, 3, 4},
         {1, 0, 5, 0, 7},
         {2, 5, 0, 6, 0},
         {3, 0, 6, 0, 0},
         {4, 7, 0, 0, 0}};
Output : 10

*/

#include <bits/stdc++.h>

using namespace std;

// Function to find out minimum valued node
// among the nodes which are not yet included in MST
int minnode(int n, int keyval[], bool mstset[])
{
    int mini = numeric_limits<int>::max();
    int mini_index;

// Loop through all the values of the nodes
// which are not yet included in MST and find
// the minimum valued one.
    for (int i = 0; i < n; i++)
    {
        if (mstset[i] == false && keyval[i] < mini)
        {
            mini = keyval[i], mini_index = i;
        }
    }
    return mini_index;
}

// Function to find out the MST and
// the cost of the MST.
void findcost(int n, vector<vector<int>> city)
{

// Array to store the parent node of a
// particular node.
    int parent[n];

// Array to store key value of each node.
    int keyval[n];

// Boolean Array to hold bool values whether
// a node is included in MST or not.
    bool mstset[n];

// Set all the key values to infinite and
// none of the nodes is included in MST.
    for (int i = 0; i < n; i++)
    {
        keyval[i] = numeric_limits<int>::max();
        mstset[i] = false;
    }

// Start to find the MST from node 0.
// Parent of node 0 is none so set -1.
// key value or minimum cost to reach
// 0th node from 0th node is 0.
    parent[0] = -1;
    keyval[0] = 0;

// Find the rest n-1 nodes of MST.
    for (int i = 0; i < n - 1; i++)
    {

        // First find out the minimum node
        // among the nodes which are not yet
        // included in MST.
        int u = minnode(n, keyval, mstset);

        // Now the uth node is included in MST.
        mstset[u] = true;

        // Update the values of neighbor
        // nodes of u which are not yet
        // included in MST.
        for (int v = 0; v < n; v++)
        {

            if (city[u][v] && mstset[v] == false &&
                    city[u][v] < keyval[v])
            {
                keyval[v] = city[u][v];
                parent[v] = u;
            }
        }
    }

// Find out the cost by adding
// the edge values of MST.
    int cost = 0;
    for (int i = 1; i < n; i++)
        cost += city[parent[i]][i];
    cout << cost << endl;
}

// Utility Program:
int main()
{

// Input 1
    int n1 = 5;
    vector<vector<int>> city1 = {{0, 1, 2, 3, 4},
        {1, 0, 5, 0, 7},
        {2, 5, 0, 6, 0},
        {3, 0, 6, 0, 0},
        {4, 7, 0, 0, 0}
    };
    findcost(n1, city1);

// Input 2
    int n2 = 6;
    vector<vector<int>> city2 = {{0, 1, 1, 100, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {100, 0, 0, 0, 2, 2},
        {0, 0, 0, 2, 0, 2},
        {0, 0, 0, 2, 2, 0}
    };
    findcost(n2, city2);

    return 0;
}

/*
The minnode function is defined to find the minimum valued node among the nodes that are not yet included in the Minimum Spanning Tree (MST). It takes the number of nodes n, an array of key values keyval[] (the cost to reach each node), and a boolean array mstset[] that marks whether a node is included in the MST.

The findcost function calculates the minimum cost path to connect all cities. It takes the number of nodes n and a 2D vector city that represents the cost matrix between cities.

Inside the findcost function:

Arrays are initialized to store parent nodes, key values, and whether nodes are included in the MST.
All key values are set to infinity, and all nodes are initially not included in the MST.
The key value of the first node (0th node) is set to 0 since the path cost to itself is 0.
A loop iterates through all nodes to build the MST.
The minimum valued node among those not included in the MST is identified using the minnode function.
The identified node is included in the MST (mstset[u] = true).
The algorithm updates the key values and parent nodes for neighboring nodes that are not yet included in the MST.
Finally, the cost of the MST is calculated by adding up the edge values between the nodes in the MST.

*/


