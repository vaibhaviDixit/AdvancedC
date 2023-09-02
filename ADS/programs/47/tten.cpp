/*
Given two arrays a[] and b[] of equal length n. The task is to pair each element of array a to an element in array b, such that sum S of absolute differences of all the pairs is minimum.
Suppose, two elements a[i] and a[j] (i != j) of a are paired with elements b[p] and b[q] of b respectively,
then p should not be equal to q.

Input :  a[] = {3, 2, 1}
         b[] = {2, 1, 3}
Output : 0

Input :  n = 4
         a[] = {4, 1, 8, 7}
         b[] = {2, 3, 6, 5}
Output : 6

*/

// C++ program to find minimum sum of absolute  differences of two arrays.
#include <bits/stdc++.h>
using namespace std;

// Returns minimum possible pairwise absolute difference of two arrays.
long long int findMinSum(long long int a[],long long int b[], int n)
{
	// Sort both arrays
	sort(a, a+n);
	sort(b, b+n);

	// Find sum of absolute differences
	long long int sum= 0 ;
	for (int i=0; i<n; i++)
		sum = sum + abs(a[i]-b[i]);

	return sum;
}


int main()
{
	// Both a[] and b[] must be of same size.
	long long int a[] = {4, 1, 8, 7};
	long long int b[] = {2, 3, 6, 5};
	int n = sizeof(a)/sizeof(a[0]);
	printf("%lld\n", findMinSum(a, b, n));
	return 0;
}

/*
The findMinSum function takes three parameters:

a: An array of long long integers representing the first array.
b: An array of long long integers representing the second array.
n: An integer representing the size of both arrays (assumed to be of the same size).
Inside the findMinSum function:

Both input arrays a and b are sorted in non-decreasing order using the std::sort function from the C++ Standard Template Library (STL).
A variable sum is initialized to 0. This variable will store the minimum possible sum of absolute differences between the corresponding elements of the sorted arrays.
A loop runs from 0 to n-1, iterating through each element of the arrays.
In each iteration, the absolute difference between the i-th elements of the sorted arrays a and b is calculated using abs(a[i] - b[i]). This absolute difference represents the contribution of the current pair of elements to the total sum of absolute differences.
The calculated absolute difference is added to the sum variable.
In the main function:

Two arrays a and b of long long integers are defined, each containing four elements.
The size of the arrays, n, is calculated as the total number of elements in either array (sizeof(a)/sizeof(a[0])).
The findMinSum function is called with arrays a and b along with the size n. The result (minimum sum of absolute differences) is printed to the console using printf.

*/
