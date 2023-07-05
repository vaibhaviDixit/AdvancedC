/*
Given a string and a pattern, find the count of all anagrams of the pattern that occur as a substring in the string.

Input: str=AAABABAA
       pattern=AABA
Output: Count of anagram occurrences: 5

*/

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 26

int countAnagramOccurrences(char str[], char pattern[]) {
    int freqPattern[MAX_CHAR] = {0};  // Frequency array for the pattern
    int freqWindow[MAX_CHAR] = {0};  // Frequency array for the sliding window
    int patternLength = strlen(pattern);  // Length of the pattern
    int windowStart = 0;  // Start index of the sliding window
    int count = 0;  // Count of anagram occurrences

    for (int i = 0; i < patternLength; i++) {
        freqPattern[pattern[i] - 'a']++;  // Increment the frequency of characters in the pattern
        freqWindow[str[i] - 'a']++;  // Increment the frequency of characters in the window
    }

    for (int windowEnd = patternLength; windowEnd <= strlen(str); windowEnd++) {
        int isAnagram = 1;  // Flag to track if the current window is an anagram of the pattern

        for (int i = 0; i < MAX_CHAR; i++) {
            if (freqPattern[i] != freqWindow[i]) {
                isAnagram = 0;  // Set the flag to false if frequencies do not match
                break;
            }
        }

        if (isAnagram)
            count++;  // Increment the count if the window is an anagram

        freqWindow[str[windowStart] - 'a']--;  // Decrement the frequency of the character at window start
        freqWindow[str[windowEnd] - 'a']++;  // Increment the frequency of the character at window end
        windowStart++;  // Move the window start ahead
    }

    return count;  // Return the count of anagram occurrences
}

int main() {
    char str[] = "AAABABAA";
    char pattern[] = "AABA";

    int count = countAnagramOccurrences(str, pattern);
    printf("Count of anagram occurrences: %d\n", count);

    return 0;
}
/*
We use two arrays freqPattern and freqWindow to store the frequency of each character in the pattern and the current window, respectively.
We initialize these arrays with the frequency of characters in the first window.
At each step, we check if the window is an anagram of the pattern.
If it is, we increment the count.
We slide the window by decrementing the frequency of the character at the window start and incrementing the frequency of the character at the window end.
*/
