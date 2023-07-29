/*
We are given an array consisting of n elements. At each operation you can select any one element and increase rest of n-1 elements by 1.
You have to make all elements equal performing such operation as many times you wish. Find the minimum number of operations needed for this.

Input: arr = {1,2,3}
Output: Minimum Operation = 3

*/


#include<bits/stdc++.h>
using namespace std;

// function for finding min operation
int minOp (int arr[], int n)
{
	// find array sum
	int sum = accumulate(arr,arr+n,0);
	// find the smallest element from array
	int small = *min_element(arr,arr+n);
	// calculate min operation required
	int minOperation = sum - (n * small);
	// return result
	return minOperation;
}

int main()
{
	int arr[] = {1,1,1,2};
	int n = sizeof(arr)/ sizeof(arr[0]);
	cout << "Minimum Operation = " << minOp (arr, n);
	return 0;
}

/*
This C++ program finds the minimum number of operations required to make all elements of a given array equal.
In one operation, you can increment or decrement any element by 1.

*/

