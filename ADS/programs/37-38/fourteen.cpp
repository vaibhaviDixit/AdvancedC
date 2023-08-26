/*
Given K sorted lists of integers of size N each, find the smallest range that includes at least one element from each of the K lists.
If more than one smallest range is found, print any one of them. Use hashing technique.

Input: K = 3
arr1[] : {4, 7, 9, 12, 15}
arr2[] : {0, 8, 10, 14, 20}
arr3[] : {6, 12, 16, 30, 50}

Output: The smallest range is [6 8]

*/

#include <bits/stdc++.h>
using namespace std;

// array for storing the current index of list i
int ptr[501];

// This function takes an k sorted lists in the form of
// 2D array as an argument. It finds out smallest range
// that includes elements from each of the k lists.
void findSmallestRange(vector<vector<int> >& arr, int N,
					int K)
{
	int i, minval, maxval, minrange, minel, maxel, flag,
		minind;

	// initializing to 0 index;
	for (i = 0; i <= K; i++)
		ptr[i] = 0;

	minrange = INT_MAX;

	while (1) {
		// for maintaining the index of list containing the minimum element
		minind = -1;
		minval = INT_MAX;
		maxval = INT_MIN;
		flag = 0;

		// iterating over all the list
		for (i = 0; i < K; i++) {
			// if every element of list[i] is traversed then break the loop
			if (ptr[i] == N) {
				flag = 1;
				break;
			}
			// find minimum value among all the list elements pointing by the ptr[] array
			if (ptr[i] < N && arr[i][ptr[i]] < minval) {
				minind = i; // update the index of the list
				minval = arr[i][ptr[i]];
			}
			// find maximum value among all the list elements pointing by the ptr[] array
			if (ptr[i] < N && arr[i][ptr[i]] > maxval) {
				maxval = arr[i][ptr[i]];
			}
		}

		// if any list exhaust we will not get any better
		// answer, so break the while loop
		if (flag)
			break;

		ptr[minind]++;

		// updating the minrange
		if ((maxval - minval) < minrange) {
			minel = minval;
			maxel = maxval;
			minrange = maxel - minel;
		}
	}

	printf("The smallest range is [%d, %d]\n", minel,
		maxel);
}


int main()
{
	vector<vector<int> > arr = { { 4, 7, 9, 12, 15 },
								{ 0, 8, 10, 14, 20 },
								{ 6, 12, 16, 30, 50 } };

	int K = arr.size();
	int N = arr[0].size();

	// Function call
	findSmallestRange(arr, N, K);

	return 0;
}

/*
Main Function (main()): The program starts by defining a 2D vector arr containing sorted lists. The number of lists K is determined by the size of the outer vector, and the length of each list N is determined by the size of the inner vector.

Smallest Range Function (findSmallestRange()): This function takes the 2D vector arr, the length of each list N, and the number of lists K as arguments.

Pointer Array (ptr): An integer array ptr of size 501 is defined to keep track of the current index of each list.

Initialization: The function initializes the ptr array to 0 for all lists and initializes variables like minrange, minel, and maxel to store the smallest range and its corresponding minimum and maximum values.

Main Loop: The main loop continues until at least one list exhausts (no more elements to compare).

Inner Loop: Within the main loop, an inner loop iterates over all the lists to find the minimum and maximum values among the current elements pointed to by the ptr array. The index of the list with the minimum value (minind) is also tracked.

Update Pointers: After finding the minimum value, the pointer for the corresponding list is incremented (ptr[minind]++).

Update Smallest Range: The difference between the maximum and minimum values is calculated (maxval - minval) and compared with the current smallest range (minrange). If it's smaller, the minrange, minel, and maxel values are updated.

Print Result: After the main loop, the program prints the smallest range found along with the minimum and maximum values that form this range.

*/

