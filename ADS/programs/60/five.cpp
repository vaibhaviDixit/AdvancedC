/*
Given a weighted directed graph represented by an adjacency matrix, find the shortest distances between all pairs of vertices using
Warshall's algorithm.

Input: matrix = {{0,1,43},{1,0,6},{-1,-1,0}}
Output: {{0,1,7},{1,0,6},{-1,-1,0}}

We can reach 2 from 0 as 0->1->2 and the cost will be 1+6=7 which is less than 43.

*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
      // Function to find the shortest distance between all pairs of vertices
    void shortest_distance(vector<vector<int>>&matrix){

        int n=matrix.size();

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                     // If there is a path from vertex i to vertex k and from vertex k to vertex j
                    if(matrix[i][k]!=-1 && matrix[k][j]!=-1){
                        if(matrix[i][j]==-1){
                            matrix[i][j]=matrix[i][k]+matrix[k][j];
                        }
                        else{
                            matrix[i][j]=min(matrix[i][j], matrix[i][k]+matrix[k][j]);
                        }
                    }
                }
            }
        }
    }
};

int main(){

		int n;
		cin >> n;
		 //Initialize a matrix with -1 representing no direct edge between vertices
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}

	return 0;
}


/*
This C++ program utilizes the Floyd-Warshall algorithm to compute the shortest distances between all pairs of vertices in a graph represented by a distance matrix. The program follows these steps:

Header and Libraries: The program includes the necessary C++ standard libraries.

Class Solution: This class encapsulates the algorithm to compute the shortest distances.

shortest_distance Function:

This function takes a reference to a 2D vector (matrix) representing the distance matrix as input.
It iterates through each vertex k and updates the distance matrix based on the shortest paths through vertex k.
If there is a path from vertex i to k and from k to j, the function updates the distance from vertex i to j if it's shorter through vertex k.
main Function:

The program starts by inputting the number of vertices (n).
It initializes a distance matrix with -1 representing no direct edges.
The program then inputs the distance matrix.
An object of the Solution class is created, and the shortest_distance function is called on the matrix.
Finally, the program outputs the computed shortest distance matrix.
The program's core is the shortest_distance function, which applies the Floyd-Warshall algorithm to efficiently compute the shortest distances between all pairs of vertices, and the result is printed as the updated distance matrix.

*/
