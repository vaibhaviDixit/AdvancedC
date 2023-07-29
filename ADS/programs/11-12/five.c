/*
Implement the Z Function algorithm to efficiently count the occurrences of a given pattern in a given text.

Input: Text: ABABDABACDABABCABAB
       Pattern: ABAB
Output: Number of occurrences: 3


*/
#include <stdio.h>
#include <string.h>

// Z Function Algorithm - Counting Occurrences
int ZCount(char* text, char* pattern) {
    char concat[strlen(pattern) + strlen(text) + 1];
    strcpy(concat, pattern);
    strcat(concat, "$");
    strcat(concat, text);

    int len = strlen(concat);
    int count = 0;

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
            count++;
    }

    return count;
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABAB";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    int occurrences = ZCount(text, pattern);

    printf("Number of occurrences: %d\n", occurrences);

    return 0;
}


/*
The Z Function algorithm is a string-searching algorithm that efficiently finds all occurrences of a pattern in a given text.
It uses the Z array to store the length of the longest substring starting from each index that matches the pattern.
By comparing the Z array value with the length of the pattern, we can count the occurrences of the pattern in the text.
*/
