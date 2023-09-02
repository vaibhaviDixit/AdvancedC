/*
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job
takes a single unit of time, so the minimum possible deadline for any job is 1. Maximize the total profit if only one job can be scheduled at a time.

Input: Four Jobs with following deadlines and profits
JobID  Deadline  Profit

  a           4          20
  b           1          10
  c           1          40
  d          1          30

Output: Following is maximum profit sequence of jobs: c, a

Input:  Five Jobs with following deadlines and profits
JobID   Deadline  Profit

  a            2          100
  b            1          19
  c            2          27
 d            1          25
 e            3          15

Output: Following is maximum profit sequence of jobs: c, a, e

*/


#include <algorithm>
#include <iostream>
using namespace std;

// A structure to represent a job
struct Job {

	char id; // Job Id
	int dead; // Deadline of job
	int profit; // Profit if job is over before or on
				// deadline
};

// Comparator function for sorting jobs
bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

// Returns maximum profit from jobs
void printJobScheduling(Job arr[], int n)
{
	// Sort all jobs according to decreasing order of profit
	sort(arr, arr + n, comparison);

	int result[n]; // To store result (Sequence of jobs)
	bool slot[n]; // To keep track of free time slots

	// Initialize all slots to be free
	for (int i = 0; i < n; i++)
		slot[i] = false;

	// Iterate through all given jobs
	for (int i = 0; i < n; i++) {
		// Find a free slot for this job (Note that we start
		// from the last possible slot)
		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
			// Free slot found
			if (slot[j] == false) {
				result[j] = i; // Add this job to result
				slot[j] = true; // Make this slot occupied
				break;
			}
		}
	}

	// Print the result
	for (int i = 0; i < n; i++)
		if (slot[i])
			cout << arr[result[i]].id << " ";
}

int main()
{
	Job arr[] = { { 'a', 2, 100 },
				{ 'b', 1, 19 },
				{ 'c', 2, 27 },
				{ 'd', 1, 25 },
				{ 'e', 3, 15 } };

	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobs "
			"\n";

	// Function call
	printJobScheduling(arr, n);
	return 0;
}

/*
A structure Job is defined to represent a job with the following attributes:

id: Job identifier.
dead: Deadline for the job.
profit: Profit earned if the job is completed on or before the deadline.
A comparator function comparison is defined to be used for sorting the jobs. It compares jobs based on their profits in descending order.

The printJobScheduling function is defined to find and print the maximum profit sequence of jobs. It takes the following arguments:

arr[]: An array of job structures.
n: The total number of jobs.
The first step inside the printJobScheduling function is to sort all the jobs in decreasing order of profit using the sort function and the comparison comparator.

Two arrays, result and slot, are created to keep track of the selected jobs and available time slots, respectively.

All slots in the slot array are initialized to be free (set to false).

The program iterates through all the given jobs, starting from the job with the highest profit.

For each job, it searches for a free time slot starting from the last possible slot (which is the deadline of the job minus one).

If a free slot is found for the current job, it is added to the result array, and the slot is marked as occupied (set to true).

The loop continues until all jobs have been considered.

Finally, the program prints the job sequence that maximizes the total profit.

In the main function, an example set of jobs with their deadlines and profits is provided in the arr[] array. The program is then called to find and print the maximum profit sequence of jobs.

*/
