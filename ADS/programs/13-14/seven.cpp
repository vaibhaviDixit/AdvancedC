/*
Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
Note: Array should start with a positive number and 0 (zero) should be considered a positive element.

Input:
N = 9
Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
Output:
9 -2 4 -1 5 -5 0 -3 2

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to rearrange the elements of the array, placing positive elements first followed by negative elements.
    void rearrange(int arr[], int n) {
        queue<int> pos; // Queue to store positive elements.
        queue<int> neg; // Queue to store negative elements.

        // Separate positive and negative elements into respective queues.
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                pos.push(arr[i]);
            } else {
                neg.push(arr[i]);
            }
        }

        int i = 0; // Index to keep track of the current position in the array.

        // Alternately place positive and negative elements back into the array.
        while (!pos.empty() || !neg.empty()) {
            if (!pos.empty()) {
                arr[i++] = pos.front(); // Put the front element of the positive queue into the array and increment index.
                pos.pop(); // Remove the front element from the positive queue.
            }
            if (!neg.empty()) {
                arr[i++] = neg.front(); // Put the front element of the negative queue into the array and increment index.
                neg.pop(); // Remove the front element from the negative queue.
            }
        }
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

    // Call the rearrange function to rearrange the array.
    ob.rearrange(arr, n);

    // Output the rearranged array.
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
The rearrange function takes two parameters: arr (an array of integers) and n (the size of the array).
The function uses two queues, pos to store positive elements and neg to store negative elements.
It then iterates through the array and separates positive and negative elements into their respective queues.
The function initializes a variable i to keep track of the current position in the array.
Using a while loop, the function alternately places positive and negative elements back into the array, thereby rearranging the array as required.
After the loop, the array arr will contain positive elements followed by negative elements in the order they appeared in the original array.
In the main function, the user is prompted to enter the size of the array (n).
An array arr of size n is declared to store the elements of the array.
The elements of the array are input from the user using a loop.
An object of the Solution class is created (named ob).
The rearrange function is called on the object ob, passing the array arr and the size n.
The elements of the rearranged array are printed on the console.

*/


