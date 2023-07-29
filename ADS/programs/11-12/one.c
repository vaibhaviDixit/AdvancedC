/*
Implement the Knuth-Morris-Pratt (KMP) algorithm to efficiently search for occurrences of a given pattern in a given text.

Input: Text: ABABDABACDABABCABAB
       Pattern: ABABCABAB
Output: Pattern found at index 10

*/
#include <stdio.h>
#include <string.h>

// KMP Algorithm
void KMPSearch(char* text, char* pattern) {
    int N = strlen(text);
    int M = strlen(pattern);

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

    // Search for occurrences of the pattern in the text
    int j = 0; // Index for pattern[]
    i = 0;     // Index for text[]

    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    printf("Pattern occurrences:\n");
    KMPSearch(text, pattern);

    return 0;
}


/*
The KMP algorithm is an efficient string-searching algorithm that improves upon the standard brute-force approach.
It constructs a longest prefix suffix (LPS) array for the pattern, which helps in avoiding unnecessary comparisons
during the search process.

*/
