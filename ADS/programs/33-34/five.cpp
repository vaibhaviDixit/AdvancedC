/*
Given an array of N element. The task is to check if it is Inorder traversal of any Binary Search Tree or not.
Print “Yes” if it is Inorder traversal of any Binary Search Tree else print “No”.

Input : arr[] = { 19, 23, 25, 30, 45 }
Output : Yes

Input : arr[] = { 19, 23, 30, 25, 45 }
Output : No

*/

#include<bits/stdc++.h>
using namespace std;

// Function that returns true if array is Inorder
// traversal of any Binary Search Tree or not.
bool isInorder(int arr[], int n)
{
	// Array has one or no element
	if (n == 0 || n == 1)
		return true;

	for (int i = 1; i < n; i++)

		// Unsorted pair found
		if (arr[i-1] > arr[i])
			return false;

	// No unsorted pair found
	return true;
}

int main()
{
	int arr[] = { 19, 23, 25, 30, 45 };
	int n = sizeof(arr)/sizeof(arr[0]);

	if (isInorder(arr, n))
		cout << "Yes";
	else
		cout << "No";

return 0;
}

/*
The isInorder function takes an array arr and its size n as parameters. It checks whether the given array could be the result of an in-order traversal of a Binary Search Tree (BST).

Inside the isInorder function:

It first handles the base cases where the array has either 0 or 1 elements. Since an array of 0 or 1 element is always considered sorted, the function returns true in these cases.
It uses a loop to iterate through the array from index 1 to n - 1.
It checks if there's any element that is smaller than its preceding element (an unsorted pair). If such a pair is found, the function immediately returns false to indicate that the array is not sorted.
If the loop completes without finding any unsorted pairs, it returns true, indicating that the array is sorted.

*/


