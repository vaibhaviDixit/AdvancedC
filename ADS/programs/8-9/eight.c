/*

Write a C program to check if two given strings are anagrams of each other.

Input: Enter the first string: silent
       Enter the second string: listen
Output: The two strings are anagrams.

*/

#include <stdio.h>
#include <string.h>

// Function to check if two strings are anagrams
int areAnagrams(char str1[], char str2[]) {
    int count[128] = {0};

    // If the lengths of the strings are different, they cannot be anagrams
    if (strlen(str1) != strlen(str2))
        return 0;

    for (int i = 0; i < strlen(str1); i++) {
        count[str1[i]]++;
        count[str2[i]]--;
    }

    for (int i = 0; i < 128; i++) {
        if (count[i] != 0)
            return 0;
    }

    return 1;
}

int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string: ");
    gets(str2);

    if (areAnagrams(str1, str2))
        printf("The two strings are anagrams.");
    else
        printf("The two strings are not anagrams.");

    return 0;
}
/* This program takes two strings as input and checks if they are anagrams of each other using the frequency array approach.
It first checks if the lengths of the two strings are equal; if not, they cannot be anagrams. Then, it maintains a frequency array 'count'
for both strings and verifies that the frequencies of all characters are the same.

*/

