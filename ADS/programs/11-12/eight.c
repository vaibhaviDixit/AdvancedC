/*

Implement the Z Function Algorithm to find the Longest Common Prefix (LCP) of two given strings text1 and text2.

Input: Text 1: ababaa
       Text 2: babab
Output: Longest Common Prefix: baba

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Z Function Algorithm
void ZFunction(char* text, int Z[]) {
    int N = strlen(text);

    int left = 0;
    int right = 0;

    for (int k = 1; k < N; k++) {
        if (k > right) {
            left = right = k;
            while (right < N && text[right] == text[right - left])
                right++;
            Z[k] = right - left;
            right--;
        } else {
            int k1 = k - left;
            if (Z[k1] < right - k + 1)
                Z[k] = Z[k1];
            else {
                left = k;
                while (right < N && text[right] == text[right - left])
                    right++;
                Z[k] = right - left;
                right--;
            }
        }
    }
}

// Longest Common Prefix (LCP) using Z Function
char* LCP_Z(char* text1, char* text2) {
    int N1 = strlen(text1);
    int N2 = strlen(text2);
    int N = N1 + N2 + 1;

    char concat[N];
    strcpy(concat, text1);
    strcat(concat, "$");
    strcat(concat, text2);

    int Z[N];
    ZFunction(concat, Z);

    int max_LCP = 0;
    int start = 0;

    for (int i = 1; i < N; i++) {
        if (Z[i] > max_LCP && i > N1) {
            max_LCP = Z[i];
            start = i - N1 - 1;
        }
    }

    char* result = (char*)malloc((max_LCP + 1) * sizeof(char));
    strncpy(result, text1 + start, max_LCP);
    result[max_LCP] = '\0';

    return result;
}

int main() {
    char text1[] = "ababaa";
    char text2[] = "babab";

    printf("Text 1: %s\n", text1);
    printf("Text 2: %s\n", text2);

    char* lcp = LCP_Z(text1, text2);

    printf("Longest Common Prefix: %s\n", lcp);

    free(lcp);

    return 0;
}



/*
The Z Function Algorithm is a string-matching algorithm that constructs the Z array, where Z[i] represents the length of the longest
common prefix (LCP) of the substring starting at index i with the whole text.
It efficiently calculates the LCP values using linear time complexity.

*/
