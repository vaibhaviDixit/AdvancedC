/*

Write a C program to check if a given string can be rearranged to form a palindrome.

Input: Enter a string: abb
Output: The string can be rearranged to form a palindrome.

*/

#include <stdio.h>
#include <string.h>

// Function to check if the string can be rearranged to form a palindrome
int canFormPalindrome(char str[]) {
    int count[128] = {0};

    for (int i = 0; i < strlen(str); i++)
        count[str[i]]++;

    int oddCount = 0;

    for (int i = 0; i < 128; i++) {
        if (count[i] % 2 != 0)
            oddCount++;
    }

    return oddCount <= 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);

    if (canFormPalindrome(str))
        printf("The string can be rearranged to form a palindrome.");
    else
        printf("The string cannot be rearranged to form a palindrome.");

    return 0;
}
/*
 This program takes a string as input and checks if it can be rearranged to form a palindrome using the frequency array approach.
 For a string to be rearranged as a palindrome, it should have at most one character with an odd frequency (all other characters must have
 even frequencies).

*/

