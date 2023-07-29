/*
Given an array arr[] denoting heights of N towers and a positive integer K.
For each tower, you must perform exactly one of the following operations exactly once.
Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any
negative integers.

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the minimum possible difference between the maximum and minimum elements in the array
    // after adding or subtracting 'k' from each element.
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n); // Sort the array in ascending order.

        int diff = arr[n - 1] - arr[0]; // Initialize the difference as the range between max and min elements.

        int a_min = 0; // Initialize variables to store potential new min and max elements.
        int a_max = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] - k < 0)
                continue; // Skip elements for which 'k' will cause a negative result.

            // Calculate the new potential max and min elements.
            a_max = max(arr[n - 1] - k, arr[i - 1] + k);
            a_min = min(arr[0] + k, arr[i] - k);

            diff = min(diff, a_max - a_min); // Update the minimum difference if needed.
        }

        return diff;
    }
};


int main() {
    int n, k;
    cin >> k; // Input the value of 'k'.
    cin >> n; // Input the number of elements in the array.

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input the elements of the array.
    }

    Solution ob; // Create an object of the Solution class.
    auto ans = ob.getMinDiff(arr, n, k); // Call the getMinDiff function to get the result.

    cout << ans << "\n"; // Output the minimum possible difference.

    return 0;
}

/*
The class Solution defines a class that contains the function getMinDiff to find the minimum difference between the maximum and minimum elements in the array after adding or subtracting k.
The getMinDiff function takes three parameters: arr (the input array), n (the number of elements in the array), and k (the value to be added or subtracted from each element).
The function first sorts the input array in ascending order using the sort function from the standard library.
It initializes the variable diff to store the initial difference between the maximum and minimum elements in the array.
It then initializes variables a_min and a_max to store the potential new minimum and maximum elements in the array after adding or subtracting k.
The function iterates over each element of the sorted array, skipping elements for which k would cause a negative result (non-positive elements).
It calculates the new potential minimum and maximum elements and updates the minimum difference if a smaller difference is found.
Finally, the function returns the minimum difference between the maximum and minimum elements in the array after applying the operations.
In the main function, the user is prompted to enter the value of k and the number of elements in the array (n).
An array arr of size n is declared to store the elements of the array.
The elements of the array are input from the user using a loop.
An object of the Solution class is created (named ob).
The getMinDiff function is called on the object ob, passing the array arr, n, and k.
The result is stored in the variable ans and printed on the console.

*/


