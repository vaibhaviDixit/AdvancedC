/*
 Write a C program to find the length of the longest substring without repeating characters in a given string.

 Input: Enter a string:advance
 Output: Length of the longest substring without repeating characters: 6


*/

#include <stdio.h>
#include <string.h>

// Function to find the length of the longest substring without repeating characters
int lengthOfLongestSubstring(char str[]) {
    int n = strlen(str);
    int maxLength = 0;
    int start = 0;
    int lastIndex[128];

    for (int i = 0; i < 128; i++)
        lastIndex[i] = -1;

    for (int i = 0; i < n; i++) {
        if (lastIndex[str[i]] >= start)
            start = lastIndex[str[i]] + 1;

        maxLength = (i - start + 1 > maxLength) ? i - start + 1 : maxLength;
        lastIndex[str[i]] = i;
    }

    return maxLength;
}

int main() {
    char str[100];
    printf("Enter a string:");
    gets(str);

    int length = lengthOfLongestSubstring(str);
    printf("Length of the longest substring without repeating characters: %d", length);

    return 0;
}
/*
 This program takes a string as input and finds the length of the longest substring without repeating characters using the two pointers approach.
 It uses an array 'lastIndex' to store the last index of each character encountered in the string. The 'start' pointer keeps track of the starting
 position of the current substring without repeating characters.

 */
