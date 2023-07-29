/*
Given strings A, B, and C, find whether C is formed by an interleaving of A and B.

An interleaving of two strings S and T is a configuration such that it creates a new string Y from the concatenation substrings of A and B
and |Y| = |A + B| = |C|

For example:
A = "XYZ"
B = "ABC"

so we can make multiple interleaving string Y like, XYZABC, XAYBCZ, AXBYZC, XYAZBC and many more so here your task is to check whether you
can create a string Y which can be equal to C.
Specifically, you just need to create substrings of string A and create substrings B and concatenate them and check whether it is equal to
C or not.
Note: a + b is the concatenation of strings a and b.
Return true if C is formed by an interleaving of A and B, else return false.

Input:
A = XY, B = X, C = XXY
Output: 1

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if string 'c' is an interleaving of strings 'a' and 'b'.
    bool isInterleave(string a, string b, string c) {
        int x = a.length(); // Length of string 'a'.
        int y = b.length(); // Length of string 'b'.
        int z = c.length(); // Length of string 'c'.

        // Check if the combined length of 'a' and 'b' matches the length of 'c'.
        if (x + y != z) return false;

        // Create a 2D DP array to store the subproblem results for interleaving.
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

        dp[0][0] = 1; // Base case: Empty strings 'a' and 'b' can form an empty string 'c'.

        // Check if 'a' can form the prefix of 'c'.
        for (int i = 1; i <= x; i++) {
            if (a[i - 1] == c[i - 1])
                dp[i][0] = 1;
            else
                break; // If a character mismatch is found, no further interleaving is possible.
        }

        // Check if 'b' can form the prefix of 'c'.
        for (int j = 1; j <= y; j++) {
            if (b[j - 1] == c[j - 1])
                dp[0][j] = 1;
            else
                break; // If a character mismatch is found, no further interleaving is possible.
        }

        // Fill the DP array using the recurrence relation for interleaving.
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (a[i - 1] == c[i + j - 1])
                    dp[i][j] |= dp[i - 1][j];
                if (b[j - 1] == c[i + j - 1])
                    dp[i][j] |= dp[i][j - 1];
            }
        }

        return dp[x][y]; // Return the result for the entire problem.
    }
};

int main() {
    string a, b, c;
    cin >> a >> b >> c; // Input the three strings.

    Solution obj; // Create an object of the Solution class.

    // Call the isInterleave function to check if 'c' is an interleaving of 'a' and 'b'.
    bool result = obj.isInterleave(a, b, c);

    cout << result << endl; // Output the result (1 for true, 0 for false).

    return 0;
}

/*
The isInterleave function takes three parameters: a (the first input string), b (the second input string), and c (the third input string).
The function calculates the lengths of strings 'a', 'b', and 'c' using the length() method of the string class.
It checks if the combined length of 'a' and 'b' matches the length of 'c'. If not, it returns false as 'c' cannot be formed by interleaving 'a' and 'b'.
It creates a 2D DP array dp to store the subproblem results for interleaving.
The function initializes the base cases of the DP array where empty strings 'a' and 'b' can form an empty string 'c'.
It then iterates through the DP array using nested loops to fill the array using the recurrence relation for interleaving.
The recurrence relation checks if characters from 'a' and 'b' can be matched with characters from 'c' to form the interleaved string.
After filling the DP array, the function returns the result for the entire problem, which is stored in dp[x][y].
In the main function, the user is prompted to enter three strings ('a', 'b', and 'c').
An object of the Solution class is created (named obj).
The isInterleave function is called on the object obj, passing the three strings 'a', 'b', and 'c'.
The result (true or false) is printed on the console (1 for true and 0 for false).

*/


