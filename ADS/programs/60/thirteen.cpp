/*
Given a matrix of dimension M * N where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:

0: Empty cell
1: Cells have fresh oranges
2: Cells have rotten oranges
Determine what is the minimum time required so that all the oranges become rotten. A rotten orange at index (i,j ) can rot other fresh oranges which are
its neighbours (up, down, left and right). If it is impossible to rot every orange then simply return -1.

Input:  arr[][C] = { {2, 1, 0, 2, 1}, {1, 0, 1, 2, 1}, {1, 0, 0, 2, 1}}
Output: 2
Explanation: At 0th time frame:
{2, 1, 0, 2, 1}
{1, 0, 1, 2, 1}
{1, 0, 0, 2, 1}
At 1st time frame:
{2, 2, 0, 2, 2}
{2, 0, 2, 2, 2}
{1, 0, 0, 2, 2}
At 2nd time frame:
{2, 2, 0, 2, 2}
{2, 0, 2, 2, 2}
{2, 0, 0, 2, 2}

Input:  arr[][C] = { {2, 1, 0, 2, 1}, {0, 0, 1, 2, 1}, {1, 0, 0, 2, 1}}
Output: -1
Explanation: At 0th time frame:
{2, 1, 0, 2, 1}
{0, 0, 1, 2, 1}
{1, 0, 0, 2, 1}
At 1st time frame:
{2, 2, 0, 2, 2}
{0, 0, 2, 2, 2}
{1, 0, 0, 2, 2}
At 2nd time frame:
{2, 2, 0, 2, 2}
{0, 0, 2, 2, 2}
{1, 0, 0, 2, 2}

*/

#include <bits/stdc++.h>
#define R 3
#define C 5
using namespace std;

// This function finds if it is possible to rot all oranges or not. If possible, then it returns minimum time required to rot all, otherwise returns -1
int rotOranges(vector<vector<int> >& grid)
{
	int n = grid.size(); // row size
	int m = grid[0].size(); // column size

	// delrow and delcol are used to traverse in
	// up,right,bottom and left respectively.

	int delrow[] = { -1, 0, 1, 0 };
	int delcol[] = { 0, 1, 0, -1 };

	// visited matrix to keep track of the visited cell.
	int vis[n][m];

	// queue stores rowIndex,colIndex and time taken to rot
	// respectively.

	queue<pair<pair<int, int>, int> > q;

	// counter to keep track of fresh cells.
	int cntfresh = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 2) {
				q.push({ { i, j },
						0 }); // already rotten hence 0
							// time to rot.
				vis[i][j]
					= 2; // visited cell marked as rotten.
			}
			else {
				vis[i][j] = 0; // unvisited
			}
			if (grid[i][j] == 1)
				cntfresh++; // maintaining count for fresh
							// oranges.
		}
	}
	int cnt = 0, tm = 0;
	while (!q.empty()) {
		int row = q.front().first.first; // row index
		int col = q.front().first.second; // col index
		int t = q.front().second; // time an orange at a
								// cell takes to rot.
		q.pop();

		tm = max(tm, t);

		// checking for adjacent nodes in 4 directions.
		for (int i = 0; i < 4; i++) {
			int nrow = row + delrow[i];
			int ncol = col + delcol[i];

			// checking the validity of a node and also
			// vis[nrow][ncol] !=2
			if (nrow >= 0 && nrow < n && ncol >= 0
				&& ncol < m && grid[nrow][ncol] == 1
				&& vis[nrow][ncol] != 2) {
				vis[nrow][ncol] = 2; // adj orange is rotten
				q.push({ { nrow, ncol },
						t + 1 }); // incrementing time for
								// that orange by 1
				cnt++;
			}
		}
	}

	return (cnt == cntfresh) ? tm : -1;
}

int main()
{
	vector<vector<int> > arr
		= { { 1, 1, 2 }, { 1, 1, 2 }, { 2, 1, 1 } };
	int ans = rotOranges(arr);
	if (ans == -1)
		cout << "All oranges cannot rotn";
	else
		cout << "Time required for all oranges to rot => "
			<< ans << endl;
	return 0;
}

/*
The function rotOranges takes a 2D vector grid as input, where each cell represents an orange's status. The function returns the minimum time required to rot all fresh oranges or -1 if it's not possible.

Inside the rotOranges function:

It initializes variables and arrays to keep track of cells and their statuses.
The program iterates through the grid to initialize visited statuses and count fresh oranges.
A queue is used for BFS traversal to spread the rotting effect. Initially, all rotten oranges are enqueued with time 0.
The BFS traversal is done while the queue is not empty:
The program dequeues an orange, updates the maximum time, and checks its adjacent cells for possible rotting.
If an adjacent cell is fresh and not already visited, it's marked as rotten and enqueued with an incremented time.
A count is maintained to track the number of fresh oranges that become rotten.
After BFS, if the count of rotten oranges matches the count of fresh oranges, the function returns the maximum time. Otherwise, it returns -1.
The main function:

Initializes a 2D vector arr representing the grid.
Calls the rotOranges function and prints the result, either the time required for all oranges to rot or a message indicating that not all oranges can rot.

*/






