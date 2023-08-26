/*
Given an array arr[] of length N, find the length of the longest sub-array with a sum equal to 0 using hashing.

Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23}
Output: 5

Input: arr[] = {1, 2, 3}
Output: 0

*/

#include <bits/stdc++.h>
using namespace std;

// Returns Length of the required subarray
int maxLen(int arr[], int N)
{
	// Map to store the previous sums
	unordered_map<int, int> presum;

	int sum = 0; // Initialize the sum of elements
	int max_len = 0; // Initialize result

	// Traverse through the given array
	for (int i = 0; i < N; i++) {

		// Add current element to sum
		sum += arr[i];
		if (sum == 0)
			max_len = i + 1;

		// Look for this sum in Hash table
		if (presum.find(sum) != presum.end()) {

			// If this sum is seen before, then update
			// max_len
			max_len = max(max_len, i - presum[sum]);
		}
		else {
			// Else insert this sum with index
			// in hash table
			presum[sum] = i;
		}
	}

	return max_len;
}

int main()
{
	int arr[] = { 15, -2, 2, -8, 1, 7, 10, 23 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "Length of the longest 0 sum subarray is "
		<< maxLen(arr, N);

	return 0;
}

/*
Main Function (main()): The program starts by defining an array arr containing integers. The size of the array is determined by dividing the total size of arr by the size of a single element arr[0]. This is stored in the variable N.

Max Length Function (maxLen()): This function takes the array arr and its length N as arguments and returns the length of the longest subarray with a sum of zero.

Prefix Sum and Hashing: The function initializes an unordered map called presum to store cumulative sums and their corresponding indices.

Variables Initialization: The function initializes variables such as sum (to keep track of the cumulative sum) and max_len (to store the length of the longest subarray with a sum of zero).

Traverse Through the Array: The function traverses through the given array using a loop.

Updating Cumulative Sum: For each element in the array, the cumulative sum sum is updated by adding the current element.

Check for Zero Sum Subarray: If the cumulative sum sum becomes zero, it indicates that the subarray from the beginning to the current index forms a subarray with a sum of zero. In this case, max_len is updated to include this subarray.

Check for Hash Table: If the cumulative sum sum is found in the hash table presum, it suggests that there is a subarray between the indices stored in the hash table and the current index with a sum of zero. The length of this subarray is calculated, and if it's greater than the current max_len, max_len is updated.

Updating Hash Table: If the cumulative sum sum is not found in the hash table, it is added to the hash table with its index as the value.

Return Result: After traversing the entire array, the function returns the value of max_len, which represents the length of the longest subarray with a sum of zero.

*/



