/*
Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not. Both arrays are not in sorted order.
It may be assumed that elements in both arrays are distinct. Use hashing technique.

Input: arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1}
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {1, 2, 3, 4, 5, 6}, arr2[] = {1, 2, 4}
Output: arr2[] is a subset of arr1[]

*/


#include <bits/stdc++.h>
using namespace std;

/* Return true if arr2[] is a subset of arr1[] */
bool isSubset(int arr1[], int m, int arr2[], int n)
{

	// Using STL set for hashing
	set<int> hashset;

	// hashset stores all the values of arr1
	for (int i = 0; i < m; i++) {
		hashset.insert(arr1[i]);
	}

	// loop to check if all elements of arr2 also lies in arr1
	for (int i = 0; i < n; i++) {
		if (hashset.find(arr2[i]) == hashset.end())
			return false;
	}
	return true;
}

int main()
{
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset(arr1, m, arr2, n))
		cout << "arr2[] is subset of arr1[] "
			<< "\n";
	else
		cout << "arr2[] is not a subset of arr1[] "
			<< "\n";
	return 0;
}

/*
isSubset() Function: This is the main function that checks whether arr2[] is a subset of arr1[]. It takes four parameters: arr1[] (the first array), m (the size of arr1[]), arr2[] (the second array), and n (the size of arr2[]).

Using STL Set for Hashing: A std::set<int> named hashset is used to store all the values of arr1[]. This set helps in quickly checking if a value from arr2[] exists in arr1[].

Hashset Construction: The loop iterates through arr1[] and inserts each element into the hashset.

Subset Check: Another loop iterates through arr2[], and for each element, it checks whether it exists in the hashset using hashset.find(). If any element from arr2[] is not found in the hashset, it means that arr2[] is not a subset of arr1[], and the function returns false.

If all elements of arr2[] are found in the hashset, the function returns true.

*/



