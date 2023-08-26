/*
Given an array, find the next greater element for each element. If there is no greater element, output -1 for that element.

Input: [4, 5, 2, 10]
Output: [5, 10, 10, -1]

*/

#include <iostream>
using namespace std;

/* prints element and NGE pair
for all elements of arr[] of size n */
void printNGE(int arr[], int n)
{
	int next, i, j;
	for (i = 0; i < n; i++) {
		next = -1;
		for (j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				next = arr[j];
				break;
			}
		}
		cout << next << " ";
	}
}

int main()
{
	int arr[] = {9,12,6,61,91};
	int n = sizeof(arr) / sizeof(arr[0]);
	printNGE(arr, n);
	return 0;
}

/*
The program defines a function printNGE that iterates through the array and, for each element, finds its NGE by searching for the first
greater element on its right side. The driver code in the main function initializes an array and then calls the printNGE function to display
the NGE pairs.
*/
