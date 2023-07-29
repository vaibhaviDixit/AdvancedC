/*
 Write a C program to count the occurrences of a given substring in a string.

 Input: Enter a string: spring
        Enter a substring: ring
 Output: Number of occurrences: 1

*/

#include <stdio.h>
#include <string.h>

// Function to count occurrences of a substring
int countOccurrences(char str[], char sub[]) {
    int count = 0;
    int subLen = strlen(sub);

    for (int i = 0; i <= strlen(str) - subLen; i++) {
        int j;
        for (j = 0; j < subLen; j++) {
            if (str[i + j] != sub[j])
                break;
        }

        if (j == subLen)
            count++;
    }

    return count;
}

int main() {
    char str[100], sub[100];
    printf("Enter a string: ");
    gets(str);
    printf("Enter a substring: ");
    gets(sub);

    int occurrences = countOccurrences(str, sub);
    printf("Number of occurrences: %d", occurrences);

    return 0;
}

/*
This program takes a string and a substring as input and counts the number of occurrences of the substring in the string using the two
pointers approach. It compares each substring of the same length as the given substring in the main string and counts matches.

*/
