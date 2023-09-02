/*
Given an array of n size, the task is to find the longest subsequence such that difference between adjacents is one.

Input :  arr[] = {10, 9, 4, 5, 4, 8, 6}
Output :  3
As longest subsequences with difference 1 are, "10, 9, 8",
"4, 5, 4" and "4, 5, 6"

Input :  arr[] = {1, 2, 3, 2, 3, 7, 2, 1}
Output :  7

*/

#include<bits/stdc++.h>
using namespace std;

// Function to find the length of the longest subsequence
// with one difference
int longestSubsequence(int n, int arr[]) {
    // Base case: if there is only one element, the length is 1
    if(n == 1)
        return 1;

    // Create an unordered map to store the length of subsequences
    unordered_map<int, int> mapp;

    // Initialize the result to 1
    int res = 1;

    // Loop through the array
    for(int i = 0; i < n; i++) {
        // If the element arr[i] - 1 or arr[i] + 1 exists in the map,
        // calculate the length of the subsequence at arr[i] and update the map
        if(mapp.count(arr[i] + 1) > 0 || mapp.count(arr[i] - 1) > 0) {
            mapp[arr[i]] = 1 + max(mapp[arr[i] + 1], mapp[arr[i] - 1]);
        }
        // If neither arr[i] - 1 nor arr[i] + 1 exists, set length to 1
        else {
            mapp[arr[i]] = 1;
        }

        // Update the result with the maximum length
        res = max(res, mapp[arr[i]]);
    }

    // Return the final result
    return res;
}

int main() {
    // Array of integers
    int arr[] = {1, 2, 3, 4, 5, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the function and print the result
    cout << "Longest subsequence with one difference: " << longestSubsequence(n, arr) << endl;

    return 0;
}

/*
The longestSubsequence Function: This function calculates the length of the longest subsequence in an array with a difference of exactly one between adjacent elements. It takes two parameters: an integer n representing the size of the array and an array arr[] of integers.

Base Case: The base case is handled when the array has only one element. In this case, the length of the subsequence is 1.

Unordered Map mapp: An unordered map is used to store the length of subsequences ending at different elements.

Loop through the Array: A loop iterates through the array. For each element arr[i], the program checks if arr[i] + 1 or arr[i] - 1 is already present in the map. If either is present, the program calculates the length of the subsequence ending at arr[i] and updates the map.

Updating the Result: The program updates the result by taking the maximum of the current result and the length of the subsequence ending at arr[i].

*/

