/*
Implement the Rabin-Karp algorithm to efficiently search for occurrences of a given pattern in a given text.

Input: Text: ABABDABACDABABCABAB
       Pattern: ABABCABAB
Output: Pattern found at index 10

*/


#include <stdio.h>
#include <string.h>

#define d 256 // Number of characters in the input alphabet

// Rabin-Karp Algorithm
void RabinKarpSearch(char* text, char* pattern, int q) {
    int M = strlen(pattern);
    int N = strlen(text);
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
                printf("Pattern found at index %d\n", i);
        }

        // Calculate the hash value for the next window of text: Remove leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;

            // We might get a negative value of t, converting it to positive
            if (t < 0)
                t = t + q;
        }
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "DABAC";
    int q = 101; // A prime number

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    printf("Pattern occurrences:\n");
    RabinKarpSearch(text, pattern, q);

    return 0;
}

/*
The Rabin-Karp algorithm is a string-searching algorithm that uses hashing to find occurrences of a pattern in a given text.
It works by calculating the hash value of the pattern and the first window of text. If the hash values match, then it checks
for character-by-character match to confirm the occurrence of the pattern at that position. If there is a hash value collision,
it further verifies the match by checking character by character. The algorithm slides the pattern over the text one position at
a time and re-calculates the hash value for each window of text.
By comparing the hash values, it efficiently finds all occurrences of the pattern in the text.
*/
