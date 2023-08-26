/*
Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from the source or 1st cell.
Basically, the player has total control over the outcome of the dice throw and wants to find out the minimum number of throws required to reach the last cell.
If the player reaches a cell which is the base of a ladder, the player has to climb up that ladder and if reaches a cell is the mouth of the snake,
and has to go down to the tail of the snake without a dice throw.

Input:
  N=30

// Ladders
    moves[2] = 21
    moves[4] = 7
    moves[10] = 25
    moves[19] = 28

// Snakes
    moves[26] = 0
    moves[20] = 8
    moves[16] = 3
    moves[18] = 6


Output: Min Dice throws required is 3

*/

// C++ program to find minimum number of dice throws required to reach last cell from first cell of a given snake and ladder board
#include <iostream>
#include <queue>
using namespace std;

// An entry in queue used in BFS
struct queueEntry {
	int v; // Vertex number
	int dist; // Distance of this vertex from source
};

// This function returns minimum number of dice throws
// required to Reach last cell from 0'th cell in a snake and
// ladder game. move[] is an array of size N where N is no.
// of cells on board If there is no snake or ladder from
// cell i, then move[i] is -1 Otherwise move[i] contains
// cell to which snake or ladder at i takes to.
int getMinDiceThrows(int move[], int N)
{
	// The graph has N vertices. Mark all the vertices as
	// not visited
	bool* visited = new bool[N];
	for (int i = 0; i < N; i++)
		visited[i] = false;

	// Create a queue for BFS
	queue<queueEntry> q;

	// Mark the node 0 as visited and enqueue it.
	visited[0] = true;
	queueEntry s
		= { 0, 0 }; // distance of 0't vertex is also 0
	q.push(s); // Enqueue 0'th vertex

	// Do a BFS starting from vertex at index 0
	queueEntry qe; // A queue entry (qe)
	while (!q.empty()) {
		qe = q.front();
		int v = qe.v; // vertex no. of queue entry

		// If front vertex is the destination vertex,
		// we are done
		if (v == N - 1)
			break;

		// Otherwise dequeue the front vertex and enqueue
		// its adjacent vertices (or cell numbers reachable
		// through a dice throw)
		q.pop();
		for (int j = v + 1; j <= (v + 6) && j < N; ++j) {
			// If this cell is already visited, then ignore
			if (!visited[j]) {
				// Otherwise calculate its distance and mark
				// it as visited
				queueEntry a;
				a.dist = (qe.dist + 1);
				visited[j] = true;

				// Check if there a snake or ladder at 'j'
				// then tail of snake or top of ladder
				// become the adjacent of 'i'
				if (move[j] != -1)
					a.v = move[j];
				else
					a.v = j;
				q.push(a);
			}
		}
	}

	// We reach here when 'qe' has last vertex
	// return the distance of vertex in 'qe'
	return qe.dist;
}

int main()
{
	// Let us construct the board given in above diagram
	int N = 30;
	int moves[N];
	for (int i = 0; i < N; i++)
		moves[i] = -1;

	// Ladders
	moves[2] = 21;
	moves[4] = 7;
	moves[10] = 25;
	moves[19] = 28;

	// Snakes
	moves[26] = 0;
	moves[20] = 8;
	moves[16] = 3;
	moves[18] = 6;

	cout << "Min Dice throws required is "
		<< getMinDiceThrows(moves, N);
	return 0;
}

/*
The structure queueEntry is defined to store a vertex number and its distance from the source.

The getMinDiceThrows function calculates the minimum number of dice throws required to reach the last cell from the first cell using a breadth-first search (BFS) approach. It takes the move array representing the snake and ladder positions and the size N of the board as input.

Inside the getMinDiceThrows function:

A boolean array visited is created to keep track of visited cells.
A queue of queueEntry type is created for BFS traversal.
The source vertex (cell 0) is marked as visited and enqueued with a distance of 0.
The BFS traversal starts:
The front vertex of the queue is dequeued.
For each adjacent vertex reachable by dice throws (up to a maximum of 6), if it's not visited:
If the vertex represents a snake or ladder destination, that destination is enqueued.
Otherwise, the vertex itself is enqueued.
The traversal continues until the destination cell (last cell) is reached.
The main function:

Defines the number of cells N and an array moves to represent the snake and ladder board. It initializes the array with -1 indicating no snake or ladder.
Sets the positions of ladders and snakes in the moves array.
Calls the getMinDiceThrows function with the moves array and prints the minimum number of dice throws required to reach the last cell.
The program returns 0 to indicate successful execution.

*/


