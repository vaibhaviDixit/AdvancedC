/*
Given two strings s and t. Return the minimum number of operations required to convert s to t.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.


Example 1:

Input:
s = "mumbai", t = "momba"
Output: 2

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the minimum edit distance between two strings 's' and 't'.
    int editDistance(string s, string t) {
        int m = s.length(); // Length of string 's'.
        int n = t.length(); // Length of string 't'.

        // Create a 2D DP array to store the minimum edit distance for all substrings of 's' and 't'.
        int dp[m + 1][n + 1];

        // Initializing the base cases of the DP array.
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0)
                    dp[i][j] = j; // If string 's' is empty, the minimum edit distance is the length of string 't'.
                else if (j == 0)
                    dp[i][j] = i; // If string 't' is empty, the minimum edit distance is the length of string 's'.
                else if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1]; // If the characters match, no edit is required, take the diagonal value.
                else
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])); // Otherwise, choose the minimum of three edit operations (insert, remove, or replace).
            }
        }

        return dp[m][n]; // Return the minimum edit distance between the strings 's' and 't'.
    }
};

int main() {
    string s, t;
    cin >> s >> t; // Input the two strings.

    Solution ob; // Create an object of the Solution class.

    // Call the editDistance function to calculate the minimum edit distance.
    int ans = ob.editDistance(s, t);

    cout << ans << "\n"; // Output the minimum edit distance.

    return 0;
}

/*
The editDistance function takes two parameters: s (the first input string) and t (the second input string).
The function calculates the lengths of the strings 's' and 't' using the length() method of the string class.
It creates a 2D DP array dp to store the minimum edit distance for all possible substrings of 's' and 't'.
The function initializes the base cases of the DP array where the strings are empty.
It then iterates through the DP array using nested loops to calculate the minimum edit distance.
If the characters at the current positions of 's' and 't' match, the function takes the diagonal value as no edit is required.
If the characters don't match, the function chooses the minimum of three edit operations (insert, remove, or replace) and adds 1 to it.
After filling the DP array, the function returns the minimum edit distance between the strings 's' and 't'.
In the main function, the user is prompted to enter the two strings ('s' and 't').
An object of the Solution class is created (named ob).
The editDistance function is called on the object ob, passing the two strings 's' and 't'.
The minimum edit distance is calculated and printed on the console.

*/

