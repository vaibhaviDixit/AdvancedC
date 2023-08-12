/*
You have given an array of distinct elements and a range [low, high], find all numbers that are in a range,
but not present array. Print missing elements in sorted order. Use hashing to achieve same.

Input: arr[] = {10, 12, 11, 15},
       low = 10, high = 15
Output: 13, 14

*/


#include <bits/stdc++.h>
using namespace std;

// Function to find and print missing elements in the given range
void findMissing(int arr[], int n, int low, int high) {
	// Loop through the range of numbers from low to high
	for (int i = low; i <= high; i++) {
		bool found = false;

		// Loop through the array to check if i exists in it
		for (int j = 0; j < n; j++) {
			if (arr[j] == i) {
				found = true;
				break;
			}
		}

		// If i is not found in the array, print it
		if (!found) {
			cout << i << " ";
		}
	}
}

int main() {
	// Input array
	int arr[] = { 1, 3, 5, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int low = 1, high = 10;

	// Function call
	findMissing(arr, n, low, high);
	return 0;
}


/*
This program finds and prints the missing elements in a given range [low, high] within an array of integers.

In the provided code:

The findMissing function takes four parameters: the array of integers arr, the size n of the array, and the lower and upper bounds of the range, low and high.

The function iterates through each number within the specified range using a loop. For each number i in the range, it checks if i exists in the given array arr. To do this, it loops through the array and uses a boolean variable found to keep track of whether i is found in the array.

If i is not found in the array, the program prints the missing number i.

The main function initializes an input array arr with values {1, 3, 5, 4}. It also specifies the lower bound low as 1 and the upper bound high as 10. These bounds define the range of numbers to check for missing elements.

The findMissing function is called with the array, its size, and the specified range. It then prints the missing elements within that range.

*/


