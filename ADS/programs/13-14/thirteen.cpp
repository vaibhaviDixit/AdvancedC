/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return the maximum value that can be put in the knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) {
        // Create a 2D DP table to store the maximum value for each subproblem.
        int t[n + 1][w + 1];

        // Initialize the base cases: when the number of elements is 0 or the knapsack capacity is 0, the maximum value is 0.
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < w + 1; j++) {
                if (i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }

        // Calculate the maximum value that can be put in the knapsack for each possible weight and number of elements.
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < w + 1; j++) {
                if (wt[i - 1] <= j) {
                    // If the current item can be included in the knapsack, find the maximum value by either including it or excluding it.
                    t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
                } else {
                    // If the current item's weight exceeds the current knapsack capacity, skip it and consider the previous best solution.
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][w]; // Return the maximum value that can be put in the knapsack of capacity W.
    }
};

int main() {
    // Read the number of elements and the knapsack capacity.
    int n, w;
    cin >> n >> w;

    int val[n];
    int wt[n];

    // Input the values of the elements.
    for (int i = 0; i < n; i++)
        cin >> val[i];

    // Input the weights of the elements.
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    Solution ob; // Create an object of the Solution class.

    // Call the knapSack method to find the maximum value that can be put in the knapsack.
    cout << ob.knapSack(w, wt, val, n) << endl;

    return 0;
}


/*
The knapSack function takes four parameters: w (knapsack capacity), wt[] (array of weights of elements), val[] (array of values of elements), and n (number of elements).
The function uses a 2D DP table t to store the maximum value for each subproblem. It follows the bottom-up approach of dynamic programming to find the maximum value that can be put in the knapsack for each possible weight and number of elements.
The function returns the maximum value that can be put in the knapsack of capacity W.
In the main function, the user is prompted to enter the number of elements (n) and the knapsack capacity (w).
Two arrays val[] and wt[] are declared to store the values and weights of the elements, respectively.
The elements' values and weights are input from the user using loops.
An object of the Solution class is created (named ob).
The knapSack function is called on the object ob, passing the knapsack capacity, value array, weight array, and number of elements.
The maximum value that can be put in the knapsack is printed on the console.

*/



