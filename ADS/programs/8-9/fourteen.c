/*
Write a C program to concatenate two strings without using the standard library function strcat().

Input: Enter the first string: Hello
       Enter the second string: Rains
Output: Concatenated string: HelloRains

*/

#include <stdio.h>
#include <string.h>

// Function to concatenate two strings
void concatenateStrings(char str1[], char str2[], char result[]) {
    int i, j;

    // Copy the characters of the first string to the result
    for (i = 0; str1[i] != '\0'; i++) {
        result[i] = str1[i];
    }

    // Copy the characters of the second string to the result
    for (j = 0; str2[j] != '\0'; j++) {
        result[i + j] = str2[j];
    }

    // Terminate the result string with null character
    result[i + j] = '\0';
}

int main() {
    char str1[100], str2[100], result[200];
    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string: ");
    gets(str2);

    concatenateStrings(str1, str2, result);
    printf("Concatenated string: %s", result);

    return 0;
}

/* This program takes two strings as input and concatenates them into a third string ('result') without using the strcat() function.
 It uses a loop to copy characters from both strings to the 'result' string until the null character '\0' is encountered.
*/

