/*
Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers.
If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order.
You are given an list of numbers arr[ ] of size N.

Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the next lexicographically greater permutation of the input array.
    vector<int> nextPermutation(int n, vector<int> arr) {
        int index = -1;

        // Step 1: Find the first element from the right that is smaller than its next element.
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                index = i;
                break;
            }
        }

        // Step 2: If no such element is found, the array is in decreasing order, so reverse the array and return.
        if (index == -1) {
            reverse(arr.begin(), arr.end());
            return arr;
        }

        // Step 3: Find the smallest element from the right that is greater than the element at 'index'.
        for (int i = n - 1; i > index; i--) {
            if (arr[index] < arr[i]) {
                swap(arr[i], arr[index]);
                break;
            }
        }

        // Step 4: Reverse the elements to the right of 'index'.
        reverse(arr.begin() + index + 1, arr.end());

        return arr; // Return the next lexicographically greater permutation.
    }
};

int main() {
    int N;
    cin >> N; // Input the size of the array.

    vector<int> arr(N); // Declare a vector to store the elements of the array.

    // Input the elements of the array.
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    Solution ob; // Create an object of the Solution class.

    // Call the nextPermutation function to find the next lexicographically greater permutation.
    vector<int> ans = ob.nextPermutation(N, arr);

    // Output the elements of the next permutation.
    for (int u : ans) {
        cout << u << " ";
    }
    cout << "\n";

    return 0;
}

/*
The nextPermutation function takes two parameters: n (the size of the array) and arr (a vector that holds the elements of the array).
The function follows the standard "next permutation" algorithm.
It first finds the index index of the first element from the right that is smaller than its next element.
If no such element is found, the array is in decreasing order, and it means it is the last permutation. So, the function reverses the entire array and returns it.
Otherwise, it finds the smallest element from the right that is greater than the element at index. It then swaps these two elements.
After swapping, the elements to the right of index are in decreasing order. So, the function reverses those elements to make the permutation lexicographically greater.
The function returns the next lexicographically greater permutation of the input array.
In the main function, the user is prompted to enter the size of the array (N).
A vector arr of size N is declared to store the elements of the array.
The elements of the array are input from the user using a loop.
An object of the Solution class is created (named ob).
The nextPermutation function is called on the object ob, passing the size N and the vector arr.
The elements of the next permutation are printed on the console.

*/


