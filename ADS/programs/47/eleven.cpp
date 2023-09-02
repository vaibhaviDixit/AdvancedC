/*
We are given N jobs, and their starting and ending times. We can do two jobs simultaneously at a particular moment. If one job ends at the same moment some
other show starts then we can’t do them. We need to check if it is possible to complete all the jobs or not.

Input :  Start and End times of Jobs
         1 2
         2 3
         4 5
Output : Yes


Input : Start and End times of Jobs
        1 5
        2 4
        2 6
        1 7
Output : No

*/


// CPP program to check if all jobs can be scheduled if two jobs are allowed at a time.
#include <bits/stdc++.h>
using namespace std;

bool checkJobs(int startin[], int endin[], int n)
{
	// making a pair of starting and ending time of job
	vector<pair<int, int> > a;
	for (int i = 0; i < n; i++)
		a.push_back(make_pair(startin[i], endin[i]));

	// sorting according to starting time of job
	sort(a.begin(), a.end());

	// starting first and second job simultaneously
	long long tv1 = a[0].second, tv2 = a[1].second;

	for (int i = 2; i < n; i++) {

		// Checking if starting time of next new job is greater than ending time of currently scheduled first job
		if (a[i].first >= tv1)
		{
			tv1 = tv2;
			tv2 = a[i].second;
		}

		// Checking if starting time of next new job is greater than ending time of currently scheduled second job
		else if (a[i].first >= tv2)
			tv2 = a[i].second;

		else
			return false;
	}
	return true;
}

int main()
{
	int startin[] = { 1, 2, 4 }; // starting time of jobs
	int endin[] = { 2, 3, 5 }; // ending times of jobs
	int n = sizeof(startin) / sizeof(startin[0]);
	cout << checkJobs(startin, endin, n);
	return 0;
}

/*
The checkJobs function takes three parameters:

startin: An array of integers representing the starting times of jobs.
endin: An array of integers representing the ending times of jobs.
n: An integer representing the total number of jobs.
Inside the checkJobs function:

A vector of pairs, a, is created to store pairs of starting and ending times of jobs. Each pair is created using make_pair and added to the vector a.
The vector a is sorted in non-decreasing order based on the starting times of jobs. This step is crucial to ensure that jobs are processed in ascending order of their starting times.

Two variables, tv1 and tv2, are initialized to represent the ending times of the first and second jobs, respectively. Initially, these variables store the ending times of the first two jobs since two jobs can be scheduled simultaneously.

A loop iterates through the remaining jobs (from the third job onward):

It checks if the starting time of the current job (a[i].first) is greater than or equal to tv1. If this condition is met, it means that the current job can be scheduled right after the first job, and tv1 is updated to the ending time of the second job (tv2). The variable tv2 is updated to the ending time of the current job (a[i].second).
If the condition is not met, it checks if the starting time of the current job is greater than or equal to tv2. In this case, it means that the current job can be scheduled right after the second job, and tv2 is updated to the ending time of the current job.
If neither of the above conditions is met, it implies that there is a conflict between jobs, and the function returns false.
If the loop completes without any conflicts, the function returns true, indicating that all jobs can be scheduled without conflicts.

In the main function:

Sample data is provided by initializing arrays startin and endin, which represent the starting and ending times of jobs.
The number of jobs n is determined based on the size of the startin array.
The checkJobs function is called with the job data, and the result (whether all jobs can be scheduled) is printed to the console.

*/
