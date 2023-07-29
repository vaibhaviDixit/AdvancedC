/*
Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array(In Place).
In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....

If there are multiple solutions, find the lexicographically smallest one.

Note:The given array is sorted in ascending order, and you don't need to return anything to make changes in the original array itself.

Input:
n = 5
arr[] = {1,2,3,4,5}
Output: 2 1 4 3 5
Explanation: Array elements after
sorting it in wave form are
2 1 4 3 5.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to convert the input array to a wave array.
    void convertToWave(int n, vector<int>& arr) {
        for (int i = 0; i < n; i = i + 2) { // Iterate through the array, considering every other element (even index).
            if (arr[i] < arr[i + 1]) { // Check if the current element is less than the next element.
                swap(arr[i], arr[i + 1]); // Swap the current element with the next element to make it greater or equal.
            }
        }
    }
};

int main() {
    int n;
    cin >> n; // Input the size of the array.

    vector<int> a(n); // Declare a vector of size n to store the elements of the array.
    for (int i = 0; i < n; i++)
        cin >> a[i]; // Input the elements of the array.

    sort(a.begin(), a.end()); // Sort the array in ascending order.

    Solution ob; // Create an object of the Solution class.

    ob.convertToWave(n, a); // Call the convertToWave function to convert the array to a wave array.

    for (int i = 0; i < n; i++)
        cout << a[i] << " "; // Print the elements of the array after conversion.

    cout << endl;

    return 0;
}

/*

The convertToWave function takes two parameters: n (the size of the array) and arr (a reference to a vector that holds the elements of the array).
The function iterates through the array using a loop, considering every other element (even index).
For each even-indexed element, it checks if the current element is less than the next element (arr[i] < arr[i + 1]).
If the condition is true, it swaps the current element with the next element using the swap function to make it greater or equal to the next element.
After the loop, the function modifies the vector arr, effectively converting it to a wave array.
In the main function, the user is prompted to enter the size of the array (n).
A vector a of size n is declared to store the elements of the array.
The elements of the array are input from the user using a loop and stored in the vector a.
The vector a is then sorted in ascending order using the sort function from the standard library.
An object of the Solution class is created (named ob).
The convertToWave function is called on the object ob, passing the size n and the vector a.
The vector a now holds the elements of the array in wave format.
The elements of the vector a are printed on the console in their new order.

*/

