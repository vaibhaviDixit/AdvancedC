/*
Given an array of size n that has the following specifications:

Each element in the array contains either a policeman or a thief.
Each policeman can catch only one thief.
A policeman cannot catch a thief who is more than K units away from the policeman.
We need to find the maximum number of thieves that can be caught.

Input : arr[] = {'P', 'T', 'T', 'P', 'T'},
            k = 1.
Output : 2

--Here maximum 2 thieves can be caught, first policeman catches first thief and second police-
man can catch either second or third thief.

Input : arr[] = {'T', 'T', 'P', 'P', 'T', 'P'},
            k = 2.
Output : 3.

*/


// C++ program to find maximum number of thieves caught
#include <bits/stdc++.h>
using namespace std;

// Returns maximum number of thieves that can be caught.
int policeThief(char arr[], int n, int k)
{
	int res = 0;
	vector<int> thi;
	vector<int> pol;

	// store indices in the vector
	for (int i = 0; i < n; i++) {
		if (arr[i] == 'P')
			pol.push_back(i);
		else if (arr[i] == 'T')
			thi.push_back(i);
	}

	// track lowest current indices of
	// thief: thi[l], police: pol[r]
	int l = 0, r = 0;
	while (l < thi.size() && r < pol.size()) {
		// can be caught
		if (abs(thi[l] - pol[r]) <= k) {
			l++;
			r++;
			res++;
		}
		// increment the minimum index
		else if (thi[l] < pol[r]) {
			l++;
		}
		else {
			r++;
		}
	}
	return res;
}

int main()
{
	int k, n;
	char arr1[] = { 'P', 'T', 'T', 'P', 'T' };
	k = 2;
	n = sizeof(arr1) / sizeof(arr1[0]);
	cout << "Maximum thieves caught: "
		<< policeThief(arr1, n, k) << endl;

	char arr2[] = { 'T', 'T', 'P', 'P', 'T', 'P' };
	k = 2;
	n = sizeof(arr2) / sizeof(arr2[0]);
	cout << "Maximum thieves caught: "
		<< policeThief(arr2, n, k) << endl;

	char arr3[] = { 'P', 'T', 'P', 'T', 'T', 'P' };
	k = 3;
	n = sizeof(arr3) / sizeof(arr3[0]);
	cout << "Maximum thieves caught: "
		<< policeThief(arr3, n, k) << endl;
	return 0;
}

/*
The policeThief function takes three parameters:

arr: A character array representing the positions of police ('P') and thieves ('T') on a track.
n: The total number of elements in the array.
k: An integer representing the maximum distance within which a police officer can catch a thief.
Inside the policeThief function:

Two vectors, thi (thieves) and pol (police), are declared to store the indices (positions) of thieves and police officers, respectively.
A loop iterates through the elements of the input array (arr) and populates the thi and pol vectors with the corresponding indices of thieves and police officers.
Two pointers, l (for thieves) and r (for police), are used to iterate through the thi and pol vectors, respectively.

The goal is to match a thief and a police officer such that the absolute difference of their indices is less than or equal to k, indicating that the thief can be caught by the police officer within the given range.
Inside the loop, the following conditions are checked:

If the absolute difference between the current thief's index (thi[l]) and the current police officer's index (pol[r]) is less than or equal to k, it means the police officer can catch the thief. In this case, both pointers l and r are incremented, and the res (result) counter is incremented to indicate a caught thief.
If the thief's index is less than the police officer's index, it means the thief is to the left of the police officer. In this case, l is incremented to consider the next thief.
If the thief's index is greater than the police officer's index, it means the thief is to the right of the police officer. In this case, r is incremented to consider the next police officer.
After processing all elements of the vectors, the res counter stores the maximum number of thieves that can be caught.

In the main function:

Sample data is provided by initializing character arrays arr1, arr2, and arr3, representing the positions of police and thieves.
The value of k (maximum catching distance) is set for each test case.
The policeThief function is called for each test case to calculate and print the maximum number of thieves caught.

*/

