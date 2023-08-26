/*
Given an array of size N and an integer K, return the count of distinct numbers in all windows of size K. Use hashing technique.

Input: arr[] = {1, 2, 1, 3, 4, 2, 3}, K = 4
Output: 3 4 4 3

*/

#include <iostream>
#include <unordered_map>
using namespace std;

void countDistinct(int arr[], int K, int N)
{
	// Creates an empty hashmap hm
	unordered_map<int, int> hm;

	// initialize distinct element count for current window
	int dist_count = 0;

	// Traverse the first window and store count of every element in hash map
	for (int i = 0; i < K; i++) {
		if (hm[arr[i]] == 0) {
			dist_count++;
		}

		hm[arr[i]] += 1;
	}

	// Print count of first window
	cout << dist_count << endl;

	// Traverse through the remaining array
	for (int i = K; i < N; i++) {
		// Remove first element of previous window If there was only one occurrence, then reduce distinct count.
		if (hm[arr[i - K]] == 1) {
			dist_count--;
		}
		// reduce count of the removed element
		hm[arr[i - K]] -= 1;

		// Add new element of current window If this element appears first time, increment distinct element count

		if (hm[arr[i]] == 0) {
			dist_count++;
		}
		hm[arr[i]] += 1;

		// Print count of current window
		cout << dist_count << endl;
	}
}

int main()
{
	int arr[] = {1, 2, 1, 3, 4, 2, 3};
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 4;

	// Function call
	countDistinct(arr, K, N);

	return 0;
}

/*
countDistinct() Function: This function takes three arguments - an integer array arr[], an integer K representing the size of subarrays,
and an integer N representing the total number of elements in the array.

Hash Map: The code uses an unordered_map<int, int> named hm to store the frequency of elements in the current subarray.

Initial Window: The code first processes the first window of size K. It counts the distinct elements in the window and stores their
frequencies in the hm map.

Printing Count: After processing the first window, the count of distinct elements in that window is printed.

Sliding Window: The code then uses a sliding window approach to process the remaining subarrays. For each new subarray, the code adjusts the
frequency of elements by removing the element that goes out of the window and adding the element that comes into the window.

Updating Distinct Count: The distinct element count is updated based on whether an element's frequency becomes zero (indicating that it's no
longer in the window) or becomes one (indicating that it's a new distinct element in the window).

Printing Count for Each Window: For each processed subarray, the code prints the count of distinct elements in that subarray.

*/



