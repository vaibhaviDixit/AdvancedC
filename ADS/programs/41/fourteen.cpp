/*
Given a distance ‘dist’, count total number of ways to cover the distance with 1, 2 and 3 steps.

Input: n = 3
Output: 4
Explanation:
Below are the four ways
 1 step + 1 step + 1 step
 1 step + 2 step
 2 step + 1 step
 3 step

Input: n = 4
Output: 7

*/

// A Dynamic Programming based C++ program to count number of ways to cover a distance with 1, 2 and 3 steps
#include<iostream>
using namespace std;

int printCountDP(int dist)
{
	int count[dist+1];

	// Initialize base values. There is one way to cover 0 and 1
	// distances and two ways to cover 2 distance
	count[0] = 1;
	if(dist >= 1)
			count[1] = 1;
	if(dist >= 2)
			count[2] = 2;

	// Fill the count array in bottom up manner
	for (int i=3; i<=dist; i++)
	count[i] = count[i-1] + count[i-2] + count[i-3];

	return count[dist];
}


int main()
{
	int dist = 4;
	cout << printCountDP(dist);
	return 0;
}

/*

The printCountDP function is defined to calculate the number of ways to cover a given distance 'dist' using 1, 2, and 3 steps. It uses dynamic programming to store and compute the counts.

Inside the printCountDP function:

An array count of size (dist + 1) is created to store the counts of ways for different distances.

Base values are initialized as follows:

There is one way to cover 0 distance (by not taking any steps).
There is one way to cover 1 distance (by taking one step).
There are two ways to cover 2 distance (by taking either two 1-step or one 2-step).
A loop runs from 3 to 'dist' to fill the count array using the bottom-up approach. The count for each distance is calculated based on the counts for the previous three distances.

*/
