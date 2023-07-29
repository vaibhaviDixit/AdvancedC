/*
Given a text and a pattern, find all occurrences of anagrams of the pattern in the text.


Input:
Text: BACDGABCDA
Pattern: ABCD

Output:
Anagram occurrences:
Anagram found at index 0
Anagram found at index 5
Anagram found at index 6

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

// Function to compare two frequency arrays
int compareFreqArrays(int freq1[], int freq2[]) {
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq1[i] != freq2[i])
            return 0;
    }
    return 1;
}

// Anagram Substring Search using Frequency Arrays and Sliding Window
void anagramSubstringSearch(char* text, char* pattern) {
    int N = strlen(text);
    int M = strlen(pattern);

    int countText[MAX_CHAR] = {0};
    int countPattern[MAX_CHAR] = {0};

    // Initialize frequency arrays for the first window
    for (int i = 0; i < M; i++) {
        countText[text[i]]++;
        countPattern[pattern[i]]++;
    }

    // Check if the first window is an anagram of the pattern
    if (compareFreqArrays(countText, countPattern))
        printf("Anagram found at index 0\n");

    // Sliding Window: Check subsequent windows for anagrams
    for (int i = M; i < N; i++) {
        countText[text[i]]++;
        countText[text[i - M]]--;

        if (compareFreqArrays(countText, countPattern))
            printf("Anagram found at index %d\n", i - M + 1);
    }
}

int main() {
    char text[] = "BACDGABCDA";
    char pattern[] = "ABCD";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    printf("Anagram occurrences:\n");
    anagramSubstringSearch(text, pattern);

    return 0;
}

/*
This C program implements the Sliding Window technique along with Frequency Arrays to find all occurrences of anagrams of a
given pattern in the given text. An anagram is a word or phrase formed by rearranging the letters of another, such as "cinema"
and "iceman."

*/

