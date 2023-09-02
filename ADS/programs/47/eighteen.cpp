/*
Given the arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms required for the railway station so that no train waits. We are given two arrays that represent the arrival and departure times of trains that stop.

Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}, dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
Output: 3
Explanation: There are at-most three trains at a time (time between 9:40 to 12:00)

Input: arr[] = {9:00, 9:40}, dep[] = {9:10, 12:00}
Output: 1

*/

// C++ program to implement the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of platforms required
int findPlatformOptimized(int arr[], int dep[], int n)
{
	int count = 0, maxPlatforms = 0;
	// Find the maximum departure time
	int maxDepartureTime = dep[0];
	for (int i = 1; i < n; i++) {
		maxDepartureTime = max(maxDepartureTime, dep[i]);
	}

	// Create a vector to store the count of trains at each time
	vector<int> v(maxDepartureTime + 2, 0);

	// Increment the count at the arrival time and decrement at the departure time
	for (int i = 0; i < n; i++) {
		v[arr[i]]++;
		v[dep[i] + 1]--;
	}

	// Iterate over the vector and keep track of the maximum sum seen so far
	for (int i = 0; i <= maxDepartureTime + 1; i++) {
		count += v[i];
		maxPlatforms = max(maxPlatforms, count);
	}

	return maxPlatforms;
}

int main()
{
	int arr[] = { 100, 300, 600 };
	int dep[] = { 900, 400, 500 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findPlatformOptimized(arr, dep, n);
	return 0;
}

/*
The program defines the findPlatformOptimized function, which calculates the minimum number of platforms required. It takes the following parameters:

arr[]: An array representing the arrival times of trains.
dep[]: An array representing the departure times of trains.
n: The number of trains.
Inside the function:

An integer variable count is initialized to 0, which represents the current count of trains at the station.
An integer variable maxPlatforms is initialized to 0, which will store the maximum number of platforms required.
The maximum departure time, maxDepartureTime, is found by iterating through the dep[] array and keeping track of the maximum value.
A vector v of integers is created with a size of maxDepartureTime + 2, initialized to all 0s. This vector will be used to store the count of trains at each time.

A loop iterates over the trains (arrival and departure times) and increments the count at the arrival time and decrements it at the departure time in the v vector.

Another loop iterates over the v vector, simulating the movement of trains in and out of the station. It calculates the cumulative count of trains at each time and keeps track of the maximum count, which represents the maximum number of platforms required simultaneously.

The function returns maxPlatforms, which is the minimum number of platforms required to accommodate all trains without schedule conflicts.

In the main function:

Two arrays, arr[] (arrival times) and dep[] (departure times), are defined to represent the schedule of trains.
The number of trains n is calculated using sizeof(arr) / sizeof(arr[0]).
The findPlatformOptimized function is called with the arr[], dep[], and n as arguments.
The program prints the result to the console, which represents the minimum number of platforms required at the railway station to avoid schedule conflicts.

*/

