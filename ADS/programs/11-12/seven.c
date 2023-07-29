/*
Implement the KMP Algorithm to find the length of the Longest Prefix that is also a Suffix (LPAS) of a given pattern.

Input: Pattern: ababcababc
Output: Length of Longest Prefix that is also a Suffix: 5

*/

#include <stdio.h>
#include <string.h>

// KMP Algorithm to find the Longest Prefix that is also a Suffix (LPAS)
int LPAS_KMP(char* pattern) {
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

    return lps[M - 1];
}

int main() {
    char pattern[] = "ababcababc";

    printf("Pattern: %s\n", pattern);

    int length_LPAS = LPAS_KMP(pattern);

    printf("Length of Longest Prefix that is also a Suffix: %d\n", length_LPAS);

    return 0;
}


/*
The KMP Algorithm is a string-searching algorithm that efficiently finds occurrences of a pattern in a given text.
In this implementation, we use the KMP Algorithm to find the length of the Longest Prefix that is also a Suffix (LPAS) of a
given pattern.
*/
