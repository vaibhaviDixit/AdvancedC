/*

Implement the KMP algorithm to efficiently count the occurrences of a given pattern in a given text.

Input: Text: ABABDABACDABABCABAB
       Pattern: ABAB
Output: Number of occurrences: 3

*/

#include <stdio.h>
#include <string.h>

// KMP Algorithm - Counting Occurrences
int KMPCount(char* text, char* pattern) {
    int N = strlen(text);
    int M = strlen(pattern);
    int count = 0;

    // Construct the longest prefix suffix (LPS) array
    int lps[M];
    int len = 0; // Length of the previous longest prefix suffix
    int i = 1;

    lps[0] = 0;

    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // Count occurrences of the pattern in the text
    int j = 0; // Index for pattern[]
    i = 0;     // Index for text[]

    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            count++;
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return count;
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABAB";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    int occurrences = KMPCount(text, pattern);

    printf("Number of occurrences: %d\n", occurrences);

    return 0;
}


/*
The Knuth-Morris-Pratt (KMP) algorithm is a string-searching algorithm that efficiently finds all occurrences of a pattern in a given text.
It works by constructing the longest prefix suffix (LPS) array for the pattern, which helps in skipping unnecessary comparisons while
searching for the pattern in the text.
*/
