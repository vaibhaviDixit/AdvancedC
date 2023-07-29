/*
Implement the Rabin-Karp Algorithm to efficiently count the occurrences of a given pattern in a given text.

Input: Text: ABABDABACDABABCABAB
       Pattern: ABAB
Output: Number of occurrences: 3

*/

#include <stdio.h>
#include <string.h>

#define d 256 // Number of characters in the input alphabet

// Rabin-Karp Algorithm - Counting Occurrences
int RabinKarpCount(char* text, char* pattern, int q) {
    int M = strlen(pattern);
    int N = strlen(text);
    int count = 0;

    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // Check the hash values of the current window of text and pattern
        // If the hash values match, then check for character by character match
        if (p == t) {
            // Check for characters one by one
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == M)
                count++;
        }

        // Calculate the hash value for the next window of text: Remove leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;

            // We might get a negative value of t, converting it to positive
            if (t < 0)
                t = t + q;
        }
    }

    return count;
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABAB";
    int q = 101; // A prime number

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    int occurrences = RabinKarpCount(text, pattern, q);

    printf("Number of occurrences: %d\n", occurrences);

    return 0;
}

/*

The Rabin-Karp Algorithm is a string-searching algorithm that efficiently finds all occurrences of a pattern in a given text.
It uses a rolling hash function to calculate the hash values of the pattern and the text substrings and then compares these hash
values to find matches.
The rolling hash function allows for a constant-time update of the hash value for each window of the text.

*/
