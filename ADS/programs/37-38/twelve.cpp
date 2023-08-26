/*
Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m using hashing

Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4

Explanation : The subarrays having XOR of
              their elements as 6 are {4, 2},
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}

Input : arr[] = {5, 6, 7, 8, 9}, m = 5
Output : 2

*/

#include <bits/stdc++.h>

using namespace std;


//Function to return the XOR of all subarrays
int subarrayXor(int arr[], int n, int m)
{
	//declaring the hashtable and initializing it with a count of 1 for 0
	unordered_map <int, int> HashTable;
	HashTable[0] = 1;
	int count = 0, curSum = 0;
	for (int i = 0; i < n; i++)
	{
		curSum ^= arr[i];
		if (HashTable[curSum ^ m] > 0)
			count += HashTable[curSum ^ m];
		HashTable[curSum]++;
	}
	return(count);
}

int main()
{
	int arr[] = { 5, 6, 7, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = 5;

	//Function call
	cout << "Number of subarrays having given XOR is " << subarrayXor(arr, n, m);
}

/*
subarrayXor() Function: This function takes three arguments - an integer array arr[] representing the input array, an integer n representing the size of the array, and an integer m representing the target XOR value.

Hash Table: The code uses an unordered_map<int, int> named HashTable to store the frequency of XOR values encountered so far. It initializes the hash table with a count of 1 for the XOR value of 0 (initialization step).

Count and Current XOR Sum: The variable count is used to keep track of the count of subarrays with the given XOR value. The variable curSum represents the XOR sum of the current subarray being considered.

Iterating Through Array: The program iterates through the array elements using a loop. For each element arr[i], it calculates the XOR sum by updating curSum ^= arr[i].

Checking for Subarrays: It checks if there is any subarray with the XOR value (curSum ^ m) that has been encountered before. If such an XOR value exists in the hash table, it means there is a subarray with the required XOR value.

Updating Hash Table: The hash table is then updated with the current XOR sum. This helps keep track of the frequency of XOR values encountered.

Main Function: In the main() function, an example integer array arr is defined. The program calls the subarrayXor() function with the array, its size, and the target XOR value as arguments.

*/

