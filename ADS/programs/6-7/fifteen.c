/*
Given a string 'str', find the length of the Longest Palindromic Subsequence (LPS) of the string.
The LPS is a subsequence of the string that reads the same backward as forward.

Input: str= "racecar"
Output: Longest palindromic subsequence length: 7

*/

#include <stdio.h>
#include <string.h>

// LPS Algorithm
// This function takes a string 'str' and its length 'n' as input.
// It finds the length of the Longest Palindromic Subsequence (LPS) of 'str' using dynamic programming.
// The function returns the length of the LPS.
int lps(char str[], int n) {
    // Create a 2D array to store the LPS lengths for substrings of 'str'
    int L[n][n];

    // Initialize LPS lengths for substrings of length 1 (single characters)
    for (int i = 0; i < n; i++)
        L[i][i] = 1;

    // Calculate the LPS lengths using dynamic programming
    for (int cl = 2; cl <= n; cl++) {
        for (int i = 0; i < n - cl + 1; i++) {
            int j = i + cl - 1;
            if (str[i] == str[j] && cl == 2)
                L[i][j] = 2;
            else if (str[i] == str[j])
                L[i][j] = L[i + 1][j - 1] + 2;
            else
                L[i][j] = (L[i][j - 1] > L[i + 1][j]) ? L[i][j - 1] : L[i + 1][j];
        }
    }

    return L[0][n - 1];
}

int main() {
    // Sample string
    char str[] = "racecar";

    // Calculate the length of the string
    int n = strlen(str);

    // Call the lps function to find the length of the Longest Palindromic Subsequence (LPS)
    int longest_palindromic_subseq = lps(str, n);

    // Print the length of the LPS
    printf("Longest palindromic subsequence length: %d", longest_palindromic_subseq);

    return 0;

}


/*
The program implements the Longest Palindromic Subsequence (LPS) Algorithm to find the length of the LPS of a given string.
The LPS is a subsequence of the string that reads the same backward as forward.
The algorithm uses dynamic programming to calculate the LPS lengths for all possible substrings of the given string.
It creates a 2D array 'L' to store the LPS lengths, where 'L[i][j]' represents the LPS length for the substring 'str[i...j]'.
The function initializes the LPS lengths for substrings of length 1 (single characters) to 1.
It then iterates through all substrings of increasing lengths, filling in the 'L' array based on the LPS lengths of the smaller substrings.
The LPS length for the entire string is stored in 'L[0][n-1]', where 'n' is the length of the string.

*/



