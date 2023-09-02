/*
We are given n-platform and two main running railway track for both direction. Trains which needs to stop at your station must occupy one platform for their stoppage and the trains which need not to stop at your station will run away through either of main track without stopping. Now, each train has three value first arrival time, second departure time and third required platform number. We are given m such trains you have to tell maximum number of train for which you can provide stoppage at your station.

Input : n = 3, m = 6
Train no.|  Arrival Time |Dept. Time | Platform No.
    1    |   10:00       |  10:30    |    1
    2    |   10:10       |  10:30    |    1
    3    |   10:00       |  10:20    |    2
    4    |   10:30       |  12:30    |    2
    5    |   12:00       |  12:30    |    3
    6    |   09:00       |  10:05    |    1
Output : Maximum Stopped Trains = 5


*/


// CPP to design platform for maximum stoppage
#include <bits/stdc++.h>
using namespace std;

// number of platforms and trains
#define n 2
#define m 5

// function to calculate maximum trains stoppage
int maxStop(int arr[][3])
{
	// declaring vector of pairs for platform
	vector<pair<int, int> > vect[n + 1];

	// Entering values in vector of pairs as per platform number
	// make departure time first element of pair
	for (int i = 0; i < m; i++)
		vect[arr[i][2]].push_back(
			make_pair(arr[i][1], arr[i][0]));

	// sort trains for each platform as per dept. time
	for (int i = 0; i <= n; i++)
		sort(vect[i].begin(), vect[i].end());

	// perform activity selection approach
	int count = 0;
	for (int i = 0; i <= n; i++) {
		if (vect[i].size() == 0)
			continue;

		// first train for each platform will also be selected
		int x = 0;
		count++;
		for (int j = 1; j < vect[i].size(); j++) {
			if (vect[i][j].second >=
							vect[i][x].first) {
				x = j;
				count++;
			}
		}
	}
	return count;
}

int main()
{
	int arr[m][3] = { 1000, 1030, 1,
					1010, 1020, 1,
					1025, 1040, 1,
					1130, 1145, 2,
					1130, 1140, 2 };
	cout << "Maximum Stopped Trains = "
		<< maxStop(arr);
	return 0;
}

/*
The program defines constants n and m, representing the number of platforms (n) and the number of trains (m).

The maxStop function calculates the maximum number of trains that can stop at different platforms. It takes a 2D array arr as input, where each row represents a train with three values: arrival time, departure time, and the platform number it belongs to.

Inside the maxStop function:

A vector of pairs (vect[n + 1]) is declared, where each index represents a platform, and the pairs store the departure time and arrival time of the trains for that platform.
The program populates the vector of pairs based on the input data, making the departure time the first element of each pair.
For each platform (indexed from 0 to n), the trains are sorted based on their departure times.
The program implements the activity selection approach to determine the maximum number of trains that can stop. It iterates through the platforms and selects the first train. Then, it compares the departure times of subsequent trains and selects the next train if it doesn't conflict with the previous one.
The count of selected trains is maintained and returned as the result.
In the main function, a sample arr array is provided with arrival times, departure times, and platform numbers for five trains. The maxStop function is called with this data, and the program prints the maximum number of trains that can stop at different platforms.

*/
