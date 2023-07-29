/*
Given a string, find the length of the longest substring that does not contain any repeating characters.

Input: Text: abcabcbb
Output: Length of the Longest Substring without Repeating Characters: 3

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is present in the current window
int isCharInWindow(char* window, char c, int windowSize) {
    for (int i = 0; i < windowSize; i++) {
        if (window[i] == c)
            return 1;
    }
    return 0;
}

// Longest Substring without Repeating Characters using Sliding Window
int longestSubstring(char* text) {
    int N = strlen(text);
    int maxLen = 0;
    int start = 0;

    // Create a window to store the current substring
    char* window = (char*)malloc(N * sizeof(char));
    int windowSize = 0;

    for (int i = 0; i < N; i++) {
        if (!isCharInWindow(window, text[i], windowSize)) {
            window[windowSize] = text[i];
            windowSize++;
        } else {
            int len = windowSize - start;
            if (len > maxLen)
                maxLen = len;

            // Shrink the window until the repeated character is removed
            while (text[start] != text[i]) {
                start++;
            }
            start++; // Move the start pointer one position after the repeated character
            windowSize = i - start + 1;
        }
    }

    // Check if the last window contains the longest substring
    int len = windowSize - start;
    if (len > maxLen)
        maxLen = len;

    free(window);

    return maxLen;
}

int main() {
    char text[] = "abcabcbb";

    printf("Text: %s\n", text);

    int longestLen = longestSubstring(text);

    printf("Length of the Longest Substring without Repeating Characters: %d\n", longestLen);

    return 0;
}

/*
This C program implements the Sliding Window technique to find the length of the longest substring without repeating characters.
The sliding window approach is an efficient way to handle substring problems where a window is maintained to track the current
substring being considered.

*/


