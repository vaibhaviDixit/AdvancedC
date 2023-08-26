/*
Two pairs (a, b) and (c, d) are said to be symmetric if c is equal to b and a is equal to d. For example, (10, 20) and (20, 10) are symmetric. Given an array of pairs find all symmetric pairs in it.
It may be assumed that the first elements of all pairs are distinct. Use hashing technique.

Input: arr[] = {{11, 20}, {30, 40}, {5, 10}, {40, 30}, {10, 5}}
Output: Following pairs have symmetric pairs
        (30, 40)
        (5, 10)

*/

#include<bits/stdc++.h>
using namespace std;

void findSymPairs(int arr[][2], int row)
{
	// Creates an empty hashMap hM
	unordered_map<int, int> hM;

	// Traverse through the given array
	for (int i = 0; i < row; i++)
	{
		// First and second elements of current pair
		int first = arr[i][0];
		int sec = arr[i][1];

		// If found and value in hash matches with first
		// element of this pair, we found symmetry
		if (hM.find(sec) != hM.end() && hM[sec] == first)
			cout << "(" << sec << ", " << first << ")" <<endl;

		else // Else put sec element of this pair in hash
			hM[first] = sec;
	}
}

int main()
{
	int arr[5][2];
	arr[0][0] = 11; arr[0][1] = 20;
	arr[1][0] = 30; arr[1][1] = 40;
	arr[2][0] = 5; arr[2][1] = 10;
	arr[3][0] = 40; arr[3][1] = 30;
	arr[4][0] = 10; arr[4][1] = 5;
	cout<<"Following pairs have symmetric pairs\n";
	findSymPairs(arr, 5);
}

/*
findSymPairs() Function: This function takes two arguments - a 2D integer array arr[][] representing the pairs and an integer row representing the number of rows (pairs) in the array.

Hash Map: The code uses an unordered_map<int, int> named hM to store the mapping of elements.

Traversing Pairs: The code traverses through each pair in the array. For each pair, it checks whether the symmetric pair (pair with reversed elements) exists in the hash map or not.

Symmetric Pair Check: If a symmetric pair is found, it is printed. The symmetric pair is identified by checking if the second element of the current pair exists in the hash map and is equal to the first element of the current pair.

Updating Hash Map: If no symmetric pair is found for the current pair, the first element of the pair is stored in the hash map with the second element as its value. This helps in identifying symmetric pairs in subsequent iterations.

*/




