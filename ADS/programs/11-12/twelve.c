/*
Given a text and a pattern, find the minimum window substring of the text that contains all the characters of the pattern.

Input: Text: ADOBECODEBANC
       Pattern: ABC
Output: Minimum Window Substring: BANC

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

// Function to compare two frequency hashmaps
int compareFreqHashmaps(int freqText[], int freqPattern[]) {
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freqPattern[i] > 0 && freqText[i] < freqPattern[i])
            return 0;
    }
    return 1;
}

// Minimum Window Substring using Frequency HashMap and Sliding Window
char* minWindowSubstring(char* text, char* pattern) {
    int N = strlen(text);
    int M = strlen(pattern);

    int freqPattern[MAX_CHAR] = {0};
    for (int i = 0; i < M; i++) {
        freqPattern[pattern[i]]++;
    }

    int start = 0;
    int minLength = N + 1;
    int minStart = -1;
    int charCount = 0;

    // Find the minimum window using the Sliding Window technique
    for (int i = 0; i < N; i++) {
        if (freqPattern[text[i]] > 0) {
            charCount++;
        }

        freqPattern[text[i]]--;

        // Move the 'start' pointer to shrink the window
        while (charCount == M && start <= i) {
            int length = i - start + 1;
            if (length < minLength) {
                minLength = length;
                minStart = start;
            }

            freqPattern[text[start]]++;

            if (freqPattern[text[start]] > 0) {
                charCount--;
            }

            start++;
        }
    }

    // Allocate memory for the minimum window substring and copy it
    if (minStart == -1) {
        return NULL;
    }

    char* result = (char*)malloc((minLength + 1) * sizeof(char));
    strncpy(result, text + minStart, minLength);
    result[minLength] = '\0';

    return result;
}

int main() {
    char text[] = "ADOBECODEBANC";
    char pattern[] = "ABC";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    char* minSub = minWindowSubstring(text, pattern);

    if (minSub != NULL) {
        printf("Minimum Window Substring: %s\n", minSub);
        free(minSub);
    } else {
        printf("No such window exists.\n");
    }

    return 0;
}


/*
This C program implements the Sliding Window technique along with Frequency HashMap to find the minimum window substring of the
given text that contains all the characters of the input pattern.
*/
