/*
Given a text string and a pattern string, write a program to find all occurrences of the pattern (case-insensitive) in the text.

Input: text = "AaBAACAadaabaaabaa";
       pattern = "AABa";
Output:
Pattern found at index 0
Pattern found at index 9
Pattern found at index 13

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to implement Rabin-Karp algorithm with case-insensitivity
void rabinKarpCaseInsensitive(char text[], char pattern[]) {
    int prime = 101;
    int lenText = strlen(text);
    int lenPattern = strlen(pattern);
    int hashPattern = 0, hashText = 0;
    int h = 1;
    int i, j;

    // Calculate the hash value of the lowercase pattern and the first window of the lowercase text
    for (i = 0; i < lenPattern - 1; i++)
        h = (h * 256) % prime;
    for (i = 0; i < lenPattern; i++) {
        hashPattern = (256 * hashPattern + tolower(pattern[i])) % prime;
        hashText = (256 * hashText + tolower(text[i])) % prime;
    }

    // Slide the pattern over the lowercase text and check for matches
    for (i = 0; i <= lenText - lenPattern; i++) {
        if (hashPattern == hashText) {
            // If the hash matches, compare individual characters in lowercase
            for (j = 0; j < lenPattern; j++) {
                if (tolower(text[i + j]) != tolower(pattern[j]))
                    break;
            }
            if (j == lenPattern)
                printf("Pattern found at index %d\n", i);
        }
        if (i < lenText - lenPattern) {
            // Calculate the hash value for the next window in the lowercase text
            hashText = (256 * (hashText - tolower(text[i]) * h) + tolower(text[i + lenPattern])) % prime;
            if (hashText < 0)
                hashText = hashText + prime;
        }
    }
}

int main() {
    char text[] = "AaBAACAadaabaaabaa";
    char pattern[] = "AABa";
    rabinKarpCaseInsensitive(text, pattern);
    return 0;
}


/*
In this scenario, we want to find the occurrences of a case-insensitive pattern in a given text.

*/
