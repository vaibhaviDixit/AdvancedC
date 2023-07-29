/*
Given two strings 's1' and 's2,' check if 's2' contains a permutation of 's1.'

Input:  s1=ab
        s2=eidbaooo
Output: s2 contains a permutation of s1: true

*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHARS 256
bool compareArrays(int arr1[], int arr2[]) {
    for (int i = 0; i < MAX_CHARS; i++) {
        if (arr1[i] != arr2[i]) {
            return false;  // Return false if any count is different
        }
    }
    return true;  // Return true if all counts are the same
}


bool checkPermutation(char* s1, char* s2) {
    int s1Count[MAX_CHARS] = {0};  // Frequency array for characters in s1
    int s2Count[MAX_CHARS] = {0};  // Frequency array for characters in s2
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);

    if (s1Len > s2Len) {
        return false;  // If s1 is longer than s2, s2 cannot contain a permutation of s1
    }

    for (int i = 0; i < s1Len; i++) {
        s1Count[s1[i]]++;  // Increment the count of character in s1
        s2Count[s2[i]]++;  // Increment the count of character in s2
    }

    for (int i = s1Len; i < s2Len; i++) {
        if (compareArrays(s1Count, s2Count)) {  // Compare the frequency arrays
            return true;
        }

        s2Count[s2[i]]++;  // Increment the count of the current character in s2
        s2Count[s2[i - s1Len]]--;  // Decrement the count of the character leaving the window
    }

    return compareArrays(s1Count, s2Count);  // Compare the frequency arrays at the end
}

int main() {
    char s1[] = "ring";
    char s2[] = "night";

    bool result = checkPermutation(s1, s2);
    printf("s2 contains a permutation of s1: %s\n", (result) ? "true" : "false");

    return 0;
}



/*
Two frequency arrays, s1Count and s2Count, are initialized to keep track of character frequencies.
The algorithm iterates through both s1 and s2 simultaneously. It increments the count of each character encountered in both arrays.
After the initial iteration, the algorithm starts sliding a window of the same length as s1 through s2.
At each step, the algorithm compares the frequency arrays using the compareArrays function. If they match, it means s2 contains a permutation of s1, and true is returned.
The algorithm increments the count of the current character in s2 and decrements the count of the character leaving the window.
Finally, after the window has passed through the entire s2, the algorithm compares the frequency arrays again to handle the last possible permutation.
The result is returned to the main function, and a message indicating whether s2 contains a permutation of s1 is printed.
*/
