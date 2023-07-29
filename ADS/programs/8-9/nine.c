/*
 Write a C program to remove all duplicate characters from a given string.

 Input: Enter a string: breadbuttertoast
 Output: String after removing duplicates: breadutos

*/

#include <stdio.h>
#include <string.h>

// Function to remove duplicate characters from the string
void removeDuplicates(char str[]) {
    int n = strlen(str);
    int index = 0;

    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j])
                break;
        }

        if (j == i)
            str[index++] = str[i];
    }

    str[index] = '\0';
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);

    removeDuplicates(str);
    printf("String after removing duplicates: %s", str);

    return 0;
}
/*
 This program takes a string as input and removes all duplicate characters from it using the two pointers approach.
 It maintains an 'index' to keep track of the non-duplicate characters and shifts them to the front of the string.

*/
