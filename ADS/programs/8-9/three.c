/*
Write a C program to count the number of vowels and consonants in a given string.

Input: Enter a string: kanyakumari
Output:
Number of vowels: 5
Number of consonants: 6


*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to count vowels and consonants
void countVowelsAndConsonants(char str[]) {
    int vowels = 0;
    int consonants = 0;

    for (int i = 0; i < strlen(str); i++) {
        char ch = tolower(str[i]);

        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);

    countVowelsAndConsonants(str);

    return 0;
}

/*
 This program takes a string as input and counts the number of vowels and consonants using a frequency array approach.
 It iterates through each character in the string, converts it to lowercase, and increments the respective counters based on vowel and consonant
 conditions.
*/
