/*
Write a C program to find the longest common prefix among a set of strings.

Input: Enter the number of strings: 4
       Enter the strings: apple appu apron apex
Output: Longest Common Prefix: ap

*/

#include <stdio.h>
#include <string.h>

// Function to find the longest common prefix
void longestCommonPrefix(char strings[][100], int numStrings) {
    int prefixLen = 0;
    int minLen = strlen(strings[0]);

    // Find the minimum length among all strings
    for (int i = 1; i < numStrings; i++) {
        int len = strlen(strings[i]);
        if (len < minLen)
            minLen = len;
    }

    // Compare characters at each position in all strings
    for (int i = 0; i < minLen; i++) {
        char ch = strings[0][i];
        int j;
        for (j = 1; j < numStrings; j++) {
            if (strings[j][i] != ch)
                break;
        }

        if (j == numStrings)
            prefixLen++;
        else
            break;
    }

    // Copy the longest common prefix to a new string
    char longestPrefix[100];
    for (int i = 0; i < prefixLen; i++) {
        longestPrefix[i] = strings[0][i];
    }

    longestPrefix[prefixLen] = '\0';

    printf("Longest Common Prefix: %s", longestPrefix);
}

int main() {
    char strings[100][100];
    int numStrings;

    printf("Enter the number of strings: ");
    scanf("%d", &numStrings);

    printf("Enter the strings:\n");
    for (int i = 0; i < numStrings; i++) {
        scanf("%s", strings[i]);
    }

    longestCommonPrefix(strings, numStrings);

    return 0;
}
 /*
  This program takes a set of strings as input and finds the longest common prefix among them.
  It iterates through each position in the strings and compares the characters at that position. If the characters match in all strings,
  it increments the 'prefixLen'. If the characters do not match in any string, it stops and copies the longest common prefix into the
  'longestPrefix' string.

*/

