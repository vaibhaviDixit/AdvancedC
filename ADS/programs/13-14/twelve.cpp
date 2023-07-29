/*
Given an sequence from 1 to N and also given an array arr[] of size N. Basically the array is the permutation of 1 to N which determines
that the element from ith position should move to the jth position. Now the task is to find the minimum number of operations such that each
array element is present at its original positions.
(For more understanding please go through the examples)

Note: the answer can be large, so return the answer modulo 10^9+7.

Input: N = 3, arr[] = {1,2,3}
Output: 1

Input: N = 5, arr[] = {2,3,1,5,4}
Output: 6

*/

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define mod 1000000007

class Solution {
public:
    // Function to rearrange the array and return the final result.
    int rearrange_array(vector<int> &arr) {
        int n = arr.size(); // Get the size of the input array.
        vector<int> ans; // Initialize a vector to store the lengths of cycles.

        // Create a vector to mark visited elements during cycle detection.
        vector<bool> vis(n);

        // Iterate through the array to find the cycles and their lengths.
        for (int i = 0; i < n; i++) {
            // Skip the element if it is already visited (part of a previously found cycle).
            if (vis[arr[i] - 1] == true)
                continue;

            int start = arr[i]; // Mark the start element of the current cycle.
            int curr = arr[i]; // Initialize a pointer to traverse the cycle.
            int len = 0; // Initialize the length of the current cycle to zero.

            // Traverse the cycle and count the number of elements in it.
            do {
                vis[curr - 1] = true; // Mark the current element as visited.
                curr = arr[curr - 1]; // Move to the next element in the cycle.
                len++; // Increment the cycle length.
            } while (start != curr); // Continue until the cycle is completed.

            ans.push_back(len); // Store the length of the current cycle in the ans vector.
        }

        // Combine the lengths of cycles using the formula lcm(a, b) = (a * b) / gcd(a, b).
        while (ans.size() > 1) {
            long long x = ans.back(); // Get the last element of the ans vector.
            ans.pop_back(); // Remove the last element.
            long long y = ans.back(); // Get the new last element after removing the previous one.
            ans.pop_back(); // Remove the new last element.

            // Calculate the least common multiple (LCM) of x and y using the formula and take modulo with 'mod'.
            long long z = (x * y) / (__gcd(x, y));
            z = z % mod;

            ans.push_back((int)z); // Store the result of the LCM calculation in the ans vector.
        }

        return (int)(ans[0]); // Return the final result, which is the LCM of all cycle lengths.
    }
};

int main() {
    int n;
    cin >> n; // Input the size of the array.
    vector<int> a(n); // Declare a vector of size n to store the elements of the array.

    // Input the elements of the array.
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Solution obj; // Create an object of the Solution class.

    // Call the rearrange_array function to rearrange the array and get the final result.
    int ans = obj.rearrange_array(a);

    cout << ans << endl; // Output the final result.

    return 0;
}

/*
The rearrange_array function takes a reference to a vector of integers (arr) as its parameter.
The function iterates through the array to find cycles and their lengths using a cycle detection algorithm.
It stores the lengths of the cycles in the ans vector.
The function then combines the lengths of the cycles using the formula LCM(a, b) = (a * b) / gcd(a, b).
The LCM calculation is done using long long data types to avoid overflow and then taken modulo with 'mod'.
Finally, the function returns the final result, which is the LCM of all cycle lengths.
In the main function, the user is prompted to enter the size of the array (n).
A vector a of size n is declared to store the elements of the array.
The elements of the array are input from the user using a loop.
An object of the Solution class is created (named obj).
The rearrange_array function is called on the object obj, passing the vector a by reference.
The final result (LCM of cycle lengths) is printed on the console.

*/


