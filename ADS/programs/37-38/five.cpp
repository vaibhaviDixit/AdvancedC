/*
Given an array of n non-negative integers and a series of queries, each defined by a range within the array,
the task is to determine the frequency of a specific element within each specified range. The provided ranges are given
in terms of positions (not 0-based indexes) within the array. The goal is to process multiple queries of this type and
calculate the frequency of the specified element in each range.

Input  : arr[] = {2, 8, 6, 9, 8, 6, 8, 2, 11};
         left = 2, right = 8, element = 8
         left = 2, right = 5, element = 6
Output : 3
         1

*/


#include<bits/stdc++.h>
using namespace std;

unordered_map< int, vector<int> > store;

// Returns frequency of element in arr[left-1..right-1]
int findFrequency(int arr[], int n, int left,
					int right, int element)
{
	// Find the position of first occurrence of element
	int a = lower_bound(store[element].begin(),
						store[element].end(),
						left)
			- store[element].begin();

	// Find the position of last occurrence of element
	int b = upper_bound(store[element].begin(),
						store[element].end(),
						right)
			- store[element].begin();

	return b-a;
}


int main()
{
	int arr[] = {2, 8, 6, 9, 8, 6, 8, 2, 11};
	int n = sizeof(arr) / sizeof(arr[0]);

	// Storing the indexes of an element in the map
	for (int i=0; i<n; ++i)
		store[arr[i]].push_back(i+1); //starting index from 1

	// Print frequency of 2 from position 1 to 6
	cout << "Frequency of 2 from 1 to 6 = "
		<< findFrequency(arr, n, 1, 6, 2) <<endl;

	// Print frequency of 8 from position 4 to 9
	cout << "Frequency of 8 from 4 to 9 = "
		<< findFrequency(arr, n, 4, 9, 8);

	return 0;
}

/*
This C++ program deals with finding the frequency of a particular element within specified ranges of an array. It utilizes an unordered map to efficiently store the indexes of each element encountered in the array. The findFrequency function calculates the frequency of the element within a given range using lower and upper bounds on the indexes stored in the map. The main function demonstrates how to use this approach by calculating and printing the frequencies of specific elements in specified ranges.

The program starts by defining an unordered map named store that maps integers to vectors of integers. This map is used to store the indexes of elements in the original array.

The findFrequency function takes the array arr, its size n, the left and right bounds of the range, and the element for which the frequency is to be calculated. Inside this function, it calculates the position of the first occurrence and the position after the last occurrence of the element within the specified range. The difference between these positions gives the frequency of the element in that range.

In the main function, the array arr is defined, and its size n is calculated. The indexes of each element are stored in the store map. The frequencies of two specific elements within certain ranges are calculated using the findFrequency function and printed to the console.

*/

