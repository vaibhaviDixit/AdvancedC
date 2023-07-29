/*
Write a C program to check if a given string is a palindrome or not.

Input: Enter a string: mom
Output: The string is a palindrome.

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the string is a palindrome
bool isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right])
            return false;

        // Move the pointers inward
        left++;
        right--;
    }

    return true;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);

    if (isPalindrome(str))
        printf("The string is a palindrome.");
    else
        printf("The string is not a palindrome.");

    return 0;
}

/*
This program takes a string as input and checks if it is a palindrome or not using two pointers approach, similar to the previous program.
If the characters at the left and right pointers are not the same, the function returns false; otherwise, it continues until the pointers meet
in the middle, indicating a palindrome.

*/


