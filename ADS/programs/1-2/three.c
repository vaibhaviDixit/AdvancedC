/*
Given a string, find the length of the longest substring that contains at most K distinct characters.

Input: string=abbbbbbc
       k=2
Output: Length of the longest substring with at most 2 distinct characters is: 7


*/

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 26

int longestSubstringKDistinct(char str[], int k) {
    int freq[MAX_CHAR] = {0};  // Frequency array to track character occurrences
    int distinctCount = 0;  // Number of distinct characters in the current window
    int windowStart = 0;  // Start index of the sliding window
    int maxLength = 0;  // Length of the longest substring

    for (int windowEnd = 0; windowEnd < strlen(str); windowEnd++) {
        if (freq[str[windowEnd] - 'a'] == 0)
            distinctCount++;  // Increment distinct count if encountering a new character

        freq[str[windowEnd] - 'a']++;  // Update the frequency of the current character

        while (distinctCount > k) {  // Shrink the window until distinct count becomes <= k
            freq[str[windowStart] - 'a']--;  // Decrement the frequency of the character at window start
            if (freq[str[windowStart] - 'a'] == 0)
                distinctCount--;  // Decrement distinct count if the frequency becomes 0
            windowStart++;  // Move the window start ahead
        }

        maxLength = (windowEnd - windowStart + 1) > maxLength ? (windowEnd - windowStart + 1) : maxLength;
        // Update the maximum length if the current length is larger
    }

    return maxLength;  // Return the length of the longest substring with at most k distinct characters
}

int main() {
    char str[] = "aabbcc";
    int k = 1;

    int maxLength = longestSubstringKDistinct(str, k);
    printf("Length of the longest substring with at most %d distinct characters is: %d\n", k, maxLength);

    return 0;
}


/*
We use an array freq to store the frequency of each character.
We maintain a distinct count and a window start index.
If the frequency of the current character is 0, we increment the distinct count.
If the distinct count becomes greater than K, we move the window start index and decrement the frequency of the character at that position.
We update the maximum length at each step.
*/
