/*
 Write a C program to find the frequency of each word in a given sentence.

Input: Enter a sentence: It can talk, talk, talk.

Output:
Frequency of 'It': 1
Frequency of 'can': 1
Frequency of 'talk,': 2
Frequency of 'talk.': 1


*/

#include <stdio.h>
#include <string.h>

// Function to find the frequency of words
void findWordFrequency(char sentence[]) {
    char words[100][100];
    int frequency[100] = {0};
    int numWords = 0;

    // Tokenize the sentence to extract individual words
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        strcpy(words[numWords], token);
        numWords++;
        token = strtok(NULL, " ");
    }

    // Calculate the frequency of each word
    for (int i = 0; i < numWords; i++) {
        frequency[i]++;
        for (int j = i + 1; j < numWords; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequency[i]++;
                // Mark the word as visited to avoid counting it again
                frequency[j] = -1;
            }
        }
    }

    // Print the frequency of each word
    for (int i = 0; i < numWords; i++) {
        if (frequency[i] > 0)
            printf("Frequency of '%s': %d\n", words[i], frequency[i]);
    }
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    gets(sentence);

    findWordFrequency(sentence);

    return 0;
}
/*
 This program takes a sentence as input and finds the frequency of each word in the sentence using a frequency array approach.
 It tokenizes the sentence to extract individual words and then calculates the frequency of each word by comparing it with other words
 in the sentence.

 */

