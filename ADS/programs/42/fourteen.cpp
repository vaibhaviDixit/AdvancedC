/*
Given N jobs where every job is represented by following three elements of it.

Start Time
Finish Time
Profit or Value Associated (>= 0)
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

Input: Number of Jobs n = 4
       Job Details {Start Time, Finish Time, Profit}
       Job 1:  {1, 2, 50}
       Job 2:  {3, 5, 20}
       Job 3:  {6, 19, 100}
       Job 4:  {2, 100, 200}
Output: The maximum profit is 250.

*/

// C++ program for weighted job scheduling using Dynamic Programming.
#include <algorithm>
#include <iostream>
using namespace std;

// A job has start time, finish time and profit.
struct Job {
	int start, finish, profit;
};

// A utility function that is used for sorting events according to finish time
bool jobComparator(Job s1, Job s2)
{
	return (s1.finish < s2.finish);
}

// Find the latest job (in sorted array) that doesn't conflict with the job[i]
int latestNonConflict(Job arr[], int i)
{
	for (int j = i - 1; j >= 0; j--) {
		if (arr[j].finish <= arr[i].start)
			return j;
	}
	return -1;
}

// The main function that returns the maximum possible profit from given array of jobs
int findMaxProfit(Job arr[], int n)
{
	// Sort jobs according to finish time
	sort(arr, arr + n, jobComparator);

	// Create an array to store solutions of subproblems. table[i] stores the profit for jobs till arr[i] (including arr[i])
	int* table = new int[n];
	table[0] = arr[0].profit;

	// Fill entries in M[] using recursive property
	for (int i = 1; i < n; i++) {
		// Find profit including the current job
		int inclProf = arr[i].profit;
		int l = latestNonConflict(arr, i);
		if (l != -1)
			inclProf += table[l];

		// Store maximum of including and excluding
		table[i] = max(inclProf, table[i - 1]);
	}

	// Store result and free dynamic memory allocated for table[]
	int result = table[n - 1];
	delete[] table;

	return result;
}

int main()
{
	Job arr[] = { { 3, 10, 20 },
				{ 1, 2, 50 },
				{ 6, 19, 100 },
				{ 2, 100, 200 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The optimal profit is "
		<< findMaxProfit(arr, n);
	return 0;
}

/*

Job Structure: The program defines a structure named Job to represent a job with its start time, finish time, and profit.

Function jobComparator: This function is used as a comparator to sort the jobs based on their finish times. It returns true if the finish time of the first job is less than the finish time of the second job, indicating that the first job should appear earlier.

Function latestNonConflict: Given an array of jobs and an index i, this function finds the latest job in the sorted array that doesn't conflict with the job at index i. It returns the index of the latest non-conflicting job.

Function findMaxProfit: This is the main function that calculates the maximum possible profit using dynamic programming.

It sorts the array of jobs based on finish times using the jobComparator.
It creates an array table to store the maximum profits for each job.
It initializes the profit for the first job (job 0).
For each subsequent job i, it calculates the maximum profit that can be obtained by either including the current job i (if it doesn't conflict with previous jobs) or excluding it.
The maximum profit is stored in the table array for each job.
The final result is the maximum profit for the last job.
Main Function:

The main function creates an array of jobs as input.
It calculates the maximum profit using the findMaxProfit function and prints the result.

*/

