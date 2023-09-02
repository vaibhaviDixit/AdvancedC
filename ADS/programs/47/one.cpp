/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person,
assuming that a person can only work on a single activity at a time.

Input: start[]  =  {10, 12, 20}, finish[] =  {20, 25, 30}
Output: 0 2
Explanation: A person can perform at most two activities. The maximum set of activities that can be executed is {0, 2} [ These are indexes in start[] and finish[] ]

Input: start[]  =  {1, 3, 0, 5, 8, 5}, finish[] =  {2, 4, 6, 7, 9, 9};
Output: 0 1 3 4

*/


// The following implementation assumes that the activities are already sorted according to their finish time
#include <bits/stdc++.h>
using namespace std;

// Prints a maximum set of activities that can be done by a
// single person, one at a time.
void printMaxActivities(int s[], int f[], int n)
{
	int i, j;

	cout << "Following activities are selected" << endl;

	// The first activity always gets selected
	i = 0;
	cout << i << " ";

	// Consider rest of the activities
	for (j = 1; j < n; j++) {
		// If this activity has start time greater than or equal to the finish time of previously selected activity, then select it
		if (s[j] >= f[i]) {
			cout << j << " ";
			i = j;
		}
	}
}

int main()
{
	int s[] = { 1, 3, 0, 5, 8, 5 };
	int f[] = { 2, 4, 6, 7, 9, 9 };
	int n = sizeof(s) / sizeof(s[0]);

	// Function call
	printMaxActivities(s, f, n);
	return 0;
}

/*
The printMaxActivities function is defined to find and print the maximum set of activities that can be done by a single person, one at a time. It takes the following arguments:

s[]: An array representing the start times of activities.
f[]: An array representing the finish times of activities.
n: The total number of activities.
The program starts by selecting the first activity (activity 0) since it's assumed to have the earliest finish time. The variable i is set to 0.

The program then iterates through the remaining activities, starting from index 1 (j = 1).

For each activity j, it checks whether the start time of activity j is greater than or equal to the finish time of the previously selected activity (activity i). If this condition is met, it means that activity j can be performed without overlapping with the previous activity.

If the condition is satisfied, the program selects activity j, prints its index, and updates i to j. This means that activity j is now considered as the previously selected activity for the next iteration.

The loop continues until all activities have been considered.

The program prints the indices of the selected activities, which represent the maximum set of non-overlapping activities that can be performed.

In the main function, an example set of activities with their start and finish times is provided in arrays s[] and f[]. The program is then called to find and print the maximum set of activities that can be performed.

*/


