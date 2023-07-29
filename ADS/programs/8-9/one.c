
/*
Write a C program to reverse a given string.

Input: Enter a string: Abacus
Output: Reversed string: sucabA

*/

#include <stdio.h>
#include <string.h>

// Function to reverse the string
void reverseString(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Swap characters at left and right pointers
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        // Move the pointers inward
        left++;
        right--;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);

    reverseString(str);
    printf("Reversed string: %s", str);

    return 0;
}

/*
This program takes a string as input and reverses it in-place using two pointers - one at the beginning and one at the end of the string.
It repeatedly swaps the characters at the left and right pointers and moves the pointers towards each other until they meet in the middle.

*/



