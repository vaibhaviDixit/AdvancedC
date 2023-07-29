/*
Write a C program to find the second most frequent character in a given string.

Input: Enter a string: TrainingAndPlacementCell
Output: Second most frequent character: e

*/

#include <stdio.h>
#include <string.h>

// Function to find the second most frequent character
char findSecondMostFrequentChar(char str[]) {
    int count[128] = {0};

    for (int i = 0; i < strlen(str); i++)
        count[str[i]]++;

    int firstMax = 0;
    int secondMax = 0;
    char secondMaxChar;

    for (int i = 0; i < 128; i++) {
        if (count[i] > count[firstMax]) {
            secondMax = firstMax;
            firstMax = i;
        } else if (count[i] > count[secondMax] && count[i] < count[firstMax]) {
            secondMax = i;
        }
    }

    secondMaxChar = (char)secondMax;
    return secondMaxChar;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);

    char secondMostFrequent = findSecondMostFrequentChar(str);
    printf("Second most frequent character: %c", secondMostFrequent);

    return 0;
}
/*
 This program takes a string as input and finds the second most frequent character using the frequency array approach.
 It iterates through the 'count' array to find the indices of the first and second most frequent characters.

 */
