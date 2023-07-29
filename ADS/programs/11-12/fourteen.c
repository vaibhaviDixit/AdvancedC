/*
Given a string text, find the longest non-overlapping repeated substring in the text.

Input: str- banana
Output: Longest Repeated Non-Overlapping Substring: an

*/

#include <stdio.h>
#include <string.h>

// Function to find the longest repeating non-overlapping substring in str
char* longestRepeatedSubstring(const char* str) {
    int n = strlen(str);
    int LCSRe[n+1][n+1];

    // Setting all to 0
    memset(LCSRe, 0, sizeof(LCSRe));

    char* res = NULL; // To store result
    int res_length = 0; // To store length of result
    int index = 0; // To store the finishing index of the suffix

    // Building table in bottom-up manner
    int i;
    for (i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            // (j - i) > LCSRe[i-1][j-1] to remove overlapping
            if (str[i - 1] == str[j - 1] && LCSRe[i - 1][j - 1] < (j - i)) {
                LCSRe[i][j] = LCSRe[i - 1][j - 1] + 1;

                // Updating maximum length of the substring and updating the finishing index of the suffix
                if (LCSRe[i][j] > res_length) {
                    res_length = LCSRe[i][j];
                    index = i;
                }
            } else {
                LCSRe[i][j] = 0;
            }
        }
    }

    // If we have a non-empty result, then allocate memory and copy the characters from the first character to the last character of the string
    if (res_length > 0) {
        res = (char*)malloc((res_length + 1) * sizeof(char));
        int k = 0;
        for (i = index - res_length + 1; i <= index; i++) {
            res[k++] = str[i - 1];
        }
        res[res_length] = '\0';
    }

    return res;
}

// Driver program to test the above function
int main() {
    const char* str = "banana";
    char* longestRepeatedSub = longestRepeatedSubstring(str);

    if (longestRepeatedSub != NULL) {
        printf("Longest Repeated Non-Overlapping Substring: %s\n", longestRepeatedSub);
        free(longestRepeatedSub);
    } else {
        printf("No such substring found.\n");
    }

    return 0;
}

/*
This program finds the longest non-overlapping repeated substring in the given text using the Z Function algorithm.
*/
