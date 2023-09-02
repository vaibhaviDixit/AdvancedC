/*
Given array a, we have to find the minimum product possible with the subset of elements present in the array. The minimum product can be a single element
also.

Input : a[] = { -1, -1, -2, 4, 3 }
Output : -24
Explanation : Minimum product will be ( -2 * -1 * -1 * 4 * 3 ) = -24

Input : a[] = { -1, 0 }
Output : -1
Explanation : -1(single element) is minimum product possible

Input : a[] = { 0, 0, 0 }
Output : 0

*/


// CPP program to find maximum product of a subset.
#include <bits/stdc++.h>
using namespace std;

int minProductSubset(int a[], int n)
{
	if (n == 1)
		return a[0];
	// Find count of negative numbers, count of zeros, maximum valued negative number, minimum valued
	// positive number and product of non-zero numbers
	int max_neg = INT_MIN, min_pos = INT_MAX, count_neg = 0,
		count_zero = 0, prod = 1;
	for (int i = 0; i < n; i++) {
		// If number is 0, we don't multiply it with
		// product.
		if (a[i] == 0) {
			count_zero++;
			continue;
		}
		// Count negatives and keep track of maximum valued
		// negative.
		if (a[i] < 0) {
			count_neg++;
			max_neg = max(max_neg, a[i]);
		}
		// Track minimum positive number of array
		if (a[i] > 0)
			min_pos = min(min_pos, a[i]);
		prod = prod * a[i];
	}
	// If there are all zeros or no negative number present
	if (count_zero == n || (count_neg == 0 && count_zero > 0))
		return 0;
	// If there are all positive
	if (count_neg == 0)
		return min_pos;

	// If there are even number of negative numbers and count_neg not 0
	if (!(count_neg & 1) && count_neg != 0)
		// Otherwise result is product of all non-zeros divided by maximum valued negative.
		prod = prod / max_neg;
	return prod;
}

int main()
{
	int a[] = { -1, -1, -2, 4, 3 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << minProductSubset(a, n);
	return 0;
}

/*
The minProductSubset function takes two parameters:

a: An array of integers representing the input array.
n: An integer representing the size of the input array.
Inside the minProductSubset function:

Special cases are handled first:
If the size of the array n is 1, the function returns the only element of the array as the result.
The function counts the number of negative numbers (count_neg) and zeros (count_zero) in the array and initializes variables to keep track of the maximum valued negative number (max_neg), minimum valued positive number (min_pos), and the product of non-zero numbers (prod) which is initially set to 1.
A loop iterates through each element of the input array.
For each element:
If the element is 0, it increments the count_zero counter and is skipped for further processing.
If the element is negative, it increments the count_neg counter and updates the max_neg variable with the maximum negative number encountered so far.
If the element is positive, it updates the min_pos variable with the minimum positive number encountered so far.
The product of all non-zero numbers (prod) is calculated.
After processing all elements, the function checks for special cases:
If all elements are zeros or there are no negative numbers but at least one zero in the array, the function returns 0 (since the product will be zero).
If there are no negative numbers, the function returns the minimum positive number (min_pos).
If there are an even number of negative numbers, it divides the product of all non-zero numbers by the maximum valued negative number (max_neg).
In the main function:

An array a of integers is defined, containing a sequence of numbers, including negative, positive, and zero values.
The size of the array, n, is calculated as the total number of elements in the array (sizeof(a) / sizeof(a[0])).
The minProductSubset function is called with the array a and its size n. The result (minimum product of a subset) is printed to the console using cout.

*/
