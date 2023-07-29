/*
Given an array arr of N integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2,
otherwise false.

Input:
N = 5
Arr[] = {3, 2, 4, 6, 5}
Output: Yes
Explanation: a=3, b=4, and c=5 forms a
pythagorean triplet.

Input:
N = 3
Arr[] = {3, 8, 5}
Output: No

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if a Pythagorean triplet exists in the given array.
    bool checkTriplet(int arr[], int n) {
        // Sort the input array in ascending order.
        sort(arr, arr + n);

        // Iterate through all possible triplets in the array using nested loops.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    // Check if the current triplet forms a Pythagorean triplet.
                    if ((arr[i] * arr[i] + arr[j] * arr[j]) == arr[k] * arr[k]) {
                        return true; // If a Pythagorean triplet is found, return true.
                    }
                }
            }
        }

        return false; // If no Pythagorean triplet is found, return false.
    }
};

int main() {
    int n, i;
    cin >> n; // Input the size of the array.

    int arr[n]; // Declare an array to store the elements of the array.

    // Input the elements of the array.
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution ob; // Create an object of the Solution class.

    // Call the checkTriplet function to check if a Pythagorean triplet exists.
    auto ans = ob.checkTriplet(arr, n);

    // Output the result.
    if (ans) {
        cout << "Yes\n"; // If a Pythagorean triplet exists, print "Yes".
    } else {
        cout << "No\n"; // If no Pythagorean triplet exists, print "No".
    }

    return 0;
}

/*
The class Solution defines a class that contains the function checkTriplet to check if a Pythagorean triplet exists in the given array.
The checkTriplet function takes two parameters: arr (an array of integers) and n (the size of the array).
The function first sorts the input array arr in ascending order using the sort function from the standard library.
It then uses nested loops to iterate through all possible triplets in the array (i, j, k), where i < j < k.
For each triplet, the function checks if the current triplet forms a Pythagorean triplet using the condition (arr[i] * arr[i] + arr[j] * arr[j]) == arr[k] * arr[k].
If a Pythagorean triplet is found, the function returns true.
If no Pythagorean triplet is found after checking all possible triplets, the function returns false.
In the main function, the user is prompted to enter the size of the array (n).
An array arr of size n is declared to store the elements of the array.
The elements of the array are input from the user using a loop.
An object of the Solution class is created (named ob).
The checkTriplet function is called on the object ob, passing the array arr and the size n.
The result (ans) is stored, and based on whether a Pythagorean triplet exists or not, the program outputs "Yes" or "No" on the console.

*/


