/*
Write a C program to find all occurrences of an anagram of a word in a given sentence.

Input: Enter a sentence: listen silent earth heart
       Enter a word to find anagrams: earth
Output:
Anagram of 'earth' found at index 2
Anagram of 'earth' found at index 3

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if two strings are anagrams
bool areAnagrams(char str1[], char str2[]) {
    int count[128] = {0};

    if (strlen(str1) != strlen(str2))
        return false;

    for (int i = 0; i < strlen(str1); i++) {
        count[str1[i]]++;
        count[str2[i]]--;
    }

    for (int i = 0; i < 128; i++) {
        if (count[i] != 0)
            return false;
    }

    return true;
}

// Function to find all occurrences of anagrams of a word in a sentence
void findAnagramsInSentence(char sentence[], char word[]) {
    char words[100][100];
    int numWords = 0;

    // Tokenize the sentence to extract individual words
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        strcpy(words[numWords], token);
        numWords++;
        token = strtok(NULL, " ");
    }

    // Check each word if it is an anagram of the given word
    for (int i = 0; i < numWords; i++) {
        if (areAnagrams(words[i], word))
            printf("Anagram of '%s' found at index %d\n", word, i);
    }
}

int main() {
    char sentence[1000], word[100];
    printf("Enter a sentence: ");
    gets(sentence);
    printf("Enter a word to find anagrams: ");
    gets(word);

    findAnagramsInSentence(sentence, word);

    return 0;
}
/*
This program takes a sentence and a word as input and finds all occurrences of anagrams of the given word in the sentence.
It first tokenizes the sentence to extract individual words and then checks each word using the 'areAnagrams' function from a previous program.

*/

