/*
 C++ program to find the path in Peterson graph

 Note: The Peterson graph is a well-known example of a non-Hamiltonian graph, meaning it does not contain a Hamiltonian circuit—a circuit
 that visits each vertex exactly once.

 Input : s = 'ABB'
 Output: 016

 Input : s = 'AABE'
 Output :-1

*/


#include <bits/stdc++.h>
using namespace std;

// path to be checked
char S[100005];

// adjacency matrix.
bool adj[10][10];

// resulted path - way
char result[100005];

// we are applying breadth first search
// here
bool findthepath(char* S, int v)
{
	result[0] = v + '0';
	for (int i = 1; S[i]; i++) {

		// first traverse the outer graph
		if (adj[v][S[i] - 'A'] || adj[S[i] -
							'A'][v]) {
			v = S[i] - 'A';
		}

		// then traverse the inner graph
		else if (adj[v][S[i] - 'A' + 5] ||
				adj[S[i] - 'A' + 5][v]) {
			v = S[i] - 'A' + 5;
		}

		// if the condition failed to satisfy
		// return false
		else
			return false;

		result[i] = v + '0';
	}

	return true;
}

int main()
{
	// here we have used adjacency matrix to make
	// connections between the connected nodes
	adj[0][1] = adj[1][2] = adj[2][3] = adj[3][4] =
	adj[4][0] = adj[0][5] = adj[1][6] = adj[2][7] =
	adj[3][8] = adj[4][9] = adj[5][7] = adj[7][9] =
	adj[9][6] = adj[6][8] = adj[8][5] = true;

	// path to be checked
	char S[] = "ABB";

	if (findthepath(S, S[0] - 'A') ||
		findthepath(S, S[0] - 'A' + 5)) {
		cout << result;
	} else {
		cout << "-1";
	}
	return 0;
}

/*
Adjacency Matrix: The program uses an adjacency matrix (adj) to represent the connections between nodes in the Peterson graph. The adjacency matrix indicates whether there is an edge between two nodes. The connections are set up to represent the structure of the Peterson graph.

Path to be Checked: The variable S holds the sequence of characters that represents the path to be checked in the Peterson graph. For example, if S is "ABB", it means the program will check whether there exists a path in the graph that follows the sequence "ABB".

Breadth First Search (BFS) Approach: The program uses a breadth-first search approach to find the specified path in the Peterson graph. It starts at a given node (determined by the first character in the sequence) and iterates through the sequence of characters to traverse the graph.

Finding the Path: The findthepath function is responsible for finding the path in the Peterson graph. It takes the input sequence S and the starting node index (derived from the first character in S) as parameters. The function iterates through each character in the sequence. It first tries to traverse the outer graph using the adjacency matrix. If that is not possible, it then tries to traverse the inner graph. If neither option is possible, the function returns false.

Printing the Result: If the findthepath function successfully finds a path, it constructs the path using node indices and stores it in the result array. The result array holds the nodes in the order they are visited to form the desired path.

Main Function: In the main function, the adjacency matrix is set up to represent the Peterson graph's connections. The program then calls the findthepath function with the given sequence S and starting node index (based on the first character in S). If a valid path is found, the program prints the path; otherwise, it prints "-1".

*/
