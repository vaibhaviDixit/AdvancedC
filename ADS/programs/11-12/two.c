/*
Implement the Z Function algorithm to efficiently search for occurrences of a given pattern in a given text.

Input: Text: ABABDABACDABABCABAB
       Pattern: ABABCABAB
Output: Pattern found at index 10

*/

#include <stdio.h>
#include <string.h>

// Z Function Algorithm
void ZSearch(char* text, char* pattern) {
    char concat[strlen(pattern) + strlen(text) + 1];
    strcpy(concat, pattern);
    strcat(concat, "$");
    strcat(concat, text);

    int len = strlen(concat);

    int Z[len];
    Z[0] = 0;

    int left = 0;
    int right = 0;

    for (int k = 1; k < len; k++) {
        if (k > right) {
            left = right = k;
            while (right < len && concat[right] == concat[right - left])
                right++;
            Z[k] = right - left;
            right--;
        } else {
            int k1 = k - left;
            if (Z[k1] < right - k + 1)
                Z[k] = Z[k1];
            else {
                left = k;
                while (right < len && concat[right] == concat[right - left])
                    right++;
                Z[k] = right - left;
                right--;
            }
        }

        if (Z[k] == strlen(pattern))
            printf("Pattern found at index %d\n", k - strlen(pattern) - 1);
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    printf("Pattern occurrences:\n");
    ZSearch(text, pattern);

    return 0;
}


/*
The Z Function algorithm is an efficient string-searching algorithm that constructs a Z array for a concatenation of the
pattern and text. The Z array contains information about the length of the longest prefix of the concatenated string that
matches the prefix of the pattern.
By examining the Z array, we can find all occurrences of the pattern in the text.

*/
