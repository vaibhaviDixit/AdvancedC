/*
Consider the given array arr[], we need to find if we can sort array with the given operation. The operation is

We have to select a subarray from the given array such that the middle element(or elements (in case of even
number of elements)) of subarray is also the middle element(or elements (in case of even number of elements)) of
the given array.
Then we have to reverse the selected subarray and place this reversed subarray in the array.
We can do the above operation as many times as we want. The task is to find if we can sort array with the given operation.

Input : arr[] = {1, 6, 3, 4, 5, 2, 7}
Output : Yes

Input : arr[] = {1, 6, 3, 4, 5, 7, 2}
Output : No

*/

// CPP program to find possibility to sort by multiple subarray reverse operation
#include <bits/stdc++.h>
using namespace std;

bool ifPossible(int arr[], int n)
{
	int cp[n];

	// making the copy of the original array
	copy(arr, arr + n, cp);

	// sorting the copied array
	sort(cp, cp + n);

	for (int i = 0; i < n; i++) {

		// checking mirror image of elements of sorted
		// copy array and equivalent element of original array
		if (!(arr[i] == cp[i]) && !(arr[n - 1 - i] == cp[i]))
			return false;
	}

	return true;
}


int main()
{
	int arr[] = { 1, 7, 6, 4, 5, 3, 2, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	if (ifPossible(arr, n))
	cout << "Yes";
	else
	cout << "No";

	return 0;
}

/*
The ifPossible function takes two parameters:

arr: An array of integers representing the input array.
n: An integer representing the size of the input array.
Inside the ifPossible function:

A copy of the original array arr is created, named cp. This copy is used for comparison and sorting while preserving the original array.
The copy function from the C++ Standard Library is used to duplicate the content of the arr array into the cp array.
The sort function is then applied to the cp array, sorting it in ascending order.
The program then enters a loop that iterates from 0 to n-1, where n is the size of the array.

In each iteration, it checks whether the current element in the original arr array is equal to either:
The corresponding element in the sorted cp array (arr[i] == cp[i]).
The mirror image element in the sorted cp array (arr[n-1-i] == cp[i]).
If the condition is not satisfied for any element, it returns false, indicating that it's not possible to sort the array using multiple subarray reverse operations.
If the loop completes without returning false, it means that all elements in the original array arr can be transformed into a sorted order using multiple subarray reverse operations. In this case, the function returns true.

In the main function:

An array arr of integers is defined, containing a sequence of numbers in arbitrary order.
The size of the array, n, is calculated as the total number of elements in the array (sizeof(arr) / sizeof(arr[0])).
The ifPossible function is called with the array arr and its size n. If the function returns true, it prints "Yes" to the console, indicating that it's possible to sort the array using subarray reverse operations. Otherwise, it prints "No."

*/


