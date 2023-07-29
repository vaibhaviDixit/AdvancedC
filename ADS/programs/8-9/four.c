/*
Write a C program to remove all spaces from a given string.

Input: Enter a string: There is no Idli without chutney
Output: String after removing spaces: ThereisnoIdliwithoutchutney

*/

#include <stdio.h>
#include <string.h>

// Function to remove spaces from the string
void removeSpaces(char str[]) {
    int n = strlen(str);
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] != ' ') {
            str[count] = str[i];
            count++;
        }
    }

    str[count] = '\0';
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);

    removeSpaces(str);
    printf("String after removing spaces: %s", str);

    return 0;
}
/*
 This program takes a string as input and removes all spaces from it using an implementation of the two pointers approach.
 It maintains a count of non-space characters and shifts them to the front of the string while discarding the spaces.
*/
