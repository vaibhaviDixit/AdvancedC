/*

Write a C program to find the frequency of each character in a given string.

Input: Enter a string: HadappaLife
Output:
Frequency of H: 1
Frequency of L: 1
Frequency of a: 3
Frequency of d: 1
Frequency of e: 1
Frequency of f: 1
Frequency of i: 1
Frequency of p: 2

*/

#include <stdio.h>
#include <string.h>

// Function to find the frequency of characters
void findFrequency(char str[]) {
    int freq[128] = {0};

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];
        freq[ch]++;
    }

    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0 && i != ' ') {
            printf("Frequency of %c: %d\n", i, freq[i]);
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);

    findFrequency(str);

    return 0;
}
/*
 This program takes a string as input and finds the frequency of each character using a frequency array approach.
 It iterates through the string and increments the count for each character encountered in the 'freq' array.
 The program then prints the frequency of each character (excluding spaces).

 */

